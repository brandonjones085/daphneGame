/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The headerfile for the Bedroom class
*******************************************************************************/



#ifndef BEDROOM_HPP
#define BEDROOM_HPP

#include "Space.hpp"



#include <string>

class Bedroom : public Space
{
private: 
	std::string name = "Bedroom 1";

public:
	Bedroom();
	virtual Space *move();
	virtual std::string getName();
	virtual int specialAbility(); 
	~Bedroom();
};


#endif
