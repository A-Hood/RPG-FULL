#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Header.h"

int* EnemyRewards(int* ptrEProfile, int* ptrPProfile)
{
	int goldDrop;
	goldDrop = rand() % (ptrEProfile[5] - ptrEProfile[4] - 1) + ptrEProfile[4];

	ptrPProfile[9] = ptrPProfile[9] + goldDrop;

	Type("\n\nThe enemy dropped ", 30);
	std::cout << goldDrop;
	Type(" gold! You now have ", 30);
	std::cout << ptrPProfile[9];
	Type(" gold!", 30);

	return ptrPProfile;
}

int* BossRewards(int* ptrPProfile)
{
	int goldDrop;
	goldDrop = rand() % (100 - 60 - 1) + 60;

	ptrPProfile[9] = ptrPProfile[9] + goldDrop;

	Type("\n\nThe boss dropped ", 30);
	std::cout << goldDrop;
	Type(" gold! You now have ", 30);
	std::cout << ptrPProfile[9];
	Type(" gold!", 30);

	return ptrPProfile;
}