#include "AbstractEntity.h"

#ifndef PLAYER_H
#define PLAYER_H

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
private:
	float posX;
	float posY;
	int numLive;
	bool stateJump;
	bool isAlive;
};

#endif