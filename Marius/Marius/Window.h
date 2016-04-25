#include <SFML/Graphics.hpp>

#ifndef WINDOW_H
#define WINDOW_H

class Window : public sf::RenderWindow {
public:
	void init();
	void update(sf::CircleShape shape);
	void setLng(int newLng);
	void setLarg(int newLarg);
	int  getLng();
	int  getLarg();
private:
	int lng;
	int larg;
	std::string nom;
};

#endif // !WINDOW_H
