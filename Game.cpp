/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The main file where the program is run.
*******************************************************************************/


#include "Game.hpp"
#include "Player.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>


Game::Game()
{
	game = true; 
	head = NULL; 
	tail = NULL; 
}

int Game::getBroccoliRoom()
{
	return broccoliRoom; 
}

/*******************************************************************************
** Description:  This function runs the majority of the game
*******************************************************************************/

void Game::run()
{
	//prints background about game
	gameIntro(); 

	broccoli(); 
	//sets the starting room
	setStartRoom();

	//creates the game loop
	while (game)//game == true
	{
		gameMenu();
		if ( rounds % 6 == 0)
		{
			//places the brocoli in the house somewhere
			broccoli(); 
			
		}

		//checks if the current room is where the brocoli is located
		if (getCurrentRoom()->getRoomNum() == getBroccoliRoom())
		{
			std::cout << "\n\nYOU FOUND THE BROCCOLI\n"; 
			broccoli();
			int h = player.getHealth(); 
			h += 10; 
			player.setHealth(h); 

			//if found, runs the function again
			 

		}

		//looks for special ability
		//if 1 is returned it will be stored
		int special = getCurrentRoom()->specialAbility(); 

		if (special == 1)
		{
			createNode("Pepcid"); 
		}
		else if(special == 3)
		{
			createNode("Multivitamin"); 
		}
		else if (special == 5)
		{
			createNode("Dirty Laundry Location"); 
		}





		//randomly occuring negative health even
		somethingBad(); 


		//health drops below 0
		if (player.getHealth() < 1)
		{
			game = false; 
			std::cout << "\n\nGAME OVER\n\n"; 
		}

		if (player.getHealth() >= 100)
		{
			game = false; 
			std::cout << "\n\n\n\nCONGRATULATIONS\n\n";
			std::cout << "\n\nYou have reached obtained almight maximum pupness\n"; 
			std::cout << "You really are a good pup!"; 

		}



	}

	char option = ' ';
	std::cout << "\nWould you like to player again? y/n "; 
	std::cin >> option; 

	//validation
	validateChar(option); 

	if (option == 'y')
	{
		game = true; 
		run(); 
		
	}


	std::cout << "\n\n\nGOODBYE!!!\n"; 
}



/*******************************************************************************
** Description:  Creates random number between 1 and 5. 
** The random int causes negative health events to occur
*******************************************************************************/
void Game::somethingBad()
{
int num = std::rand() % 6 + 1;
	


	char choice = ' '; 

	//1 was returned
	if (num == 1)
	{
		//found a turd
		std::cout << "\n\n\nYou went off in the corner and pooped, then ate all of it! -15 health\n"; 
		
		int damage = 15; 
		std::cout << "\n\nWould you like to check if you have anything that can help?\n"; 
		std::cin >> choice; 

		//validation
		validateChar(choice); 

		if (choice == 'y')
		{
			showList(); 

			if (head != NULL)
			{
				int n; 

				//finds the length of the linked list
				int length = getCount(head); 


				std::cout << "\nEnter the index number for your selection: "; 
				std::cin >> n;
				validateLinkList(n, length); 

				//uses the user input to find the index and damage
				damage = heal(selectIndex(head, n), damage); 


				//checks for multivitamin
				if (damage == 30)
				{
					int p = player.getHealth();
					p += 30; 
					player.setHealth(p); 
					damage = 15; 
				}
				//dirty clothes
				else if (damage == 40)
				{
					int p = player.getHealth();
					p += 40;
					player.setHealth(p);
					damage = 15;
				}

				//removes the node
				deleteNode(head, n); 
			}

		}

		int h = player.getHealth();
		

		h -= damage;

		
		player.setHealth(h); 

	}

	//2 was returned
	else if (num == 2)
	{
		//found a dead worm
		std::cout << "\n\n\nYou found a dead bug on the ground and ate it! -10 health\n";
		
		int damage = 10; 

		std::cout << "\n\nWould you like to check if you have anything that can help?\n";
		std::cin >> choice;

		//validation
		validateChar(choice);


		if (choice == 'y')
		{
			showList();

			if (head != NULL)
			{
				int n;

				//finds the length of the linked list
				int length = getCount(head);

				std::cout << "\nEnter the index number for your selection: ";
				std::cin >> n;
				validateLinkList(n, length); 

				//uses the user input to find the index and damage
				damage = heal(selectIndex(head, n), damage);

				//checks for multivitamin
				if (damage == 30)
				{
					int p = player.getHealth();
					p += 30;
					player.setHealth(p);
					damage = 10; 
				}
				//dirty clothes
				else if (damage == 40)
				{
					int p = player.getHealth();
					p += 40;
					player.setHealth(p);
					damage = 10;
				}

					

				//removes the node
				deleteNode(head, n);
			}

		}


		int h = player.getHealth();

		h -= damage;
		player.setHealth(h);

	}
	//3 was returned
	else if (num == 3)
	{
		//found a random piece of hair
		std::cout << "\n\n\nYou a piece of your wifes hair on the ground and ate it! -5 health\n";
		
		int damage = 5; 

		std::cout << "\n\nWould you like to check if you have anything that can help?\n";
		std::cin >> choice;

		//validation
		validateChar(choice);

		if (choice == 'y')
		{
			showList();

			if (head != NULL)
			{
				int n;

				//finds the length of the linked list
				int length = getCount(head);


				std::cout << "\nEnter the index number for your selection: ";
				std::cin >> n;
				validateLinkList(n, length); 

				//uses the user input to find the index and damage
				damage = heal(selectIndex(head, n), damage);

				//checks for multivitamin
				if (damage == 30)
				{
					int p = player.getHealth();
					p += 30;
					player.setHealth(p);
					damage = 5; 
				}
				//dirty clothes
				else if (damage == 40)
				{
					int p = player.getHealth();
					p += 40;
					player.setHealth(p);
					damage = 5;
				}

				//removes the node
				deleteNode(head, n);
			}

		}

		int h = player.getHealth();

		h -= damage; 
		player.setHealth(5); 
	}


}


/*******************************************************************************
** Description:  Takes in the node head for reference and an index value
** it is used to search the linked list and select by index.
*******************************************************************************/
std::string Game::selectIndex(node *head, int i)
{
	node *current = head; 
	int count = 0; 

	while (current != NULL)
	{
		if (count == i)
		{
			return (current->data);
		}
		count++; 
		current = current->next;
	}

	return " "; 

}


/*******************************************************************************
** Description:  takes in the head of the linked list and the index
** it removes that number index from the linked list
*******************************************************************************/
void Game::deleteNode(node *h, int i)
{
	if (h == NULL)
	{
		std::cout << "\nNothing can be deleted!\n";
	}
	else
	{
		node *temp = head;

		if (i == 0)
		{
			head = temp->next;
			free(temp);
			return;
		}

		for (int j = 0; temp != NULL && j < i - 1; j++)
		{
			temp = temp->next;
		}

		if (temp == NULL || temp->next == NULL)
		{
			return;
		}


		node *next = temp->next->next;

		free(temp->next); 

		temp->next = next; 

	}

}

void Game::setBroccoliRoom(int i)
{
	this->broccoliRoom = i; 
}


/*******************************************************************************
** Description: Background behind the game. 
** Only run once in the beginning
*******************************************************************************/
void Game::gameIntro()
{
	std::cout << "\nWelcome to the chihuahua house\n\n"; 
	std::cout << "\n\nIt's a big scary world for a small chihuahua named Daphne\n"; 
	std::cout << "\nYou are in a house with seven rooms\n"; 
	std::cout << "2 Bathroom\n"; 
	std::cout << "2 Bedrooms\n"; 
	std::cout << "1 Living room\n"; 
	std::cout << "1 Kitchen\n"; 
	std::cout << "1 Garage\n"; 
	std::cout << "\n\nYou are always hungry and looking for food.\nPlus you will eat anything you find on the ground.\nEVEN if it's bad for your health\n"; 
	std::cout << "Sometimes a piece of broccoli appears in one of the rooms and your goal is to reach that room\n"; 
	std::cout << "\nHowever, you are easily distracted.\nSometimes eat things that will damage your health while trying to reach the broccoli\n"; 
	std::cout << "Your goal is to eat 10 pieces of broccoli\n";
	std::cout << "Each piece of broccoli is 10 points\n"; 
	std::cout << "Eating something bad for you will decrease your health\n"; 
	std::cout << "Each room has it's own special qualities.\n"; 
	std::cout << "Some rooms will randomly contain medicine which you can hold onto to help your health when you eat something bad\n"; 
	std::cout << "GOOD LUCK!\n\n"; 
	std::cout << "Game based on actual events!";


}


/*******************************************************************************
** Description:  Function runs every loop. 
** Asks player if they'd like to see the map or move to another room
*******************************************************************************/
void Game::gameMenu()
{
	std::cout << "You are in the " << currentRoom->getName() << std::endl;
	std::cout << "Players health: " << player.getHealth() << std::endl; 
	int num; 
	std::cout << "what would you like to do next?\n";
	std::cout << "1. Show map\n"; 
	std::cout << "2. Change room\n"; 
	std::cout << "3. Show what you're carrying\n";

	std::cin >> num; 

	//validation
	validateNum(num); 

	if (num == 1)
	{
		

		//prints the map
		showMap(); 

		//runs function again
		gameMenu(); 
	}
	else if (num == 2)
	{
		//change room
		runRound(); 
	}
	else if (num == 3)
	{
		showList(); 

		//runs function again
		gameMenu(); 
	}

}


int Game::getRounds()
{
	return rounds; 
}

void Game::setRounds(int &i)
{
	this->rounds = i; 
}


 Space *Game::getCurrentRoom()
{
	 return currentRoom; 
}


void Game::setCurrentRoom(Space *r)
{
	this->currentRoom = r; 

}

/*******************************************************************************
** Description:  creates a random int between 14 and 20. 
** The int returned is used to place the broccoli randomly in the house 
*******************************************************************************/

void Game::broccoli()
{
	 
	int num = std::rand() % (20 - 14) + 14;

	//makes sure it's not in the current room of the player

	if (rounds >= 2)
	{
		while (num == currentRoom->getRoomNum())
		{
			num = std::rand() % (20 - 14) + 14;
		}

	}
	

	if (num == 14)
	{
		//garage
		std::cout << "\n\n-----------------The broccoli is in the garage--------------------\n";
		setBroccoliRoom(14); 
	}
	else if (num == 15)
	{
		//bathroom1
		std::cout << "\n\n-----------------The broccoli is in bathroom 1--------------------\n";
		setBroccoliRoom(15);
	}
	else if (num == 16)
	{
		//bedroom1
		std::cout << "\n\n-----------------The broccoli is in bedroom 1--------------------\n";
		setBroccoliRoom(16);
	}
	else if (num == 17)
	{
		//kitchen
		std::cout << "\n\n-----------------The broccoli is in the kitchen--------------------\n";
		setBroccoliRoom(17);
	}
	else if (num == 18)
	{
		//living room
		std::cout << "\n\n-----------------The broccoli is in the living room------------------\n";
		setBroccoliRoom(18);
	}
	else if (num == 19)
	{
		//bedroom2
		std::cout << "\n\n-----------------The broccoli is in bedroom 2--------------------\n";
		setBroccoliRoom(19);
	}
	else if (num == 20)
	{
		//bathroom2
		std::cout << "\n\n-----------------The broccoli is in bathroom 2--------------------\n";
		setBroccoliRoom(20);
	}


}



/*******************************************************************************
** Description:  This is run every time the place decices to move rooms
*******************************************************************************/
void Game::runRound()
{
	Space *s = getCurrentRoom(); 

	
	int r = getRounds(); 

	std::cout << "Rounds #" << r << std::endl;
	
	  
	setCurrentRoom(s->move());

	std::cout << "\n\n\nYou are moving into the " << getCurrentRoom()->getName() << std::endl; 

	r += 1; 
	setRounds(r); 

}


/*******************************************************************************
** Description:  Prints the map of the house
*******************************************************************************/
void Game::showMap()
{
	std::cout << "__________________________________________________________\n"; 
	std::cout << "|               |                     |                   |\n";
	std::cout << "|  Bedroom 1    |     Kitchen         |     Bathroom 2    |\n";
	std::cout << "|               |                     |                   |\n";
	std::cout << "|_______________|_____________________|___________________|\n";
	std::cout << "|               |                     |                   |\n";
	std::cout << "|  Bathroom 1   |     Living Room     |     Bedroom 2     |\n";
	std::cout << "|               |                     |                   |\n";
	std::cout << "|_______________|_____________________|___________________|\n";
	std::cout << "|               |\n";
	std::cout << "|   Garage      |\n";
	std::cout << "|_______________|\n";
}


/*******************************************************************************
** Description: creates a random int and uses that value to place the 
** player randomly within the house somewhere
*******************************************************************************/
void Game::setStartRoom()
{

	int num = std::rand() % 7 + 1; 

	if (num == 1)
	{
		//garage
		std::cout << "\n\nYou are starting in the Garage!\n";
		setCurrentRoom(new Garage()); 
		
	}
	else if (num == 2)
	{
		//kitchen
		std::cout << "\n\nYou are starting in the Kitchen!\n";
		setCurrentRoom(new Kitchen());
		
	}
	else if (num == 3)
	{
		//bathroom 1
		std::cout << "\n\nYou are starting in the Bathroom 1!\n";
		setCurrentRoom(new Bathroom());
		
	}
	else if (num == 4)
	{
		//bathroom 2
		std::cout << "\n\nYou are starting in the Bathroom 2!\n";
		setCurrentRoom(new Bathroom2());
		
	}
	else if (num == 5)
	{
		//bedroom 1
		std::cout << "\n\nYou are starting in Bedroom 1!\n";
		setCurrentRoom(new Bedroom());
		
	}

	else if (num == 6)
	{
		//bedroom 2
		std::cout << "\n\nYou are starting in Bedroom 2!\n";
		setCurrentRoom(new Bedroom2());
	
	}
	else
	{
		//living room; 
		std::cout << "\n\nYou are starting in the Living Room!\n";
		setCurrentRoom(new LivingRoom());
		
	}

}

/*******************************************************************************
** Description:  Takes in a string and adds it to the linked list
*******************************************************************************/
void Game::createNode(std::string s)
{
	node *temp = new node; 
	temp->data = s; 
	temp->next = NULL; 

	if (head == NULL)
	{
		head = temp; 
		tail = temp; 
		temp = NULL; 
	}
	else
	{
		tail->next = temp; 
		tail = temp; 
	}


}


/*******************************************************************************
** Description:  Displays the linked list 
*******************************************************************************/
void Game::showList()
{
	node *temp = new node; 
	temp = head; 
	if (head == NULL)
	{
		std::cout << "\n\n\nYou are carrying nothing!\n"; 
	}



	while (temp != NULL)
	{
		std::cout << temp->data << ", "; 
		temp = temp->next; 
	}

}

/*******************************************************************************
** Description:  used with the linked list. 
** takes in a string and an int
** performs a type of healing on the players health
*******************************************************************************/
int Game::heal(std::string s, int d)
{
	if (s == "Pepcid")
	{
		d = 0; 
		
		std::cout << "\nThe pepcid was helpful\n";
		std::cout << "\nYou received no damage!\n"; 
		std::cout << "\nAll little dogs need a little help sometimes!\n\n";
		
	}
	else if (s == "Multivitamin")
	{
		std::cout << "\nMultivitamins are healthy for pups too\n"; 
		std::cout << "\nSit back and let the healing begin!\n"; 
		d = 30; 
	}
	else if (s == "Dirty Laundry Location")
	{
		std::cout << "\nSometimes all a pup needs is a long nap in a dirty pile of clothes\n";
		std::cout << "\nTake a load off and burrow into the smelly pile of joy!\n";
		d = 40;
	}

	return d; 
}

/*******************************************************************************
** Description:  Finds the length of the linked list
** Takes in a pointer to the node head
*******************************************************************************/
int Game::getCount(node *h)
{
	int count = 0; 
	node *current = h; 

	while(current != NULL)
	{
		count++; 
		current = current->next; 
	}
	return count; 

}

/*******************************************************************************
** Description:  Takes in the int for validation and the 
** length of the linked list
** if it is not an int, below 0, or greater than ll it will loop
*******************************************************************************/
void Game::validateLinkList(int &i, int ll)
{
	
	while (!std::cin || (i < 0 || i > ll))
	{
		std::cout << "\nEnter a number within the range\n";
		std::cout << "Start at index 0!\n";
		std::cout << "Try again: ";
		std::cin >> i;


	}

	
}

/*******************************************************************************
** Description:  Takes a reference to an char and validates it's 
** equal to y or n
*******************************************************************************/

void Game::validateChar(char &c)
{
	c = tolower(c);

	while (c != 'y' && c != 'n')
	{
		std::cout << "\nInvalid input! Try again: "; 
		std::cin >> c; 

		c = tolower(c); 
	}
}

/*******************************************************************************
** Description:  Takes a reference to an int and validates it's
**between 1 and 7
*******************************************************************************/
void Game::validateRoomInt(int &i)
{
	while (!std::cin || (i < 1 || i > 7))
	{
		std::cout << "\nEnter a number between 1 and 7\n";
	
		std::cout << "Try again: ";
		std::cin >> i;


	}
}

/*******************************************************************************
** Description:  Takes a reference to an int and validates it's
**between 1 and 3
*******************************************************************************/
void Game::validateNum(int &i)
{
	while (!std::cin || (i < 1 || i > 3))
	{
		std::cout << "\nEnter a number between 1 and 3\n";

		std::cout << "Try again: ";
		std::cin >> i;


	}
}
