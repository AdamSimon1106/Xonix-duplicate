#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include <cmath>
//#include "Board.h"
class Board;

class Trail {
public:
	Trail(int size);
	void updatePath(sf::Vector2f point);
	void draw(sf::RenderWindow& window) const;
	bool checkColistions(const sf::RectangleShape& objBounde);
	void handlecolisions();
	void setDirection();
	
	const sf::RectangleShape getLastRect() const;
	void setAndPushLastRect(sf::Vector2f point);

	std::vector<sf::RectangleShape> getPath() const;
	
private:
	const float distance(const sf::Vector2f x1,const sf::Vector2f x2) const;
	
	std::vector<sf::RectangleShape> m_path;
	
	bool m_collide = false;

	sf::Vector2f m_direction;



};