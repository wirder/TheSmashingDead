#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

using namespace std;

class EventManager {
public:
	void manageEvent();
	Vector2f getVectorDirection();
	bool isKeyEnterPressed();
	bool isKeySpacePressed();
	static EventManager* getInstance();
	static int instance;
private:
	static EventManager* eManager;
	EventManager();
	void keyboardEvent();
	void setVectorDirection();
	Vector2f vectorDirection;
	sf::Event event;
	int speedLevel = 3;
	int speedLevelShift = 2;
	vector<bool> keyPressed;
};