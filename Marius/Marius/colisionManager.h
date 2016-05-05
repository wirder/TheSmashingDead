#include <cmath>
#include "TileMap.h"
#include "Player.h"

#ifndef COLISIONMANAGER_H
#define COLISIONMANAGER_H

class colisionManager {
public:
	int Update(Player *player);
	colisionManager();
private:
	Player* player;
	TileMap* map;
};

#endif