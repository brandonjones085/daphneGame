/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The main file where the program is run.
*******************************************************************************/


#include "Player.hpp"



Player::Player()
{
	this->health = 50; 
}


void Player::setHealth(int h)
{
	this->health = h; 
}

int Player::getHealth()
{
	return health; 
}





Player::~Player()
{
}
