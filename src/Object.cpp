#include "Object.h"

Object::Object(sf::Vector2f pos)
	:m_position(pos)
{
}

void Object::setPosition(sf::Vector2f pos)
{
	m_position = pos;
}

sf::Vector2f Object::getPosition() const
{
	return m_position;
}
