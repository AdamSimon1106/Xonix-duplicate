//
// Created by Adam Simonov on 12/5/25.
//

#include "../include/Board.h"

Board::Board(sf::Vector2i screenSize)
{
}

void Board::loadLevel(const LevelData& levelData)
{
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