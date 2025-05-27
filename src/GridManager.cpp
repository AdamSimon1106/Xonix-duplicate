#include "GridManager.h"

GridManager::GridManager(int width, int height)
	: m_width(width), m_height(height)
{
	initializeGrid();
}

void GridManager::initializeGrid()
{
	m_grid.clear();
	m_grid.resize(m_height, std::vector<Tile>(m_width));

	for (int x = 0; x < m_width; ++x)
	{
		m_grid[0][x].setPosition(x, 0);
		m_grid[0][x].setType(TileType::Filled);
		m_grid[0][x].setColor(sf::Color::Blue);

		m_grid[m_width - 1][x].setPosition(x, m_width - 1);
		m_grid[m_width - 1][x].setType(TileType::Filled);
		m_grid[m_width - 1][x].setColor(sf::Color::Blue);
	}

	for (int y = 0; y < m_height; ++y)
	{
		m_grid[y][0].setPosition(0, y);
		m_grid[y][0].setType(TileType::Filled);
		m_grid[y][0].setColor(sf::Color::Blue);

		m_grid[y][m_height - 1].setPosition(m_height - 1, y);
		m_grid[y][m_height - 1].setType(TileType::Filled);
		m_grid[y][m_height - 1].setColor(sf::Color::Blue);
	}
}

void GridManager::draw(sf::RenderWindow& window)
{
	for (int y = 0; y < m_height; ++y)
	{
		for (int x = 0; x < m_width; ++x)
		{
			m_grid[y][x].draw(window);
		}
	}
}

bool GridManager::isOnFilledTile(sf::Vector2i point) const
{
	return m_grid[point.y][point.x].getType() == TileType::Filled;
}
