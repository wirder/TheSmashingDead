#include "Player.h"
#include "Debug.h"
#include <cstdlib>
#include <iostream>
Player::Player() {
	/*
	const int level[] =
	{
		1
	};
	Player::load("res/sprites/hero/down.png", sf::Vector2u(32, 32), level, 1, 2);
	*/
	sf::Texture texture;
	texture.loadFromFile("res/sprites/hero/down.png");
	// Create a sprite
	this->playerSprite.setTexture(texture);
	this->playerSprite.setTextureRect(sf::IntRect(100, 100, 64, 32));
	//this->playerSprite.setColor(sf::Color(255, 255, 255, 200));
	this->setPosX(100);
	this->setPosY(100);
	this->playerSprite.setPosition(this->getPosX(), this->getPosY());
}


void Player::moveSelection(Vector2f vector) {
	this->posX = vector.x;
	this->posY = vector.y;
}
bool Player::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{
	// on charge la texture du tileset
	if (!m_tileset.loadFromFile(tileset))
		return false;

	// on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	// on remplit le tableau de vertex, avec un quad par tuile
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// on r�cup�re le num�ro de tuile courant
			int tileNumber = tiles[i + j * width];
			// on en d�duit sa position dans la texture du tileset
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv =  tileNumber / (m_tileset.getSize().x / tileSize.x);

			// on r�cup�re un pointeur vers le quad � d�finir dans le tableau de vertex
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			// on d�finit ses quatre coins
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// on d�finit ses quatre coordonn�es de texture
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}

		

	return true;
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
void Player::Update()
{
}

void Player::Draw()
{
}