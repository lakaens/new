#ifndef CLASES_H
#define CLASES_H

using namespace std;

class Item {
	friend class Player;
private:
	char* name;
public:
	Item(char* name) {
		this->name = name;
	}
	~Item() {}
};

class Player {
private:
	char name[10];
	unsigned short numLifes;
	bool invincible;
	bool* capabilities = new bool[3];
	bool* weapon = new bool[3];
	
public:
	Player(){
		char name[10];
		numLifes = 3;
		invincible = false;
		capabilities[0] = false;
		capabilities[1] = true;
		capabilities[2] = false;
		weapon[0] = false;
		weapon[1] = false;
		weapon[2] = false;
	}
	~Player() {}
	char getName(char name) const {
		return name;
	}
	void PrintNumLifes(int numLifes) {
		cout << "lifes: " << numLifes << endl;
	}
	void PrintInvincible(bool invincible) {
		if (invincible == true) {
			cout << "The Player is invincible" << endl;
		}
		else {
			cout << "The Player is not invincible" << endl;
		}
	}
	void PrintCapabilities(bool capabilities[3]) {
		if (capabilities[0] == true) {
			cout << capabilities[0] << "is set to true" << endl;
		}
		else if (capabilities[1] == true) {
			cout << capabilities[1] << "is set to true" << endl;
		}
		else if (capabilities[2] == true) {
			cout << capabilities[2] << "is set to true" << endl;
		}
	}
	void PrintWeapon(bool weapon[3]) {
		if (weapon[0] == true) {
			cout << weapon[0] << "is set to true" << endl;
		}
		else if (weapon[1] == true) {
			cout << weapon[1] << "is set to true" << endl;
		}
		else if (weapon[2] == true) {
			cout << weapon[2] << "is set to true" << endl;
		}
	}
	bool operator == (const Player& p)const {
			return(name==p.name);
	}
	void useItem(const Item& i) {
		if (i.name == "One_Up") {
			numLifes++;
		}
		else if (i.name=="Mini_Mario") {
			capabilities[0] = true;
			capabilities[1] = false;
			capabilities[2] = false;
		}
		else if (i.name == "Super_Mario") {
			capabilities[0] = false;
			capabilities[1] = false;
			capabilities[2] = true;
		}
		else if (i.name == "Fire_Flower") {
			weapon[0] = true;
			weapon[1] = false;
			weapon[2] = false;
		}
		else if (i.name == "Ice_Flower") {
			weapon[0] = false;
			weapon[1] = true;
			weapon[2] = false;
		}
		else if (i.name == "Golden_Flower") {
			weapon[0] = false;
			weapon[1] = false;
			weapon[2] = true;
		}
	}
};
#endif // !CLASES_H
