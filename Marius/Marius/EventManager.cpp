#include "EventManager.h"
#include "Debug.h"
#include "Game.h"
#include <vector>

using namespace std;
using namespace sf;

int EventManager::instance = 0;

EventManager::EventManager()
{
	EventManager::instance = EventManager::instance + 1;
	vectorDirection = Vector2f();
	keyPressed = vector<bool>(7);
	// Up Down Left Right Shift Enter Space
	keyPressed[0] = false;
	keyPressed[1] = false;
	keyPressed[2] = false;
	keyPressed[3] = false;
	keyPressed[4] = false;
	keyPressed[5] = false;
	keyPressed[6] = false;
}

EventManager *EventManager::getInstance() {
	if (EventManager::instance < 1)
		eManager = new EventManager();
	return eManager;
}

void EventManager::manageEvent()
{
	Game *game = Game::getInstance();
	while (game->getWindow()->pollEvent(event)) {
		switch (event.type)
		{
		case Event::Closed:
			game->getWindow()->close();
			break;
		case Event::KeyPressed:
		case Event::KeyReleased:
			keyboardEvent();
			break;
		default:
			break;
		}
	}
}

void EventManager::keyboardEvent()
{
	if (event.type == Event::KeyPressed) {
		if ((event.key.code == Keyboard::Z) || (event.key.code == Keyboard::Up))
			keyPressed[0] = true;
		else if ((event.key.code == Keyboard::S) || (event.key.code == Keyboard::Down))
			keyPressed[1] = true;
		else if ((event.key.code == Keyboard::Q) || (event.key.code == Keyboard::Left))
			keyPressed[2] = true;
		else if ((event.key.code == Keyboard::D) || (event.key.code == Keyboard::Right))
			keyPressed[3] = true;
		else if (event.key.code == Keyboard::LShift)
			keyPressed[4] = true;
		else if (event.key.code == Keyboard::Return)
			keyPressed[5] = true;
		else if (event.key.code == Keyboard::Space)
			keyPressed[6] = true;
	}
	else {
		if ((event.key.code == Keyboard::Z) || (event.key.code == Keyboard::Up))
			keyPressed[0] = false;
		else if ((event.key.code == Keyboard::S) || (event.key.code == Keyboard::Down))
			keyPressed[1] = false;
		else if ((event.key.code == Keyboard::Q) || (event.key.code == Keyboard::Left))
			keyPressed[2] = false;
		else if ((event.key.code == Keyboard::D) || (event.key.code == Keyboard::Right))
			keyPressed[3] = false;
		else if (event.key.code == Keyboard::LShift)
			keyPressed[4] = false;
		else if (event.key.code == Keyboard::Return)
			keyPressed[5] = false;
		else if (event.key.code == Keyboard::Space)
			keyPressed[6] = false;
	}
	setVectorDirection();
}

void EventManager::setVectorDirection() 
{
	vectorDirection.x = 0;
	vectorDirection.y = 0;
	if (keyPressed[0])
		vectorDirection.y -= speedLevel;
	if (keyPressed[1])
		vectorDirection.y += speedLevel;
	if (keyPressed[2])
		vectorDirection.x -= speedLevel;
	if (keyPressed[3])
		vectorDirection.x += speedLevel;
	if (keyPressed[4]) {
		vectorDirection.x *= speedLevelShift;
		//vector.y *= speedLevelShift;
	}
}

Vector2f EventManager::getVectorDirection() {
	return vectorDirection;
}

bool EventManager::isKeyEnterPressed() {
	return keyPressed[5];
}

bool EventManager::isKeySpacePressed() {
	return keyPressed[6];
}