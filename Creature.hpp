/*************************************************
 * Program Name: Creature.hpp
 * Author: Elizabeth Donato
 * Date: 2-17-2018
 * Description: This is the header file 
 * 		for the abstract Creature
 * 		base class
*************************************************/
#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <cstdlib>
#include <ctime>
#include <string>

//Creature class declaration
class Creature
{
   protected:
	int strength;
   	int armor;
	int attackRoll;
	int defenseRoll;
	int totalRoll;
	int newLives;
	std::string type;

   public:
	Creature();		//Constructor
	void set_strength(int);
	int get_strength();
	std::string get_type();
	int roll(int, int);
 	void new_life();

	//Pure virtual functions
	virtual int attack() = 0;
	virtual int defend() = 0;

	virtual ~Creature() {};		//Destructor
};
#endif 		
