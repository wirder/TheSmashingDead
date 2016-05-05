#include <SFML/Graphics.hpp>
#ifndef TILEMAP_H
#define TILEMAP_H

class TileMap : public sf::Drawable, public sf::Transformable {
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
public:
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
	TileMap();
	int getMap();
private:
	static TileMap* map;
	int level[];
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // !TILEMAP_H
                                                                                                                                                                                                                                                                                        