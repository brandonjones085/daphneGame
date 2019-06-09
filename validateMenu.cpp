
/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The validateMenu function takes in a reference to an int and validates that it
** is an int and between 1 and 2.
*******************************************************************************/



#include "validateMenu.hpp"
#include <iostream>


void validateMenu(int &i)
{
	while (!std::cin || (i < 1 || i > 2))
	{
		std::cin.clear(); 
		std::cin.sync(); 
		std::cin.ignore(); 
		std::cout << "\nInvalid input! Try again: "; 
		std::cin >> i; 
	}
}
