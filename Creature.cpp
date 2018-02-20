/*************************************************
 * Program Name: Creature.cpp
 * Author: Elizabeth Donato
 * Date: 2-17-2018
 * Description: This is the implementation file 
 * 		for the abstract Creature
 * 		base class
*************************************************/

#include "Creature.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

/*************************************************
 * 		Creature			*
 * 						*
 * This is the default constructor for the 	*
 * Creature class.				*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: Nothing				*
*************************************************/
Creature::Creature()
{
   strength = 0;
   armor = 0;
   newLives = 0;
   type = "Creature";
   
   //Seeds random number generator
   unsigned seed = time(0);
   srand(seed);
} 

/*************************************************
 * 	Creature::set_strength			*
 * 						*
 * This function adjusts creature strength 	*
 * based on damage inflicted by an attack.	*
 * 						*
 * Accepts: int (Damage inflicted)		*
 * 						*
 * Returns: Nothing				*
*************************************************/
void Creature::set_strength(int dam)
{
   strength -= dam;
} 

/*************************************************
 * 	Creature::get_strength			*
 * 						*
 * This function gets the strength of a 	*
 * Creature.					*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (Creature strength)		*
*************************************************/ 
int Creature::get_strength()
{
   return strength;
}

/*************************************************
 * 	Creature::get_type()			*
 * 						*
 * This function gets the type of a Creature.	*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: string(Creature type)		*
*************************************************/
std::string Creature::get_type()
{
   return type;
} 
	
/*************************************************
 * 		Creature::roll			*
 * 						*
 * This function generates and returns the 	*
 * value of a randomly generated roll of the 	*
 * dice.					*
 * 						*
 * Accepts: int (number of dice)		*
 * 	    int (size of each die)		*
 * 	    					*
 * Returns: int (total value of dice roll)	*
*************************************************/
int Creature::roll(int numDice, int sizeDie)
{
   int dieRoll = 0;
   int totalRoll = 0;

   //Loops to roll each die
   for(int i = 0; i < numDice; i++)
   {
	dieRoll = rand() % sizeDie + 1;
	totalRoll += dieRoll;
   }

   return totalRoll;
}

/*************************************************
 * 		Creature::new_life		*
 * 						*
 * This function determines if a new life is 	*
 * available and, if so, generates one for the 	*
 * creature.					*
 * 						*
 * Accepts: Nothing				*
 *						*
 * Returns: Nothing				*
*************************************************/
void Creature::new_life()
{
   //Resets strength if new life is available
   //As Harry Potter is the only Creature with 
   //this characteristic, defaults are set for
   //Harry Potter

   if(newLives == 1)
   {
	std::cout << "\nHarry Potter has recovered!  He now has a strength of 20!" << std::endl;
	std::cout <<"Harry Potter has no new lives remaining." << std::endl;
	strength = 20;

	//Decrements newLives counter
	newLives --;
   }
} 
