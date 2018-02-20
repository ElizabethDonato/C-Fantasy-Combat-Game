/*************************************************
 * Program Name: Vampire.cpp
 * Author: Elizabeth Donato
 * Date: 2-17-2018
 * Description: This is the implementation file 
 * 		for the Vampire class which is
 * 		derived from the Creature class
*************************************************/

#include "Vampire.hpp"
#include <iostream>
#include <string>

/*************************************************
 * 	Vampire::Vampire			*
 * 						*
 * This is the constructor for the Vampire	*
 * class.					*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: Nothing				*
*************************************************/
Vampire::Vampire()
{
   strength = 18;
   armor = 1;
   type = "Vampire";
}

/*************************************************
 * 	Vampire::attack				*
 * 						*
 * This function generates and returns the 	*
 * fighter's attack roll.			*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (total attack roll)		*
*************************************************/
int Vampire::attack()
{
   int num = 1;			//Number of attack dice rolled
   int size = 12;		//Size of each die rolled
   int totalRoll = 0;		//Total attack roll

   totalRoll = roll(num, size);

   return totalRoll;
}

/*************************************************
 * 	Vampire::defend				*
 * 						*
 * This function generates and returns the 	*
 * fighter's defense roll.  For each attack, 	*
 * there is a 50% chance the Vampire can charm  *
 * an opponent into not attacking.  This is     *
 * implemented through the defense roll.  If 	*
 * the roll is 1, 2, or 3, Charm is not 	*
 * effective.  If the roll is 4, 5, or 6, 	*
 * Charm is effective. A negative value is 	*
 * returned to the client program to indicate 	*
 * that Charm was effective.			*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (total defense roll)		*
*************************************************/
int Vampire::defend()
{
   int num = 1;			//Number of defense dice rolled
   int size = 6;		//Size of each die rolled
   int totalRoll = 0;		//Total defense roll

   totalRoll = roll(num, size);

   //Determines if Vampire's charm defense is effective.
   if(totalRoll > 3)
   {
	//totalRoll is -2 so that when armor value of 1 is added, 
	//function will return -1 to indicate that Charm was effective
	totalRoll = -2;
   }
   return (totalRoll + armor);
}
