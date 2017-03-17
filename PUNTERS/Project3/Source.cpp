#include <iostream>
#include <stdlib.h>

using namespace std;

/*
void sida(int* p) {
	*p += 2;
}
*/

int main() {
	/* int pointers

	int v[5] = { 0, 1, 2, 3, 4 };
	int *p = v;
	cout << *p << endl;
	*p = *(p++);
	cout << *p << endl;
	*p = *(p + 2);
	cout << *p << endl;
	*p = v[0];
	sida(&v[0]);
	cout << v[0] << endl;
	*/

	/* char pointers

	char* s = "SIDA";
	cout << *s << endl;
	cout << *(s + 2) << endl;
	*/

	/* void pointers 

	int a = 3;
	void* y = &a;
	cout << *((int*)y) << endl; //referenciar l'element al que apunta el punter. si poses "cout << *y" no funciona
	*/

	/* malloc --> guarda un block de memòria d'un tamany determinat, pero amb els elements sense inicialitzar (estan a null. el punter pot apuntar a qualsevol lloc, fins i tot
	a una adreça de memòria invàlida 
	
	//malloc amb int
	int* m = (int*)malloc(4 * sizeof(int));
	for (int x = 0; x < 4; ++x) m[x] = x;
	for (int y = 0; y < 4; ++y) cout << m[y] << endl;

	
	//malloc amb char
	char* n = (char*)malloc(4 * sizeof(char));
	for (int i = 0; i < 4; ++i) n[i] = 'm';
	for (int j = 0; j < 4; ++j) cout << n[j] << endl;
	*/
		
	/* calloc --> guarda un determinat nombre de blocs de memòria consecutius i els inicialitza a 0

	//calloc amb int
	int* num = (int*)calloc(4, sizeof(int));
	for (int i = 0; i < 4; ++i) *(num + i) = i;
	for (int j = 0; j < 4; ++j) cout << *(num + j) << endl;

	//calloc amb char
	char* c = (char*)calloc(4, sizeof(char));
	for (int x = 0; x < 4; ++x) *(c + x) = 'm';
	for (int y = 0; y < 4; ++y) cout << *(c + y) << endl;
	*/
	
	system("pause");
	return 0;
}