#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class MovingObject : public Object {
public:
	MovingObject(sf::Vector2f pos, sf::Color color);
	void draw(sf::RenderWindow& window) const override;
	sf::Vector2i GetPosOnGrid(sf::Vector2f pos) const;
	sf::RectangleShape getShape() const;
protected:
	sf::Vector2f m_direction;
	sf::RectangleShape m_shape;
	float m_speed = 100.0f; 
};
