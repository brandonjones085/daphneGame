/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The Bedroom2 class inherits from the Space class
*******************************************************************************/


#include "Bedroom2.hpp"
#include "Bathroom2.hpp"
#include "LivingRoom.hpp"

#include <iostream>

Bedroom2::Bedroom2()
{
	roomNum = 19;

}


std::string Bedroom2::getName()
{
	return name;
}

/*******************************************************************************
** Description:  Moves the character based on the user input received.
** validates the user input and
** points to the surounding available options.
*******************************************************************************/

Space *Bedroom2::move()
{

	int num;
	std::cout << "You are in the Bedroom 2...\n";
	std::cout << "Which direction would you like to move?\n";
	std::cout << "1. Up\n";
	std::cout << "2. Down\n";
	std::cout << "3. Left\n";
	std::cout << "4. Right\n";
	std::cin >> num;

	while (num == 2 && num == 4)
	{
		std::cout << "\nYou cannot go that way!\n";
		std::cout << "Please try again: ";
		std::cin >> num;
		std::cin.clear();
		std::cin.ignore();
		std::cin.sync();
		move();

	}

	if (num == 1)
	{
		top = new Bathroom2();
		currentSpace = top;


	}
	else if (num == 3)
	{
		left = new LivingRoom();
		currentSpace = left;

	}

	return currentSpace;
}


int Bedroom2::specialAbility()
{
	int num = std::rand() % (6 - 5) + 5;
	char choice = ' ';


	if (num == 5)
	{
		std::cout << "\n\nYou found a dirty pile of laundry\n\n";
		std::cout << "These are the best places to burrow and sleep for hours\n\n";
		std::cout << "\nYou are easily distracted though and could easily forget the location\n";
		std::cout << "\nIt will give your health a boost +40\n";
		std::cout << "Would you like to remeber the location for later? y/n \n";

		std::cin >> choice;

		if (choice == 'y')
		{
			std::cout << "\nIt will be stored for later when you need it!\n";
			return 5;
		}

	}

	return 1000;
}


Bedroom2::~Bedroom2()
{
}
