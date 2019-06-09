/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The header file for the Garage class
*******************************************************************************/



#ifndef GARAGE_HPP
#define GARAGE_HPP


#include "Space.hpp"

#include <string>

class Garage : public Space
{

	std::string name = "Garage"; 


public:
	Garage();


	virtual Space *move(); 
	virtual std::string getName();



	~Garage();
};

#endif
