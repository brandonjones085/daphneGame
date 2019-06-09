/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The header file for the Living room class
*******************************************************************************/



#ifndef LIVINGROOM_HPP
#define LIVINGROOM_HPP

#include "Space.hpp"

class LivingRoom : public Space
{
private: 
	std::string name = "Living Room";


public:
	LivingRoom();
	virtual Space *move();
	virtual std::string getName();
	~LivingRoom();
};


#endif

