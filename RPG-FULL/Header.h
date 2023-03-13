#pragma once

int* PlayerProfile(int characterChoice, int playerHealth, int playerMinDamage, int playerMaxDamage, int weaponChoice, int dodgeChance);

std::string* PlayerDetails(int* ptrPProfile);

int* EnemyProfile(int enemySpawnType, int* ptrPProfile);

int Fight(int* ptrPProfile, std::string* ptrPDetails, std::string enemyName, int enemySpawnType);

std::string EnemyName(int* ptrEProfile, std::string enemyName, int* ptrPProfile);

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

int* PlayerAttack(int* ptrPProfile, std::string* ptrPDetails, int* ptrEProfile, float* ptrUpgrades, std::string enemyName, int attackChoice);

// CHEST TYPES

int* ChestDrop(int* ptrPProfile);

int* CommonChest(int* ptrPProfile, int chestType, int chestValue);
int* RareChest(int* ptrPProfile, int chestType, int chestValue);
int* LegendaryChest(int* ptrPProfile, int chestType, int chestValue);
int* MythicalChest(int* ptrPProfile, int chestType, int chestValue);

// BOSS FUNCTIONS

int* Boss1(int* ptrPProfile, float* ptrUpgrades, std::string* ptrPDetails);
int* PlayerAttackBoss(int* ptrPProfile, int* ptrBossOne, std::string* ptrPDetails, float* ptrUpgrades);
int* BossRewards(int* ptrPProfile);
int* BossOneAttack(int* ptrPProfile, int* ptrBossOne, float* ptrUpgrades, bool dodge, bool failDodge);

int* ThiefFight(int* ptrPProfile, std::string* ptrPDetails, int* ptrEProfile, float* ptrUpgrades, std::string enemyName, int attackChoice);