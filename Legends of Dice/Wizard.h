#pragma once
#include "Character.h"

class Wizard : public Character
{
private:
	const float BASE_WIZARD_LIFE = 150;
	const float BASE_WIZARD_MANA = 200;
	const float BASE_WIZARD_DAMAGE = 15;

public:
	Wizard();
	Wizard(Race race);
	~Wizard();


	//Parent mehotds
	void SetDamage() override;
	void SetHealth() override;
	void SetMana() override;
	void SeTAllStats(Race myRace) override;
};