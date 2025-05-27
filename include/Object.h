#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class Object {
public:
	Object(sf::Vector2f pos);
	virtual ~Object() = default;
	//ask Adam
	virtual void update(sf::Time deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) const = 0;
	void setPosition(sf::Vector2f pos);
	sf::Vector2f getPosition() const;
protected:
	sf::Vector2f m_position;
};