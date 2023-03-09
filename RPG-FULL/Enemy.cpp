#include <iostream>
#include "Header.h"

int* EnemyProfile(int enemySpawnType)
{
	static int enemyProfile[4];

	// BANDIT ENEMY TYPE !
	if (enemySpawnType == 1)
	{
		enemyProfile[0] = 10;
		enemyProfile[1] = 5;
		enemyProfile[2] = 5;
		enemyProfile[3] = 1;
	}

	// MERCANARY ENEMY TYPE !
	else if (enemySpawnType == 2)
	{
		enemyProfile[0] = 20;
		enemyProfile[1] = 10;
		enemyProfile[2] = 10;
		enemyProfile[3] = 2;
	}

	// TROLL ENEMY TYPE !
	else if (enemySpawnType == 3)
	{
		enemyProfile[0] = 30;
		enemyProfile[1] = 10;
		enemyProfile[2] = 20;
		enemyProfile[3] = 3;
	}

	return enemyProfile;
}

std::string EnemyName(int* ptrEProfile, std::string enemyName)
{
	if (ptrEProfile[3] == 1)
	{
		enemyName = "bandit";
	}
	else if (ptrEProfile[3] == 2)
	{
		enemyName = "mercenary";
	}
	else if (ptrEProfile[3] == 3)
	{
		enemyName = "troll";
	}

	return enemyName;
}