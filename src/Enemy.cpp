// Created by Adam Simonov and Benny Beer, 2025

#include "Enemy.h"


Enemy::Enemy(const sf::Vector2i& startPosition)
	: MovingObject(startPosition)
{
	
	setTextur(sf::Color(0, 255, 0)); 

	setDirection();
}

void Enemy::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

void Enemy::update(const sf::Time& deltaTime)
{
	sf::Vector2f moveDelta(
		m_direction.x * m_speed * deltaTime.asSeconds(),
		m_direction.y * m_speed * deltaTime.asSeconds()
	);

	sf::Vector2f newPosition = m_position + moveDelta;

	InWindow(newPosition);
	m_position = newPosition;
	m_sprite.setPosition(m_position);

}

void Enemy::InWindow(sf::Vector2f& newPosition)
{
	sf::FloatRect bounds = m_sprite.getGlobalBounds();

	if (newPosition.x < 0) {
		newPosition.x = 0;
		m_direction.x *= -1; // Reverse direction
	}	
	if (newPosition.y < 0) {
		newPosition.y = 0;
		m_direction.y *= -1; // Reverse direction
	}
	if (newPosition.x + bounds.width > WINDOW_WIDTH) { // Assuming window width is 800
		newPosition.x = WINDOW_WIDTH - bounds.width;
		m_direction.x *= -1; // Reverse direction
	}
	if (newPosition.y + bounds.height > WINDOW_HEIGHT) { // Assuming window height is 600
		newPosition.y = WINDOW_HEIGHT - bounds.height;
		m_direction.y *= -1; // Reverse direction
	}

	
}

void Enemy::setDirection()
{
	int randomDirection = rand() % 4;
	switch (randomDirection) {
	case 0: m_direction = sf::Vector2f(1, 1); break; // Right
	case 1: m_direction = sf::Vector2f(-1, 1); break; // Left
	case 2: m_direction = sf::Vector2f(-1, -1); break; // Down
	case 3: m_direction = sf::Vector2f(1, -1); break; // Up
	}
}
