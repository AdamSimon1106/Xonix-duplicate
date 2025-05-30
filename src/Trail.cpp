#include "Trail.h"
#include <iostream>

Trail::Trail()
{
}

void Trail::update()
{
}

void Trail::draw(sf::RenderWindow& window) const
{
	if (!m_path.empty())
	{
		for (const auto& point : m_path)
		{
			sf::RectangleShape square;
			square.setSize({ CELL_SIZE, CELL_SIZE });
			square.setPosition(point);
			square.setFillColor(sf::Color::Magenta);
			window.draw(square);
		}
	}
	
}

void Trail::addPoint(const sf::Vector2f& point)
{
	if (m_path.empty())
	{
		m_path.push_back(point);
		return;
	}
	if (m_path.back() == point)
	{
		return; // Do not add the same point consecutively
	}
	if (distanceToLastPoint(point) < CELL_SIZE * 0.2f) // Assuming distance is a method that calculates the distance between two points
	{
		return; // Do not add point if it's too close to the last point
	}
	m_path.push_back(point);
}

void Trail::clear()
{
	m_path.clear();
}

float Trail::distanceToLastPoint(const sf::Vector2f& point) const
{
	if (m_path.empty())
	{
		return 0.0f; // No points in the trail
	}
	float dx = abs(m_path.back().x - point.x);
	float dy = abs(m_path.back().y - point.y);
	return sqrt(dx * dx + dy * dy);
}

std::vector<sf::Vector2f> Trail::getPath() const
{
	return m_path;
}

bool Trail::checkCollisions(MovingObject& obj) 
{
	sf::FloatRect objBounds = obj.getShape().getGlobalBounds();
	for (const auto& point : m_path)
	{
		sf::FloatRect pointBounds(point.x, point.y, CELL_SIZE, CELL_SIZE);
		if (objBounds.intersects(pointBounds))
		{
			handleCollision();
			return true; 
		}
	}
	return false; 

}

void Trail::handleCollision()
{
	m_path.clear(); 
}












