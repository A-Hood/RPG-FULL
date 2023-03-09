#include <iostream>
#include "Header.h"

int* EnemyProfile(int enemySpawnType)
{
	static int enemyProfile[4];

	// BANDIT ENEMY TYPE !
	if (enemySpawnType == 1)
	{
		enemyProfile[0] = 10; // HEALTH
		enemyProfile[1] = 5; // MIN DAMAGE
		enemyProfile[2] = 5; // MAX DAMAGE
		enemyProfile[3] = 1; // ENEMY TYPE
	}

	// MERCANARY ENEMY TYPE !
	else if (enemySpawnType == 2)
	{
		enemyProfile[0] = 20; // HEALTH
		enemyProfile[1] = 10; // MIN DAMAGE
		enemyProfile[2] = 10; // MAX DAMAGE
		enemyProfile[3] = 2; // ENEMY TYPE
	}

	// TROLL ENEMY TYPE !
	else if (enemySpawnType == 3)
	{
		enemyProfile[0] = 30; // HEALTH
		enemyProfile[1] = 10; // MIN DAMAGE
		enemyProfile[2] = 20; // MAX DAMAGE
		enemyProfile[3] = 3; // ENEMY TYPE
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