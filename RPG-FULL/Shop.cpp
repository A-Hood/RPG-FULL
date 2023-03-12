#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Header.h"

int* Shop(int* ptrPProfile)
{
	std::string shopItems[4] = { "Health Potions", "Weapon Upgrade", "Armour Upgrade", "NULL" };
	int shopAmount[4] = { 2, 0, 0, 0 };
	int shopPrices[4] = { 20, 0, 0 , 0 };
	std::string* ptrShopI;
	int* ptrShopA;
	int* ptrShopC;
	std::string yesOrNo, confirm;
	ptrShopI = shopItems;
	ptrShopA = shopAmount;
	ptrShopC = shopPrices;
	bool valid = false;
	bool completePurchasing = false;
	int itemSelect;
	int optionSelect;


	if (ptrPProfile[10] == 1)
	{
		shopAmount[1] = 1;
		shopPrices[1] = 100;
	}
	else if (ptrPProfile[10] == 2)
	{
		shopAmount[1] = 1;
		shopPrices[1] = 200;
	}


	if (ptrPProfile[11] == 1)
	{
		shopAmount[2] = 1;
		shopPrices[2] = 100;
	}
	else if (ptrPProfile[11] == 2)
	{
		shopAmount[2] = 1;
		shopPrices[2] = 200;
	}

	std::cout << "\n\n";
	Type("=$=$=$=$=$=$= SHOP =$=$=$=$=$=$=", 40);

	std::cout << "\n\n";
	
	ShopOutput(ptrShopI, ptrShopA, shopPrices, ptrPProfile);

	std::cout << "\n\n\n";

	Type("Would you like to purchase something? (Yes or No): ", 30);
	std::cin >> yesOrNo;
	
	// MAKE FULL STRING LOWERCASE
	yesOrNo = Lowercase(yesOrNo);

	//  STAY OR LEAVE SCRIPT
	while (valid == false)
	{
		if (yesOrNo == "yes") // IF ANSWER == YES
		{
			Type("\n\nWhat would you like to purchase? (Enter 0 for shop options!): ", 30);
			std::cin >> itemSelect;
			while (completePurchasing == false)
			{
				// ITEM 1 PURCHASE
				if (itemSelect == 1)
				{
					if (ptrShopA[0] > 0)
					{
						if (ptrPProfile[9] >= shopPrices[0])
						{
							ptrShopA[0] = ptrShopA[0] - 1; // TAKE AWAY FROM SHOP AMOUNT
							ptrPProfile[7] = ptrPProfile[7] + 1; // ADD HEALTH POTION
							ptrPProfile[9] = ptrPProfile[9] - shopPrices[0]; // TAKE AWAY COST
							Type("\n\nPurchased Health Potion! You now have ", 30);
							std::cout << ptrPProfile[7];
							Type(" Health Potions!\n\nYou now have ", 30);
							std::cout << ptrPProfile[9];
							Type(" gold left!", 30);
						}
						else if (ptrPProfile[9] < shopPrices[0])
						{
							Type("\n\nSorry! You cannot afford that item! You only have ", 30);
							std::cout << ptrPProfile[9];
							Type(" gold!", 30);
						}
					}
					else if (ptrShopA[0] == 0)
					{
						Type("\n\n*Checks under desk*\nSorry! I'm out of stock! I will be restocking soon.", 30);
					}
				}

				// ITEM 2 PURCHASE
				else if (itemSelect == 2)
				{
					if (ptrShopA[1] > 0)
					{
						if (ptrPProfile[9] >= shopPrices[1])
						{
							ptrShopA[1] = ptrShopA[1] - 1; // TAKE AWAY FROM SHOP AMOUNT
							ptrPProfile[10] = ptrPProfile[10] + 1; // ADD WEAPON UPGRADE
							ptrPProfile[9] = ptrPProfile[9] - shopPrices[1]; // TAKE AWAY COST
							Type("\n\nPurchased Weapon Upgrade! You now have ", 30);
							std::cout << ptrPProfile[10];
							Type(" Upgrade!\n\nYou now have ", 30);
							std::cout << ptrPProfile[9];
							Type(" gold left!", 30);

						}
						else if (ptrPProfile[9] < shopPrices[1])
						{
							Type("\n\nSorry! You cannot afford that item! You only have ", 30);
							std::cout << ptrPProfile[9];
							Type(" gold!", 30);
						}
					}
					else if (ptrShopA[1] == 0 && ptrPProfile[10] < 3)
					{
						Type("\n\n*Checks under desk*\nSorry! I'm out of stock! I will be restocking soon.", 30);
					}
					else if (ptrShopA[1] == 0 && ptrPProfile[10] == 3)
					{
						Type("\n\nYou are at max weapon upgrade!", 30);
					}
				}

				// ITEM 3 PURCHASE
				else if (itemSelect == 3)
				{
					if (ptrShopA[2] > 0)
					{
						if (ptrPProfile[9] >= shopPrices[2])
						{
							ptrShopA[2] = ptrShopA[2] - 1; // TAKE AWAY FROM SHOP AMOUNT
							ptrPProfile[11] = ptrPProfile[11] + 1; // ADD ARMOU UPGRADE
							ptrPProfile[9] = ptrPProfile[9] - shopPrices[2]; // TAKE AWAY COST
							Type("\n\nPurchased Armour Upgrade! You now have ", 30);
							std::cout << ptrPProfile[10];
							Type(" Upgrade!\n\nYou now have ", 30);
							std::cout << ptrPProfile[9];
							Type(" gold left!", 30);

						}
						else if (ptrPProfile[9] < shopPrices[2])
						{
							Type("\n\nSorry! You cannot afford that item! You only have ", 30);
							std::cout << ptrPProfile[9];
							Type(" gold!", 30);
						}
					}
					else if (ptrShopA[2] == 0 && ptrPProfile[11] < 3)
					{
						Type("\n\n*Checks under desk*\nSorry! I'm out of stock! I will be restocking soon.", 30);
					}
					else if (ptrShopA[2] == 0 && ptrPProfile[11] == 3)
					{
						Type("\n\nYou are at max armour upgrade!", 30);
					}
				}

				// ITEM 4 PURCHASE
				else if (itemSelect == 4)
				{
					Type("\n\nSorry, we are out of stock on that item!", 40);
				}

				else if (itemSelect > 4)
				{
					Type("\n=!=!= ERROR =!=!=\n\nItem choice invalid! ", 40);
				}		
				else if (itemSelect < 0)
				{
					Type("\n=!=!= ERROR =!=!=\n\nItem choice invalid! ", 40);
				}
				else if (itemSelect == 0)
				{
					Type("\n\nHere are the shop options!\n\n#1: Display items again!\n#2: Return to shop!\n#3: Exit shop!\n\nChoice: ", 30);
					std::cin >> optionSelect;
					
					if (optionSelect == 1) // DISPLAY SHOP AGAIN
					{
						Type("\n\n=$=$=$=$=$=$= SHOP =$=$=$=$=$=$=\n\n", 10);
						ShopOutput(ptrShopI, ptrShopA, ptrShopC, ptrPProfile);
						std::cout << "\n";
						itemSelect = 0;
					}

					else if (optionSelect == 2) // RETURN TO SHOP
					{
						Type("\n\nGoing back to shop!", 30);
						itemSelect = 0;
					}

					else if (optionSelect == 3) // EXIT SHOP
					{
						Type("\n\nExiting shop!", 30);
						return ptrPProfile;
					}
				}

				Type("\n\nWhat else do you want to buy? (Enter 0 for shop options!): ", 30);
				std::cin >> itemSelect;
			}

			return ptrPProfile;
		}
		else if (yesOrNo == "no") // IF ANSWER == NO
		{
			Type("\n\nAre you sure you want to exit the shop? (Yes or No): ", 30);
			std::cin >> confirm;
			confirm = Lowercase(confirm);
			if (confirm == "yes")
			{
				Type("\n\nExiting shop!", 30);
				valid = true;
				return ptrPProfile;
			}
			else if (confirm == "no")
			{
				Type("\n\nReturning to shop!\n\n", 30);
			}

		}
		else if (!(yesOrNo == "yes") && !(yesOrNo == "no"))
		{
			Type("\n=!=!= ERROR = !=!=\n\nChoice invalid! ", 40);
		}
		
		Type("Re-enter your correct choice (Yes or No): ", 40);
		std::cin >> yesOrNo;
	}

	return 0;
}

void ShopOutput(std::string* ptrShopI, int* ptrShopA, int* ptrShopC, int* ptrPProfile)
{
	// ITEM 1
	Type("#1: ", 50);
	std::cout << ptrShopI[0];
	Type(" | Cost: ", 50);
	std::cout << ptrShopC[0];
	Type(" | Amount: ", 50);
	std::cout << ptrShopA[0];
	// ITEM 1 END

	std::cout << "\n\n";

	if (ptrPProfile[10] < 3)
	{
		//ITEM 2
		Type("#2: ", 50);
		std::cout << ptrShopI[1] << " " << ptrPProfile[10];
		Type(" | Cost: ", 50);
		std::cout << ptrShopC[1];
		Type(" | Amount: ", 50);
		std::cout << ptrShopA[1];
		// ITEM 2 END
	}
	else if (ptrPProfile[10] == 3)
	{
		//ITEM 2
		Type("#2: ", 50);
		std::cout << "Out Of Stock!";
		Type(" | Cost: ", 50);
		std::cout << ptrShopC[1];
		Type(" | Amount: ", 50);
		std::cout << ptrShopA[1];
		// ITEM 2 END
	}

	std::cout << "\n\n";

	if (ptrPProfile[10] < 3)
	{
		//ITEM 3
		Type("#3: ", 50);
		std::cout << ptrShopI[2] << " " << ptrPProfile[11];
		Type(" | Cost: ", 50);
		std::cout << ptrShopC[2];
		Type(" | Amount: ", 50);
		std::cout << ptrShopA[2];
		// ITEM 3 END
	}
	else if (ptrPProfile[10] == 3)
	{
		//ITEM 3
		Type("#3: ", 50);
		std::cout << "Out Of Stock!";
		Type(" | Cost: ", 50);
		std::cout << ptrShopC[2];
		Type(" | Amount: ", 50);
		std::cout << ptrShopA[2];
		// ITEM 3 END
	}

	std::cout << "\n\n";

	//ITEM 4
	Type("#4: ", 50);
	std::cout << ptrShopI[3];
	Type(" | Cost: ", 50);
	std::cout << ptrShopC[3];
	Type(" | Amount: ", 50);
	std::cout << ptrShopA[3];
	// ITEM 4 END

	Type("\n\nGold Balance: ", 30);
	std::cout << ptrPProfile[9];
}

std::string Lowercase(std::string str) // CONVERT STRING TO LOWERCASE
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}

	return str;
}