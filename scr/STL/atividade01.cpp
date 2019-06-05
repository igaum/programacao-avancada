#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "atividades.h"

using namespace std;

void imprime(vector<string> vetor) {

	for (int i = 0; i <vetor.size(); i++) {
		cout << vetor[i] << endl;
	} cout << endl << endl;
}

void atividade01(){

	//cria vetor vazio e imprime
	vector<string> vetor(5, "\0");
	imprime(vetor);


	//preenche e imprime
	vetor[0] = "ovos";
	vetor[1] = "leite";
	vetor[2] = "acucar";
	vetor[3] = "chocolate";
	vetor[4] = "farinha";
	imprime(vetor);


	//retira o ultimo valor ("farinha") e imprime
	vetor.pop_back();
	imprime(vetor);


	//adiciona o valor ("cafe") e imprime
	vetor.push_back("cafe");
	imprime(vetor);


	//localiza ("acucar") para substituir por mel e imprime
	auto pos = find(begin(vetor), end(vetor), "acucar");
	*pos = "mel";
	imprime(vetor);


	//localiza ("leite"), remove e imprime
	pos = find(begin(vetor), end(vetor), "leite");
	vetor.erase(pos);
	imprime(vetor);


	//ordena o vetor e imprime
	sort(vetor.begin(), vetor.end());
	imprime(vetor);
}