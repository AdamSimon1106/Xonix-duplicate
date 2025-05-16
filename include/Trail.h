#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class Trail {
public:
	Trail(int size);
	void updatePath(sf::Vector2f point);
	void draw(sf::RenderWindow& window) const;
	bool colideWithObject(const sf::FloatRect& playerBounds);
	void clearPath(); 
	std::vector<sf::Vector2f> m_path;
	mutable sf::RectangleShape trailShape;
	bool m_iscolide = false;


};