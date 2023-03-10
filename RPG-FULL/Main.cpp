#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Header.h"

// PLAYER PROFILE IS: HEALTH, MINDAMAGE, MAXDAMAGE, CHARACTERSELECTION, WEAPONSELECTION, ENEMYKILLS, DODGECHANCE, HEALTHPOTIONAMOUNT, MAXIMUM HEALTH!
// ENEMY PROFILE IS: HEALTH, MINDAMAGE, MAXDAMAGE, TYPE!

// ENEMY PROFILE OUTPUT: std::cout << "\nEnemy Health: " << ptrEDamage[0] << "\nEnemy Minimum Damage: " << ptrEDamage[1] << "\nEnemy Maximum Damage: " << ptrEDamage[2] << std::endl;
int enemySpawnType, enemyHealth, enemyMinDamage, enemyMaxDamage; // ENEMY GLOBALS
int playerHealth, playerMinDamage, playerMaxDamage, characterChoice, weaponChoice, dodgeChance; // PLAYER GLOBALS
std::string username, enemyName;

int main()
{
	srand(time(NULL)); // RANDOM NUMBER SEED

	// DECLARING PTRs FOR ARRAYS
	int* ptrPProfile;// PTR FOR PlayerProfile
	std::string* ptrPDetails; // PTR FOR PlayerDetails
	// DECLARING PTRs END

	std::cout << "========================================================\n\n";
	Type("WELCOME TO [insert whatever generic rpg name] RPG!", 15); 
	std::cout << "\n\n========================================================\n\n";
	Type("Each class has different weapons with different stats.\nSome have a lot of power while others have lower power while attacking more times!\nFeel free to experiment!\n\n", 15);
	std::this_thread::sleep_for(std::chrono::seconds(2));

	// PLAYER PROFILE
	ptrPProfile = PlayerProfile(characterChoice, playerHealth, playerMinDamage, playerMaxDamage, weaponChoice, dodgeChance); // INT PLAYER HEALTH [0] 
	ptrPDetails = PlayerDetails(ptrPProfile); // STRING ARRAY FOR 'JOB NAME' ([0]) AND 'WEAPON NAME' ([1])
	// PLAYER PROFILE END

	// FOR DEBUG!: std::cout << "\n\n=======================================\n\nDEBUG!!!\n\nArray PlayerProfile: " << ptrPProfile[0] << " " << ptrPProfile[1] << " " << ptrPProfile[2] << " " << ptrPProfile[3] << " " << ptrPProfile[4] << "\n\nArray PlayerDetails: " << ptrPDetails[0] << " " << ptrPDetails[1] << "\n\nEnemy Name: " << enemyName << "\n\n======================================\n";

	while (ptrPProfile[0] > 0)
	{
		ptrPProfile[0] = Fight(ptrPProfile, ptrPDetails, enemyName, enemySpawnType);
	}


	std::cin.get();
}