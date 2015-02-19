// Stumble.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "TestObject.h"
#include "Game.h"

int main(int argc, _TCHAR* argv[])
{
	Game game;
	TestObject t;
	game.addGameObject(&t);
	while (1)
		game.update();
	return 0;
}

