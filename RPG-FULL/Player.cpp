#include <iostream>
#include "Header.h"

int* PlayerProfile(int characterChoice, int playerHealth, int playerMinDamage, int playerMaxDamage)
{
	static int playerProfile[5];
	int weaponChoice;

	std::cout << "What class do you wish to be:\n\n#1: Knight\n#2: Rogue\n#3: Mage\n\nChoice: ";
	std::cin >> characterChoice;


	// KNIGHT CLASS CHOICE!
	if (characterChoice == 1)
	{
		playerHealth = 120;
		std::cout << "\nWhat weapon do you wish to weild: \n\n#1: Sword\n#2: Axe\n#3:Mace\n\nChoice: ";
		std::cin >> weaponChoice;

		if (weaponChoice == 1)
		{
			playerMinDamage = 5;
			playerMaxDamage = 10;
		}

		else if (weaponChoice == 2)
		{
			playerMinDamage = 15;
			playerMaxDamage = 20;
		}

		else if (weaponChoice == 3)
		{
			playerMinDamage = 20;
			playerMaxDamage = 25;
		}
	}


	// ROGUE CLASS CHOICE!
	else if (characterChoice == 2)
	{
		playerHealth = 100;
		std::cout << "\nWhat weapon do you wish to weild: \n\n#1: Sword\n#2: Axe\n#3: Mace\n\nChoice: ";
		std::cin >> weaponChoice;

		if (weaponChoice == 1)
		{
			playerMinDamage = 15;
			playerMaxDamage = 20;
		}

		else if (weaponChoice == 2)
		{
			playerMinDamage = 7;
			playerMaxDamage = 7;
		}

		else if (weaponChoice == 3)
		{
			playerMinDamage = 10;
			playerMaxDamage = 15;
		}
	}


	// MAGE CLASS CHOICE!
	else if (characterChoice == 3)
	{
		playerHealth = 75;
		std::cout << "\nWhat weapon do you wish to weild: \n\n#1: Sword\n#2: Axe\n#3:Mace\n\nChoice: ";
		std::cin >> weaponChoice;

		if (weaponChoice == 1)
		{
			playerMinDamage = 10;
			playerMaxDamage = 15;
		}

		else if (weaponChoice == 2)
		{
			playerMinDamage = 5;
			playerMaxDamage = 5;
		}

		else if (weaponChoice == 3)
		{
			playerMinDamage = 25;
			playerMaxDamage = 30;
		}
	}



	playerProfile[0] = playerHealth;
	playerProfile[1] = playerMinDamage;
	playerProfile[2] = playerMaxDamage;
	playerProfile[3] = characterChoice;
	playerProfile[4] = weaponChoice;

	return playerProfile;
}

std::string* PlayerDetails(int* ptrPProfile)
{
	static std::string playerDetails[2];


	// KNIGHT PROFILE
	if (ptrPProfile[3] == 1)
	{
		std::cout << "Job Type selected: Knight" << std::endl;
		playerDetails[0] = "knight";

		if (ptrPProfile[4] == 1)
		{
			std::cout << "Weapon selected: Sword";
			playerDetails[1] = "sword";
		}

		else if (ptrPProfile[4] == 2)
		{
			std::cout << "Weapon selected: Axe";
			playerDetails[1] = "axe";
		}

		else if (ptrPProfile[4] == 3)
		{
			std::cout << "Weapon selected: Mace";
			playerDetails[1] = "mace";
		}

	}


	// ROGUE PROFILE
	else if (ptrPProfile[3] == 2)
	{
		std::cout << "Job Type selected: Rogue" << std::endl;
		playerDetails[0] = "rogue";

		if (ptrPProfile[4] == 1)
		{
			std::cout << "Weapon selected: Bow";
			playerDetails[1] = "bow";
		}

		else if (ptrPProfile[4] == 2)
		{
			std::cout << "Weapon selected: Daggers";
			playerDetails[1] = "daggers";
		}

		else if (ptrPProfile[4] == 3)
		{
			std::cout << "Weapon selected: Scimitar";
			playerDetails[1] = "scimitar";
		}
	}


	// MAGE PROFILE
	else if (ptrPProfile[3] == 3)
	{
		std::cout << "Job Type selected: Mage" << std::endl;
		playerDetails[0] = "mage";

		if (ptrPProfile[4] == 1)
		{
			std::cout << "Weapon selected: Staff";
			playerDetails[1] = "staff";
		}

		else if (ptrPProfile[4] == 2)
		{
			std::cout << "Weapon selected: Wand";
			playerDetails[1] = "wand";
		}

		else if (ptrPProfile[4] == 3)
		{
			std::cout << "Weapon selected: Wand";
			playerDetails[1] = "wand";
		}
	}

	return playerDetails;
}