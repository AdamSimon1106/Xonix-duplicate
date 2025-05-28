// Created by Adam Simonov and Benny Beer, 2025

#include "Player.h"
#include <iostream>
#include "Board.h"

Player::Player(sf::Vector2f pos, int lives, const Board& board, sf::Color color)
	:MovingObject(pos, color), m_lives(lives), m_startPosition(pos), m_board(const_cast<Board*>(&board))
{
}

void Player::update(sf::Time deltaTime)
{
	m_oldPosition = m_position;
	setDirectionByInput();

	sf::Vector2f moveDelta(
		m_direction.x * m_speed * deltaTime.asSeconds(),
		m_direction.y * m_speed * deltaTime.asSeconds()
	);


	move(moveDelta);

	bool isMoving = (m_direction.x != 0 || m_direction.y != 0);
	bool onFilledTile = m_board->isOnFilledTile(GetPosOnGrid(m_position));
	bool wasOnFilledTile = m_board->isOnFilledTile(GetPosOnGrid(m_oldPosition));
	
	//walking on water from filled
	if (!onFilledTile && wasOnFilledTile)
	{
		m_trail.addPoint(m_position);
		//std::cout << "Player is walking on water from filled tile" << std::endl;
	}
	//closed area
	else if (!wasOnFilledTile && onFilledTile)
	{
		m_board->setOnClosedArea(m_trail.getPath());
		//std::cout << "Player  closed area" << std::endl;
		m_trail.clear(); 
	}
	//walking on water from water
	else if (!onFilledTile && isMoving)
	{
		m_trail.addPoint(m_position);
		//std::cout << "Player is walking on water" << std::endl;
	}


}


void Player::InWindow(sf::Vector2f& newPosition)
{
	sf::FloatRect bounds = m_shape.getGlobalBounds();

	if (newPosition.x < 0) {
		newPosition.x = 0;
	}
	if (newPosition.y < 0) {
		newPosition.y = 0;
	}
	if (newPosition.x + bounds.width > WINDOW_WIDTH) { 
		newPosition.x = WINDOW_WIDTH - bounds.width;
	}
	if (newPosition.y + bounds.height > WINDOW_HEIGHT) {
		newPosition.y = WINDOW_HEIGHT - bounds.height;
	}
}

void Player::setDirectionByInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_direction = sf::Vector2f(0, -1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_direction = sf::Vector2f(0, 1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_direction = sf::Vector2f(-1, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_direction = sf::Vector2f(1, 0);
	}
	else {
		m_direction = sf::Vector2f(0, 0);
	}
}

void Player::move(sf::Vector2f moveDelta)
{

	sf::Vector2f newPosition = m_shape.getPosition() + moveDelta;
	InWindow(newPosition);
	m_shape.setPosition(newPosition);
	m_position = newPosition;
}

void Player::draw(sf::RenderWindow& window) const
{
	m_trail.draw(window);
	MovingObject::draw(window);
}



bool Player::checkCollisions(Enemy& enemy)
{
	if (m_shape.getGlobalBounds().intersects(enemy.getShape().getGlobalBounds())) {
		std::cout << "Collision with enemy detected!" << std::endl;
		handleCollisions();
		return true;
	}
	if (m_trail.checkCollisions(enemy)) {
		std::cout << "Collision with trail detected!" << std::endl;
		handleCollisions();
		return true;
	}
}

void Player::handleCollisions()
{
	m_trail.clear();
	m_lives--;
	resetPosition();
}

void Player::resetPosition()
{
	m_position = m_startPosition;
	m_shape.setPosition(m_startPosition);
}

int Player::getScore() const
{
	return m_score;
}

int Player::getLives() const
{
	return m_lives;
}



