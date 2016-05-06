#pragma once
#include "World.h"
#include "Debug.h"
#include "colisionManager.h"
World::World()
{
	player = new Player();
	enemy = new Enemy();
	map = new TileMap();
	cm = new colisionManager();
}

void World::draw()
{
	Game *game = Game::getInstance();
	game->getWindow()->draw(*map);
	player->Draw();
	enemy->Draw();
}
void World::moveSelection(Vector2f vector, bool jump) {
	if (jump)
		player->jump(true);
	Game *game = Game::getInstance();

	int up = cm->Update(player, enemy);
	if (up == 1) {
		player->setPosX(player->getCoord().x - 10);
	} else if (up == 2) {
		//player->setPosX(player->getCoord().y - 1);
	} else if (up == 3) {
		player->setPosX(player->getCoord().x - 10);
		DebugOut("Enemy detect");
		game->setIsMenu(true);
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