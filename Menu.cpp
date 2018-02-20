/************************************************
 * Program Name: Menu.cpp
 * Author: Elizabeth Donato
 * Date: 1-20-2018
 * Description: This is the implementation file  
   for the menu class.   
************************************************/

#include "Menu.hpp"
#include "ValidInt.hpp"
#include <iostream>

/*************************************************
 * 		Menu::Menu			*
 * 						*
 * This is the constructor for the Menu class.	*
 * It initializes class variables.		*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: Nothing				*
*************************************************/
Menu::Menu()
{
   testString = "";
   validInput = false;		//Will change to true once valid input has been entered
   lowest = 0;
   highest = 5;		   
}

/*************************************************
 * 		Menu::get_choice		*
 * 						*
 * 						*
 * This function displays a menu of choices 	*
 * for the user and gets the user's choice.	*
 *						*
 * Accepts: Nothing				*
 *          					*
 * Returns: int (User's choice)			*
 * 						*
*************************************************/
int Menu::get_choice(int fNum)
{
   //Gets and validates user's choice
   while(!validInput)
   {
	std::cout << "\n\nChoose fighter number " << fNum << " or choose 0 to exit the program." << std::endl; 
	std::cout << "\n\n  Fantasy Combat Game Menu" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "1.  Barbarian" << std::endl;
	std::cout << "2.  Vampire" << std::endl;
	std::cout << "3.  Blue Men" << std::endl;
	std::cout << "4.  Medusa" << std::endl;
	std::cout << "5.  Harry Potter" << std::endl << std::endl;
	std::cout << "0.  Exit Program" << std::endl<<std::endl;

      	std::cout << "\n\nPlease enter your choice:  ";
   	std::getline(std::cin, testString);
	validInput = userInput.is_valid_int_range(testString, lowest, highest);
   } 

   //Returns user's choice to client program
   userChoice = userInput.get_int();

   validInput = false;

   return userChoice;
}


