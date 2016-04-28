#include "AbstractEntity.h"

#ifndef BLOC_H
#define BLOC_H

class Bloc : public AbstractEntity {
public:
	float getPosX();
	void setPosX(float posX);
	float getPosY();
	void setPosY(float posY);
	bool getState();
	void setState(bool state);
	void Update();
	void Draw();
private:
	float posX;
	float posY;
	bool state;
};

#endif