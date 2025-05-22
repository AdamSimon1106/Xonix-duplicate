#include "Trail.h"
#include <iostream>

Trail::Trail(int size)
{
}

void Trail::updatePath(sf::Vector2f point)
{
	if (m_collide == true)
	{
		m_path.clear();
		m_collide = false;
	}
	if (!m_path.empty()) {
		const sf::Vector2f& lastPos = m_path.back().getPosition();

		if (distance(lastPos, point) < CELL_SIZE-1) 
		{
			return;
		}
			
	}

	sf::RectangleShape square;
	//square.getGlobalBounds().contains(point);

	square.setSize({ CELL_SIZE, CELL_SIZE });

	square.setPosition(point);
	square.setFillColor(sf::Color::Magenta); // או כל צבע שתבחר
	m_path.push_back(square);

	
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
	if (m_path.size() < 1)
		return false;
	sf::FloatRect intersection;
	for (auto it = m_path.begin(); it != m_path.end() - 1; ++it)
	{
		if (it->getGlobalBounds().intersects(objBounde.getGlobalBounds(), intersection))
		{
			
			// תנאי: רק אם השטח מספיק משמעותי
			if (intersection.height > 1 && intersection.width >1)
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
}





