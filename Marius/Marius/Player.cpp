#include "Player.h"

void Player::goLeft(float posX) {
	this->posX = posX--;
}

void Player::goRight(float posX) {
	this->posX = posX++;
}

void Player::jump(float posY) {
	this->stateJump = true;
	this->posY = posY++;
}

void Player::attack() {

}

void Player::setPosX(float posX) {
	this->posX = posX;
}

float Player::getPosX() {
	return this->posX;
}

void Player::setPosY(float posY) {
	this->posY = posY;
}

float Player::getPosY() {
	return this->posY;
}

void Player::setNumLive(int numLive) {
	this->numLive = numLive;

	if (this->numLive > 0)
		this->isAlive = true;
	else
		this->isAlive = false;
}

int Player::getNumLive() {
	return this->numLive;
}