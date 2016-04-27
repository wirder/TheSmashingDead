#include "AbstractEntity.h"

#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public AbstractEntity {
public:
	void goLeft();
	void goRight();
	void attack();
	void setPosX(float posX);
	float getPosX();
	void setPosY(float posY);
	float getPosY();
	void setState(bool state);
	bool getState();
	void Update();
	void Draw();
private:
	float posX;
	float posY;
	bool state;
};

#endif