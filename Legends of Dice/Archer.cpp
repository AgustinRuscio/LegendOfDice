#include "Archer.h"

Archer::Archer()
{
	PRINT("Archer()");
}

Archer::Archer(Race myRace) : Archer()
{
	SetRace(myRace);

	SetDamage();
	SetHealth();
	SetMana();
}

Archer::~Archer()
{
	PRINT("~Archer()");
}


void Archer::SetDamage()
{
	damage = BASE_ARCHER_DAMAGE + 1.5f * stats.GetStrenght() + 1.2f * stats.GetAgility();
}

void Archer::SetHealth()
{
	health = BASE_ARCHER_LIFE + 2 * stats.GetStrenght();
}

void Archer::SetMana()
{
	mana = BASE_ARCHER_MANA + 1.5f * stats.GetIntelligence();
	initialMana = mana;
}

void Archer::SeTAllStats(Race myRace)
{
	SetRace(myRace);

	SetDamage();
	SetHealth();
	SetMana();
	

}
