/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The header file for the Kitchen class
*******************************************************************************/


#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "Space.hpp"

#include <string>

class Kitchen : public Space
{
private: 
	std::string name = "Kitchen";


public:
	Kitchen();
	virtual Space *move();
	virtual std::string getName();
	virtual int specialAbility(); 
	~Kitchen();
};

#endif
