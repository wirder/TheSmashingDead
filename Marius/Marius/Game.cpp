#include "Game.h"
#include "Menu.h"


Game::Game(RenderWindow &mainWindow, Menu &mainMenu) : window(mainWindow), menu(mainMenu)
{
	isInMenu = true;
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
}

RenderWindow & Game::getWindow()
{
	return window;
}

Menu & Game::getMenu()
{
	return menu;
}

void Game::draw()
{
	if (isInMenu) {
		menu.Draw();
	}
}

bool Game::isMenu()
{
	return isInMenu;
}
