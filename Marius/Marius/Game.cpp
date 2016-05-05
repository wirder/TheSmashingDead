#pragma once
#include "Game.h"
#include "Menu.h"
#include "World.h"
#include "EventManager.h"

int Game::instance = 0;

Game::Game()
{
		Game::instance = Game::instance + 1;
		isInMenu = true;
		window = new RenderWindow(sf::VideoMode(1280, 720), "The Smashing Dead");
		window->setFramerateLimit(60);
		window->setVerticalSyncEnabled(true);
		window->setKeyRepeatEnabled(false);
		menu = new Menu();
		world = new World();
		view = new View();
}

Game* Game::getInstance()
{
	if (Game::instance < 1) {
		game = new Game();
	}
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

World* Game::getWorld()
{
	return world;
}

View* Game::getView()
{
	return view;
}

void Game::Draw()
{
	window->clear();
	if (isInMenu)
		menu->Draw();
	else {
		world->draw();
	}
	window->display();
}

void Game::Update() {
	EventManager *eManager = EventManager::getInstance();
	if (game->isMenu()) {
		if (eManager->isKeyEnterPressed())
			game->getMenu()->validateSelection();
		else
			game->getMenu()->moveSelection(eManager->getVectorDirection());
	}
	else
		game->getWorld()->moveSelection(eManager->getVectorDirection(), eManager->isKeySpacePressed());
}

bool Game::isMenu()
{
	return isInMenu;
}

void Game::leaveMenu() {
	isInMenu = false;
	view->zoom(0.5f);
	window->setView(*view);
}
