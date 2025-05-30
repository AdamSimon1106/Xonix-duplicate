#include "GridManager.h"
#include "Exception.h"

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
		m_grid[0][x].setType(TileType::Border);
		m_grid[0][x].setColor(sf::Color::Blue);

		m_grid[m_width - 1][x].setPosition(x, m_width - 1);
		m_grid[m_width - 1][x].setType(TileType::Border);
		m_grid[m_width - 1][x].setColor(sf::Color::Blue);
	}

	for (int y = 0; y < m_height; ++y)
	{
		m_grid[y][0].setPosition(0, y);
		m_grid[y][0].setType(TileType::Border);
		m_grid[y][0].setColor(sf::Color::Blue);

		m_grid[y][m_height - 1].setPosition(m_height - 1, y);
		m_grid[y][m_height - 1].setType(TileType::Border);
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

sf::Vector2i GridManager::getPosOnGrid(sf::Vector2f pos) const
{
	return sf::Vector2i(pos.x / CELL_SIZE, pos.y / CELL_SIZE);
}

Tile& GridManager::operator()(sf::Vector2i tilePos)
{
	if (isInGrid(tilePos))
		return m_grid[tilePos.y][tilePos.x];
}

bool GridManager::isInGrid(sf::Vector2i pos)
{
	if (pos.x < 0 || pos.x >= m_width || pos.y < 0 || pos.y >= m_height)
		throw OutOfBounds(pos);
		
	return true;
}

bool GridManager::isOnFilledTile(sf::Vector2i point) const
{
	return m_grid[point.y][point.x].getType() == TileType::Filled || m_grid[point.y][point.x].getType() == TileType::Border
		;
}

