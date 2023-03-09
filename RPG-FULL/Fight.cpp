#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Header.h"

int Fight(int* ptrPProfile, std::string* ptrPDetails, std::string enemyName, int enemySpawnType)
{
	bool fight = true;
	bool pDead, eDead = false;
	bool valid = false;
	bool dodge = false;
	int pDamage, eDamage;
	int attackChoice;
	std::string pause;

	srand(time(NULL)); // SEEDING RANDOM NUM GENERATOR

	int* ptrEProfile;
	enemySpawnType = rand() % (3 - 1 + 1) + 1; // DECLARING RANDOM NUM FROM 1 TO 3 FOR ENEMY SPAWN TYPE	

	ptrEProfile = EnemyProfile(enemySpawnType); // PTR TO enemyProfile ARRAY

	enemyName = EnemyName(ptrEProfile, enemyName); // GETS ENEMY NAME


	// ENCOUNTER BEGIN!
	std::cout << "\n\n=!=!= ENCOUTER ALERT! =!=!=\n\n";

	std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT

	std::cout << "You encountered a " << enemyName << "!\n";
	std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
	std::cout << "\nAre you ready to fight? (Press enter to start!)";
	
	// PRESS ENTER
	std::cin >> pause;
	pause = "";

	// DEBUG!
	std::cout << "\n\n=======================================\n\nDEBUG!!!\n\nArray Enemy Profile: " << ptrEProfile[0] << " " << ptrEProfile[1] << " " << ptrEProfile[2] << " " << ptrEProfile[3] << "\n\nEnemy Name: " << enemyName << "\n\nPlayer Array: " << ptrPProfile[0] << " " << ptrPProfile[1] << " " << ptrPProfile[2] << " " << ptrPProfile[3] << " " << ptrPProfile[4] << "\n\nPlayer Details Array: " << ptrPDetails[0] << " " << ptrPDetails[1] << "\n\n======================================\n";
	
	// FIRST ATTACK
	std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
	std::cout << "\n\nYou go first! Would you like to:\n\n#1: Attack\n#2: Dodge\n\nChoice: ";
	std::cin >> attackChoice;
	// FIRST ATTACK END
	while (fight = true) // FIGHT OVER?
	{
		while (valid == false) // CHOICE IS VALID?
		{
			// ATTACKING CHOICE
			if (attackChoice == 1)
			{
				pDamage = rand() % (ptrEProfile[2] - ptrEProfile[1] - 1) + ptrEProfile[1]; // RANDOM NUMBER BETWEEN PLAYERS DAMAGEMAX AND DAMAGEMIN
				std::cout << "\n\nYour attack did ";
				std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
				std::cout << "" << pDamage << " damage!";
				ptrEProfile[0] = ptrEProfile[0] - pDamage; // ENEMY HEALTH - PLAYER DAMAGE
				std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
				std::cout << "\n\nThe enemy " << enemyName << " is on " << ptrEProfile[0] << " health!\n\n";
				attackChoice = 0;
				valid = true;
			}

			// BLOCKING CHOICE
			else if (attackChoice == 2)
			{
				dodge = true;
				std::cout << "You will dodge the next attack from the enemy " << enemyName << "!";
				attackChoice = 0;
				valid = true;
			}

			// INVALID OPTIONS
			else if (attackChoice < 1)
			{
				std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
				std::cout << "Attack choice invalid!\n\nRe-enter a correct choice: ";
				std::cin >> attackChoice;
			}
			else if (attackChoice > 2) 
			{
				std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
				std::cout << "Attack choice invalid!\n\nRe-enter a correct choice: ";
				std::cin >> attackChoice;
			}
			// INVALID OPTIONS OVER
		}

		valid = false; // DECLARED AT FALSE AGAIN SO YOU CAN CHOOSE AGAIN LATER

		if (ptrEProfile[0] <= 0) // CHECKS IF ENEMY HEALTH IS UNDER OR EQUAL TO 0
		{
			std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
			std::cout << "\n\nEnemy has been slain!";
			ptrPProfile[5] = ptrPProfile[5] + 1; // ADDS A KILL
			std::cout << "\n\nYou have now killed " << ptrPProfile[5] << " enemies!"; // OUTPUTS AMOUNT OF KILLS
			eDead = false; // ENEMY DEAD
			fight = false; // FIGHT OVER
			break; // RUNS NEXT PART
		}

		else if (ptrEProfile[0] > 0)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
			std::cout << "\n\nThe enemy " << enemyName << " is now attacking!";
			eDamage = rand() % (ptrEProfile[2] - ptrEProfile[1] + 1) + ptrEProfile[1]; // RANDOM NUMBER BETWEEN ENEMIES DAMAGEMIN AND DAMAGEMAX
			std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT

			//CHECKS IF USER CHOSE DODGE
			if (dodge == true) // USER CHOSE DODGE
			{
				std::cout << "\n\nYou dodged the attack!";
			}
			else if (dodge == false) // USER DID NOT CHOOSE DODGE
			{
				std::cout << "\n\nYou were attacked for ";
				std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
				std::cout << eDamage << " damage!";
				std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
				ptrPProfile[0] = ptrPProfile[0] - eDamage; // PLAYER HEALTH - ENEMY DAMAGE
				std::cout << "You are now on " << ptrPProfile[0] << " health!"; // DISPLAYS CURRENT HEALTH
			}
		}

		if (ptrPProfile[0] <= 0) // IF PLAYER HEALTH IS LESS THAN OR EQUAL TO 0
		{
			pDead = true; // PLAYER DEAD
			fight = false; // FIGHT OVER
			std::this_thread::sleep_for(std::chrono::seconds(1)); // WAIT
			std::cout << "\n\nYou are dead! You killed " << ptrPProfile[5] << " enemies!"; // DISPLAYS HOW MANY ENEMIES YOU KILLED
			std::cin.get();
			exit(0);
		}
		
		std::cout << "\n\n\nIt is your turn to attack again! What would you like to do?\n\nChoice: ";
		std::cin >> attackChoice;
	}

	std::cout << "\n\nDEBUG: ENCOUNTER OVER!";
	// ENCOUNTER OVER!

	return 0;
}