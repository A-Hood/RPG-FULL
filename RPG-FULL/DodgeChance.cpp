#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Header.h"

bool DodgeChance(int* ptrPProfile, bool dodge)
{
	int dodgeRand;

	dodgeRand = rand() % (ptrPProfile[6] - 1 + 1) + 1;

	if (dodgeRand == 1)
	{
		dodge = true;
		return dodge;
	}
	else
	{
		dodge = false;
		return dodge;
	}
}