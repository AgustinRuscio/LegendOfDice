#pragma once
#include "Character.h"

class Archer : public Character
{
private:
	const float BASE_ARCHER_LIFE = 100;
	const float BASE_ARCHER_MANA = 150;
	const float BASE_ARCHER_DAMAGE = 50;

public:
	Archer();
	Archer(Race race);
	~Archer();
	

	void SetDamage() override;
	void SetHealth() override;
	void SetMana() override;

	void SeTAllStats(Race myRace) override;
};