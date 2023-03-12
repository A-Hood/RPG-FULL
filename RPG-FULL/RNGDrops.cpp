#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <cmath>
#include "Header.h"

int* ChestDrop(int* ptrPProfile)
{
	int chestType = 0;
	int chestValue = 0;
	Type("\n\n=%=%=%=%= RNG-DROP =%=%=%=%=", 30);
	chestType = rand() % (100 - 1 + 1) + 1; // RANDOM NUMBER BETWEEN 1 AND 100 FOR RNG CHANCE

	if (chestType >= 1 && chestType <= 50) // 50% COMMON CHEST TYPE
	{
		CommonChest(ptrPProfile, chestType, chestValue);
	}
	else if (chestType >= 51 && chestType <= 85) // 35% RARE CHEST TYPE
	{
		RareChest(ptrPProfile, chestType, chestValue);
	}
	else if (chestType >= 86 && chestType <= 99) // 14% LEGENDARY CHEST DROP
	{
		LegendaryChest(ptrPProfile, chestType, chestValue);
	}
	else if (chestType == 100) // 1% (<- Might be raised) MYTHICAL CHEST DROP (INCLUDES ITEM TO RAISE MAX HP!)
	{
		MythicalChest(ptrPProfile, chestType, chestValue);
	}

	return ptrPProfile;
}

int* CommonChest(int* ptrPProfile, int chestType, int chestValue)
{
	Type("\n\n\nYou found a common chest!\n\n", 30);
	chestValue = rand() % (30 - 10 + 1) + 10;
	ptrPProfile[9] = ptrPProfile[9] + chestValue;
	std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
	Type("You loot the chest and find ", 30);
	std::this_thread::sleep_for(std::chrono::milliseconds(100)); // WAIT
	std::cout << chestValue;
	std::this_thread::sleep_for(std::chrono::milliseconds(100)); // WAIT
	Type(" gold!\n\nYou now have ", 30);
	std::cout << ptrPProfile[9];
	Type(" gold!\n\nYou then leave the chest room...", 30);

	return ptrPProfile;
}

int* RareChest(int* ptrPProfile, int chestType, int chestValue)
{
	Type("\n\n\nYou found a rare chest!\n\n", 30);
	chestValue = rand() % (50 - 30 + 1) + 30;
	ptrPProfile[9] = ptrPProfile[9] + chestValue;
	std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
	Type("You loot the chest and find ", 30);
	std::this_thread::sleep_for(std::chrono::milliseconds(100)); // WAIT
	std::cout << chestValue;
	std::this_thread::sleep_for(std::chrono::milliseconds(100)); // WAIT
	Type(" gold!\n\nYou now have ", 30);
	std::cout << ptrPProfile[9];
	Type(" gold!\n\nYou then leave the chest room...", 30);

	return ptrPProfile;
}

int* LegendaryChest(int* ptrPProfile, int chestType, int chestValue)
{
	Type("\n\n\nYou found a legendary chest!\n\n", 30);
	chestValue = rand() % (100 - 70 + 1) + 70;
	ptrPProfile[9] = ptrPProfile[9] + chestValue;
	std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
	Type("You loot the chest and find ", 30);
	std::this_thread::sleep_for(std::chrono::milliseconds(100)); // WAIT
	std::cout << chestValue;
	std::this_thread::sleep_for(std::chrono::milliseconds(100)); // WAIT
	Type(" gold!\n\nYou are now have ", 30);
	std::cout << ptrPProfile[9];
	Type(" gold!", 30);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	Type("In the chest you also find a key.\nYou use the key on a door next to the chest.", 30);
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
	Type("You find", 30);
	for (int i = 0; i < 3; i++)
	{
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	Type("\na room with a healing fountain!\n\nYou choose to heal the healing fountain and are now at full health!", 30);
	ptrPProfile[0] = ptrPProfile[8];
	Type("\n\nYou then leave the chest room...", 30);

	return ptrPProfile;
}

int* MythicalChest(int* ptrPProfile, int chestType, int chestValue)
{
	Type("\n\n\nYou found a MYTHICAL chest!!\n\n", 30);
	chestValue = rand() % (150 - 100 + 1) + 100; // RANDOM GOLD AMOUNT
	ptrPProfile[9] = ptrPProfile[9] + chestValue; // ADD GOLD AMOUNT TO BALANCE
	ptrPProfile[8] = ptrPProfile[8] + 30; // ADDS 30 TO MAXIMUM HEALTH
	ptrPProfile[0] = ptrPProfile[8]; // FULL HEAL TO NEW FULL HEALTH
	std::this_thread::sleep_for(std::chrono::milliseconds(500)); // WAIT
	Type("You loot the chest and find ", 30);
	std::this_thread::sleep_for(std::chrono::milliseconds(100)); // WAIT
	std::cout << chestValue;
	std::this_thread::sleep_for(std::chrono::milliseconds(100)); // WAIT
	Type(" gold!\n\nYou now have ", 30);
	std::cout << ptrPProfile[9];
	Type(" gold!\n\nReaching into the chest, you pull out a heart shaped container.\nIt flies out of your hand into the air and shines a bright red.\nYou touch the container and feel a rush!\n\nYou have gained an extra 30 maximum health!\nYou also heal to your new full health which is ", 30);
	std::cout << ptrPProfile[0];
	Type("!\n\nYou then leave the chest room...", 30);

	return ptrPProfile;
}