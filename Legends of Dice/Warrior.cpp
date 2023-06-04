#include "Warrior.h"

Warrior::Warrior()
{
	PRINT("Warrior()");
}

Warrior::Warrior(Race myRace) : Warrior()
{
	SetRace(myRace);

	SetDamage();
	SetHealth();
	SetMana();
}

Warrior::~Warrior()
{
	PRINT("~Warrior()");
}

void Warrior::SetDamage()
{
	damage = BASE_WARRIOR_DAMAGE + 1.5f * stats.GetStrenght() + 1.2f * stats.GetAgility();
}

void Warrior::SetHealth()
{
	health = BASE_WARRIOR_LIFE + 2 * stats.GetStrenght();
}

void Warrior::SetMana()
{
	mana = BASE_WARRIOR_MANA + 1.5f * stats.GetIntelligence();
	initialMana = mana;
}

void Warrior::SeTAllStats(Race myRace)
{
	SetRace(myRace);

	SetDamage();
	SetHealth();
	SetMana();
}
