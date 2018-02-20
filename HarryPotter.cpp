/*************************************************
 * Program Name: HarryPotter.cpp
 * Author: Elizabeth Donato
 * Date: 2-17-2018
 * Description: This is the implementation file 
 * 		for the HarryPotter class which is
 * 		derived form the Creature class
*************************************************/

#include "HarryPotter.hpp"
#include <iostream>
#include <string>

/*************************************************
 * 	HarryPotter::HarryPotter		*
 * 						*
 * This is the constructor for the HarryPotter	*
 * class.					*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: Nothing				*
*************************************************/
HarryPotter::HarryPotter()
{
   strength = 10;
   armor = 0;
   type = "Harry Potter";
   newLives = 1;
}

/*************************************************
 * 	HarryPotter::attack			*
 * 						*
 * This function generates and returns the 	*
 * fighter's attack roll.			*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (total attack roll)		*
*************************************************/
int HarryPotter::attack()
{
   int num = 2;			//Number of attack dice rolled
   int size = 6;		//Size of each die rolled
   int totalRoll = 0;		//Total attack roll

   totalRoll = roll(num, size);

   return totalRoll;
}

/*************************************************
 * 	HarryPotter::defend			*
 * 						*
 * This function generates and returns the 	*
 * fighter's defense roll.			*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (total defense roll)		*
*************************************************/
int HarryPotter::defend()
{
   int num = 2;			//Number of defense dice rolled
   int size = 6;		//Size of each die rolled
   int totalRoll = 0;		//Total defense roll

   totalRoll = roll(num, size);

   return (totalRoll + armor);
}
