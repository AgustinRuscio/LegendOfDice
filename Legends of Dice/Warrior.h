#pragma once
#include "Character.h"

class Warrior : public Character
{
private:
	const float BASE_WARRIOR_LIFE = 200;
	const float BASE_WARRIOR_MANA = 100;
	const float BASE_WARRIOR_DAMAGE = 25;

public:
	Warrior();
	Warrior(Race race);
	~Warrior();

	void SetDamage() override;
	void SetHealth() override;
	void SetMana() override;
	void SeTAllStats(Race myRace) override;
};

