#include "Bloc.h"

void Bloc::setPosX(float posX) {
	this->posX = posX;
}

float Bloc::getPosX() {
	return this->posX;
}

void Bloc::setPosY(float posY) {
	this->posY = posY;
}

float Bloc::getPosY() {
	return this->posY;
}

void Bloc::setState(bool state) {
	this->state = state;
}

bool Bloc::getState() {
	return this->state;
}