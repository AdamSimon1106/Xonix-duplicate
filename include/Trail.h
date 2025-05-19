#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include <cmath>

class Trail {
public:
	Trail(int size);
	void updatePath(sf::Vector2f point);
	void draw(sf::RenderWindow& window) const;
	bool colideWithObject(const sf::FloatRect& playerBounds);
	bool collideWithObj(sf::Vector2f objPos) const;
	void clearPath();
private:
	float distance(sf::Vector2f x1, sf::Vector2f x2)
	{
		float dx = x1.x - x2.x;
		float dy = x1.y - x2.y;
		return std::sqrt(dx * dx + dy * dy);
	}
	std::vector<sf::Vector2f> m_path;
	mutable sf::RectangleShape trailShape;
	bool m_iscolide = false;


};