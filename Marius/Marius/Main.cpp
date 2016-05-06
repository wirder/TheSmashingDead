#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "EventManager.h"
#include "Game.h"

Game* Game::game = NULL;
EventManager* EventManager::eManager = NULL;

int main()
{
	Game *game = Game::getInstance();
	EventManager *eManager = EventManager::getInstance();

	sf::Music music;
	if (music.openFromFile("res/music.wav")) {
		music.setLoop(true);
		music.play();
	}
		

	while (game->getWindow()->isOpen())
	{
		eManager->manageEvent();
		game->Update();
		game->Draw();
	}

	return 0;
}
