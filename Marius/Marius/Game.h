#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

using namespace sf;

class Game {
public:
	Game(RenderWindow & mainWindow);
	RenderWindow &getWindow();
private:
	RenderWindow &window;
	bool isInMenu;
};
