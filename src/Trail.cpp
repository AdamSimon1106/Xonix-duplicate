#include "Trail.h"
#include <iostream>

Trail::Trail(int size)
	:trailShape(sf::Vector2f(size, size))
{
	trailShape.setFillColor(sf::Color(200, 0, 200, 150));
}

void Trail::updatePath(sf::Vector2f point)
{
	for (auto it = m_path.begin(); it != m_path.end(); it++)
	{
		if (*it == point)
		{
			return;
		}
			
	}
	
	std::cout << point.x << ' ' << point.y << '\n';
	m_path.push_back(point);
}

void Trail::draw(sf::RenderWindow& window) const
{
	for (const auto& point : m_path)
	{
		trailShape.setPosition(point);
		window.draw(trailShape);
	}
}


bool Trail::colideWithObject(const sf::FloatRect& playerBounds)
{
	if (m_path.size() < 1) 
		return false;

	for (auto it = m_path.begin(); it != m_path.end(); ++it)
	{
		sf::FloatRect trailRect(*it, trailShape.getSize());
		if (trailRect.intersects(playerBounds))
			return true;
	}
	return false;
}

bool Trail::collideWithObj(sf::Vector2f objPos) const {
	if (m_path.size() < 1)
		return false;
	for (auto it = m_path.begin(); it != m_path.end() - 1; ++it)
	{
		
		if (*it == objPos)
		{
			std::cout << it->x << " " << it->y << " " << objPos.x << " " << objPos.y << '\n';
			return true;
		}
			
	}
	return false;

}

void Trail::clearPath()
{
	m_path.clear();
}


