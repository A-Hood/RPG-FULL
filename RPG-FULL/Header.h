#pragma once

int* PlayerProfile(int characterChoice, int playerHealth, int playerMinDamage, int playerMaxDamage, int weaponChoice);

std::string* PlayerDetails(int* ptrPProfile);

int* EnemyProfile(int enemySpawnType);

int Fight(int* ptrPProfile, std::string* ptrPDetails, std::string enemyName, int enemySpawnType);

std::string EnemyName(int* ptrEProfile, std::string enemyName);

int* Wand();

int* Daggers();

void Type(std::string str, int speed);

void JobLBL(std::string job);

void WeaponLBL(std::string weapon);