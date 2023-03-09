#include <iostream>
#include <cstdlib>
#include "Header.h"

// PLAYER PROFILE IS: HEALTH, MINDAMAGE, MAXDAMAGE, CHARACTERSELECTION, WEAPONSELECTION!
// ENEMY PROFILE IS: HEALTH, MINDAMAGE, MAXDAMAGE, TYPE!

// ENEMY PROFILE OUTPUT: std::cout << "\nEnemy Health: " << ptrEDamage[0] << "\nEnemy Minimum Damage: " << ptrEDamage[1] << "\nEnemy Maximum Damage: " << ptrEDamage[2] << std::endl;
int enemySpawnType, enemyHealth, enemyMinDamage, enemyMaxDamage; // ENEMY GLOBALS
int playerHealth, playerMinDamage, playerMaxDamage, characterChoice, weaponChoice; // PLAYER GLOBALS
std::string username, enemyName;

int main()
{
	srand(time(NULL)); // RANDOM NUMBER SEED

	// DECLARING PTRs FOR ARRAYS
	int* ptrPProfile;// PTR FOR PlayerProfile
	std::string* ptrPDetails; // PTR FOR PlayerDetails
	// DECLARING PTRs END

	// PLAYER PROFILE
	ptrPProfile = PlayerProfile(characterChoice, playerHealth, playerMinDamage, playerMaxDamage); // INT PLAYER HEALTH [0] 
	ptrPDetails = PlayerDetails(ptrPProfile); // STRING ARRAY FOR 'JOB NAME' ([0]) AND 'WEAPON NAME' ([1])
	// PLAYER PROFILE END

	// FOR DEBUG!: std::cout << "\n\n=======================================\n\nDEBUG!!!\n\nArray PlayerProfile: " << ptrPProfile[0] << " " << ptrPProfile[1] << " " << ptrPProfile[2] << " " << ptrPProfile[3] << " " << ptrPProfile[4] << "\n\nArray PlayerDetails: " << ptrPDetails[0] << " " << ptrPDetails[1] << "\n\nEnemy Name: " << enemyName << "\n\n======================================\n";

	while (ptrPProfile[0] > 0)
	{
		ptrPProfile[0] = Fight(ptrPProfile, ptrPDetails, enemyName, enemySpawnType);
	}


	std::cin.get();
}