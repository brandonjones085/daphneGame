/*******************************************************************************
** Author:       Brandon Jones
** Date:         06/01/2019
** Description:  The header file for the Space class
*******************************************************************************/



#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>

class Space
{
protected: 
	
	Space *currentSpace; 
	Space *top;
	Space *right;
	Space *left;
	Space *bottom;
	std::string name = "Space";
	int roomNum; 




public:
	Space();
	virtual Space *move(); 
	virtual void welcome(); 
	virtual std::string getName();
	virtual int getRoomNum(); 
	
	virtual void *getCurrentRoom();
	virtual int specialAbility(); 


	~Space();
};


#endif
