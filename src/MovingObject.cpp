#include "MovingObject.h"

MovingObject::MovingObject(sf::Vector2f pos, sf::Color color)
	:Object(pos)
{
	m_shape.setPosition(pos);
	m_shape.setOrigin(CELL_SIZE/2.f, CELL_SIZE/2.f);
	m_shape.setFillColor(color);
	m_shape.setSize(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
}

void MovingObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_shape);
}

sf::Vector2i MovingObject::GetPosOnGrid(sf::Vector2f pos) const
{
	return sf::Vector2i(pos.x/CELL_SIZE, pos.y/CELL_SIZE);
}

sf::RectangleShape MovingObject::getShape() const
{
	return m_shape; 
}
