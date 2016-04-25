#include "EventManager.h"
#include "Debug.h"

using namespace std;
using namespace sf;

EventManager::EventManager(RenderWindow &refWindow) : window(refWindow)
{
keyUp = false;
keyDown = false;
keyLeft = false;
keyRight = false;
keyShift = false;
}

void EventManager::manageEvent()
{
	while (window.pollEvent(event)) {
		switch (event.type)
		{
		case Event::Closed:
			window.close();
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
			keyUp = true;
		if ((event.key.code == Keyboard::S) || (event.key.code == Keyboard::Down))
			keyDown = true;
		if ((event.key.code == Keyboard::Q) || (event.key.code == Keyboard::Left))
			keyLeft = true;
		if ((event.key.code == Keyboard::D) || (event.key.code == Keyboard::Right))
			keyRight = true;
		if (event.key.code == Keyboard::LShift)
			keyShift = true;
	}
	else {
		if ((event.key.code == Keyboard::Z) || (event.key.code == Keyboard::Up))
			keyUp = false;
		if ((event.key.code == Keyboard::S) || (event.key.code == Keyboard::Down))
			keyDown = false;
		if ((event.key.code == Keyboard::Q) || (event.key.code == Keyboard::Left))
			keyLeft = false;
		if ((event.key.code == Keyboard::D) || (event.key.code == Keyboard::Right))
			keyRight = false;
		if (event.key.code == Keyboard::LShift)
			keyShift = false;
	}
}

Vector2f EventManager::getVector() {
	Vector2f vector = Vector2f();
	vector.x = 0;
	vector.y = 0;
	if (keyUp)
		vector.y -= speedLevel;
	if (keyDown)
		vector.y += speedLevel;
	if (keyLeft)
		vector.x -= speedLevel;
	if (keyRight)
		vector.x += speedLevel;
	if (keyShift) {
		vector.x *= speedLevelShift;
		vector.y *= speedLevelShift;
	}
	return vector;
}