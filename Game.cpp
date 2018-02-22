/*************************************************
 * Program Name: Game.cpp
 * Author: Elizabeth Donato
 * Date: 2-17-2018
 * Description: This is the implementation file
 * 		for the Game class
*************************************************/
#include "Game.hpp"
#include "Menu.hpp"
#include "UserInput.hpp"
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Vampire.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <iostream>
#include <string>
	
/*************************************************
 * 		Game::play_game			*
 * 						*
 * This function conducts gameplay.		*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (exit status)			*
*************************************************/ 
bool Game::play_game()
{
   //Instantiates needed objects
   Menu userMenu;
   UserInput gameInfo;

   //Gameplay variables
   bool playGame = true;
   bool isStone = false;   

   choice1 = userMenu.get_choice(1);
   switch(choice1)
   {
	case 0: std::cout << "\nYou have chosen to exit the program.  Good bye." << std::endl << std::endl;
		playGame = false;
		break;
	case 1: fighter1 = new Barbarian();
		break;
	case 2: fighter1 = new Vampire();
		break;
	case 3: fighter1 = new BlueMen();
		break;
	case 4: fighter1 = new Medusa();
		break;
	case 5: fighter1 = new HarryPotter();
		break;
   }
   if(playGame)
   {
   	choice2 = userMenu.get_choice(2);
   	switch(choice2)
   	{
	   case 0: std::cout << "\nYou have chosen to exit the program.  Good bye." << std::endl << std::endl;
	   	   playGame = false;
		   break;
	   case 1: fighter2 = new Barbarian();
		   break;
	   case 2: fighter2 = new Vampire();
		   break;
	   case 3: fighter2 = new BlueMen();
		   break;
	   case 4: fighter2 = new Medusa();
		   break;
	   case 5: fighter2 = new HarryPotter();
		   break;
      	}
   }
   if(playGame)
   {
      std::cout << "\nFighter 1 will be a " << fighter1 ->get_type() << "!" << std::endl;
      std::cout << "Fighter 1 Starting Strength:  " << fighter1 ->get_strength() << std::endl << std::endl;
      std::cout << "\nFighter 2 will be a " << fighter2 ->get_type() << "!" << std::endl;
      std::cout << "Fighter 2 Starting Strength:  " << fighter2 ->get_strength() << std::endl << std::endl;

      //Loops to conduct gameplay until a fighter's strength is completely depleted
      do
      {
         //Establishes strength for each fighter
         fighter1Strength = fighter1 ->get_strength();
         fighter2Strength = fighter2 ->get_strength();

	 //Displays round header
   	 std::cout << "\n\n                 Round " << round << std::endl;
   	 std::cout << "----------------------------------------" << std::endl << std::endl;

         //fighter 1 attacks
         fighterAttack = fighter1 ->attack();
	 //If Medusa's Glare is effective, deplete all of opponent's strength
	 if(fighterAttack == -2)
	 {
	    fighterAttack = fighter2Strength;
	    isStone = true;
	    std::cout <<"The " << fighter1 ->get_type() << " Glare is effective!" << std::endl;
	 }

         //fighter 2 defends
         fighterDefend = fighter2 -> defend();
	 //If Defender has been turned to stone
	 if(isStone)
	 {
	    fighterDefend = 0;
	    std::cout << fighter2 ->get_type() << " has been turned to stone! No defense is possible!" 
		      << std::endl << std::endl;  
	 }
	 //If Vampire's Charm defense if effective, opponent does not attack
	 if(fighterDefend == -1)
	 {
	    std::cout << "The " << fighter2 ->get_type() << " has charmed the " 
	    << fighter1 ->get_type() << "!  The " << fighter2 ->get_type() 
	    << " takes no damage this round!" << std::endl << std::endl;
	    fighterAttack = 0;
	    fighterDefend = 0;
	 }

         //Calculates damage
         totalDamage = damage(fighterAttack, fighterDefend);

         //Sets new strength for defender
         fighter2 ->set_strength(totalDamage);
         fighter2Strength = fighter2 ->get_strength();

         //Displays round information
         display_round(1);

         //Checks to see if new life is available
         if(fighter2Strength <= 0)
         {
            fighter2 ->new_life();
	    fighter2Strength = fighter2 ->get_strength();
	    isStone = false;
         }

         //Ends game if fighter has no strength left
         if(fighter2Strength <= 0)
         {
	    std::cout << "\nFighter 2, the " << fighter2 ->get_type() << ", has been defeated!" << std::endl;
	    std::cout << "Fighter 1, the " << fighter1 ->get_type() << ", wins!" << std::endl << std::endl;
         }

         //Continues to next attack sequence if both fighters have strength remaining
         else
         {
	    //fighter 2 attacks
	    fighterAttack = fighter2 ->attack();
	    //If Medusa's Glare is effective, deplete all of opponent's strength
	    if(fighterAttack == -2)
	    {
	       fighterAttack = fighter1Strength;
	       isStone = true;
	       std::cout <<"The " << fighter2 ->get_type() << " Glare is effective!" << std::endl;
	    }
	    
	    //fighter 1 defends
	    fighterDefend = fighter1 -> defend();
	    //If Defender has been turned to stone
	    if(isStone)
	    {
	       fighterDefend = 0;
	       std::cout << fighter1 ->get_type() << " has been turned to stone! No defense is possible!" 
		         << std::endl << std::endl;  
	    }
	    //If Vampire's Charm defense if effective, opponent does not attack
	    if(fighterDefend == -1)
	    {
	       std::cout << "The " << fighter1 ->get_type() << " has charmed the "
	       << fighter2 ->get_type() << "!  The " << fighter1 ->get_type() 
	       << " takes no damage this round!" << std::endl << std::endl;
	       fighterAttack = 0;
	       fighterDefend = 0;
	    }

	    //Calculates damage
	    totalDamage = damage(fighterAttack, fighterDefend);

	    //Sets new strength for defender
	    fighter1 ->set_strength(totalDamage);
	    fighter1Strength = fighter1 ->get_strength();

	    //Displays round information
	    display_round(2);

	    //Checks to see if new life is available
	    if(fighter1Strength <= 0)
	    {
	       fighter1 ->new_life();
	       fighter1Strength = fighter1 ->get_strength();
	       isStone = false;
   	    }

   	    //Ends game if fighter has no strength left
   	    if(fighter1Strength <= 0)
   	    {
	       std::cout << "\nFighter 1, the " << fighter1 ->get_type() << ", has been defeated!" << std::endl;
	       std::cout << "Fighter 2, the " << fighter2 ->get_type() << ", wins!" << std::endl << std::endl;
   	    }
         } 
      //Increment round counter
      round++;
      } while ((fighter1Strength > 0) && (fighter2Strength > 0));
   }
   //Frees memory
   delete fighter1;
   fighter1 = 0;
   delete fighter2;
   fighter2 = 0;
 
   //resets round counter so user can play again
   round = 1;
   
   return playGame;
}

/*************************************************
 * 		Game::damage			*
 * 						*
 * This function calculates the damage to a 	*
 * defender in a given round.			*
 * 						*
 * Accepts: int (attack value)			*
 *   	    int (defense value)			*
 *   	    					*
 * Returns: int (total damage)			*
*************************************************/
int Game::damage(int att, int def)
{
   int calcDamage;

   //If defense value is large enough to negate all damage, set damage to 0
   if(def >= att)
   {
	calcDamage = 0;
   }

   //If defense value does not negate all damage, calculate total damage
   else
   {
	calcDamage = (att - def);
   }

   return calcDamage;
} 

/*************************************************
 * 		Game::display_round		*
 * 						*
 * This function displays combat information 	*
 * for a round.					*
 * 						*
 * Accepts: int (current stage of combat	*
 * 						*
 * Returns: Nothing				*
*************************************************/
void Game::display_round(int stage)
{
   if(stage ==1)
   {
	std::cout << "Fighter 1, the " << fighter1 ->get_type() << ", attacks first!" << std::endl;
   	std::cout << "The " << fighter1 ->get_type() << " attacks with a " << fighterAttack << "!" << std::endl;
   	std::cout << "Fighter 2, the " << fighter2 ->get_type() << ", defends with a " << fighterDefend << "!" << std::endl;
   	std::cout << "The " << fighter2 ->get_type() << " takes " << totalDamage << " points of damage." << std::endl;
   	std::cout << "Fighter 1, the " << fighter1 ->get_type() << ", Strength: " << fighter1Strength << std::endl;
   	std::cout << "Fighter 2, the " << fighter2 ->get_type() << ", Strength: " << fighter2Strength 
		  << std::endl << std::endl;
   }

   else
   {
	std::cout << "Now Fighter 2, the " << fighter2 ->get_type() << ", attacks!" << std::endl;
   	std::cout << "The " << fighter2 ->get_type() << " attacks with a " << fighterAttack << "!" << std::endl;
   	std::cout << "Fighter 1, the " << fighter1 ->get_type() << ", defends with a " << fighterDefend << "!" << std::endl;
   	std::cout << "The " << fighter1 ->get_type() << " takes " << totalDamage << " points of damage." << std::endl;
   	std::cout << "Fighter 1, the " << fighter1 ->get_type() << ", Strength: " << fighter1Strength << std::endl;
   	std::cout << "Fighter 2, the " << fighter2 ->get_type() << ", Strength: " << fighter2Strength << std::endl;

   }
}
