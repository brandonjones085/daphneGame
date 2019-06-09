/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The main file where the program is run. 
*******************************************************************************/



#include "menu.hpp"
#include "Game.hpp"


#include <iostream>


int main()
{

	Game g; 
	int num = menu(); 

	if (num == 1)
	{
		//play the game
		g.run(); 

	}
	else
	{
		//exit; 
		std::cout << "\n\n\n__________________Goodbye!_______________________\n\n\n"; 
		exit(0); 
	}

	return 0; 
}

