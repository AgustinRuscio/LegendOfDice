#include <iostream>
#include "Character.h"
#include "Archer.h"
#include "Warrior.h"
#include "Wizard.h"

#define PRINT(x) cout<< x <<endl;
#define PRINT_COMPLEX(x, tx) cout<< x <<tx <<endl;

using namespace std;

int RandomRange(int min, int max);


struct CharacterVector
{
	Character* oponet;

	CharacterVector(int randNum, int rundNum2)
	{
		oponet = SetClass(SetRace(rundNum2), randNum);
	}

	void EnemyStadistics(int i)
	{
		oponet->PrintStadistics();
	}

	Character* SetClass(Race race, int randNum)
	{
		switch (randNum)
		{
		case 0:
			return new Warrior(race);

		case 1:
			return new Wizard(race);

		case 2:
			return new Archer(race);
		}
		
	}

	Race SetRace(int randNum)
	{
		switch (randNum)
		{
		case 0:
			return (Race::Human);

		case 1:
			return (Race::Dwarf);

		case 2:
			return (Race::Elf);

		case 3:
			return (Race::Orc);
		}
		
	}

	Character* GiveOponet()
	{
		return oponet;
	}

	~CharacterVector()
	{
		PRINT("~CharacterVector()");

		if(oponet != nullptr)
		{
			oponet = nullptr;
			delete oponet; 
		}
	}
};

int main()
{
	Race mainRace;
	Character* mainCharacter = nullptr;

	//-------------------------Character Personalization

	while (mainCharacter == nullptr)
	{
		cout << endl;
		PRINT("Your Adventure begin. You must defeat as many enemies as you can.");
		PRINT("If you defeat all of them you will became the MMORPG master.");
		PRINT("Now select you Class...");
		PRINT("Enter number 1 -> if you want to be a warrior. Base Life: 200, Base mana: 100, Base damage: 25");
		PRINT("Enter number 2 -> if you want to be a wizard. Base Life: 150, Base mana: 200, Base damage: 15");
		PRINT("Enter number 3 -> if you want to be a archer. Base Life: 100, Base mana: 150, Base damage: 50");

		unsigned int classAnswer;
		cin >> classAnswer;


		switch (classAnswer)
		{
		case 1:
			mainCharacter = new Warrior();
			break;

		case 2:
			mainCharacter = new Wizard();
			break;

		case 3:
			mainCharacter = new Archer();
			break;
			
		default:
			PRINT("Please enter a valid option");
			continue;
		}
	}

	int selection = 0;
	while (selection == 0)
	{
		PRINT("So that will be!");
		PRINT("Now select your race...");
		PRINT("Enter number 1 -> if you want to be a Human. Strenght = 4; Agility = 3; Intelligence = 3");
		PRINT("Enter number 2 -> if you want to be a Elf. Strenght = 2; Agility = 4; Intelligence = 4");
		PRINT("Enter number 3 -> if you want to be a Drawrf. Strenght = 5; Agility = 2; Intelligence = 3");
		PRINT("Enter number 4 -> if you want to be an Orc. Strenght = 6; Agility = 2; Intelligence = 2");

		unsigned int raceAnswer;
		cin >> raceAnswer;


		switch (raceAnswer)
		{
		case 1:
			mainCharacter->SeTAllStats(Race::Human);
			selection++;
			break;

		case 2:
			mainCharacter->SeTAllStats(Race::Elf);
			selection++;
			break;

		case 3:
			mainCharacter->SeTAllStats(Race::Dwarf);
			selection++;
			break;

		case 4:
			mainCharacter->SeTAllStats(Race::Orc);
			selection++;
			break;

		default:
			PRINT("Please enter a valid option");
			continue;
		}

	}

	PRINT("Theese are your stats then:");
	mainCharacter->PrintStadistics();

	PRINT("Great!! Now your journey begins. Be brave and kill them all");


	//-------------------------------Game loop

	bool isAlive = true;

	Character* last = nullptr;

	CharacterVector* enemyVector = nullptr;

	while (isAlive || mainCharacter->GetDefeatsEnemies() < 10)
	{
		if(mainCharacter->GetDefeatsEnemies() >= 10 || !isAlive) break;

		cout << endl;
		PRINT("An enemy appeard");
		PRINT("Fight!!!");

		enemyVector = new CharacterVector(RandomRange(0,2), RandomRange(0,3));
		last = enemyVector->GiveOponet();

		PRINT("Enemy stats: ");
		last->PrintStadistics();
		cout << endl;

		while (mainCharacter->GetLife() > 0 || last->GetLife() > 0)
		{
			if (mainCharacter->GetLife() > 0)
			{
				PRINT("What will you do now?");
				PRINT("1. Normal attack. Mana cost = 10, Damage is normal");
				PRINT("2. Powered attack. Mana cost = 30, Damage is multiply by 1.5");
				PRINT("3. Super attack. Mana cost = 50, Damage is double");
				PRINT("4. Rest. Mana + 10");
				PRINT("5. Show stats");


				unsigned int action1;
				cin >> action1;

				cout << endl;
				switch (action1)
				{
					case 1:
						mainCharacter->NormalAttack(last);
						PRINT_COMPLEX("Current enemy life: ", last->GetLife());
						PRINT_COMPLEX("Your current mana amout is: ", mainCharacter->GetMana());
						break;

					case 2:
						mainCharacter->PoweredAttack(last);
						PRINT_COMPLEX("Current enemy life: ", last->GetLife());
						PRINT_COMPLEX("Your current mana amout is: ", mainCharacter->GetMana());
						break;

					case 3:
						mainCharacter->SuperAttack(last);
						PRINT_COMPLEX("Current enemy life: ", last->GetLife());
						PRINT_COMPLEX("Your current mana amout is: ", mainCharacter->GetMana());
						break;

					case 4:
						mainCharacter->Rest();
						break;

				case 5:
					mainCharacter->PrintStadistics();
					continue;

					default:
							continue;
				}
			}
			else
			{
				isAlive = false;
				break;
			}

			if(last->GetLife() > 0)
			{
				cout << endl;

				PRINT("Emeny turn");

				int randNum = RandomRange(0, 3);

				switch (randNum)
				{
					case 0:
						last->NormalAttack(mainCharacter);
						PRINT_COMPLEX("Your current life: ", mainCharacter->GetLife());
						break;

					case 1:
						last->PoweredAttack(mainCharacter);
						PRINT_COMPLEX("Your current life: ", mainCharacter->GetLife());
						break;

					case 2:
						last->SuperAttack(mainCharacter);
						PRINT_COMPLEX("Your current life: ", mainCharacter->GetLife());
						break;

					case 3:
						last->Rest();
						break;
				}
				cout << endl;

			}
			else
			{
				cout<<endl;

				mainCharacter->AddDefeatEnemy();
				mainCharacter->OnWin();

				PRINT("Enemy defeat!");
				PRINT_COMPLEX("Enemies defeat: ", mainCharacter->GetDefeatsEnemies());

				PRINT("Mana restored and life + 40");
				PRINT_COMPLEX("Current life : ", mainCharacter->GetLife());
				PRINT_COMPLEX("Current mana : ", mainCharacter->GetMana());

				cout << endl;
				break;
			}
		}
	}

	if(mainCharacter->GetLife()<=0)
	{
		PRINT("You die. Sad ending");
		PRINT_COMPLEX("Defeated Enemies: ", mainCharacter->GetDefeatsEnemies());
		cout << endl;

		PRINT("Last enemy stats: ");

		last->PrintStadistics();
		
		cout << endl;

		PRINT_COMPLEX("Average damage: ", mainCharacter->GetAverageDamage());

		PRINT("Try again");
	}

	if(mainCharacter->GetDefeatsEnemies() >= 10)
	{
		PRINT("You defeat all enemies!");
		PRINT_COMPLEX("Your average damage was: ", mainCharacter->GetAverageDamage());

		PRINT("You stats");
		mainCharacter->PrintStadistics();

		PRINT("Great job!");
	}
	
	delete mainCharacter;
	delete last;
	delete enemyVector;

	unsigned int end;
	cin >> end;

	return 0;	
}


int RandomRange(int min, int max)
{
	srand(time(0));

	return min + rand() % (max - min + 1);
}
