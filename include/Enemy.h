// Created by Adam Simonov and Benny Beer, 2025
// TODO(benny): implement Enemy diagonal movement and collision logic
#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"


class Enemy : public MovingObject{
public:
	Enemy(const sf::Vector2i& startPosition);
	void draw(sf::RenderWindow& window) const;
	void update(const sf::Time& deltaTime);
	void InWindow(sf::Vector2f& newPosition);
	void setDirection();
private:
	/*sf::Vector2i m_startPosition;
	sf::Vector2f m_position;

	sf::Vector2i m_direction;
	float m_speed = 100.0f;

	sf::Sprite m_sprite;
	sf::Texture m_texture;*/
};
