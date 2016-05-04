#include "AbstractEntity.h"
#include <SFML/Graphics.hpp>

#ifndef PLAYER_H
#define PLAYER_H
using namespace sf;

class Player : public AbstractEntity {
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
public:
	void jump(float posY);
	void move(Vector2f vector);
	Vector2f getCoord();
	void attack();
	void Update();
	void Draw();
	Player();
private:
	float posX;
	float posY;
	int numLive;
	int animationLoop;
	bool stateJump;
	bool isAlive;
	Sprite playerSprite;
	Texture txPlayer;
	void setAnimation(int x);
};


#endif