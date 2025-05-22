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
	const float distance(const sf::Vector2f x1,const sf::Vector2f x2) const;
	
	std::vector<sf::RectangleShape> m_path;
	
	bool m_collide = false;



};