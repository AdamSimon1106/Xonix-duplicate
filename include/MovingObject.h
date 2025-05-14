#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
//abstract class MovingObject <-- enemy, player;

class MovingObject {
public:
	MovingObject(const sf::Vector2i& startPosition);
	virtual ~MovingObject() = default;
	virtual void draw(sf::RenderWindow& window) const = 0;
	virtual void update(const sf::Time& deltaTime) = 0;
	virtual void InWindow(sf::Vector2f& newPosition) = 0;


	void setTextur(sf::Color color);
protected:
	sf::Vector2i m_startPosition;
	sf::Vector2f m_position;
	sf::Vector2i m_direction;

	sf::Sprite m_sprite;
	sf::Texture m_texture;

	float m_speed = 100.0f;
	
private:
	
};