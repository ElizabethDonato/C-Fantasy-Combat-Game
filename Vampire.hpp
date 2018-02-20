/*************************************************
 * Program Name: Vampire.hpp
 * Author: Elizabeth Donato
 * Date: 2-17-2018
 * Description: This is the header file 
 * 		for the Vampire class which is
 * 		derived form the Creature class
*************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"

//Vampire class declaration
class Vampire: public Creature
{
   public:
	Vampire();		//Constructor
	virtual int attack();
	virtual int defend();

	~Vampire() {};		//Destructor
};
#endif 		
