#include "EntityManager.h"
#include "Bloc.h"
#include "Enemy.h"
#include "Player.h"

using namespace std;

AbstractEntity *EntityManager::create(string type) {
	if (type == "bloc")
		return new Bloc();
	else if (type == "ennemy")
		return new Enemy();
	else if (type == "player")
		return new Player();
}
