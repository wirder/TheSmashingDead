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
	this->posX = 100;
	this->posY = 100;
	this->playerSprite.setPosition(this->posX, this->posY);
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
			// on récupère le numéro de tuile courant
			int tileNumber = tiles[i + j * width];
			// on en déduit sa position dans la texture du tileset
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv =  tileNumber / (m_tileset.getSize().x / tileSize.x);

			// on récupère un pointeur vers le quad à définir dans le tableau de vertex
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			// on définit ses quatre coins
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// on définit ses quatre coordonnées de texture
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


void Player::jump(float posY) {
	this->stateJump = true;
	this->posY = posY++;
}

void Player::attack() {

}

void Player::move(Vector2f vector) {
	this->posX += vector.x;
	this->posY += vector.y;
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
}