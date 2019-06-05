#include <iostream>
#include <set>
#include <algorithm>

#include "atividades.h"

using namespace std;

void atividade03(){

	//cria o conjunto e insere os valores
	set<int> conjunto;

	conjunto.insert(1234);
	conjunto.insert(9999);
	conjunto.insert(9876);
	

	//solicita um valor, informa se obteve acesso e encerra a aplicação em caso de duas ocorrencias do mesmo codigo
	set<int> tentativas; //armazena os valores incorretos 

	while (true) {

		int codigo;
		cout << "Informe um codigo de acesso: ";
		cin >> codigo;

		if (!conjunto.count(codigo)) {

			//se o codigo atual (incorreto) ja foi informado anteriormente, aborta o programa
			if (tentativas.count(codigo)) {
				cout << "Numero de tentativas esgotadas para este codigo: " << codigo << "!" << endl;
				cout << "Abortando..." << endl;
				return;
			}

			cout << "Codigo incorreto, tentar novamente." << endl;
			tentativas.insert(codigo); //armazena o codigo informado, no caso de outra ocorrencia, o sistema ira abortar
		}
		else {
			cout << "Codigo verificado, voce obteve acesso!" << endl;
			break;
		}
	}
}