#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <cmath>
#include "Header.h"

// BOSSES SHOULD SPAWN AT KILL 6 AND KILL 15

// BOSS ARRAY


int* Boss1(int* ptrPProfile, float* ptrUpgrades, std::string* ptrPDetails)
{
	int bossOne[3] = { 80, 10, 25 }; // [0] HEALTH, [1] MIN DAMAGE, [2] MAX DAMAGE!
	int* ptrBossOne = bossOne;

	std::string healChoice;
	bool choiceValid = false;
	int attackChoice;
	bool fight = true;
	bool attackChoiceValid = false;
	bool failDodge = false;
	bool dodge = false;
	bool heal = false;

	std::string pause = "";

	Type("\n\n\n=#=#=#=#= BOSS-ENCOUNTER =#=#=#=#=\n\nYou encountered the ancient dragon named '[insert dragon name]'!\n\nYou are on ", 30);
	std::cout << ptrPProfile[0];
	Type(" health, do you want to heal one last time before the fight?\nYou are on ", 30);
	std::cout << ptrPProfile[7];
	Type(" health potions!\n\nChoice (Yes Or No): ", 30);
	std::cin >> healChoice;
	healChoice = Lowercase(healChoice);
	while (!(choiceValid))
	{
		if (healChoice == "yes")
		{
			Heal(ptrPProfile);
			choiceValid = true;
		}
		else if (healChoice == "no")
		{
			Type("\n\nYou chose not to heal!", 30);
			choiceValid = true;
		}
		else if (!(healChoice == "yes") && !(healChoice == "no"))
		{
			Type("\n=!=!= ERROR =!=!=\n\nChoice invalid! Re-enter a correct choice: ", 30);
			std::cin >> healChoice;
			healChoice = Lowercase(healChoice);
		}
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
	Type("\n\nAre you ready for the fight? (Press any letter and then press enter!) ", 30);
	std::cin >> pause;
	pause = "";

/*============================================================ FIGHT START ============================================================*/

	// FIRST ATTACK
	std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
	std::cout << "\n\n";
	Type("=-=-=-=-=-=-=-=-FIGHT=INITIATED-=-=-=-=-=-=-=-=\n\n\nYou go first! ", 15);
	Type("Would you like to: \n\n#1: Attack!\n#2: Dodge and heal!\n\nChoice: ", 50);
	std::cin >> attackChoice;
	// FIRST ATTACK END

	while (fight = true) // FIGHT OVER?
	{
		failDodge = false;
		dodge = false;

		while (attackChoiceValid == false) // CHOICE IS VALID?
		{
			// ATTACKING CHOICE
			if (attackChoice == 1)
			{
				ptrBossOne = PlayerAttackBoss(ptrPProfile, ptrBossOne, ptrPDetails, ptrUpgrades);
				attackChoice = 0;
				attackChoiceValid = true;
				break;
			}

			// BLOCKING CHOICE
			else if (attackChoice == 2)
			{
				dodge = DodgeChance(ptrPProfile, dodge);
				Type("\nYou will try and dodge the next attack from [insert dragon name]!", 60);
				std::cout << "\n\n";
				if (dodge == false)
				{
					failDodge = true;
				}
				else if (dodge == true)
				{
					failDodge = false;
				}
				attackChoice = 0;
				attackChoiceValid = true;
			}

			// INVALID OPTIONS
			else if (attackChoice < 1)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
				Type("Attack choice invalid!\n\nRe - enter a correct choice : ", 60);
				std::cin >> attackChoice;
			}
			else if (attackChoice > 2)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
				Type("\n=!=!= ERROR =!=!=\n\nAttack choice invalid! Re-enter a correct choice: ", 40);
				std::cin >> attackChoice;
			}
			// INVALID OPTIONS OVER
		}

		attackChoiceValid = false;
		// START BOSS ATTACK HERE!
		// VVVVV

		if (ptrBossOne[0] <= 0) // IF BOSS IS KILLED
		{
			Type("You killed [insert dragon name]!", 30);
			ptrPProfile = BossRewards(ptrPProfile);
			Type("\n\nYou walk up to the body of the dragon you have just slain...\n", 40);
			std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
			Type("You touch the it and are suddenly jolted into the air!\nYou panic and wonder what is happening!\n\nYou feel a rush through your body and you start to feel stronger!\n\nYour max health has been raised by 50!\nYou have also been fully healed to your new max health!\n\nYour current health is ", 40);
			ptrPProfile[8] = ptrPProfile[8] + 50;
			ptrPProfile[0] = ptrPProfile[8];
			std::cout << ptrPProfile[0];
			Type("!", 40);
			std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
			Type("\n\nYou have killed your first boss!\n\nGood job!", 30);
			ptrPProfile[12] = ptrPProfile[12] + 1;
			fight = false;

			ptrPProfile = Shop(ptrPProfile);

			return ptrPProfile;
		}

		else if (ptrBossOne[0] > 0)
		{
			ptrPProfile = BossOneAttack(ptrPProfile, ptrBossOne, ptrUpgrades, dodge, failDodge);
		}

		if (ptrPProfile[0] <= 0) // IF PLAYER HEALTH IS LESS THAN OR EQUAL TO 0
		{
			fight = false; // FIGHT OVER
			std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
			Type("\n\n\n\nYou are dead! You killed ", 120);
			std::this_thread::sleep_for(std::chrono::milliseconds(120)); // WAIT
			std::cout << ptrPProfile[5];
			std::this_thread::sleep_for(std::chrono::milliseconds(120)); // WAIT
			Type(" enemies!", 100); // DISPLAYS HOW MANY ENEMIES YOU KILLED
			std::cin.get();
			exit(0);
		}
		
		std::cout << "\n\n\n";
		Type("It is your turn to attack again! What would you like to do?\n\n#1: Attack!\n#2: Dodge and heal!", 50);
		std::cout << "\n\n";
		Type("You have ", 60);
		std::cout << ptrPProfile[7];
		Type(" health potions left!\n\nChoice: ", 60);
		std::cin >> attackChoice;
	}
	return ptrPProfile;
}



// ATTACKS BELOW VVVVV



int* PlayerAttackBoss(int* ptrPProfile, int* ptrBossOne,std::string* ptrPDetails, float* ptrUpgrades)
{
	int* ptrDaggers;
	int* ptrWand;

	int pDamage;
	float tempDamage;

	pDamage = rand() % (ptrPProfile[2] - ptrPProfile[1] - 1) + ptrPProfile[1]; // RANDOM NUMBER BETWEEN PLAYERS DAMAGEMAX AND DAMAGEMIN
	if (ptrPDetails[1] == "daggers") // INITIATE DAGGER SPECIFICS FROM WEAPONSPECIFICS
	{
		ptrDaggers = Daggers();
		std::cout << "\n\n";
		Type("You attacked ", 60);
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
		std::cout << ptrDaggers[1];
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
		Type(" times!", 60);
		std::cout << "\n";
		Type("You dealt ", 60);
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT

		tempDamage = ptrDaggers[0] * ptrUpgrades[0];
		pDamage = round(tempDamage);
		std::cout << pDamage;

		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
		Type(" damage!", 60);

		ptrBossOne[0] = ptrBossOne[0] - pDamage; // BOSS HEALTH - pDamage

		std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
		std::cout << "\n\n";
		Type("The enemy [insert dragon name] is on ", 60);
		std::cout << ptrBossOne[0];
		Type(" health!\n\n", 60);

		return ptrBossOne;
	}
	else if (ptrPDetails[1] == "wand") // INITIATE WAND SPECIFICS FROM WEAPONSPECIFICS
	{
		ptrWand = Wand();
		std::cout << "\n\n";
		Type("You attacked ", 60);
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
		std::cout << ptrWand[1];
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
		Type(" times!\n", 60);
		Type("You dealt ", 60);
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT


		tempDamage = ptrWand[0] * ptrUpgrades[0];
		pDamage = round(tempDamage);
		std::cout << pDamage;

		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
		Type(" damage!", 60);

		ptrBossOne[0] = ptrBossOne[0] - pDamage; // BOSS HEALTH - pDamage

		std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
		std::cout << "\n\n";
		Type("The enemy [insert dragon name] is on ", 60);
		std::cout << ptrBossOne[0];
		Type(" health!\n\n", 60);

		return ptrBossOne;
	}

	else
	{
		std::cout << "\n\n";
		Type("Your attack did ", 60);
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT

		tempDamage = pDamage * ptrUpgrades[0];
		pDamage = round(tempDamage);
		std::cout << pDamage;

		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
		Type(" damage!", 60);

		ptrBossOne[0] = ptrBossOne[0] - pDamage; // BOSS HEALTH - pDamage

		std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
		std::cout << "\n\n";
		Type("The enemy [insert dragon name] is on ", 60);
		std::this_thread::sleep_for(std::chrono::milliseconds(200)); // WAIT
		std::cout << ptrBossOne[0];
		Type(" health!\n\n", 60);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		std::cout << "\n";

		return ptrBossOne;
	}
}

int* BossOneAttack(int* ptrPProfile, int* ptrBossOne, float* ptrUpgrades, bool dodge, bool failDodge)
{
	float tempEDamage;
	int eDamage;

	std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
	std::cout << "\n";
	Type("The enemy [insert dragon name] is now attacking!", 70);
	eDamage = rand() % (ptrBossOne[2] - ptrBossOne[1] + 1) + ptrBossOne[1]; // RANDOM NUMBER BETWEEN ENEMIES DAMAGEMIN AND DAMAGEMAX
	std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT

	//CHECKS IF USER CHOSE DODGE
	if (dodge == true) // USER CHOSE DODGE
	{
		Type("\n\nYou succesfully dodged the attack!", 50);
		Heal(ptrPProfile);
		dodge = false;

		return ptrPProfile;
	}
	else if (failDodge == true)
	{
		Type("\n\nYou failed to dodge the attack! You were attacked for ", 50);
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT

		tempEDamage = eDamage * ptrUpgrades[1]; //
		eDamage = round(tempEDamage); // 
		std::cout << eDamage; //

		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
		Type(" damage!", 60);
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
		ptrPProfile[0] = ptrPProfile[0] - eDamage; // PLAYER HEALTH - ENEMY DAMAGE
		std::cout << "\n\n";
		Type("You are now on ", 60);
		std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
		std::cout << ptrPProfile[0];
		Type(" health!", 60); // DISPLAYS CURRENT HEALTH
		failDodge = false;

		return ptrPProfile;
	}
	else if (dodge == false) // USER DID NOT CHOOSE DODGE
	{
		std::cout << "\n\n";
		Type("You were attacked for ", 60);
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT

		tempEDamage = eDamage * ptrUpgrades[1]; //
		eDamage = round(tempEDamage); // 
		std::cout << eDamage; //

		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
		Type(" damage!", 60);
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
		ptrPProfile[0] = ptrPProfile[0] - eDamage; // PLAYER HEALTH - ENEMY DAMAGE
		std::cout << "\n\n";
		Type("You are now on ", 60);
		std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
		std::cout << ptrPProfile[0];
		Type(" health!", 60); // DISPLAYS CURRENT HEALTH

		return ptrPProfile;
	}
}