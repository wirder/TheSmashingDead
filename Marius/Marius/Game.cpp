#include "Game.h"
#include "Menu.h"


Game::Game(RenderWindow &mainWindow) : window(mainWindow)
{
	isInMenu = true;
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	Menu menu = Menu(window);
}

RenderWindow & Game::getWindow()
{
	return window;
}
