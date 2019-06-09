/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The LivingRoom class inherits from the Space class
*******************************************************************************/


#include "LivingRoom.hpp"
#include "Kitchen.hpp"
#include "Bedroom2.hpp"
#include "Bathroom.hpp"

#include <iostream>


LivingRoom::LivingRoom()
{
	roomNum = 18;
}


std::string LivingRoom::getName()
{
	return name;
}

/*******************************************************************************
** Description:  Moves the character based on the user input received.
** validates the user input and
** points to the surounding available options.
*******************************************************************************/
Space *LivingRoom::move()
{

	int num;
	std::cout << "\nYou are in the Living Room" << std::endl; 
	std::cout << "Which direction would you like to move?\n";
	std::cout << "1. Up\n";
	std::cout << "2. Down\n";
	std::cout << "3. Left\n";
	std::cout << "4. Right\n";
	std::cin >> num;

	while (num != 1 && num != 3 && num != 4)
	{
		std::cout << "\nYou cannot go that way!\n";
		std::cout << "Please try again\n";

		std::cin.clear();
		std::cin.ignore();
		std::cin.sync();
		std::cin >> num;
	}


	if (num == 1)
	{
		top = new Kitchen();
		currentSpace = top;
	}
	else if (num == 3)
	{
		left = new Bathroom();
		currentSpace = left;
	}
	else if (num == 4)
	{
		right = new Bedroom2();
		currentSpace = right; 
	}


	return currentSpace;

}


LivingRoom::~LivingRoom()
{
}
