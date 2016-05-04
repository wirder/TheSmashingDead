#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Player.h"
#include "Game.h"
using namespace sf;
using namespace std;
#ifndef WORLD_H
#define WORLD_H
class World {
private:
	Player* player;
public:
	Player* getPlayer();
	void moveSelection(Vector2f vector);
	World();
	void draw();
};
#endif 