#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
class EventManager {
public:
	EventManager();
	void manageEvent();
	sf::Event event;
	sf::Vector2f getVector();
private:
	void keyboardEvent();
	bool keyUp;
	bool keyDown;
	bool keyLeft;
	bool keyRight;
	bool keyShift;
	bool keyEnter;
	int speedLevel = 2;
	int speedLevelShift = 3;
};