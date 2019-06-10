#include <iostream>

template<typename T>
class Matriz {
public:
	Matriz(unsigned int linhas = 0, unsigned int colunas = 0) : linhas(linhas), colunas(colunas) {
		this->matriz = new T*[this->linhas];
	
		for (unsigned int i = 0; i < this->linhas; i++) {
			this->matriz[i] = new T[this->colunas];
		}

		for (int i = 0; i < this->linhas; i++) {
			for (int j = 0; j < this->colunas; j++)
				this->matriz[i][j] = 0;
		}
	}

	//getters
	int GetLinhas() { return this->linhas; };
	int GetColunas() { return this->colunas; };

	//operadores '[]', '+', '-' e '*'
	T* operator[](int index) {
		return this->matriz[index];
	}

	void operator+(Matriz m) {
		for (int i = 0; i < this->linhas; i++) {
			for (int j = 0; j < this->colunas; j++) {
				this->matriz[i][j] = this->matriz[i][j] + m[i][j];
			}
		}
	}

	void operator-(Matriz m) {
		for (int i = 0; i < this->linhas; i++) {
			for (int j = 0; j < this->colunas; j++) {
				this->matriz[i][j] = this->matriz[i][j] - m[i][j];
			}
		}
	}

	void operator*(int e) {
		for (int i = 0; i < this->linhas; i++) {
			for (int j = 0; j < this->colunas; j++) {
				this->matriz[i][j] = this->matriz[i][j] * e;
			}
		}
	}

	//operadores '<<' e '>>' 
	friend std::ostream& operator<<(std::ostream& os, Matriz& m) {
		for (int i = 0; i < m.GetLinhas(); i++) {
			for (int j = 0; j < m.GetColunas(); j++) {
				std::cout << m[i][j] << " ";
			}
			std::cout << std::endl;
		}

		return os;
	}

	friend std::istream& operator>>(std::istream& is, Matriz& m) {
		for (int i = 0; i < m.GetLinhas(); i++) {
			for (int j = 0; j < m.GetColunas(); j++) {
				is >> m[i][j];
			}
		}

		return is;
	}
private:
	int linhas;
	int colunas;
	T** matriz;
};