#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "EventManager.h"
#include "Game.h"

Game* Game::game = NULL;

int main()
{
	Game *game = Game::getInstance();
	
	EventManager eManager = EventManager();
	sf::CircleShape shape;
	shape = sf::CircleShape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Music music;
	if (music.openFromFile("res/music.wav"))
		music.play();

	while (game->getWindow()->isOpen())
	{
		eManager.manageEvent();
		game->draw();

		/*window.clear();
		window.draw(shape);
		window.display();*/
	}

	return 0;
}
