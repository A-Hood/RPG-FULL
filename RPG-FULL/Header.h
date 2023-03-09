#pragma once

int* PlayerProfile(int characterChoice, int playerHealth, int playerMinDamage, int playerMaxDamage);

std::string* PlayerDetails(int* ptrPProfile);

int* EnemyProfile(int enemySpawnType);

int Fight(int* ptrPProfile, std::string enemyName, int enemySpawnType);

std::string EnemyName(int* ptrEProfile, std::string enemyName);


