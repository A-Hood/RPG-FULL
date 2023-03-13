#include <iostream>
#include "Header.h"

int* EnemyProfile(int enemySpawnType, int* ptrPProfile)
{
	if (ptrPProfile[12] == 0) // IF BEFORE FIRST BOSS
	{
		static int enemyProfile[6];

		// BANDIT ENEMY TYPE !
		if (enemySpawnType >= 1 && enemySpawnType <= 50) // 50% CHANCE OF BANDIT
		{
			enemyProfile[0] = 15; // HEALTH
			enemyProfile[1] = 5; // MIN DAMAGE
			enemyProfile[2] = 8; // MAX DAMAGE
			enemyProfile[3] = 1; // ENEMY TYPE
			enemyProfile[4] = 20; // MIN GOLD DROP
			enemyProfile[5] = 30; // MAX GOLD DROP
		}

		// MERCANARY ENEMY TYPE !
		else if (enemySpawnType >= 51 && enemySpawnType <= 90) // 40% CHANCE OF MERCANARY
		{
			enemyProfile[0] = 25; // HEALTH
			enemyProfile[1] = 10; // MIN DAMAGE
			enemyProfile[2] = 15; // MAX DAMAGE
			enemyProfile[3] = 2; // ENEMY TYPE
			enemyProfile[4] = 25; // MIN GOLD DROP
			enemyProfile[5] = 40; // MAX GOLD DROP
		}

		// TROLL ENEMY TYPE !
		else if (enemySpawnType >= 91 && enemySpawnType <= 100) // 10% CHANCE OF TROLL
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

	// =========================================================================================

	else if (ptrPProfile[12] == 1) // IF AFTER FIRST BOSS
	{
		static int enemyProfile[8];

		// SKELETON ENEMY TYPE !
		if (enemySpawnType >= 1 && enemySpawnType <= 40) // 40% CHANCE OF SKELETON
		{
			enemyProfile[0] = 15; // HEALTH
			enemyProfile[1] = 5; // MIN DAMAGE
			enemyProfile[2] = 8; // MAX DAMAGE
			enemyProfile[3] = 1; // ENEMY TYPE
			enemyProfile[4] = 20; // MIN GOLD DROP
			enemyProfile[5] = 30; // MAX GOLD DROP
			enemyProfile[6] = 0; // MIN CASH STEAL (THIEF ONLY)
			enemyProfile[7] = 0; // MAX CASH STEAL (THIEF ONLY)
		}

		// SPIDER ENEMY TYPE !
		else if (enemySpawnType >= 41 && enemySpawnType <= 70) // 30% CHANCE OF SPIDER
		{
			enemyProfile[0] = 20; // HEALTH
			enemyProfile[1] = 10; // MIN DAMAGE
			enemyProfile[2] = 15; // MAX DAMAGE
			enemyProfile[3] = 2; // ENEMY TYPE
			enemyProfile[4] = 20; // MIN GOLD DROP
			enemyProfile[5] = 30; // MAX GOLD DROP
			enemyProfile[6] = 0; // MIN CASH STEAL (THIEF ONLY)
			enemyProfile[7] = 0; // MAX CASH STEAL (THIEF ONLY)
		}

		// MINOTAUR ENEMY TYPE !
		else if (enemySpawnType >= 71 && enemySpawnType <= 80) // 10% CHANCE OF MINOTAUR
		{
			enemyProfile[0] = 30; // HEALTH
			enemyProfile[1] = 15; // MIN DAMAGE
			enemyProfile[2] = 20; // MAX DAMAGE
			enemyProfile[3] = 3; // ENEMY TYPE
			enemyProfile[4] = 20; // MIN GOLD DROP
			enemyProfile[5] = 30; // MAX GOLD DROP
			enemyProfile[6] = 0; // MIN CASH STEAL (THIEF ONLY)
			enemyProfile[7] = 0; // MAX CASH STEAL (THIEF ONLY)
		}
		
		// THIEF ENEMY TYPE !
		if (enemySpawnType >= 81 && enemySpawnType <= 100) // 20% CHANCE OF THIEF // 81
		{
			enemyProfile[0] = 50; // HEALTH
			enemyProfile[1] = 5; // MIN DAMAGE
			enemyProfile[2] = 8; // MAX DAMAGE
			enemyProfile[3] = 4; // ENEMY TYPE
			enemyProfile[4] = 20; // MIN GOLD DROP
			enemyProfile[5] = 30; // MAX GOLD DROP
			enemyProfile[6] = 5; // MIN CASH STEAL (THIEF ONLY)
			enemyProfile[7] = 15; // MAX CASH STEAL (THIEF ONLY)
		}

		return enemyProfile;
	}

}

std::string EnemyName(int* ptrEProfile, std::string enemyName, int* ptrPProfile)
{

	if (ptrPProfile[12] == 0) // IF BEFORE FIRST BOSS
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
	}

	else if (ptrPProfile[12] == 1) // IF AFTER FIRST BOSS
	{
		if (ptrEProfile[3] == 1)
		{
			enemyName = "skeleton";
		}
		else if (ptrEProfile[3] == 2)
		{
			enemyName = "spider";
		}
		else if (ptrEProfile[3] == 3)
		{
			enemyName = "minotaur";
		}
		else if (ptrEProfile[3] == 4)
		{
			enemyName = "thief";
		}
	}

	return enemyName;
}