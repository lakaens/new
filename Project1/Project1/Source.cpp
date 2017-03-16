#include<iostream>

void doubleNum(int &num);

typedef struct pirate {
	char name[10] = { 'l','e','C','h','u','c','k' };
	int life = 100;
};

typedef struct weapon {
	char name[10] = { 'S','w','o','r','d' };
	int damage = 10;
};
void printpirateinfo(const pirate& p);
void printweaponinfo(const weapon& w);
void attack(const pirate& p,const weapon& w);

using namespace std;


int main() {
	/*
	//EJERCICIO 1
	int num = 0;

	cout << "Give me a number between 0 to 100: ";
	cin >> num;
	cout << endl;
	doubleNum(num);
	cout << "Your number * 2 is: " << num << endl;
	*/

	//EJERCICIO 3
	
	struct pirate p;
	struct weapon w;

	printpirateinfo(p);
	
	printweaponinfo(w);
	
	attack(p, w);
	


	system("pause");
	return 0;
}



void doubleNum(int &num) 
{
	
	num *= 2;
}


void printpirateinfo(const pirate& p) 
{
	cout << "-- Pirate --" << endl;
	cout << "name = "<<p.name << endl;
	cout << "life units = " << p.life << endl;
	cout << endl;
}


void printweaponinfo(const weapon& w)
{
	cout << "-- Weapon --" << endl;
	cout <<"name = "<<w.name << endl;
	cout <<"damage units = "<<w.damage << endl;
	cout << endl;
}

void attack(const pirate& p, const weapon& w) {

	cout << "-- Pirate --" << endl;
	cout << "name = " << p.name << endl;
	cout << "life units = " << p.life - w.damage << endl;
	cout << endl;
}