/*************************************************
 * Program Name: Medusa.cpp
 * Author: Elizabeth Donato
 * Date: 2-17-2018
 * Description: This is the implementation file 
 * 		for the Medusa class which is
 * 		derived form the Creature class
*************************************************/

#include "Medusa.hpp"
#include <iostream>
#include <string>

/*************************************************
 * 	Medusa::Medusa				*
 * 						*
 * This is the constructor for the Medusa	*
 * class.					*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: Nothing				*
*************************************************/
Medusa::Medusa()
{
   strength = 8;
   armor = 3;
   type = "Medusa";
}

/*************************************************
 * 	Medusa::attack				*
 * 						*
 * This function generates and returns the 	*
 * fighter's attack roll.			*
 * If Medusa rolls a 12 when attacking, the 	*
 * Glare attack is successful.  The target is 	*
 * instantly turned to stone and Medusa wins.	*
 * This is implemented by returning a negative	*
 * value to the calling function to indicate 	*
 * that Glare was effective.			*
 *						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (total attack roll)		*
*************************************************/
int Medusa::attack()
{
   int num = 2;			//Number of attack dice rolled
   int size = 6;		//Size of each die rolled
   int totalRoll = 0;		//Total attack roll

   totalRoll = roll(num, size);

   //Determines if Glare is effective
   if(totalRoll == 12)
   {
	totalRoll = -2;
   }

   return totalRoll;
}

/*************************************************
 * 	Medusa::defend				*
 * 						*
 * This function generates and returns the 	*
 * fighter's defense roll.			*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (total defense roll)		*
*************************************************/
int Medusa::defend()
{
   int num = 1;			//Number of defense dice rolled
   int size = 6;		//Size of each die rolled
   int totalRoll = 0;		//Total defense roll

   totalRoll = roll(num, size);

   return (totalRoll + armor);
}
