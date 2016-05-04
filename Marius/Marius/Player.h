#include "AbstractEntity.h"
#include <SFML/Graphics.hpp>

#ifndef PLAYER_H
#define PLAYER_H
using namespace sf;

class Player : public AbstractEntity, public sf::Drawable, public sf::Transformable {
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
public:
	void jump(float posY);
	void move(Vector2f vector);
	Vector2f getCoord();
	void attack();
	void Update();
	void Draw();
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
	Sprite *getPlayerSprite();
	Player();
private:
	float posX;
	float posY;
	int numLive;
	bool stateJump;
	bool isAlive;
	Sprite *playerSprite;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif