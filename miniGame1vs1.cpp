#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Armor {
private:
	string name_armor;
	double val_armor;

public:
	// функция возврата получения урона с учетом брони
	double getDamageArmor(int damage) {
		return damage / val_armor;
	}

	string getName() {
		return name_armor;
	}

	// установить значение назнания брони и ее защиты при ее смене
	void setValue(string new_name_armor, double new_value_armor) {
		name_armor = new_name_armor;
		val_armor = new_value_armor;
	}

	double getValArmor() {
		return val_armor;
	}
};

class Weapon {
private:
	string name_weapon;
	double val_attack;

public:
	// функция возврата атаки с учетом оружия
	double getDamageAttack() {
		return val_attack;
	}

	string getName() {
		return name_weapon;
	}

	// установить значение назнания оружия и его атаки при его смене
	void setValue(string new_name_weapon, double new_value_weapon) {
		name_weapon = new_name_weapon;
		val_attack = new_value_weapon;
	}
};

class Creature {
private:
	// имя героя
	string name;

	// основные характеристики
	double HP_max;
	double HP;
	double damage;
	bool dead;

	// оружие и броня
	Weapon weapon;
	Armor armor;

	// количество монет
	double money;

public:
	Creature(string name_unit, double HP_unit, double damage_unit, 
		string start_weapon, double value_attack_weapon,
		string start_armor, double value_def_armor) {

		name = name_unit;
		HP = HP_unit;
		HP_max = HP_unit;
		damage = damage_unit;

		if (HP > 0)
			dead = false;
		else
			dead = true;

		weapon.setValue(start_weapon, value_attack_weapon);
		armor.setValue(start_armor, value_def_armor);
	}

	// жив ли персонаж?
	bool isLife() {
		return !dead;
	}

	// получение урона
	void getDamage(int dmg) {
		HP -= armor.getDamageArmor(dmg);

		if (HP > 0) {
			cout << "Персонаж " << name << " получил " << dmg << " урона." << endl << "Осталось " << HP << " здоровья." << endl;
		}
		else {
			HP = 0;
			cout << "Персонаж " << name << " умер." << endl;
			dead = true;
		}
	}

	// атака другого существа
	void attack(Creature& unit) {
		unit.getDamage(damage + weapon.getDamageAttack());
	}

	// замена оружия
	void equipWeapon(string name_new_weapons, double new_val_att_weapons) {
		weapon.setValue(name_new_weapons, new_val_att_weapons);
	}

	// замена брони
	void equipArmor(string name_new_armor, double new_val_def_weapons) {
		weapon.setValue(name_new_armor, new_val_def_weapons);
	}

	// функции для сохранения персонажа
	// сохранение основных параметров
	vector<double> saveParameters() {
		vector<double> result;
		result.reserve(4);

		result.push_back(HP);
		result.push_back(HP_max);
		result.push_back(damage);
		result.push_back(money);
	}

	// сохранение оружия
	void saveInfoWeapon(string& name_weapon, double& val_attack) {
		name_weapon = weapon.getName();
		val_attack = weapon.getDamageAttack();
	}

	// сохранение брони
	void saveInfoArmor(string& name_armor, double& val_armor) {
		name_armor = armor.getName();
		val_armor = armor.getValArmor();
	}

	
};

ofstream operator << (ofstream& fin, Creature& player) {
	for (double parametr : player.saveParameters())
		fin << parametr << ' ';

	// переменные для сохранения
	string t_name;
	double t_val;

	// сохранение оружия
	player.saveInfoWeapon(t_name, t_val);
	fin << t_name << ' ' << t_name;

	// сохранение оружия
	player.saveInfoArmor(t_name, t_val);
	fin << t_name << ' ' << t_name;
}

ifstream operator >> (ifstream& fin, Creature& player) {
	;
}

void saveGame(Creature& player, int& round) {
	ofstream fin_save("save_game.txt");

	fin_save << player;

	fin_save << round << ' ';

	fin_save.close();
}

void loadGame(Creature& player, int& round) {
	ifstream fin_load;

	fin_load >> player;
}

// ДЗ допилить игру в команде

int main() {
	setlocale(LC_ALL, "ru");
	
	// объект класса игрока
	Creature player("Player", 100, 5, "Меч", 10, "Латы", 3);
	// количество раундов
	int round = 1;
	int final_round = 100;

	bool who_fight = true;
	while (round < final_round) {
		// действие: бой, сохраниение и т. д.
		char action;
		cin >> action;
		while (action != 'S' && action != 'B') {
		
		}
		switch (action)
		{
		case 'B':
			while (round < final_round && player.isLife())
				{
				// система боя. нужно реализовать

					who_fight = !who_fight;
				}
			round++;

			break;

		case 'S':
			saveGame(player, round);

		default:
			break;
		}
		

		if (action == 'S');

		
		
	}

	return 0;
}