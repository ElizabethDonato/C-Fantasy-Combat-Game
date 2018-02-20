/*************************************************
 * Program Name: BlueMen.cpp
 * Author: Elizabeth Donato
 * Date: 2-17-2018
 * Description: This is the implementation file 
 * 		for the BlueMen class which is
 * 		derived form the Creature class
*************************************************/

#include "BlueMen.hpp"
#include <iostream>
#include <string>

/*************************************************
 * 	BlueMen::BlueMen			*
 * 						*
 * This is the constructor for the BlueMen	*
 * class.					*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: Nothing				*
*************************************************/
BlueMen::BlueMen()
{
   strength = 12;
   armor = 3;
   type = "Blue Men";
}

/*************************************************
 * 	BlueMen::attack				*
 * 						*
 * This function generates and returns the 	*
 * fighter's attack roll.			*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (total attack roll)		*
*************************************************/
int BlueMen::attack()
{
   int num = 2;			//Number of attack dice rolled
   int size = 10;		//Size of each die rolled
   int totalRoll = 0;		//Total attack roll

   totalRoll = roll(num, size);

   return totalRoll;
}

/*************************************************
 * 	BlueMen::defend				*
 * 						*
 * This function generates and returns the 	*
 * fighter's defense roll.			*
 * For every 4 points of damage, the BlueMen	*
 * lose 1 defense die.				*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (total defense roll)		*
*************************************************/
int BlueMen::defend()
{
   int num = 3;			//Number of defense dice rolled
   int size = 6;		//Size of each die rolled
   int totalRoll = 0;		//Total defense roll

   if((strength > 0) && (strength < 5))
   {
	num = 1;
	std::cout << "The Blue Men's defenses are weakened.  Only one defense die remains." << std::endl;
   }

   if((strength > 4) && (strength < 9))
   {
	num = 2;
	std::cout << "The Blue Men's defenses are weakened.  Only two defense dice remain." << std::endl;
   }
   totalRoll = roll(num, size);

   return (totalRoll + armor);
}
