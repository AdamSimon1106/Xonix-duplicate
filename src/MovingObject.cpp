#include "MovingObject.h"

MovingObject::MovingObject(const sf::Vector2i& startPosition)
	: m_startPosition(startPosition), m_position(static_cast<sf::Vector2f>(startPosition)) {
	
}

bool MovingObject::checkCollisionWithTrail(Trail& trail)
{
    sf::FloatRect playerBounds = m_sprite.getGlobalBounds();
    return trail.colideWithObject(playerBounds);
}

sf::Vector2f MovingObject::getPoint()
{
    return m_position;
}

void MovingObject::setPosition(sf::Vector2f pos)
{
    m_position = pos;
}

sf::Vector2f MovingObject::getStartPos()
{
    return m_startPosition;
}

void MovingObject::setTextur(sf::Color color)
{
    sf::Image image;
    image.create(16, 16, color); 
    m_texture.loadFromImage(image);

    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(static_cast<sf::Vector2f>(m_startPosition));
}
