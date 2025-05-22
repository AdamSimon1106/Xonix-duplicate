//
// Created by Adam Simonov on 12/5/25.
//

#include "../include/Board.h"

Board::Board(sf::Vector2i screenSize) : m_screenSize(screenSize), m_grid(screenSize.y, std::vector<Tile>(screenSize.x ,Tile::Empty))
{}

void Board::loadLevel(const LevelData& levelData)
{
	//reset last level
	reset();
	//load level
	for(unsigned y = 0; y < m_screenSize.y; ++y) {
		for (unsigned x = 0; x < m_screenSize.x; ++x) {
			if (y == 0 || y == m_screenSize.y - 1 || x == 0 || x == m_screenSize.x - 1) {
				m_grid[y][x] = Tile::Border;
			}
			if()
		}
	}
	
	

}

int Board::getFillPresentage() const
{
	return 0;
}

Tile Board::getTileAt(const int& x, const int& y) const
{
	return Tile();
}

void Board::setTileAt(const int& x, const int& y, Tile newTile)
{
}

bool Board::isInside(const int& x, const int& y) const
{
	return false;
}

bool Board::isWalkable(const int& x, const int& y) const
{
	return false;
}

void Board::floodFillFrom(int x, int y)
{
}

void Board::fillArea()
{
}

sf::Vector2i Board::getSize() const
{

};

void Board::reset()
{

};