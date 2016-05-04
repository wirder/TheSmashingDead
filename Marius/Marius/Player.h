#include "AbstractEntity.h"
#include <SFML/Graphics.hpp>

#ifndef PLAYER_H
#define PLAYER_H
using namespace sf;

class Player : public AbstractEntity, public sf::Drawable, public sf::Transformable {
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
public:
	void goLeft(float posX);
	void goRight(float posX);
	void jump(float posY);
	void attack();
	void setPosX(float posX);
	float getPosX();
	void setPosY(float posY);
	float getPosY();
	void setNumLive(int numLive);
	int getNumLive();
	void Update();
	void Draw();
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
	Sprite getPlayer();
	void moveSelection(Vector2f vector);
	Player();
private:
	float posX;
	float posY;
	int numLive;
	bool stateJump;
	bool isAlive;
	static Player* player;
	Sprite playerSprite;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif