/*************************************************
 * Program Name: Barbarian.cpp
 * Author: Elizabeth Donato
 * Date: 2-17-2018
 * Description: This is the implementation file 
 * 		for the Barbarian class which is
 * 		derived form the Creature class
*************************************************/

#include "Barbarian.hpp"
#include <iostream>
#include <string>

/*************************************************
 * 	Barbarian::Barbarian			*
 * 						*
 * This is the constructor for the Barbarian	*
 * class.					*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: Nothing				*
*************************************************/
Barbarian::Barbarian()
{
   strength = 12;
   armor = 0;
   type = "Barbarian";
}

/*************************************************
 * 	Barbarian::attack			*
 * 						*
 * This function generates and returns the 	*
 * fighter's attack roll.			*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (total attack roll)		*
*************************************************/
int Barbarian::attack()
{
   int num = 2;			//Number of attack dice rolled
   int size = 6;		//Size of each die rolled
   int totalRoll = 0;		//Total attack roll

   totalRoll = roll(num, size);

   return totalRoll;
}

/*************************************************
 * 	Barbarian::defend			*
 * 						*
 * This function generates and returns the 	*
 * fighter's defense roll.			*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (total defense roll)		*
*************************************************/
int Barbarian::defend()
{
   int num = 2;			//Number of defense dice rolled
   int size = 6;		//Size of each die rolled
   int totalRoll = 0;		//Total defense roll

   totalRoll = roll(num, size);

   return (totalRoll + armor);
}
