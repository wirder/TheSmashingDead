#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include "colisionManager.h"

using namespace sf;
using namespace std;
#ifndef WORLD_H
#define WORLD_H
class World {
private:
	Player* player;
	Enemy* enemy;
	TileMap* map;
	colisionManager* cm;
public:
	Player* getPlayer();
	void moveSelection(Vector2f vector, bool jump);
	World();
	void draw();
};
#endif 