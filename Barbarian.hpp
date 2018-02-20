/*************************************************
 * Program Name: Barbarian.hpp
 * Author: Elizabeth Donato
 * Date: 2-17-2018
 * Description: This is the header file 
 * 		for the Barbarian class which is
 * 		derived from the Creature class
*************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

//Barbarian class declaration
class Barbarian: public Creature
{
   public:
	Barbarian();		//Constructor
	virtual int attack();
	virtual int defend();

	~Barbarian() {};		//Destructor
};
#endif 		
