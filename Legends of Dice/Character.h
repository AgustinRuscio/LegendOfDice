#pragma once
#include <iostream>
using namespace std;
#define PRINT(x) cout<< x <<endl;
#define PRINT_COMPLEX(x, tx) cout<< x <<tx <<endl;

enum Race
{
	Human, Elf, Dwarf, Orc
};

struct Stats
{
	int Strenght;
	int Agility;
	int Intelligence;

	void SetRace(Race race)
	{
		SetStrenght(race);
		SetAgility(race);
		SetIntelligence(race);
	}

	void SetStrenght(Race race)
	{
		switch (race)
		{
		case Race::Human:
			Strenght = 4;
			break;

		case Race::Elf:
			Strenght = 2;
			break;

		case Race::Dwarf:
			Strenght = 5;
			break;

		case Race::Orc:
			Strenght = 6;
			break;
		}
	}

	void SetAgility(Race race)
	{
		switch (race)
		{
		case Race::Human:
			Agility = 3;
			break;

		case Race::Elf:
			Agility = 4;
			break;

		case Race::Dwarf:
		case Race::Orc:
			Agility = 2;
			break;
		}
	}

	void SetIntelligence(Race race)
	{
		switch (race)
		{
		case Race::Human:
		case Race::Dwarf:
			Intelligence = 3;
			break;

		case Race::Elf:
			Intelligence = 4;
			break;

		case Race::Orc:
			Intelligence = 2;
			break;
		}
	}

	int GetStrenght() const
	{
		return Strenght;
	}

	int GetAgility() const
	{	 
		return Agility;
	}

	int GetIntelligence() const
	{
		return Intelligence;
	}
};


class Character
{
protected:
	float health;
	float mana;
	float initialMana;

	Race race;
	Stats stats;

	float damage;
	float avgDamage = 0;

	int defeatEnemies = 0;

	const float  NORMAL_ATTACK_COST = 10;
	const float  POWERED_ATTACK_COST = 30;
	const float  SUPER_ATTACK_COST = 50;

public:
	Character();
	virtual ~Character();

	//Pure virtual methods
	virtual void SetDamage() = 0;
	virtual void SetMana() = 0;
	virtual void SetHealth() = 0;
	virtual void SeTAllStats(Race myRace) = 0;

	//---General class methods
	float RandomRange(int min, int max) const;
	void PrintStadistics() const;

	void SetRace(Race myRace);

	void TakeDamage(float damage);

	void AddDefeatEnemy();
	int GetDefeatsEnemies();
	float GetAverageDamage();

	float GetLife() const;
	float GetMana() const;

		//Action methods
	void NormalAttack(Character* otherCharacter);
	void PoweredAttack(Character* otherCharacter);
	void SuperAttack(Character* otherCharacter);
	void Rest();
	void OnWin();

};