#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "World.h"

using namespace sf;
using namespace std;

class Game : AbstractEntity{
private:
	Game();
	static Game* game;
	RenderWindow* window;
	View* view;
	bool isInMenu;
	Menu* menu;
	World* world;
public:
	static Game* getInstance();
	RenderWindow* getWindow();
	Menu* getMenu();
	World* getWorld();
	View* getView();
	void Draw();
	void Update();
	bool isMenu();
	void leaveMenu();
	static int instance;
};
