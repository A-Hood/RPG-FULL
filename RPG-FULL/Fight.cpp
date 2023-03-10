#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <cmath>
#include "Header.h"

int Fight(int* ptrPProfile, std::string* ptrPDetails, std::string enemyName, int enemySpawnType)
{
	// these dont exist shhhhhhh...
	float* ptrUpgrades;
	bool firstAttack = true;
	bool fight = true;
	bool pDead, eDead = false;
	bool valid = false;
	bool dodge = false;
	int pDamage, eDamage;
	int attackChoice;
	int speed;
	bool failDodge = false;
	bool heal = false;
	std::string healChoice;
	std::string pause;
	float tempDamage;
	// end of the mess shhhhhh...
	
	int* ptrDaggers;
	int* ptrWand;

	srand(time(NULL)); // SEEDING RANDOM NUM GENERATOR

	int* ptrEProfile;
	enemySpawnType = rand() % (3 - 1 + 1) + 1; // DECLARING RANDOM NUM FROM 1 TO 3 FOR ENEMY SPAWN TYPE	

	ptrEProfile = EnemyProfile(enemySpawnType); // PTR TO enemyProfile ARRAY
	ptrUpgrades = UpgradeCheck(ptrPProfile);

	enemyName = EnemyName(ptrEProfile, enemyName); // GETS ENEMY NAME


	// ENCOUNTER BEGIN!
	std::cout << "\n\n\n";
	Type("=!=!= ENCOUNTER ALERT =!=!=", 40);
	std::cout << "\n\n";

	std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
	
	Type("You encountered a ", 60);
	Type(enemyName + "!", 150);
	std::cout << "\n\n";
	
	std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
	Type("Are you ready to fight? (Enter any letter then press enter to start!) ", 40);
	
	// PRESS ENTER
	std::cin >> pause;
	pause = "";

	// DEBUG! NOOOOOOOOOOOOOOOOOOOOOOO ITS GONE!!!
	//std::cout << "\n\n=======================================\n\nDEBUG!!!\n\nArray Enemy Profile: " << ptrEProfile[0] << " " << ptrEProfile[1] << " " << ptrEProfile[2] << " " << ptrEProfile[3] << "\n\nEnemy Name: " << enemyName << "\n\nPlayer Array: " << ptrPProfile[0] << " " << ptrPProfile[1] << " " << ptrPProfile[2] << " " << ptrPProfile[3] << " " << ptrPProfile[4] << "\n\nPlayer Details Array: " << ptrPDetails[0] << " " << ptrPDetails[1] << "\n\n======================================\n";
	
	// FIRST ATTACK
	std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
	std::cout << "\n\n";
	Type("=-=-=-=-=-=-=-=-FIGHT=INITIATED-=-=-=-=-=-=-=-=\n\n\nYou go first! ", 15);
	Type("Would you like to: \n\n#1: Attack!\n#2: Dodge and heal!\n\nChoice: ", 80);
	std::cin >> attackChoice;
	// FIRST ATTACK END
	while (fight = true) // FIGHT OVER?
	{
		while (valid == false) // CHOICE IS VALID?
		{
			// ATTACKING CHOICE
			if (attackChoice == 1)
			{
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

					ptrEProfile[0] = ptrEProfile[0] - pDamage; // ENEMY HEALTH - pDamage

					std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
					std::cout << "\n\n";
					Type("The enemy " + enemyName + " is on ", 60); 
					std::cout << ptrEProfile[0];
					Type(" health!\n\n", 60);
					attackChoice = 0;
					valid = true;
					break;
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

					ptrEProfile[0] = ptrEProfile[0] - pDamage; // ENEMY HEALTH - pDamage

					std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
					std::cout << "\n\n";
					Type("The enemy " + enemyName + " is on ", 60);
					std::cout << ptrEProfile[0];
					Type(" health!\n\n", 60);
					attackChoice = 0;
					valid = true;
					break;
				}

				else 
				{
					std::cout << "\n\n";
					speed = 70;
					Type("Your attack did ", speed);
					std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
					
					tempDamage = pDamage * ptrUpgrades[0];
					pDamage = round(tempDamage);
					std::cout << pDamage;

					std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
					Type(" damage!", 60);

					ptrEProfile[0] = ptrEProfile[0] - pDamage; // ENEMY HEALTH - pDamage

					std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
					std::cout << "\n\n";
					speed = 60;
					Type("The enemy " + enemyName + " is on ", speed);
					std::this_thread::sleep_for(std::chrono::milliseconds(200)); // WAIT
					std::cout << ptrEProfile[0];
					Type(" health!\n\n", speed);
					std::this_thread::sleep_for(std::chrono::milliseconds(100));
					std::cout << "\n";
					attackChoice = 0;
					valid = true;
				}
			}

			// BLOCKING CHOICE
			else if (attackChoice == 2)
			{
				dodge = DodgeChance(ptrPProfile, dodge);
				Type("\nYou will try and dodge the next attack from the enemy ", 60);
				Type(enemyName + "!", 60);
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
				valid = true;
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

		valid = false; // DECLARED AS FALSE AGAIN SO YOU CAN CHOOSE AGAIN LATER

		if (ptrEProfile[0] <= 0) // CHECKS IF ENEMY HEALTH IS UNDER OR EQUAL TO 0
		{
			std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
			std::cout << "\n\n";
			speed = 80;
			Type("Enemy has been slain!", speed);
			ptrPProfile[5] = ptrPProfile[5] + 1; // ADDS A KILL
			EnemyRewards(ptrEProfile, ptrPProfile); // PLAYER REWARDS!
			std::cout << "\n\n";
			Type("You have now killed ", speed);
			std::cout << ptrPProfile[5];
			Type(" enemies!", speed); // OUTPUTS AMOUNT OF KILLS
			Type("\n\nYou are on ", 30);
			std::cout << ptrPProfile[0];
			Type(" health, use a health potion? (Yes or No): ", 30);
			std::cin >> healChoice;
			healChoice = Lowercase(healChoice);
			
			while (heal == false)
			{

				if (healChoice == "yes")
				{
					Heal(ptrPProfile);
					heal = true;
				}
				else if (healChoice == "no")
				{
					Type("\n\nYou chose not to heal!", 30);
					heal = true;
				}
				else if (!(healChoice == "yes") && !(healChoice == "no"))
				{
					Type("\n=!=!= ERROR =!=!=\n\nChoice invalid! Re-enter a correct choice: ", 30);
					std::cin >> healChoice;
				}
			}
			heal = false;
			eDead = false; // ENEMY DEAD
			fight = false; // FIGHT OVER


			ptrPProfile = Shop(ptrPProfile);
			ptrUpgrades = UpgradeCheck(ptrPProfile);

			std::cout << "\n\n" << ptrUpgrades[0] << "\n" << ptrUpgrades[1] << "\n\n";

			break; // RUNS NEXT PART
		}

		else if (ptrEProfile[0] > 0)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
			std::cout << "\n";
			Type("The enemy " + enemyName + " is now attacking!", 70);
			eDamage = rand() % (ptrEProfile[2] - ptrEProfile[1] + 1) + ptrEProfile[1]; // RANDOM NUMBER BETWEEN ENEMIES DAMAGEMIN AND DAMAGEMAX
			std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT

			//CHECKS IF USER CHOSE DODGE
			if (dodge == true) // USER CHOSE DODGE
			{
				Type("\n\nYou succesfully dodged the attack!", 50);
				Heal(ptrPProfile);
				dodge = false;
			}
			else if (failDodge == true)
			{
				Type("\n\nYou failed to dodge the attack! You were attacked for ", 50);
				std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
				std::cout << eDamage;
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
			}
			else if (dodge == false) // USER DID NOT CHOOSE DODGE
			{
				std::cout << "\n\n";
				Type("You were attacked for ", 60);
				std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
				std::cout << eDamage;
				std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
				Type(" damage!", 60);
				std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
				ptrPProfile[0] = ptrPProfile[0] - eDamage; // PLAYER HEALTH - ENEMY DAMAGE
				std::cout << "\n\n";
				Type("You are now on ", 60);
				std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
				std::cout << ptrPProfile[0];
				Type(" health!", 60); // DISPLAYS CURRENT HEALTH
			}
		}

		if (ptrPProfile[0] <= 0) // IF PLAYER HEALTH IS LESS THAN OR EQUAL TO 0
		{
			pDead = true; // PLAYER DEAD
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
		Type("It is your turn to attack again! What would you like to do?\n\n#1: Attack!\n#2: Dodge and heal!", 60);
		std::cout << "\n\n";
		Type("You have ", 60);
		std::cout << ptrPProfile[7];
		Type(" health potions left!\n\nChoice: ", 60);
		std::cin >> attackChoice;
	}

	std::cout << "\n\n\nDEBUG: ENCOUNTER OVER!\n";
	// ENCOUNTER OVER!

	return ptrPProfile[0];
}