/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The header file for the Game class
*******************************************************************************/



#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Bathroom.hpp"
#include "Bedroom.hpp"
#include "Bedroom2.hpp"
#include "Garage.hpp"
#include "Kitchen.hpp"
#include "Space.hpp"
#include "Bathroom2.hpp"
#include "Bathroom2.hpp"
#include "LivingRoom.hpp"

#include <string>



class Game
{
private:
	int rounds = 1; 
	Player player; 
	Space *currentRoom; 
	int broccoliRoom; 
	bool game; 
	
	struct node
	{
		std::string data; 
		node *next; 
	};

	node *head; 
	node *tail; 

public:
	Game();
	
	void run(); 
	void gameIntro(); 
	void gameMenu(); 
	void showMap(); 
	void runRound(); 
	int getRounds(); 
	void setRounds(int&);
	void setStartRoom(); 
	void broccoli(); 
	void setBroccoliRoom(int); 
	int getBroccoliRoom(); 
	void somethingBad(); 
	Space *getCurrentRoom(); 
	void setCurrentRoom(Space *r); 
	void showList(); 
	void createNode(std::string);
	std::string selectIndex(node *h, int i); 
	int heal(std::string, int); 
	void deleteNode(node *h, int); 
	void validateLinkList(int &, int);
	int getCount(node *h);
	void validateChar(char &); 
	void validateRoomInt(int &); 
	void validateNum(int &); 	
};

#endif
