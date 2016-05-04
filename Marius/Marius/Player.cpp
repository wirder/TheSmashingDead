#include "Player.h"
#include "Debug.h"
#include "Game.h"
#include <cstdlib>
#include <iostream>

Player::Player() {

	txPlayer = Texture();
	txPlayer.loadFromFile("res/sprites/hero/down.png");
	// Create a sprite
	playerSprite = Sprite();
	playerSprite.setTexture(txPlayer);
	//this->playerSprite.setColor(sf::Color(255, 255, 255, 200));
	posX = 250; // Perfect pos JG : 250
	posY = 641; // Perfect pos JG : 517
	playerSprite.setPosition(this->posX, this->posY);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// on applique la transformation
	states.transform *= getTransform();

	// on applique la texture du tileset
	states.texture = &m_tileset;

	// et on dessine enfin le tableau de vertex
	target.draw(m_vertices, states);
}


void Player::jump(float posY) {
	this->stateJump = true;
	this->posY = posY++;
}

void Player::attack() {

}

void Player::move(Vector2f vector) {
	this->posX += vector.x;
	this->posY += vector.y;
	playerSprite.setPosition(getCoord());
}

Vector2f Player::getCoord() {
	Vector2f vector = Vector2f();
	vector.x = this->posX;
	vector.y = this->posY;
	return vector;
}

void Player::Update()
{
}

void Player::Draw()
{
	Game* game = Game::getInstance();
	game->getWindow()->draw(playerSprite);
}