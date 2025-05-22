#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Trail.h"

//abstract class MovingObject <-- enemy, player;

class MovingObject {
public:
	MovingObject(const sf::Vector2i& startPosition);
	virtual ~MovingObject() = default;
	virtual void draw(sf::RenderWindow& window) const;
	virtual void update(const sf::Time& deltaTime) = 0;
	virtual void InWindow(sf::Vector2f& newPosition) = 0;
	//bool checkCollisionWithTrail(Trail& trail);
	sf::Vector2f getPoint();
	void setPosition(sf::Vector2f pos);
	sf::Vector2f getStartPos();


	void setTextur(sf::Color color);
protected:
	sf::Vector2f m_startPosition;
	sf::RectangleShape m_shape;
	sf::Vector2f m_direction;
	float m_speed = 100.0f;
	
private:
	
};