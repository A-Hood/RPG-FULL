#include <iostream>
#include <chrono>
#include <thread>
#include "Header.h"

int* PlayerProfile(int characterChoice, int playerHealth, int playerMinDamage, int playerMaxDamage, int weaponChoice, int dodgeChance)
{
	std::string str;
	static int playerProfile[9];
	int speed = 60; // OUTPUT SPEED!
	bool valid = false;

	str = "What class do you wish to be:\n\n#1: Knight\n#2: Rogue\n#3: Mage\n\nChoice: ";
	Type(str, speed);
	std::cin >> characterChoice;

	while (valid == false)
	{
	// KNIGHT CLASS CHOICE!
		if (characterChoice == 1)
		{
			playerHealth = 120;
			dodgeChance = 2; // 1 IN 4 DODGE CHANCE
			str = "\nWhat weapon do you wish to wield: \n\n#1: Sword\n#2: Axe\n#3: Mace\n\nChoice: ";
			Type(str, speed);
			std::cin >> weaponChoice;

			while (valid == false)
			{
				if (weaponChoice == 1)
				{
					playerMinDamage = 5;
					playerMaxDamage = 10;
					break;
				}

				else if (weaponChoice == 2)
				{
					playerMinDamage = 15;
					playerMaxDamage = 20;
					break;
				}

				else if (weaponChoice == 3)
				{
					playerMinDamage = 20;
					playerMaxDamage = 25;
					break;
				}
				else if (weaponChoice < 1)
				{
					Type("\n=!=!= ERROR =!=!=\n\nWeapon choice invalid! Re-enter a correct choice: ", 40);
					std::cin >> weaponChoice;
				}
				else if (weaponChoice > 3)
				{
					Type("\n=!=!= ERROR =!=!=\n\nWeapon choice invalid! Re-enter a correct choice: ", 40);
					std::cin >> weaponChoice;
				}
			}
			break;

		}


		// ROGUE CLASS CHOICE!
		else if (characterChoice == 2)
		{
			playerHealth = 100;
			dodgeChance = 2; // 1 IN 3 DODGE CHANCE
			str = "\nWhat weapon do you wish to wield: \n\n#1: Bow\n#2: Daggers\n#3: Scimitar\n\nChoice: ";
			Type(str, speed);
			std::cin >> weaponChoice;

			while (valid == false)
			{
				if (weaponChoice == 1)
				{
					playerMinDamage = 15;
					playerMaxDamage = 20;
					break;
				}

				else if (weaponChoice == 2)
				{
					playerMinDamage = 7;
					playerMaxDamage = 7;
					break;
				}

				else if (weaponChoice == 3)
				{
					playerMinDamage = 10;
					playerMaxDamage = 15;
					break;
				}
				
				else if (weaponChoice < 1)
				{
					Type("\n=!=!= ERROR =!=!=\n\nWeapon choice invalid! Re-enter a correct choice: ", 40);
					std::cin >> weaponChoice;
				}

				else if (weaponChoice > 3)
				{
					Type("\n=!=!= ERROR =!=!=\n\nWeapon choice invalid! Re-enter a correct choice: ", 40);
					std::cin >> weaponChoice;
				}
			}
			break;
		}


		// MAGE CLASS CHOICE!
		else if (characterChoice == 3)
		{
			playerHealth = 75;
			dodgeChance = 2; // 1 IN 2 DODGE CHANCE
			str = "\nWhat weapon do you wish to wield: \n\n#1: Staff\n#2: Wand\n#3: Runebook\n\nChoice: ";
			Type(str, speed);
			std::cin >> weaponChoice;

			while (valid == false)
			{
				if (weaponChoice == 1)
				{
					playerMinDamage = 10;
					playerMaxDamage = 15;
					break;
				}

				else if (weaponChoice == 2)
				{
					playerMinDamage = 5;
					playerMaxDamage = 5;
					break;
				}

				else if (weaponChoice == 3)
				{
					playerMinDamage = 12;
					playerMaxDamage = 17;
					break;
				}
				else if (weaponChoice < 1)
				{
					Type("\n=!=!= ERROR =!=!=\n\nWeapon choice invalid! Re-enter a correct choice: ", 40);
					std::cin >> weaponChoice;
				}
				else if (weaponChoice > 3)
				{
					Type("\n=!=!= ERROR =!=!=\n\nWeapon choice invalid! Re-enter a correct choice: ", 40);
					std::cin >> weaponChoice;
				}
			}
			break;
		}
		else if (characterChoice < 1)
		{
			Type("\n=!=!= ERROR =!=!=\n\nCharacter choice invalid! Re-enter a correct choice: ", 40);
			std::cin >> characterChoice;
		}
		else if (characterChoice > 3)
		{
			Type("\n=!=!= ERROR =!=!=\n\nCharacter choice invalid! Re-enter a correct choice: ", 40);
			std::cin >> characterChoice;
		}
	}


	// PLAYER PROFILE
	playerProfile[0] = playerHealth; // HEALTH
	playerProfile[1] = playerMinDamage; // MIN DAMAGE
	playerProfile[2] = playerMaxDamage; // MAX DAMAGE
	playerProfile[3] = characterChoice; // CHARACTER CHOICE
	playerProfile[4] = weaponChoice; // WEAPON CHOICE
	playerProfile[5] = 0; // ENEMY KILLS!
	playerProfile[6] = dodgeChance; // DODGE CHANCE
	playerProfile[7] = 5; // HEALTH POTION AMOUNT
	playerProfile[8] = playerHealth;
	// PLAYER PROFILE END

	return playerProfile;
}

std::string* PlayerDetails(int* ptrPProfile)
{
	static std::string playerDetails[2];
	std::string str;
	int speed = 70;

	// KNIGHT PROFILE
	if (ptrPProfile[3] == 1)
	{
		std::cout << "\n\n";
		JobLBL("Knight!");
		std::cout << "\n\n";
		playerDetails[0] = "knight";
		

		if (ptrPProfile[4] == 1)
		{
			WeaponLBL("Sword!");
			playerDetails[1] = "sword";
		}

		else if (ptrPProfile[4] == 2)
		{
			WeaponLBL("Axe!");
			playerDetails[1] = "axe";
		}

		else if (ptrPProfile[4] == 3)
		{
			WeaponLBL("Mace!");
			playerDetails[1] = "mace";
		}

	}


	// ROGUE PROFILE
	else if (ptrPProfile[3] == 2)
	{
		std::cout << "\n\n";
		JobLBL("Rogue!");
		std::cout << "\n\n";
		playerDetails[0] = "rogue";

		if (ptrPProfile[4] == 1)
		{
			WeaponLBL("Bow!");
			playerDetails[1] = "bow";
		}

		else if (ptrPProfile[4] == 2)
		{
			WeaponLBL("Daggers!");
			playerDetails[1] = "daggers";
		}

		else if (ptrPProfile[4] == 3)
		{
			WeaponLBL("Scimitar!");
			playerDetails[1] = "scimitar";
		}
	}


	// MAGE PROFILE
	else if (ptrPProfile[3] == 3)
	{
		std::cout << "\n\n";
		JobLBL("Mage!");
		std::cout << "\n\n";
		playerDetails[0] = "mage";

		if (ptrPProfile[4] == 1)
		{
			WeaponLBL("Staff!");
			playerDetails[1] = "staff";
		}

		else if (ptrPProfile[4] == 2)
		{
			WeaponLBL("Wand!");
			playerDetails[1] = "wand";
		}

		else if (ptrPProfile[4] == 3)
		{
			WeaponLBL("Runebook!");
			playerDetails[1] = "runebook";
		}
	}

	return playerDetails;
}