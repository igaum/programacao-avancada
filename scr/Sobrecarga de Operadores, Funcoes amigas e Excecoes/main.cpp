#include <iostream>

#include "Pilha.h"

using namespace std;

int main() {
	try {
		Pilha p;

		//testes ex.1 (sobrecarga de operadores)
		p += "valor 1";
		p += "valor 2";
		p += "valor 3";
		p += "valor 4";
		//p += ""; // retorna a exception StringVaziaException

		p.imprime();

		cout << p-- << endl;
		cout << p-- << endl;
		cout << p-- << endl;
		cout << p-- << endl;
		//cout << p-- << endl; //retorna a exception PilhaVaziaException


		//testes ex.2 (funcoes amigas)
		cout << "Insira na pilha: ";
		cin >> p;
		cout << p << endl;
	}


	//testes ex.3 (excecoes)
	catch (PilhaCheiaException &ex)  { cerr << ex.what() << endl; }

	catch (PilhaVaziaException &ex)  { cerr << ex.what() << endl; }

	catch (StringVaziaException &ex) { cerr << ex.what() << endl; }

	system("pause");
	return 0;
}