// Created by Adam Simonov and Benny Beer, 2025
// TODO(adam): implement Board::updatePath and commit closed area
#pragma once
#include "Tile.h"
#include "FileParser.h"
#include <vector>
#include<SFML/System/Vector2.hpp>

class Board {
private:
	sf::Vector2i m_screenSize;
	std::vector<std::vector<Tile>> m_grid;

public:
	Board(sf::Vector2i screenSize);
	void loadLevel(const LevelData& levelData);
	int getFillPresentage() const;

	Tile getTileAt(const int& x, const int& y) const;
	void setTileAt(const int& x, const int& y, Tile newTile);

	bool isInside(const int& x, const int& y) const;
	//bool isWalkable(const int& x, const int& y) const;
	//
	//void floodFillFrom(int x, int y);
	//void fillArea();

	sf::Vector2i getSize() const;
	void render(sf::RenderWindow& window);
	void reset();
};
