/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The header file for the Player class
*******************************************************************************/




#ifndef PLAYER_HPP
#define PLAYER_HPP


class Player
{
private: 
	int health; 


public:
	Player();

	void setHealth(int h); 
	int getHealth(); 

	~Player();
};

#endif
