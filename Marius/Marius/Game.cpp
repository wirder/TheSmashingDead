#pragma once
#include "Game.h"
#include "Menu.h"

int Game::instance;

Game::Game()
{
	isInMenu = true;
	window = new RenderWindow(sf::VideoMode(1280, 720), "The Smashing Dead");
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);
	menu = new Menu();
	Game::instance += 1;
}

Game* Game::getInstance()
{
	if (instance < 1)
		game = new Game();
	return game;
}

RenderWindow* Game::getWindow()
{
	return window;
}

Menu* Game::getMenu()
{
	return menu;
}

void Game::draw()
{
	window->clear();
	if (isInMenu)
		menu->Draw();
	else {
		CircleShape shape(50);
		shape.setFillColor(sf::Color(100, 250, 50));
		window->draw(shape);
	}
	window->display();
}

bool Game::isMenu()
{
	return isInMenu;
}

void Game::leaveMenu() {
	isInMenu = false;
}
