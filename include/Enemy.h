// Created by Adam Simonov and Benny Beer, 2025
// TODO(benny): implement Enemy diagonal movement and collision logic
#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Board;

enum  class Direction
{
	RIGHT,
	LEFT,
	DOWN,
	UP
};

class Enemy : public MovingObject{
public:
	Enemy(const sf::Vector2f& startPosition, const Board& board);
	void update(sf::Time deltaTime) override;
	void InWater(sf::Vector2f& newPosition);
	void setInWindow(sf::Vector2f& newPosition);
	void setDirection();
private:
	Board* m_board = nullptr;
	Direction m_directionType;
	
};
