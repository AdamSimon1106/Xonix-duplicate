#include "AreaCloser.h"
#include "Tile.h"
#include <iostream>
#include <stack>

AreaCloser::AreaCloser(GridManager& gridManager)
	: m_gridMannager(gridManager)
{
}

void AreaCloser::fillArea(const std::vector<sf::Vector2f>& path, const std::vector<Enemy> enemies)
{
	setTrailOnGrid(path);
	for (const auto& enemy : enemies)
	{
		floodFill(enemy.getPosition());
	}
	for (int y = 0; y < m_gridMannager.getHeight(); ++y) {
		for (int x = 0; x < m_gridMannager.getWidth(); ++x) {
			Tile& tile = m_gridMannager(sf::Vector2i(x, y));
            if (tile.getType() != TileType::Temp) {
                tile.setType(TileType::Filled);
                tile.setColor(sf::Color::Blue);
                tile.setPosition(x, y);
            }
            else if (tile.getType() == TileType::Temp) {
                tile.setType(TileType::Empty);
            }

		}
	}
}

void AreaCloser::floodFill(sf::Vector2f inerPos) {
    sf::Vector2i gridPos(m_gridMannager.getPosOnGrid(inerPos));
    int startRow = gridPos.y;
    int startCol = gridPos.x;

    if (!(m_gridMannager.isInGrid(gridPos))) return;
    if (m_gridMannager(gridPos).getType() == TileType::Filled) return;
	if (m_gridMannager(gridPos).getType() == TileType::Temp) return;

    std::stack<std::pair<int, int>> stack;
    stack.push({ startCol, startRow });

    while (!stack.empty()) {
        auto [row, col] = stack.top();
        stack.pop();

        Tile& tile = m_gridMannager(sf::Vector2i(row, col));
        if (tile.getType() == TileType::Filled || tile.getType() == TileType::Temp || tile.getType() == TileType::Border)
            continue;

        tile.setType(TileType::Temp);

        const int dr[4] = { -1, 1, 0, 0 };
        const int dc[4] = { 0, 0, -1, 1 };

        for (int dir = 0; dir < 4; ++dir) {
            int newRow = row + dr[dir];
            int newCol = col + dc[dir];

            if (!m_gridMannager.isInGrid(sf::Vector2i(newCol, newRow))) continue;

            Tile& neighbor = m_gridMannager(sf::Vector2i(newRow, newCol));
            if ((neighbor.getType() != TileType::Filled &&
                neighbor.getType() != TileType::Temp)) {
                stack.push({ newRow, newCol });
            }
        }
    }
}
//TO DO check diferences between points
void AreaCloser::setTrailOnGrid(const std::vector<sf::Vector2f>& path)
{
    for (size_t i = 1; i < path.size(); ++i)
    {
        sf::Vector2i p0 = m_gridMannager.getPosOnGrid(path[i - 1]);
        sf::Vector2i p1 = m_gridMannager.getPosOnGrid(path[i]);

        drawLineOnGrid(p0, p1);
    }


}

void AreaCloser::drawLineOnGrid(sf::Vector2i from, sf::Vector2i to)
{
    int deltaX = abs(to.x - from.x);
    int deltaY = abs(to.y - from.y);

    int stepX = (from.x < to.x) ? 1 : -1;
    int stepY = (from.y < to.y) ? 1 : -1;

    int error = deltaX - deltaY;

    while (true) {
        m_gridMannager(from).setType(TileType::Filled);
        m_gridMannager(from).setColor(sf::Color::Blue);
        m_gridMannager(from).setPosition(from.x, from.y);

        if (from == to) break;

        int doubleError = 2 * error;

        if (doubleError > -deltaY) {
            error -= deltaY;
            from.x += stepX;
        }

        if (doubleError < deltaX) {
            error += deltaX;
            from.y += stepY;
        }
    }

}

