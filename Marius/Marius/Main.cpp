#include <SFML/Graphics.hpp>
#include "EventManager.h"
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "The Smashing Dead");
	Game game = Game(window);
	EventManager eManager = EventManager(game.getWindow());
	sf::CircleShape shape;
	shape = sf::CircleShape(100.f);
	shape.setFillColor(sf::Color::Green);
	window.display();

	while (window.isOpen())
	{
		eManager.manageEvent();
		shape.move(eManager.getVector());
		

	}

	return 0;
}
