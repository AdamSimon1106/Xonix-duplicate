#include "MovingObject.h"
//new
MovingObject::MovingObject(const sf::Vector2i& startPosition)
	:m_startPosition(startPosition.x, startPosition.y), m_direction(0, 0)
{
	m_shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));

	m_shape.setPosition(m_startPosition);
}

void MovingObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_shape);
}

void MovingObject::setTextur(sf::Color color)
{
	m_shape.setFillColor(color);
}

void MovingObject::setPosition(sf::Vector2f pos)
{
	m_shape.setPosition(pos);
}

bool MovingObject::checkCollisionWithTrail(Trail& trail)
{
	m_collide = trail.checkColistions(m_shape);
	return m_collide;
}


sf::Vector2f MovingObject::getPoint()
{
	return m_shape.getPosition();
}

sf::Vector2f MovingObject::getStartPos() const
{
	return m_startPosition;
}

sf::Vector2i MovingObject::getPosOnGrid() const
{
	sf::Vector2f pos = m_shape.getPosition();
	int x = static_cast<int>(pos.x / CELL_SIZE);
	int y = static_cast<int>(pos.y / CELL_SIZE);

	return sf::Vector2i(x, y);
	
}
