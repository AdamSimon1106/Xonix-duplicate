// Created by Adam Simonov and Benny Beer, 2025
// TODO(adam): implement Board::updatePath and commit closed area
#pragma once
#include "Tile.h"
#include "FileParser.h"
#include <vector>
#include "Trail.h"
#include <SFML/Graphics.hpp>

class Board {
private:
	sf::Vector2i m_screenSize;
	std::vector<std::vector<Tile>> m_grid;
	Trail* m_trail = nullptr;

public:
	Board(sf::Vector2i screenSize /*Trail& trail*/);
	void loadLevel(const LevelData& levelData);
	int getFillPresentage() const;

	Tile getTileAt(const int& x, const int& y) const;
	void setTileAt(const int& x, const int& y, Tile newTile);

	void setTileType(const int& x, const int& y, TileType type);

	bool isInside(const int& x, const int& y) const;

	bool isCollidewithclosedArea(sf::RectangleShape square) const;
	//bool isWalkable(const int& x, const int& y) const;
	//
	//void floodFillFrom(int x, int y);
	//void fillArea();

	sf::Vector2i getSize() const;
	void render(sf::RenderWindow& window);
	//void reset();
};
