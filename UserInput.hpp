/************************************************
 * Program Name: UserInput.hpp
 * Author: Elizabeth Donato
 * Date: 1-27-2018
 * Description: This is the header file  
   for the UserInput class that is used to 
   get information from the user about program
   specifications.  This class can easily be 
   modified for use by different programs.
************************************************/

#ifndef USERINPUT_HPP
#define USERINPUT_HPP

#include "ValidInt.hpp"
#include <string>

//UserInput class declaration
class UserInput
{
   private:
	int myInt;		//User-entered input of some sort
	ValidInt userInt;	//Used for input validation
	std::string testString;	//Used for input validation
	bool validInput;	//Used to indicate if valid input has been entered
	int lowest;		//Lowest number in specified range
	int highest;		//Highest number in specified range

   public:
	UserInput();		//Constructor
	int get_input();	
	~UserInput() {};	//Destructor
};
#endif

