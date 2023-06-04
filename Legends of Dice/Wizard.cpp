#include "Wizard.h"


Wizard::Wizard()
{
	PRINT("Wizard()");
}

Wizard::Wizard(Race myRace) : Wizard()
{
	SetRace(myRace);

	SetDamage();
	SetHealth();
	SetMana();
}

Wizard::~Wizard()
{
	PRINT("~Wizard()");
}


void Wizard::SetDamage()
{
	damage = BASE_WIZARD_DAMAGE + 1.5f * stats.GetStrenght() + 1.2f * stats.GetAgility();
}

void Wizard::SetHealth()
{
	health = BASE_WIZARD_LIFE + 2 * stats.GetStrenght();
}

void Wizard::SetMana()
{
	mana = BASE_WIZARD_MANA + 1.5f * stats.GetIntelligence();
	initialMana = mana;
}

void Wizard::SeTAllStats(Race myRace)
{
	SetRace(myRace);

	SetDamage();
	SetHealth();
	SetMana();
}
