#include <SFML/Graphics.hpp>
#include "EventManager.h"
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "The Smashing Dead");
	Menu menu = Menu(window);
	Game game = Game(window, menu);
	EventManager eManager = EventManager(game);
	sf::CircleShape shape;
	shape = sf::CircleShape(100.f);
	shape.setFillColor(sf::Color::Green);
	window.display();

	while (window.isOpen())
	{
		eManager.manageEvent();
		window.clear();
		game.draw();
		window.display();
		
		/* window.clear();
		window.draw(shape);
		window.display(); */
	}

	return 0;
}
