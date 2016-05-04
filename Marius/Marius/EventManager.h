#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
class EventManager {
public:
	EventManager();
	void manageEvent();
	sf::Event event;
	sf::Vector2f getVector();
	void update();
private:
	void keyboardEvent();
	bool keyUp;
	bool keyDown;
	bool keyLeft;
	bool keyRight;
	bool keyShift;
	bool keyEnter;
	bool keySpace;
	int speedLevel = 3;
	int speedLevelShift = 2;
};