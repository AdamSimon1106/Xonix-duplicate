#include "AreaCloser.h"
#include "AreaCloser.h"
#include <iostream>

AreaCloser::AreaCloser(GridManager& gridManager)
	: m_gridMannager(gridManager)
{
}
// todo: implement this function
bool AreaCloser::isclosingArea(const std::vector<sf::Vector2f>& path, std::vector<Enemy> enemys)
{
	return false;
}
//maybe not needed
bool AreaCloser::containEnemy(sf::Vector2f edge1, sf::Vector2f edge2, const std::vector<Enemy>& enemys) const
{
	sf::Vector2f topLeft(
		std::min(edge1.x, edge2.x),
		std::min(edge1.y, edge2.y)
	);

	// חישוב גודל המלבן
	sf::Vector2f size(
		std::abs(edge1.x - edge2.x),
		std::abs(edge1.y - edge2.y)
	);
	std::cout << "topLeft: " << topLeft.x << ", " << topLeft.y << std::endl;
	std::cout << "size: " << size.x << ", " << size.y << std::endl;
	// יצירת המלבן
	sf::RectangleShape rect(size);
	rect.setPosition(topLeft);
	for (const Enemy& enemy : enemys) {
		if (rect.getGlobalBounds().contains(enemy.getPosition())) {
			
			std::cout << "enemy position: " << enemy.getPosition().x << ", " << enemy.getPosition().y << std::endl;
			return true;
		}
		return false;
	}
}
