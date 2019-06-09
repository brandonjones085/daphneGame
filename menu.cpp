/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The menu function asks for user input and returns an int
** based on the users decision. 
*******************************************************************************/


#include "menu.hpp"
#include "validateMenu.hpp"

#include <iostream>


int menu()
{
	int num; 
	std::cout << "\n\nWhat would you like to do? \n";
	std::cout << "\n1. Play\n"; 
	std::cout << "2. Exit\n"; 
	std::cin >> num; 
	validateMenu(num);

	return num; 

}
