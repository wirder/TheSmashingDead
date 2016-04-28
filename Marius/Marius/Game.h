#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

using namespace sf;
using namespace std;

class Game {
private:
	Game();
	static Game* game;
	RenderWindow* window;
	bool isInMenu;
	Menu* menu;
public:
	static Game* getInstance();
	RenderWindow* getWindow();
	Menu* getMenu();
	void draw();
	bool isMenu();
	void leaveMenu();
	static int instance;
};
