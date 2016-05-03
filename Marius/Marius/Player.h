#include "AbstractEntity.h"
#include <SFML/Graphics.hpp>

#ifndef PLAYER_H
#define PLAYER_H
using namespace sf;

class Player : public AbstractEntity {
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
	Player();
private:
	float posX;
	float posY;
	int numLive;
	bool stateJump;
	bool isAlive;
};

#endif