#pragma once

#include <SFML/Graphics.hpp>
#include "GridManager.h"
#include "Enemy.h"

class AreaCloser{
public:
	AreaCloser(GridManager& gridManager);
	void fillArea(const std::vector<sf::Vector2f>& path, const std::vector<Enemy> enemies);
	void floodFill(sf::Vector2f inerPos);
	void setTrailOnGrid(const std::vector<sf::Vector2f>& path);
	void drawLineOnGrid(sf::Vector2i from, sf::Vector2i to);
	
private:
	GridManager& m_gridMannager;
};