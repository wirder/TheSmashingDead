#pragma once
#include "World.h"
#include "Debug.h"

World::World()
{
	player = new Player();
}

void World::draw()
{
		TileMap map;
		Game* game = Game::getInstance();

		game->getWindow()->draw(map);
		/*
			TENTATIVE AFFICHAGE PLAYER 

		Vector2f center(player.getPosX(), player.getPosY());
		Vector2f halfSize(1280, 768);
		View view(center, halfSize);
		game->getWindow()->setView(view);
	
		player->setPosition(player->getPosX(), player->getPosY());
		game->getWindow()->draw(player->getPlayer());
		*/
}
void World::moveSelection(Vector2f vector) {
	player->setPosX(vector.x);
	player->setPosY(vector.y);
}
Player* World::getPlayer()
{
	return player;
}