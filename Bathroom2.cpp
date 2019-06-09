/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The Bathroom2 class inherits from the Space class
*******************************************************************************/


#include "Bathroom2.hpp"
#include "Kitchen.hpp"
#include "Bedroom2.hpp"

#include <iostream>

Bathroom2::Bathroom2()
{
	roomNum = 7;
	
}

std::string Bathroom2::getName()
{
	return name;
}


/*******************************************************************************
** Description:  Moves the character based on the user input received.
** validates the user input and
** points to the surounding available options.
*******************************************************************************/

Space *Bathroom2::move()
{

	int num;
	std::cout << "You are in the Bathroom 2...\n";
	std::cout << "Which direction would you like to move?\n";
	std::cout << "1. Up\n";
	std::cout << "2. Down\n";
	std::cout << "3. Left\n";
	std::cout << "4. Right\n";
	std::cin >> num;

	while (num != 3 && num != 2)
	{
		std::cout << "\nYou cannot go that way!\n";
		std::cout << "Please try again\n";

		std::cin.clear();
		std::cin.ignore();
		std::cin.sync();
		std::cin >> num;
	}


	if (num == 3)
	{
		left = new Kitchen;
		currentSpace = left;
	}
	else if (num == 2)
	{
		bottom = new Bedroom2;
		currentSpace = bottom; 
	}

	return currentSpace;

}



int Bathroom2::specialAbility()
{
	int num = std::rand() % 2 + 1;
	char choice = ' ';


	if (num == 1)
	{
		std::cout << "\n\n\nYou found a pepcid pill on the ground\n";
		std::cout << "Would you like to keep it? y/n \n";
		std::cin >> choice;

		if (choice == 'y')
		{
			std::cout << "\nIt will be stored for later when you need it!\n";
			return 1;
		}

	}

	return 1000;

}



Bathroom2::~Bathroom2()
{
}
