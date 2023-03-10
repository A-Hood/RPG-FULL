#include <iostream>
#include <thread>
#include <chrono>
#include "Header.h"

// THIS IS FOR WEAPON SPECIFIC ABILITIES

int* Wand() // WAND CAN ATTACK 2-4 TIMES RANDOM NUM
{
	static int wand[2]; // WAND ARRAY SO I CAN RETURN AND STORE MULTIPLE VALUES

	int randAttackAmmount = rand() % (4 - 1 + 1) + 1; // RANDOM ATTACK AMOUNT OF TIMES

	if (randAttackAmmount == 1) // 1 TIME
	{
		wand[0] = 5;
		wand[1] = 1;

		std::cout << "\n\n";
		Type("Pew...!", 30);
		std::cout << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(300)); // WAIT
		Type("Miss...", 60);
		std::cout << "\n";
	}

	else if (randAttackAmmount == 2) // 2 TIMES
	{
		wand[0] = 10;
		wand[1] = 2;
		std::cout << "\n\n";
		for (int i = 0; i < 2; i++)
		{
			Type("Pew...!", 30);
			std::cout << "\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(300)); // WAIT
		}
	}

	else if (randAttackAmmount == 3) // 3 TIMES
	{
		wand[0] = 15;
		wand[1] = 3;
		std::cout << "\n\n";
		for (int i = 0; i < 3; i++)
		{
			Type("Pew...!", 30);
			std::cout << "\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(300)); // WAIT
		}
	}
	
	else if (randAttackAmmount == 4) // 4 TIMES
	{
		wand[0] = 20;
		wand[1] = 4;
		std::cout << "\n\n";
		for (int i = 0; i < 4; i++)
		{
			Type("Pew...!", 30);
			std::cout << "\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(300)); // WAIT
		}
	}

	return wand;
}

int* Daggers() // DAGGERS CAN ATTACK 1-3 TIMES RANDOM NUM
{
	static int daggers[2]; // DAGGERS ARRAY SO I CAN RETURN AND STORE MULTIPLE VALUES

	int randAttackAmmount = rand() % (3 - 1 + 1) + 1; // RANDOM ATTACK AMOUNT
	
	if (randAttackAmmount == 1) // 1 TIME
	{
		daggers[0] = 7;
		daggers[1] = 1;
		std::cout << "\n\n";
		Type("Slash...!", 30);
		std::cout << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(300)); // WAIT
		Type("Miss...", 60);
	}

	else if (randAttackAmmount == 2) // 2 TIMES
	{
		daggers[0] = 14;
		daggers[1] = 2;
		std::cout << "\n\n";
		for (int i = 0; i < 2; i++)
		{
			Type("Slash...!", 30);
			std::cout << "\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(300)); // WAIT
		}
	}

	else if (randAttackAmmount == 3) // 3 TIMES
	{
		daggers[0] = 21;
		daggers[1] = 3;
		std::cout << "\n\n";
		for (int i = 0; i < 3; i++)
		{
			Type("Slash...!", 30);
			std::cout << "\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(300)); // WAIT
		}
	}

	return daggers;
}
