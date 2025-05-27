#pragma once

#include <SFML/Graphics.hpp>
#include "GridManager.h"
#include "Enemy.h"

class AreaCloser{
public:
	AreaCloser(GridManager& gridManager);
	bool isclosingArea(const std::vector<sf::Vector2f>& path, std::vector<Enemy> enemys);
	bool containEnemy(sf::Vector2f edge1, sf::Vector2f edge2, const std::vector<Enemy>& enemys) const;
private:
	GridManager& m_gridMannager;
};