/*************************************************
 * Program Name: BlueMen.hpp
 * Author: Elizabeth Donato
 * Date: 2-17-2018
 * Description: This is the header file 
 * 		for the BlueMen class which is
 * 		derived from the Creature class
*************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"

//BlueMen class declaration
class BlueMen: public Creature
{
   public:
	BlueMen();		//Constructor
	virtual int attack();
	virtual int defend();

	~BlueMen() {};		//Destructor
};
#endif 		
