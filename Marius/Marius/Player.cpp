#include "Player.h"
#include "Debug.h"
#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <math.h>

const sf::IntRect pos1(0, 0, 32, 64);
const sf::IntRect pos2(32, 0, 32, 64);
const sf::IntRect pos3(64, 0, 32, 64);
const sf::IntRect pos4(96, 0, 32, 64);
const sf::IntRect pos5(128, 0, 32, 64);
const sf::IntRect pos6(160, 0, 32, 64);
const sf::IntRect jumptx(192, 0, 32, 64);

Player::Player() {

	txPlayer = Texture();
	txPlayer.loadFromFile("res/sprites/hero/walk.png");
	// Create a sprite
	playerSprite = Sprite();
	playerSprite.setTexture(txPlayer);
	//this->playerSprite.setColor(sf::Color(255, 255, 255, 200));
	posX = 250; // Perfect pos JG : 250
	posY = 641; // Perfect pos JG : 517
	playerSprite.setPosition(this->posX, this->posY);
	playerSprite.setOrigin(16, 32);
	playerSprite.setTextureRect(pos3);
	animationLoop = 0;
	jumpLoop = 0;
	delayJump = 0;
	stateJump = false;
}


void Player::jump(bool fromEvent) {
	if (stateJump && fromEvent)
		return;
	if (jumpLoop < 0 && delayJump < 15)
		return;
	else if (delayJump >= 15) {
		delayJump = 0;
	}

	stateJump = true;
	if (jumpLoop > 4.60) {
		stateJump = false;
		jumpLoop = -0.1;
		delayJump++;
		posY -= 2.5;
	} else {
		(jumpLoop > 3.14) ? jumpLoop += 0.1 : jumpLoop += 0.2;
		posY -= sin(jumpLoop) * 8;
	}
}

void Player::attack() {

}

void Player::move(Vector2f vector) {
	if (vector.x != 0) {
		animationLoop++;
		setAnimation(vector.x);
	} else 
		playerSprite.setTextureRect(pos3);
	this->posX += vector.x;
	//this->posY += vector.y;
	playerSprite.setPosition(getCoord());
}

Vector2f Player::getCoord() {
	Vector2f vector = Vector2f();
	vector.x = this->posX;
	vector.y = this->posY;
	return vector;
}

void Player::setAnimation(int x) {
	if (x > 0)
		playerSprite.setScale(1.f, 1.f);
	else
		playerSprite.setScale(-1.f, 1.f);

	if (animationLoop > 30)
		animationLoop = 0;
	else if (animationLoop > 25)
		playerSprite.setTextureRect(pos6);
	else if (animationLoop > 20)
		playerSprite.setTextureRect(pos5);
	else if (animationLoop > 15)
		playerSprite.setTextureRect(pos4);
	else if (animationLoop > 10)
		playerSprite.setTextureRect(pos3);
	else if (animationLoop > 5)
		playerSprite.setTextureRect(pos2);
	else if (animationLoop > 0)
		playerSprite.setTextureRect(pos1);
	else if (stateJump)
		playerSprite.setTextureRect(jumptx);
}

void Player::Update()
{
}

void Player::Draw()
{ 
	delayJump++;
	if (stateJump) {
		playerSprite.setTextureRect(jumptx);
		jump(false);
	}
		
	Game* game = Game::getInstance();
	game->getWindow()->draw(playerSprite);
}