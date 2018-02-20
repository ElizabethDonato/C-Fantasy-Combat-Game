/*************************************************
 * Program Name: fantasyGame.cpp
 * Author: Elizabeth Donato
 * Date: 2-17-2018
 * Description: This is the client program to run 
 * 		the fantasy combat game.
*************************************************/

#include "Game.hpp"

int main()
{
   //Instantiates a Game object
   Game myGame;
   bool play = true;

   while(play)
   {
	play = myGame.play_game();
   }

   return 0;
} 		
