#include <iostream>
#include <map>
#include <algorithm>
#include <string>

#include "atividades.h"

using namespace std;

void imprime(map<string, string> cores) {
	
	for (auto it = cores.begin(); it != cores.end(); it++) {
		cout << "chave: " << (*it).first << endl;
		cout << "valor: " << (*it).second << endl << endl;
	} cout << endl << endl;
}

void atividade04() {

	//cria um mapa vazio e imprime
	map<string, string> cores;
	imprime(cores);


	//preenche o mapa com 8 cores e imprime
	cores["Azul"]		 = "0x0000FF";
	cores["Verde Limao"] = "0x32CD32";
	cores["Ouro"]		 = "0xFFD700";
	cores["Salmao"]		 = "0xFA8072";
	cores["Laranja"]	 = "0xFFA500";
	cores["Roxo"]		 = "0xA020F0";
	cores["Cinza"]		 = "0xBEBEBE";
	cores["Preto"]		 = "0x000000";
	imprime(cores);


	//pesquisa por valores no mapa
	auto search = cores.find("Branco");
	if (search != cores.end()) cout << (*search).first << endl << (*search).second << endl;
	else cout << "Este valor nao existe no mapa" << endl;
}