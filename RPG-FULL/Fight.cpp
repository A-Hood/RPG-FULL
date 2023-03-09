#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Header.h"

int Fight(int* ptrPProfile, std::string enemyName, int enemySpawnType)
{
	srand(time(NULL));

	int* ptrEProfile;
	enemySpawnType = rand() % (3 - 1 + 1) + 1; // DECLARING RANDOM NUM FROM 1 TO 3 FOR ENEMY SPAWN TYPE	

	ptrEProfile = EnemyProfile(enemySpawnType); // PTR TO enemyProfile ARRAY

	enemyName = EnemyName(ptrEProfile, enemyName);

	std::cout << "\n\n=!=!= ENCOUTER ALERT! =!=!=\n\n";

	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "You encountered a " << enemyName << "!\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "\nAre you ready to fight? (Press enter to start!)";
	std::cin.get();

	std::cout << "\n\n=======================================\n\nDEBUG!!!\n\nArray Enemy Profile: " << ptrEProfile[0] << " " << ptrEProfile[1] << " " << ptrEProfile[2] << " " << ptrEProfile[3] << "\n\nEnemy Name: " << enemyName << "\n\n======================================\n";
	if (ptrPProfile[0] <= 0)
	{

	}

	return 0;
}