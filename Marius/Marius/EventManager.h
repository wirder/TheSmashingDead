#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
class EventManager {
public:
	EventManager(Game game);
	void manageEvent();
	sf::Event event;
	sf::Vector2f getVector();
private:
	Game game;
	void keyboardEvent();
	bool keyUp;
	bool keyDown;
	bool keyLeft;
	bool keyRight;
	bool keyShift;
	int speedLevel = 2;
	int speedLevelShift = 3;
};