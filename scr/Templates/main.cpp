#include <iostream>
#include "Matriz.h"

using namespace std;

int main() {
	
	Matriz<int>  matriz01(10, 10);

	matriz01[9][1] = 14;
	matriz01[6][9] = 89;
	matriz01[7][5] = 9;
	matriz01[1][1] = 45;

	Matriz<int> matriz02(10, 10);
	Matriz<int> matriz03(10, 10);
	Matriz<int> matriz04(10, 10);

	matriz01 * 2;
	matriz02 + matriz02;
	matriz03 - matriz03;
	
	
	cout << matriz01;
	cin >> matriz01; //pede 10x10 insercoes para gerar uma matriz completa

	cout << matriz01;

	return 0;
}