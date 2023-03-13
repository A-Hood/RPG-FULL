#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <cmath>
#include "Header.h"

int* ThiefFight(int* ptrPProfile, std::string* ptrPDetails, int* ptrEProfile, float* ptrUpgrades, std::string enemyName, int attackChoice)
{
	// these dont exist shhhhhhh...
	bool firstAttack = true;
	bool fight = true;
	bool pDead, eDead = false;
	bool valid = false;
	bool dodge = false;
	int eDamage;
	bool failDodge = false;
	bool heal = false;
	std::string healChoice;
	std::string pause;
	float tempEDamage;
	int rngChestDrop;
	int randomSteal = 0;
	int amountStolen = 0;
	int thiefTurns = 0;
	// end of the mess shhhhhh...

	while (fight)
	{
		while (valid == false) // CHOICE IS VALID?
		{
			// ATTACKING CHOICE
			if (attackChoice == 1)
			{
				ptrEProfile = PlayerAttack(ptrPProfile, ptrPDetails, ptrEProfile, ptrUpgrades, enemyName, attackChoice);
				attackChoice = 0;
				thiefTurns = thiefTurns + 1;
				valid = true;
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
				thiefTurns = thiefTurns + 1;
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
			std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
			std::cout << "\n\n";
			Type("Enemy has been slain!", 60);
			ptrPProfile[5] = ptrPProfile[5] + 1; // ADDS A KILL
			EnemyRewards(ptrEProfile, ptrPProfile); // PLAYER REWARDS!
			std::cout << "\n\n";
			ptrPProfile[9] = ptrPProfile[9] + amountStolen; // ADD AMOUNT THEIF STOLE TO ORIGINAL GOLD AMOUNT
			Type("You get the money back that the thief took from you which was ", 30);
			std::cout << amountStolen;
			Type(" gold!\nYou are back on ", 30);
			std::cout << ptrPProfile[9];
			Type(" gold!", 30);
			amountStolen = 0;
			Type("\n\nYou have now killed ", 60);
			std::cout << ptrPProfile[5];
			Type(" enemies!", 60); // OUTPUTS AMOUNT OF KILLS
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
					healChoice = Lowercase(healChoice);
				}
			}
			heal = false;
			eDead = false; // ENEMY DEAD
			fight = false; // FIGHT OVER

			rngChestDrop = rand() % (100 - 1 + 1) + 1;
			if (rngChestDrop >= 1 && rngChestDrop <= 40) // 40% CHANCE FOR CHEST DROP
			{
				ptrPProfile = ChestDrop(ptrPProfile);
			}
			else if (rngChestDrop > 41) {}

			ptrPProfile = Shop(ptrPProfile);

			return ptrPProfile; // RUNS NEXT PART
		}

		else if (thiefTurns == 4)
		{
			Type("\nThe thief ran away with your money!\n\nYou lost ", 30);
			std::cout << amountStolen;
			Type(" gold!\nYour balance after is ", 30);
			std::cout << ptrPProfile[9];
			Type(" gold!", 30);

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
					healChoice = Lowercase(healChoice);
				}
			}
			heal = false;

			return ptrPProfile;
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
				Type("\n\nYou failed to dodge the attack!\n\nSNATCH!\n\nYou were attacked for ", 50);
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

				randomSteal = rand() % (ptrEProfile[7] - ptrEProfile[6] + 1) + ptrEProfile[6];


				if (ptrPProfile[9] == 0)
				{
					Type("\nThe thief couldn't steal from you as you have no gold!\n", 30);
				}
				else if (randomSteal > ptrPProfile[9])
				{
					Type("\nThe thief also stole ", 30);
					std::cout << ptrPProfile[9];
					Type(" gold from you!\n", 30);
					ptrPProfile[9] = 0;
					amountStolen = amountStolen + randomSteal;
				}
				else if (randomSteal <= ptrPProfile[9])
				{
					Type("\nThe thief also stole ", 30);
					std::cout << randomSteal;
					Type(" gold from you!\n", 30);
					ptrPProfile[9] = ptrPProfile[9] - randomSteal;
					amountStolen = amountStolen + randomSteal;
				}


				failDodge = false;
			}
			else if (dodge == false) // USER DID NOT CHOOSE DODGE
			{
				Type("\n\nSNATCH!\n\nYou were attacked for ", 50);
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

				randomSteal = rand() % (ptrEProfile[7] - ptrEProfile[6] + 1) + ptrEProfile[6];


				if (ptrPProfile[9] == 0)
				{
					Type("\n\nThe thief couldn't steal from you as you have no gold!\n", 30);
				}
				else if (randomSteal > ptrPProfile[9])
				{
					Type("\n\nThe thief also stole ", 30);
					std::cout << ptrPProfile[9];
					Type(" gold from you!\n", 30);
					amountStolen = amountStolen + ptrPProfile[9];
					ptrPProfile[9] = 0;
				}
				else if (randomSteal <= ptrPProfile[9])
				{
					Type("\n\nThe thief also stole ", 30);
					std::cout << randomSteal;
					Type(" gold from you!\n", 30);
					ptrPProfile[9] = ptrPProfile[9] - randomSteal;
					amountStolen = amountStolen + randomSteal;
				}
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
		Type("It is your turn to attack again! What would you like to do?\n\n#1: Attack!\n#2: Dodge and heal!", 50);
		std::cout << "\n\n";
		Type("You have ", 60);
		std::cout << ptrPProfile[7];
		Type(" health potions left!\n\nChoice: ", 60);
		std::cin >> attackChoice;
	}
}
