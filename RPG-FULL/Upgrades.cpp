#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Header.h"

float* UpgradeCheck(int* ptrPProfile)
{
	static float upgradeArray[2];

	// WEAPON NOT UPGRADED
	if (ptrPProfile[10] == 1)
	{
		upgradeArray[0] = 1;
	}

	// WEAPON UPGRADE 1
	else if (ptrPProfile[10] == 2)
	{
		upgradeArray[0] = 1.15;
	}

	// WEAPON UPGRADE 2
	else if (ptrPProfile[10] == 3)
	{
		upgradeArray[0] = 1.3; 
	}
	
	// ================================================ ARMOUR

	// ARMOUR NOT UPGRADED
	if (ptrPProfile[10] == 1)
	{
		upgradeArray[1] = 1;
	}

	// ARMOUR UPGRADE 1
	else if (ptrPProfile[10] == 2)
	{
		upgradeArray[1] = 0.8;
	}

	// ARMOUR UPGRADE 2
	else if (ptrPProfile[10] == 3)
	{
		upgradeArray[1] = 0.6; 
	}

	return upgradeArray;
}