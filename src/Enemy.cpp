// Created by Adam Simonov and Benny Beer, 2025

#include "Enemy.h"
#include "Board.h"


Enemy::Enemy(const sf::Vector2f& startPosition, const Board& board)
	: MovingObject(startPosition, sf::Color::Green), m_board(const_cast<Board*>(&board))
{
	setDirection();
}

void Enemy::update(sf::Time deltaTime)
{
	sf::Vector2f moveDelta(
		m_direction.x * m_speed * deltaTime.asSeconds(),
		m_direction.y * m_speed * deltaTime.asSeconds()
	);

	sf::Vector2f newPosition = m_shape.getPosition() + moveDelta;
	/*if (m_board->isOnFilledTile(GetPosOnGrid(newPosition)))
	{
		InWater(newPosition);
	}*/
	//else
	{
		setInWindow(newPosition);
	}
	
	m_shape.setPosition(newPosition);

}

void Enemy::InWater(sf::Vector2f& newPosition)
{
	sf::FloatRect bounds = m_shape.getGlobalBounds();

	if (m_board->isOnFilledTile(GetPosOnGrid(newPosition)))
	{
		// If the new position is on a filled tile, reverse the direction
		switch (m_directionType)
		{
		case Direction::RIGHT:
							
			m_direction = sf::Vector2f(-1, 1);		m_directionType = Direction::LEFT;
			break;
		case Direction::LEFT:
			m_direction = sf::Vector2f(1, 1);		m_directionType = Direction::RIGHT;	
			break;
		case Direction::DOWN:
			m_direction = sf::Vector2f(1, -1);		 m_directionType = Direction::UP;
			break;
		case Direction::UP:
			m_direction = sf::Vector2f(-1, -1);		 m_directionType = Direction::DOWN;
			break;
		default:
			break;
		}
		newPosition.x *= m_direction.x;
		newPosition.y *= m_direction.y;
	}
	
}

void Enemy::setInWindow(sf::Vector2f& newPosition)
{
	sf::FloatRect bounds = m_shape.getGlobalBounds();

	if (newPosition.x < 0) {
		newPosition.x = 0;
		m_direction.x *= -1; // Reverse direction
		m_directionType = (m_directionType == Direction::RIGHT) ? Direction::LEFT : Direction::RIGHT; // Change direction type
		
	}
	if (newPosition.y < 0) {
		newPosition.y = 0;
		m_direction.y *= -1; // Reverse direction
		m_directionType = (m_directionType == Direction::UP) ? Direction::DOWN : Direction::UP; // Change direction type
		
	}
	if (newPosition.x + bounds.width > WINDOW_WIDTH) { // Assuming window width is 800
		newPosition.x = WINDOW_WIDTH - bounds.width;
		m_direction.x *= -1; // Reverse direction
		m_directionType = (m_directionType == Direction::RIGHT) ? Direction::LEFT : Direction::RIGHT; // Change direction type
		
	}
	if (newPosition.y + bounds.height > WINDOW_HEIGHT) { // Assuming window height is 600
		newPosition.y = WINDOW_HEIGHT - bounds.height;
		m_direction.y *= -1; // Reverse direction
		m_directionType = (m_directionType == Direction::UP) ? Direction::DOWN : Direction::UP; // Change direction type
		
	}
}

void Enemy::setDirection()
{
	int randomDirection = rand() % 4;
	switch (randomDirection) {
	case 0: m_direction = sf::Vector2f(1, 1); m_directionType = Direction::RIGHT; break; // Right
	case 1: m_direction = sf::Vector2f(-1, 1); m_directionType = Direction::LEFT; break; // Left
	case 2: m_direction = sf::Vector2f(-1, -1); m_directionType = Direction::DOWN; break; // Down
	case 3: m_direction = sf::Vector2f(1, -1); m_directionType = Direction::UP; break; // Up
	}
}
