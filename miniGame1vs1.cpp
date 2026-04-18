#include <iostream>
#include <string>
using namespace std;

class Defend {

};

class Creature {
private:
	string name;
	double HP;
	double damage;
	bool dead;

public:
	Creature(string name_unit, double HP_unit, double damage_unit) {
		name = name_unit;
		HP = HP_unit;
		damage = damage_unit;
		if (HP > 0)
			dead = false;
		else
			dead = true;
	}

	bool isLife() {
		return !dead;
	}

	void getDamage(int dmg) {
		HP -= dmg;

		if (HP > 0) {
			cout << "Персонаж " << name << " получил " << dmg << " урона." << endl << "Осталось " << HP << " здоровья." << endl;
		}
		else {
			HP = 0;
			cout << "Персонаж " << name << " умер." << endl;
			dead = true;
		}
	}

	void attack(Creature& unit) {
		unit.getDamage(damage);
	}
};

// ДЗ допилить игру в команде

int main() {
	setlocale(LC_ALL, "ru");

	Creature unit1("Dvorf", 100, 5);
	Creature unit2("Elf", 100, 10);

	int rounds = 10;
	bool who_fight = true;
	while (unit1.isLife() && unit2.isLife())
	{
		if (who_fight) {
			unit1.attack(unit2);
		}
		else {
			unit2.attack(unit1);
		}
		who_fight = !who_fight;
	}

	return 0;
}