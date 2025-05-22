#include "Trail.h"
#include <iostream>

Trail::Trail(int size)
{
}

void Trail::updatePath(sf::Vector2f point)
{
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
	square.setFillColor(sf::Color::Magenta); // �� �� ��� �����
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
			
			// ����: �� �� ���� ����� �������
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
	m_path.clear();
}


//bool Trail::colideWithObject(const sf::FloatRect& playerBounds)
//{
//	if (m_path.size() < 1) 
//		return false;
//
//	for (auto it = m_path.begin(); it != m_path.end(); ++it)
//	{
//		sf::FloatRect trailRect(*it, trailShape.getSize());
//		if (trailRect.intersects(playerBounds))
//			return true;
//	}
//	return false;
//}

//bool Trail::collideWithObj(sf::Vector2f objPos) const {
//	if (m_path.size() < 1)
//		return false;
//	for (auto it = m_path.begin(); it != m_path.end() - 1; ++it)
//	{
//		
//		if (*it == objPos)
//		{
//			std::cout << it->x << " " << it->y << " " << objPos.x << " " << objPos.y << '\n';
//			return true;
//		}
//			
//	}
//	return false;
//
//}

//bool Trail::checkColision(sf::Vector2f point) const
//{
//	if (m_path.size() < 1)
//		return false;
//	for (auto it = m_path.begin(); it != m_path.end(); ++it)
//	{
//		sf::FloatRect trailRect(*it, trailShape.getSize());
//		sf::FloatRect playerRect(point, trailShape.getSize());
//		if (trailRect.intersects(playerRect))
//			return true;
//	}
//}


