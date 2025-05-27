#pragma once

#include <SFML/Graphics.hpp>
#include "Macros.h"

class Trail {
public:
	Trail();
	void update();
	void draw(sf::RenderWindow& window) const;
	void addPoint(const sf::Vector2f& point);
	void clear();
	float distanceToLastPoint(const sf::Vector2f& point) const;
	std::vector<sf::Vector2f> getPath() const;
private:
	std::vector<sf::Vector2f> m_path;
	
};