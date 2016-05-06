#include "AbstractEntity.h"
#include <SFML/Graphics.hpp>

#ifndef ENNEMY_H
#define ENNEMY_H
using namespace sf;

class Enemy : public AbstractEntity {
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
public:
	void jump(bool fromEvent);
	void move(Vector2f vector);
	Vector2f getCoord();
	void attack();
	void Update();
	void Draw();
	Enemy();
	void setPosX(int x);
private:
	int bouge;
	float posX;
	float posY;
	int numLive;
	int animationLoop;
	float jumpLoop;
	int delayJump;
	bool stateJump;
	bool isAlive;
	Sprite playerSprite;
	Texture txPlayer;
	void setAnimation(int x);
};


#endif