/*************************************************
 * Program Name: Medusa.hpp
 * Author: Elizabeth Donato
 * Date: 2-17-2018
 * Description: This is the header file 
 * 		for the Medusa class which is
 * 		derived from the Creature class
*************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

//Medusa class declaration
class Medusa: public Creature
{
   public:
	Medusa();		//Constructor
	virtual int attack();
	virtual int defend();

	~Medusa() {};		//Destructor
};
#endif 		
