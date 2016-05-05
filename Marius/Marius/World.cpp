#pragma once
#include "World.h"
#include "Debug.h"
#include "colisionManager.h"
World::World()
{
	player = new Player();
	map = new TileMap();
	cm = new colisionManager();
}

void World::draw()
{
	Game *game = Game::getInstance();
	game->getWindow()->draw(*map);
	player->Draw();
}
void World::moveSelection(Vector2f vector, bool jump) {
	if (jump)
		player->jump(true);
	Game *game = Game::getInstance();
	if (cm->Update(player) == 1) {
		player->setPosX(player->getCoord().x - 10);
	} else if (cm->Update(player) == 2) {
		//player->setPosX(player->getCoord().y - 1);
	}
	player->move(vector);


	Vector2f vectorView = player->getCoord();
	vectorView.y -= 130;
	game->getView()->setCenter(vectorView);
	game->getWindow()->setView(*game->getView());
}

Player* World::getPlayer()
{
	return player;
}