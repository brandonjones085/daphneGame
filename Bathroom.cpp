/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The Bathroom class inherits from the Space class
*******************************************************************************/


#include "Bathroom.hpp"

#include <iostream>

//CONSTRUCTOR
Bathroom::Bathroom()
{
	roomNum = 15; 

}

//inherits from space//returns a name
std::string Bathroom::getName()
{
	return name; 
}


/*******************************************************************************
** Description:  creates a the ability for the user to not have damage. 
*******************************************************************************/
int Bathroom::specialAbility()
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


/*******************************************************************************
** Description:  Moves the character based on the user input received. 
** validates the user input and
** points to the surounding available options. 
*******************************************************************************/
Space *Bathroom::move()
{

	int num;
	std::cout << "You are in the Bathroom 1...\n";
	std::cout << "Which direction would you like to move?\n";
	std::cout << "1. Up\n";
	std::cout << "2. Down\n";
	std::cout << "3. Left\n";
	std::cout << "4. Right\n";
	std::cin >> num;


	//validation 
	while (num != 1 && num != 2 && num != 4)
	{
		std::cout << "\nYou cannot go that way!\n"; 
		std::cout << "Please try again: "; 
		std::cin >> num;
		std::cin.clear();
		std::cin.ignore();
		std::cin.sync();
	
	}

	// move to Bedroom
	if (num == 1)
	{
		delete [] currentSpace; 
		top = new Bedroom();
		currentSpace = top; 
	
	}
	//move to garage
	else if(num == 2)
	{
		delete [] currentSpace; 
		bottom = new Garage();
		currentSpace = bottom; 
		
	}
	//move to living room
	else if (num == 4)
	{
		delete [] currentSpace; 
		right = new LivingRoom(); 
		currentSpace = right; 
		
	}
	return currentSpace; 
}



Bathroom::~Bathroom()
{
}
