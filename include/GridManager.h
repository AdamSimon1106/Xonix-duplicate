#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Macros.h"
#include <vector>

class GridManager {
public:
	GridManager(int width, int height);
	void initializeGrid();
	void draw(sf::RenderWindow& window);

	bool isOnFilledTile(sf::Vector2i point) const; 
private:
	std::vector<std::vector<Tile>> m_grid;
	unsigned int m_width;
	unsigned int m_height;
};
