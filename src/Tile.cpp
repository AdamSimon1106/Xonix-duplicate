#include "Tile.h"
#include "Macros.h"

Tile::Tile() : m_type(TileType::Empty)
{
	m_shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));	
}

void Tile::setType(TileType type) {
	m_type = type;
}
void Tile::draw(sf::RenderWindow& window) {
	window.draw(m_shape);
}

TileType Tile::getType() const
{
	return m_type;
}

void Tile::setColor(sf::Color color)
{
	m_shape.setFillColor(color);
}
