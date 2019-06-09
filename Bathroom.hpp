/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The header file for the bathroom class
*******************************************************************************/



#ifndef BATHROOM_HPP
#define BATHROOM_HPP


#include <string>

#include "Space.hpp"
#include "LivingRoom.hpp"
#include "Garage.hpp"
#include "Bedroom.hpp"

class Bathroom : public Space
{
private: 
	std::string name = "Bathroom 1";


public:
	Bathroom();
	virtual Space *move();
	virtual std::string getName();
	virtual int specialAbility(); 
	~Bathroom();
};

#endif
