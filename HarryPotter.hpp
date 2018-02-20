/*************************************************
 * Program Name: HarryPotter.hpp
 * Author: Elizabeth Donato
 * Date: 2-17-2018
 * Description: This is the header file 
 * 		for the HarryPotter class which is
 * 		derived from the Creature class
*************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Creature.hpp"

//HarryPotter class declaration
class HarryPotter: public Creature
{
   public:
	HarryPotter();		//Constructor
	virtual int attack();
	virtual int defend();

	~HarryPotter() {};		//Destructor
};
#endif 		
