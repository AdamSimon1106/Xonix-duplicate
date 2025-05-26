#include "Trail.h"
#include <iostream>

Trail::Trail(int size)
{
	
}
//to do check diraction changing
void Trail::updatePath(sf::Vector2f point)
{
	setDirection();
	/*if (m_collide == true)
	{
		m_path.clear();
		m_collide = false;
	}*/
	
	if (!m_path.empty()) {
		const sf::Vector2f& lastPos = m_path.back().getPosition();
		
		float dis = distance(lastPos, point);
		if (dis > CELL_SIZE/3) 
		{
			setAndPushLastRect(point);
			return;
		}
		return;
	}
	setAndPushLastRect(point);
	
	
}

void Trail::draw(sf::RenderWindow& window) const
{
	for (const auto& point : m_path)
	{
		
		window.draw(point);
	}
}

bool Trail::checkColistions(const sf::RectangleShape& objBounde)
{
	if (m_path.size() < 3)
		return false;
	sf::FloatRect intersection;
	for (auto it = m_path.begin(); it != m_path.end() - 3; ++it)
	{
		if (it->getGlobalBounds().intersects(objBounde.getGlobalBounds(), intersection))
		{
			
			// תנאי: רק אם השטח מספיק משמעותי
			if (intersection.height > 6 && intersection.width >6)
			{
				std::cout << "colide at" << it->getPosition().x << " " << it->getPosition().y << "\n";
				std::cout << objBounde.getPosition().x << " " << objBounde.getPosition().y << "\n";

				handlecolisions();
				return true;
			}
		}
	}
	return false;

}



void Trail::handlecolisions()
{
	m_collide = true;
	m_path.clear();
}

void Trail::setDirection()
{
	if (m_path.size() < 2)
		return;
	m_direction = m_path.back().getPosition() - m_path[m_path.size() - 2].getPosition();
	
}

const sf::RectangleShape Trail::getLastRect() const
{
	if (m_path.size() < 2)
		return sf::RectangleShape();
	return m_path.back();
}

void Trail::setAndPushLastRect(sf::Vector2f point)
{
	sf::RectangleShape square;
	square.setSize({ CELL_SIZE, CELL_SIZE });

	square.setPosition(point);
	square.setFillColor(sf::Color::Magenta);
	m_path.push_back(square);
	std::cout << "add point: " << point.x << " " << point.y << "\n";

}

std::vector<sf::RectangleShape> Trail::getPath() const
{
	return m_path;
}

const float Trail::distance(const sf::Vector2f x1, const sf::Vector2f x2) const
{
	float dx = abs(x1.x - x2.x);
	float dy = abs(x1.y - x2.y);
	return sqrt(dx*dx + dy*dy);
}





