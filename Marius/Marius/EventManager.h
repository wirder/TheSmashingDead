#pragma once
#include <SFML/Graphics.hpp>

class EventManager {
public:
	EventManager(sf::RenderWindow &window);
	void manageEvent();
	sf::Event event;
	sf::Vector2f getVector();
private:
	sf::RenderWindow &window;
	void keyboardEvent();
	bool keyUp;
	bool keyDown;
	bool keyLeft;
	bool keyRight;
	bool keyShift;
	int speedLevel = 2;
	int speedLevelShift = 3;
};