#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Header.h"

int* Heal(int* ptrPProfile)
{
	if (ptrPProfile[7] > 0) // IF PLAYER HAS HEALTH POTIONS
	{
		if (ptrPProfile[0] >= (ptrPProfile[8] - 30) && ptrPProfile[0] < (ptrPProfile[8] - 1)) // IF PLAYER HAS ENOUGH HEALTH TO FULL HEAL
		{
			ptrPProfile[7] = ptrPProfile[7] - 1; // TAKE AWAY 1 HEALTH POTION
			ptrPProfile[0] = ptrPProfile[8]; // HEAL TO FULL HEALTH
			Type("\nYou have fully healed! You are now on ", 30);
			std::this_thread::sleep_for(std::chrono::milliseconds(30));
			std::cout << ptrPProfile[0];
			std::this_thread::sleep_for(std::chrono::milliseconds(30));
			Type(" health!", 30);
			return ptrPProfile;
		}
		else if (ptrPProfile[0] == ptrPProfile[8]) // IF PLAYER HAS FULL HEALTH
		{
			Type("\nYou cannot heal as you are on full health!", 30);
			return ptrPProfile;
		}
		else // IF PLAYER IS TOO FAR TO REACH FULL HEALTH
		{
			ptrPProfile[7] = ptrPProfile[7] - 1; // TAKE AWAY 1 HEALTH POTION
			ptrPProfile[0] = ptrPProfile[0] + 30; // HEAL AMOUNT
			Type("\nYou healed 30 health! You are now on ", 30);
			std::this_thread::sleep_for(std::chrono::milliseconds(30));
			std::cout << ptrPProfile[0];
			std::this_thread::sleep_for(std::chrono::milliseconds(30));
			Type(" health!", 30);
			return ptrPProfile;
		}
	}
	else if (ptrPProfile[7] == 0) // IF PLAYER HAS NO HEALTH POTIONS
	{
		Type("\nYou have no health potions left so you could not heal!\nYou are still on ", 30);
		std::this_thread::sleep_for(std::chrono::milliseconds(30));
		std::cout << ptrPProfile[0];
		std::this_thread::sleep_for(std::chrono::milliseconds(30));
		Type(" health!", 30);
		return ptrPProfile;
	}

	return ptrPProfile;
}