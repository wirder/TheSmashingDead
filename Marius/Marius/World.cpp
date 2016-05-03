#pragma once
#include "World.h"

World::World()
{

}

void World::draw()
{
		TileMap map;
		Player player;
		Game* game = Game::getInstance();
		game->getWindow()->draw(map);

		Vector2f center(player.getPosX(), player.getPosY());
		Vector2f halfSize(1280 / 4, 768 / 4);
		View view(center, halfSize);
		//game->getWindow()->setView(view);
		//game->getWindow()->draw(view);

}