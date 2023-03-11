#pragma once

int* PlayerProfile(int characterChoice, int playerHealth, int playerMinDamage, int playerMaxDamage, int weaponChoice, int dodgeChance);

std::string* PlayerDetails(int* ptrPProfile);

int* EnemyProfile(int enemySpawnType);

int Fight(int* ptrPProfile, std::string* ptrPDetails, std::string enemyName, int enemySpawnType);

std::string EnemyName(int* ptrEProfile, std::string enemyName);

int* Wand();

int* Daggers();

void Type(std::string str, int speed);

void JobLBL(std::string job);

void WeaponLBL(std::string weapon);

bool DodgeChance(int* ptrPProfile, bool dodge);

int* Heal(int* ptrPProfile);

int* Shop(int* ptrPProfile);

void ShopOutput(std::string* ptrShopI, int* ptrShopA, int* ptrShopC, int* ptrPProfile);

std::string Lowercase(std::string str);

int* EnemyRewards(int* ptrEProfile, int* ptrPProfile);

float* UpgradeCheck(int* ptrPProfile);

int* EnemyLevels(int* ptrPProfile, int* ptrEProfile);