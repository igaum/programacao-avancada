#pragma once

#include <string>

using namespace std;

//Excecoes (ex. 3)

class PilhaVaziaException : public exception {
public:
	virtual const char* what() const noexcept {
		return "Pilha vazia!";
	}
};

class PilhaCheiaException : public exception {
public:
	virtual const char* what() const noexcept {
		return "pilha cheia!";
	}
};

class StringVaziaException : public exception {
public:
	virtual const char* what() const noexcept {
		return "String vazia!";
	}
};


//classe Pilha que servira como base para os exercicios 1, 2, 3

class Pilha {

public:

	Pilha(int tamanho = 100) : tamanho(tamanho), topo(0) {
		pilha = new string*[tamanho];
	}

	void push(string valor) {

		if (valor == "") throw StringVaziaException();

		//caso ja esteja cheia, informa
		if (tamanho == topo) throw PilhaCheiaException();

		//insere no topo incrementando o mesmo
		else pilha[topo++] = new string(valor);
	}

	string pop() {

		//se o topo for zero, indica que a pilha esta vazia
		if (topo < 1) {
			throw PilhaVaziaException();
			return "";
		}

		//puxa o valor do topo e decrementa
		string valor = *pilha[(topo - 1)];

		//deleta o valor
		delete this->pilha[--topo];

		return valor;
	}

	int get_topo() { return topo; }

	void imprime() {
		for (int i = 0; i < topo; i++) {
			cout << *pilha[i] << endl;
		}
	}


	//sobrecarga de operadores (ex.1)

	//adiciona um novo item
	string operator +=(const string& valor) {
		push(valor);
		return valor;
	}

	//remove e retorna um item
	string operator --(int) { return pop(); }


	//funcoes amigas (ex. 2)

	//imprime a pilha com o operador <<
	friend ostream& operator<<(std::ostream& os, Pilha& pilha) {
		for (int i = 0; i < pilha.topo; i++)
			os << *pilha.pilha[i] << endl;
		return os;
	}

	//insere na pilha com o operador >>
	friend istream& operator >> (std::istream& is, Pilha& pilha) {

		string valor;
		is >> valor;

		//nao achei uma forma de inserir string vazia com cin...mas so pra garantir 
		if (valor == "") throw StringVaziaException();

		//caso ja esteja cheia, informa
		if (pilha.tamanho == pilha.topo) cout << "A pilha esta cheia\n";

		//insere no topo incrementando o mesmo
		else pilha.pilha[pilha.topo++] = new string(valor);

		return is;
	} 

private:

	int tamanho, topo;
	string** pilha;
};