#include <iostream>
#include <chrono>
#include <thread>

void Type(std::string str, int speed)
{
	for (int i = 0; i < str.size(); i++)
	{
		std::cout << str[i];
		std::this_thread::sleep_for(std::chrono::milliseconds(speed)); // WAIT
	}
}

void JobLBL(std::string job)
{
	std::string str;
	int speed;

	speed = 70;
	str = "Job Type selected: ";
	Type(str, speed);
	speed = 150;
	str = job;
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
	Type(str, speed);
}

void WeaponLBL( std::string weapon)
{
	std::string str;
	int speed;

	speed = 70;
	str = "Weapon selected: ";
	Type(str, speed);
	speed = 150;
	str = weapon;
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
	Type(str, speed);
}