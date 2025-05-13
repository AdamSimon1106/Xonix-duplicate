#include "MovingObject.h"

MovingObject::MovingObject(const sf::Vector2i& startPosition)
	: m_startPosition(startPosition), m_position(static_cast<sf::Vector2f>(startPosition)) {
	
}

void MovingObject::setTextur(sf::Color color)
{
    sf::Image image;
    image.create(16, 16, color); 
    m_texture.loadFromImage(image);

    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(static_cast<sf::Vector2f>(m_startPosition));
}
