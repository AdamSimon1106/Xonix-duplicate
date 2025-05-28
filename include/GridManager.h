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
	sf::Vector2i getPosOnGrid(sf::Vector2f pos) const;
	Tile& operator()(sf::Vector2i tilePos);
	bool isInGrid(sf::Vector2i pos);
	bool isOnFilledTile(sf::Vector2i point) const; 
	

	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
private:
	std::vector<std::vector<Tile>> m_grid;
	unsigned int m_width;
	unsigned int m_height;
};
