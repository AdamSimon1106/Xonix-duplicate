//
// Created by Adam Simonov on 12/5/25.
//

#include "../include/Board.h"
#include "../include/MovingObject.h"
#include "../include/Enemy.h"
#include <iostream>
#include <queue> 
#include <iostream>
using Pos = std::pair<int, int>;

//initialize m_grid to empty tiles (relying of the tile c-tor)
Board::Board(sf::Vector2i screenSize/* Trail& trail*/) : m_screenSize(screenSize), m_grid(screenSize.y, std::vector<Tile>(screenSize.x))

{
	loadLevel(LevelData{});
}

void Board::loadLevel(const LevelData& levelData)
{
	
	std::ofstream outFile2("board.txt");
	if (!outFile2) {
		//std::cerr << "Failed to open file: " << filename << std::endl;
		return;
	}
	
	for(unsigned y = 0; y < m_screenSize.y; ++y) {
		for (unsigned x = 0; x < m_screenSize.x; ++x) {
			if (y == 0 || y == m_screenSize.y - 1 || x == 0 || x == m_screenSize.x - 1) {
				m_grid[y][x].setType(TileType::Filled);
				m_grid[y][x].setColor(sf::Color::Green);
				m_grid[y][x].setPosition(x, y);
				outFile2 << static_cast<int>(TileType::Filled) << " "; // Save the tile type to the file
			}
			else {
				m_grid[y][x].setType(TileType::Empty);
				outFile2 << static_cast<int>(TileType::Empty) << " "; // Save the tile type to the file
			}
		}
		outFile2 << "\n"; // New line for each row
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
	if (nextTile.getType() == TileType::Filled &&
		m_grid[pos.y][pos.x].getType() != TileType::Filled) {
		std::cout << "Collision with closed area at: " << x << ", " << y << std::endl;
		return true;
	}

	return false;
}

void Board::closeEnclosedArea(std::vector<sf::RectangleShape> trail)
{
	for (const auto& shape : trail)
	{
		int x = static_cast<int>(shape.getPosition().x / CELL_SIZE);
		int y = static_cast<int>(shape.getPosition().y / CELL_SIZE);
		if (isInside(x, y)) {
			
			setTileType(y, x, TileType::Filled);
		}
	};
	std::ofstream outFile3("trail.txt");
	for (int y = 0; y < m_screenSize.y; ++y) {
		for (int x = 0; x < m_screenSize.x; ++x) {
			outFile3 << static_cast<int>(m_grid[y][x].getType()) << " ";
		}
		outFile3 << "\n"; // New line for each row
	}

	floodFillFromBorder();
	std::ofstream outFile("floodfill.txt");
	for (int y = 0; y < m_screenSize.y; ++y) {
		for (int x = 0; x < m_screenSize.x; ++x) {
			outFile << static_cast<int>(m_grid[y][x].getType()) << " ";
		}
		outFile << "\n"; // New line for each row
	}

	int rows = m_grid.size();
	int cols = m_grid[0].size();

	for (int y = 0; y < rows; ++y) {
		for (int x = 0; x < cols; ++x) {
			if (m_grid[y][x].getType() == TileType::Empty)
			{
				m_grid[y][x].setType(TileType::Filled);
				m_grid[y][x].setColor(sf::Color::Green); // צבע את השטח הסגור בירוק
				m_grid[y][x].setPosition(x, y); // עדכון המיקום של הטיל
			}

			else if (m_grid[y][x].getType() == TileType::Visited)
				m_grid[y][x].setType(TileType::Empty);
			else if (m_grid[y][x].getType() == TileType::Trail)
				m_grid[y][x].setType(TileType::Filled); // השביל הופך לשטח סגור
		}
	}
}

void Board::floodFillFromBorder()
{
	int rows = m_grid.size();
	int cols = m_grid[0].size();
	std::queue<Pos> q;

	auto inBounds = [&](int y, int x) {
		return y >= 0 && y < rows && x >= 0 && x < cols;
		};

	// התחלה מהגבולות
	for (int y = 0; y < rows; ++y) {
		for (int x : {0, cols - 1}) {
			if (m_grid[y][x].getType() == TileType::Empty) {
				q.push({ y, x });
				m_grid[y][x].setType(TileType::Visited);
			}
		}
	}

	for (int x = 0; x < cols; ++x) {
		for (int y : {0, rows - 1}) {
			if (m_grid[y][x].getType() == TileType::Empty) {
				q.push({ y, x });
				m_grid[y][x].setType(TileType::Visited);
			}
		}
	}

	// BFS
	std::vector<Pos> directions = { {0,1}, {1,0}, {0,-1}, {-1,0} };
	while (!q.empty()) {
		auto [y, x] = q.front(); q.pop();
		for (auto [dy, dx] : directions) {
			int ny = y + dy, nx = x + dx;
			if (inBounds(ny, nx) && m_grid[ny][nx].getType() == TileType::Empty) {
				m_grid[ny][nx].setType(TileType::Visited);
				q.push({ ny, nx });
			}
		}
	}
}

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