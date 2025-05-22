// Created by Adam Simonov and Benny Beer, 2025
// TODO(benny): implement Enemy diagonal movement and collision logic
#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"


class Enemy : public MovingObject{
public:
	Enemy(const sf::Vector2i& startPosition);
	void update(const sf::Time& deltaTime);
	void InWindow(sf::Vector2f& newPosition);
	void setDirection();
private:
	
};
