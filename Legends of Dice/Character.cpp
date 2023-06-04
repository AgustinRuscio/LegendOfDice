#include "Character.h"

Character::Character()
{
	PRINT("Character()");
}

Character::~Character()
{
	PRINT("~Character()");
}

void Character::SetRace(Race myRace)
{
	race = myRace;

	stats.SetRace(race);
}

float Character::RandomRange(int min, int max) const
{
	srand(time(0));

	return min + rand() % (max - min +1);
}

void Character::TakeDamage(float damage)
{
	health -= damage;

	if (health < 0)
		health = 0;
}

void Character::PrintStadistics() const
{
	PRINT_COMPLEX("Health: ", health);
	PRINT_COMPLEX("Mana: ", mana);
	PRINT_COMPLEX("Damage: ", damage);

	switch (race)
	{
	case Race::Human:
		PRINT("Race: human");
		break;

	case Race::Elf:
		PRINT("Race: elf");
		break;

	case Race::Dwarf:
		PRINT("Race: dwarf");
		break;

	case Race::Orc:
		PRINT("Race: orc");
		break;
	}
}

void Character::AddDefeatEnemy()
{
	defeatEnemies++;
}

int Character::GetDefeatsEnemies()
{
	return defeatEnemies;
}

float Character::GetAverageDamage()
{
	return avgDamage;
}

float Character::GetLife() const
{
	return health;
}

float Character::GetMana() const
{
	return mana;
}


void Character::NormalAttack(Character* otherCharacter)
{
	float localMana = mana - NORMAL_ATTACK_COST;

	if (localMana > 0)
	{
		mana -= NORMAL_ATTACK_COST;
		float localDamage = damage + RandomRange(1, 6);

		otherCharacter->TakeDamage(localDamage);
		avgDamage += localDamage;

		PRINT("Normal attack");
		PRINT_COMPLEX("Damage caused: ", localDamage);
	}
	else
	{
		PRINT("Fail to attack, reload mana");
	}
}

void Character::PoweredAttack(Character* otherCharacter)
{
	float localMana = mana - POWERED_ATTACK_COST;

	if (localMana > 0)
	{
		mana -= POWERED_ATTACK_COST;
		float localDamage = damage * 1.5f + RandomRange(1, 6);

		otherCharacter->TakeDamage(localDamage);
		avgDamage += localDamage;

		PRINT("Powered attack!!");
		PRINT_COMPLEX("Damage caused: ", localDamage);
	}
	else
	{
		PRINT("Fail to attack, reload mana");
	}
}

void Character::SuperAttack(Character* otherCharacter)
{
	float localMana = mana - SUPER_ATTACK_COST;

	if (localMana > 0)
	{
		mana -= POWERED_ATTACK_COST;
		float localDamage = damage * 2 + RandomRange(1, 6);

		otherCharacter->TakeDamage(localDamage);
		avgDamage += localDamage;

		PRINT("Super attack!!");
		PRINT_COMPLEX("Damage caused: ", localDamage);
	}
	else
	{
		PRINT("Fail to attack, reload mana");
	}
}

void Character::Rest()
{
	PRINT("Resting.....");
	PRINT("Mana + 10");
	PRINT_COMPLEX("Current mana: ", mana);
	mana += 10;
}

void Character::OnWin()
{
	health += 40;
	mana = initialMana;
}
