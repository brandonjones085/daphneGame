/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The Garage class inherits from the Space class
*******************************************************************************/


#include "Garage.hpp"
#include "Bathroom.hpp"

#include <iostream>



Garage::Garage()
{
	
	roomNum = 14;
}


std::string Garage::getName()
{
	return name;
}

/*******************************************************************************
** Description:  Moves the character based on the user input received.
** validates the user input and
** points to the surounding available options.
*******************************************************************************/
Space *Garage::move()
{
	
	int num; 
	std::cout << "You are in the Garage...\n";
	std::cout << "Which direction would you like to move?\n"; 
	std::cout << "1. Up\n";
	std::cout << "2. Down\n";
	std::cout << "3. Left\n";
	std::cout << "4. Right\n";
	std::cin >> num; 

	while (num != 1)
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
		delete [] currentSpace; 
		top = new Bathroom();
		currentSpace = top; 

		
	}

	return currentSpace;

}




Garage::~Garage()
{
}
