#pragma once
#include "World.h"
#include "Debug.h"

World::World()
{
	player = new Player();
	map = new TileMap();
}

void World::draw()
{
	Game *game = Game::getInstance();
	game->getWindow()->draw(*map);
	player->Draw();
}
void World::moveSelection(Vector2f vector) {
	Game *game = Game::getInstance();
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