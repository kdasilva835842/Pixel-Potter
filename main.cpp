#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Player.h"
#include "Game.h"

int main()
{

Game game; // Creating our game object.

while(!game.GetWindow()->IsDone())
{
		game.Update();
         game.Render();
}	

	return 0;
}