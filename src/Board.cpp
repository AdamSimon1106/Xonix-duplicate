//
// Created by Adam Simonov on 12/5/25.
//

#include "../include/Board.h"
#include "../include/MovingObject.h"
#include "../include/Enemy.h"
#include <iostream>
//initialize m_grid to empty tiles (relying of the tile c-tor)
Board::Board(sf::Vector2i screenSize/* Trail& trail*/) : m_screenSize(screenSize), m_grid(screenSize.y, std::vector<Tile>(screenSize.x))

{
	loadLevel(LevelData{});
}

void Board::loadLevel(const LevelData& levelData)
{
	std::cout << "in loadLevel\n";
	
	for(unsigned y = 0; y < m_screenSize.y; ++y) {
		for (unsigned x = 0; x < m_screenSize.x; ++x) {
			if (y == 0 || y == m_screenSize.y - 1 || x == 0 || x == m_screenSize.x - 1) {
				m_grid[y][x].setType(TileType::Filled);
				m_grid[y][x].setColor(sf::Color::Green);
				m_grid[y][x].setPosition(x, y);
			}
			else {
				m_grid[y][x].setType(TileType::Empty);
			}
		}
	}
	//set the starting position for the enemies
	/*for (const Enemy& e : levelData.enemies) {
		auto pos = e.getStartPos();
		m_grid[pos.x][pos.y].setType(TileType::Enemy);
	}*/
	
}
//TODO
int Board::getFillPresentage() const
{
	return 0;
}

Tile Board::getTileAt(const int& x, const int& y) const
{
	if (x < 0 || x > m_screenSize.x - 1 || y < 0 || y > m_screenSize.y - 1) {
		throw std::out_of_range("Coordinates out of bounds");
	}
	
	return m_grid[y][x];
}

void Board::setTileAt(const int& x, const int& y, Tile newTile)
{
	m_grid[y][x] = newTile;
}

void Board::setTileType(const int& x, const int& y, TileType type)
{
	m_grid[x][y].setType(type);
	std::cout << x << " " << y << "\n";
	std::cout << "in setTileType\n";
	
}

bool Board::isInside(const int& x, const int& y) const
{
	if (y < m_screenSize.y - 1 && y > 0 && x < m_screenSize.x - 1 && x > 0) {
		return true;
	}
	return false;
}

bool Board::isCollidewithclosedArea(sf::Vector2i pos, sf::Vector2f dir) const
{
	
	sf::Vector2i offset = static_cast<sf::Vector2i>(dir);

	int x = pos.x + offset.x;
	int y = pos.y + offset.y;

	std::cout << "Checking collision at: " << x << ", " << y << std::endl;
	if (x < 0 || x >= m_screenSize.x || y < 0 || y >= m_screenSize.y) {
		return false; // מחוץ לגבולות => לא התנגשות
	}

	const auto& nextTile = m_grid[y][x];

	// רק אם השחקן *עוד לא* נמצא על Border, ובכיוון הבא יש Border
	if (nextTile.getType() == TileType::Border &&
		m_grid[pos.y][pos.x].getType() != TileType::Border) {
		std::cout << "Collision with closed area at: " << x << ", " << y << std::endl;
		return true;
	}

	return false;
}

//bool Board::isWalkable(const int& x, const int& y) const
//{
//	if (m_grid[y][x] == Tile::Empty || m_grid[y][x] == Tile::Filled) {
//		return true;
//	}
//	return false;
//}

//void Board::floodFillFrom(int x, int y)
//{
//	if (!isInside(x, y)) return;
//	if (getTileAt(x, y) != Tile::Empty) return;
//
//	setTileAt(x, y, Tile::temp);
//
//	floodFillFrom(x + 1, y);
//	floodFillFrom(x - 1, y);
//	floodFillFrom(x, y + 1);
//	floodFillFrom(x, y - 1);
//}


//void Board::fillArea()
//{
//	unsigned width = m_screenSize.x;
//	unsigned height = m_screenSize.y;
//	// Step 1: Flood-fill from all border positions
//	for (int x = 0; x < static_cast<int>(width); ++x) {
//		floodFillFrom(x, 0);
//		floodFillFrom(x, height - 1);
//	}
//	for (int y = 0; y < static_cast<int>(height); ++y) {
//		floodFillFrom(0, y);
//		floodFillFrom(width - 1, y);
//	}
//
//	// Step 2: Fill enclosed area and clean up
//	for (int y = 0; y < static_cast<int>(height); ++y) {
//		for (int x = 0; x < static_cast<int>(width); ++x) {
//			Tile tile = getTileAt(x, y);
//			if (tile == Tile::Empty || tile == Tile::Trail) {
//				setTileAt(x, y, Tile::Filled);
//			}
//			else if (tile == Tile::temp) {
//				setTileAt(x, y, Tile::Empty);
//			}
//		}
//	}
//}


sf::Vector2i Board::getSize() const
{
	return m_screenSize;
};

void Board::render(sf::RenderWindow& window)
{
	for (auto& row : m_grid) {
		for (auto& tile : row) {
			tile.draw(window);
			
		}
	} 
}

//void Board::reset()
//{
//	for (int y = 0; y < m_screenSize.y; ++y) {
//		for (int x = 0; x < m_screenSize.x; ++x) {
//			m_grid[y][x] == Tile::Empty;
//		}
//	}
//};