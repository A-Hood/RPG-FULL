#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Header.h"

int* Shop(int* ptrPProfile)
{
	std::string shopItems[4] = { "Health Potions", "NULL", "NULL", "NULL" };
	int shopAmount[4] = { 5, 0, 0, 0 };
	std::string* ptrShopI;
	int* ptrShopA;
	std::string yesOrNo, confirm;
	ptrShopI = shopItems;
	ptrShopA = shopAmount;
	bool valid = false;
	bool completePurchasing = false;
	int itemSelect;
	int optionSelect;

	std::cout << "\n\n";
	Type("=$=$=$=$=$=$= SHOP =$=$=$=$=$=$=", 40);

	std::cout << "\n\n";
	
	ShopOutput(ptrShopI, ptrShopA);

	std::cout << "\n\n\n";

	Type("Would you like to purchase something? ", 30);
	std::cin >> yesOrNo;
	
	// MAKE FULL STRING LOWERCASE
	Lowercase(yesOrNo);

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
						ptrShopA[0] = ptrShopA[0] - 1;
						ptrPProfile[7] = ptrPProfile[7] + 1;
						Type("\n\nPurchased Health Potion! You now have ", 30);
						std::cout << ptrPProfile[7];
						Type(" Health Potions!", 30);
					}
					else if (ptrShopA[0] == 0)
					{
						Type("\n\n*Checks under desk*\nSorry! I'm out of stock! I will be restocking soon.", 30);
					}
				}

				// ITEM 2 PURCHASE
				else if (itemSelect == 2)
				{
					Type("\n\nSorry, we are out of stock on that item!", 40);
				}

				// ITEM 3 PURCHASE
				else if (itemSelect == 3)
				{
					Type("\n\nSorry, we are out of stock on that item!", 40);
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
						ShopOutput(ptrShopI, ptrShopA);
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

				Type("\n\nWhat else do you want to buy?: ", 30);
				std::cin >> itemSelect;
			}

			return ptrPProfile;
		}
		else if (yesOrNo == "no") // IF ANSWER == NO
		{
			Type("\n\nAre you sure you want to exit the shop?: ", 30);
			std::cin >> confirm;
			Lowercase(confirm);
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
		
		Type("Re-enter your correct choice: ", 40);
		std::cin >> yesOrNo;
	}

	return 0;
}

void ShopOutput(std::string* ptrShopI, int* ptrShopA)
{
	// ITEM 1
	Type("#1: ", 50);
	std::cout << ptrShopI[0];
	Type(" |   Amount: ", 50);
	std::cout << ptrShopA[0];
	// ITEM 1 END

	std::cout << "\n\n";

	//ITEM 2
	Type("#2: ", 50);
	std::cout << ptrShopI[1];
	Type(" |   Amount: ", 50);
	std::cout << ptrShopA[1];
	// ITEM 2 END

	std::cout << "\n\n";

	//ITEM 3
	Type("#3: ", 50);
	std::cout << ptrShopI[2];
	Type(" |   Amount: ", 50);
	std::cout << ptrShopA[2];
	// ITEM 3 END

	std::cout << "\n\n";

	//ITEM 4
	Type("#4: ", 50);
	std::cout << ptrShopI[3];
	Type(" |   Amount: ", 50);
	std::cout << ptrShopA[3];
	// ITEM 4 END
}

std::string Lowercase(std::string str) // CONVERT STRING TO LOWERCASE
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}

	return str;
}