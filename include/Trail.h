#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include <cmath>

class Trail {
public:
	Trail(int size);
	void updatePath(sf::Vector2f point);
	void draw(sf::RenderWindow& window) const;
	bool checkColistions(const sf::RectangleShape& objBounde);
	void handlecolisions();
	
	
	
private:
	float distance(sf::Vector2f x1, sf::Vector2f x2)
	{
		float dx = abs(x1.x - x2.x);
		float dy = abs(x1.y - x2.y);
		return dx>dy ? dx : dy;
	}
	std::vector<sf::RectangleShape> m_path;
	
	bool m_iscolide = false;


};