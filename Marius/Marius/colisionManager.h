#include <cmath>
#include "TileMap.h"
#include "Player.h"
#include "Enemy.h"

#ifndef COLISIONMANAGER_H
#define COLISIONMANAGER_H

class colisionManager {
public:
	int Update(Player *player, Enemy * enemy);
	colisionManager();
private:
	Player* player;
	TileMap* map;
};

#endif