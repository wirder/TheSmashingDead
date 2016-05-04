#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "World.h"

using namespace sf;
using namespace std;

class Game {
private:
	Game();
	static Game* game;
	RenderWindow* window;
	bool isInMenu;
	Menu* menu;
	World* world;
public:
	static Game* getInstance();
	RenderWindow* getWindow();
	Menu* getMenu();
	World* getWorld();
	void draw();
	bool isMenu();
	void leaveMenu();
	static int instance;
};
