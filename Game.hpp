/*************************************************
 * Program Name: Game.hpp
 * Author: Elizabeth Donato
 * Date: 2-17-2018
 * Description: This is the header file
 * 		for the Game class
*************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "Creature.hpp"

//Game class declaration
class Game
{
   protected:
	//User choices for two fighters
	int choice1 = 0;
	int choice2 = 0;

	//Pointers to fighter Creatures
	Creature *fighter1;
	Creature *fighter2;

   	//Combat variables
   	int fighterAttack = 0;		//attack value
	int fighterDefend = 0;		//defense value
	int totalDamage = 0;		//Total damage to defender in a round
	int fighter1Strength = 0;	//Current strength of fighter 1	
	int fighter2Strength = 0;	//Current strength of fighter 2
	int round = 1;			//Current round number
	

   public:
	Game() {};			//Constructor
	bool play_game();		//Conducts a combat game	
 	int damage(int, int);		//Calculates damage to defender in a round
	void display_round(int);		//Displays round information
	~Game() {};			//Destructor
};
#endif 		
