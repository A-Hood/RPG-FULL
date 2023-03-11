#include <iostream>
#include "Header.h"

int* EnemyProfile(int enemySpawnType)
{
	static int enemyProfile[6];

	// BANDIT ENEMY TYPE !
	if (enemySpawnType == 1)
	{
		enemyProfile[0] = 15; // HEALTH
		enemyProfile[1] = 5; // MIN DAMAGE
		enemyProfile[2] = 8; // MAX DAMAGE
		enemyProfile[3] = 1; // ENEMY TYPE
		enemyProfile[4] = 20; // MIN GOLD DROP
		enemyProfile[5] = 30; // MAX GOLD DROP
	}

	// MERCANARY ENEMY TYPE !
	else if (enemySpawnType == 2)
	{
		enemyProfile[0] = 25; // HEALTH
		enemyProfile[1] = 10; // MIN DAMAGE
		enemyProfile[2] = 15; // MAX DAMAGE
		enemyProfile[3] = 2; // ENEMY TYPE
		enemyProfile[4] = 25; // MIN GOLD DROP
		enemyProfile[5] = 40; // MAX GOLD DROP
	}

	// TROLL ENEMY TYPE !
	else if (enemySpawnType == 3)
	{
		enemyProfile[0] = 40; // HEALTH
		enemyProfile[1] = 15; // MIN DAMAGE
		enemyProfile[2] = 20; // MAX DAMAGE
		enemyProfile[3] = 3; // ENEMY TYPE
		enemyProfile[4] = 35; // MIN GOLD DROP
		enemyProfile[5] = 50; // MAX GOLD DROP
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