#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

using namespace sf;
using namespace std;

class Game {
public:
	Game(RenderWindow & mainWindow, Menu & mainMenu);
	RenderWindow &getWindow();
	Menu &getMenu();
	void draw();
	bool isMenu();
private:
	RenderWindow &window;
	bool isInMenu;
	Menu menu;
};
