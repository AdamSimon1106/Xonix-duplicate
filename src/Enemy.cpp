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
	/*sf::Vector2f moveDelta(
		m_direction.x * m_speed * deltaTime.asSeconds(),
		m_direction.y * m_speed * deltaTime.asSeconds()
	);*/

	sf::Vector2f newPosition = m_shape.getPosition(); //+ moveDelta;
	//setInWindow(newPosition);
	InWater(newPosition, deltaTime);     // ננסה להפוך כיוון אם נכנס ל-Filled
	 // נוודא שהוא לא חורג מהמסך

	m_shape.setPosition(newPosition);
}


void Enemy::InWater(sf::Vector2f& newPosition, sf::Time deltaTime)
{
	sf::Vector2i gridPos = GetPosOnGrid(newPosition);

	sf::Vector2i nextX = gridPos + sf::Vector2i((int)m_direction.x, 0);
	sf::Vector2i nextY = gridPos + sf::Vector2i(0, (int)m_direction.y);

	bool hitX = false, hitY = false;

	if (/*!m_board->is(nextX)*/ /*||*/ m_board->isOnFilledTile(nextX))
		hitX = true;

	if (/*!m_board->isInBounds(nextY) ||*/ m_board->isOnFilledTile(nextY))
		hitY = true;

	if (hitX)
		m_direction.x *= -1;
	if (hitY)
		m_direction.y *= -1;


	sf::Vector2f moveDelta(
		m_direction.x * m_speed * deltaTime.asSeconds(),
		m_direction.y * m_speed * deltaTime.asSeconds()
	);
	newPosition = m_shape.getPosition() + moveDelta;
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
