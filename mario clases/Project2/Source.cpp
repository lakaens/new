#include<iostream>

using namespace std;
void reverse(int* array, int sizeArray);
void printCharPtr(char* myString);
int sizeWord(char* word);
void concat(char* word1, char* word2, char* result);

void absSwap(int* arr1, int sizeArr1, int* arr2, int sizeArr2)
{
	for (int i = 0; i < sizeArr1; i++)
	{
		arr1[i] = abs(arr2[i]);
	}
	cout << "Array1 Array2" << endl;
	for (int i = 0; i < sizeArr1; i++) {
		cout << arr1[i] << " " << arr2[i] << endl;
	}
	free(arr1);
	free(arr2);
}

int main() {
	
	/*
	//EJERCICIO DICTADO
	char* nom = "Hello world of pointers";
	for (int i = 0; nom[i] != '\0'; i++) {
		cout << nom[i] << endl;
	}
	cout << "\n";
	*/
	/*
	//EJERCICIO 2
	int val1, val2;
	cout << "Give me two variables, val1 and val 2 " << endl;
	cin >> val1;
	cin >> val2;
	sum(val1, val2, &result)


	*/

	/*
	//EJERCICIO 3
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};

	reverse(arr, 10);
	*/
	/*
	//EJERCICIO 4

	int* arr1 = (int*)calloc(20, sizeof(int));
	int* arr = (int*)malloc(20 * sizeof(int));
	cout << "Introduce 20 valores tanto positivos como negativos: " << endl;
	for (int i = 0; i < 20; i++)
	{
		cin >> arr[i];
	}
	system("cls");
	absSwap(arr1, 20, arr, 20);
	*/
	//EJERCICIO 5

	char* string = "uno";
	char* string1 = "dos";

	int size = sizeWord(string);
	
	int size1 = sizeWord(string1);
	
	int sizeC = size + size1 + 1;
	
	char* stringC = (char*)malloc(sizeC);

	concat(string, string1, stringC);
	
	printCharPtr(stringC);

	free(stringC);

	
	system("pause");
	return 0;
}


void sum(int val1, int val2, int* result) {
	*result = val1 + val2;
	cout << val1 << " + " << val2<<" = " << *result;
}


void reverse(int* array, int sizeArray) {

	for (int i = sizeArray-1; i >= 0; --i) {
		cout << (*(array+i))<< endl;
	}

}

void printCharPtr(char* myString) {

	cout << myString << endl;
}
int sizeWord(char* word) {
	
	int size = 0;
	for (int i = 0; word[i] != '\0'; i++) {
		size++;
	}
	return size;
	
}

void concat(char* word1, char* word2, char* result) {

	int contadorC = 0;

	for (int i = 0; word1[i] != '\0'; i++) {
		result[contadorC] = word1[i];
		contadorC++;
	}
	for (int i = 0; word2[i] != '\0'; i++) {
		result[contadorC] = word2[i];
		contadorC++;
	}
	result[contadorC] = '\0';


}