/************************************************
 * Program Name: Menu.hpp
 * Author: Elizabeth Donato
 * Date: 1-20-2018
 * Description: This is the header file for the 
   Menu class.  
************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "ValidInt.hpp"
#include <string>

//Menu class declaration
class Menu
{
   private:
	int userChoice;		//User's menu choice
	ValidInt userInput;	//Used for input validation
	std::string testString;	//Used for input validation
	bool validInput;	//Used to indicate if valid input has been entered
	int lowest;		//Lowest menu choice; used for input validation
	int highest;		//Highest menu choice; used for input validation

   public:
	Menu();			//Constructor
	int get_choice(int);	//Displays appropriate menu and obtains user choice
	~Menu() {};		//Destructor
};
#endif
