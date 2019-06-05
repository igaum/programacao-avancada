#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <stack>

#include "atividades.h"

using namespace std;

void imprime(list<string> lista) {

	list<string>::iterator cont;

	for (cont = lista.begin(); cont != lista.end(); cont++){
		cout << *cont << endl;
	} cout << endl << endl;
}

void atividade02() {

	//cria uma lista vazia e imprime
	list<string> lista;
	imprime(lista);


	//preenche a lista e imprime
	lista.push_back("ovos");
	lista.push_back("leite");
	lista.push_back("acucar");
	lista.push_back("chocolate");
	lista.push_back("farinha");
	imprime(lista);


	//remove o ultimo elemento e imprime
	list<string>::iterator it = lista.end(); --it; //"end - 1" aponta para o ultimo node valido
	lista.erase(it);
	imprime(lista);


	//adiciona o item ("cafe") no inicio e imprime
	lista.insert(lista.begin(), "cafe");
	imprime(lista);


	//procura por ("acucar"), troca por ("mel") e imprime
	it = find(lista.begin(), lista.end(), "acucar");
	*it = "mel";
	imprime(lista);


	//insere o valor ("fermento") antes de ("chocolate")
	it = find(lista.begin(), lista.end(), "chocolate");
	lista.insert(it, "fermento");
	imprime(lista);


	//remove o item ("leite")
	it = find(lista.begin(), lista.end(), "leite");
	lista.erase(it);
	imprime(lista);


	//ordena em ordem decrescente e imprime
	lista.sort(); //ordena em ordem alfabetica

	//joga os valores em uma pilha e os recupera, fazendo assim a ordem decrescente 
	stack<string> pilha; 
	for (auto i = lista.begin(); i != lista.end(); i++) { 
		pilha.push(*i); 
	}
	for (auto i = lista.begin(); i != lista.end(); i++) {
		*i = pilha.top();
		pilha.pop();
	}
	imprime(lista);
}