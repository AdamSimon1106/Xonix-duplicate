// Created by Adam Simonov and Benny Beer, 2025

#include "Player.h"

Player::Player(const sf::Vector2i& startPosition, int lives)
	:MovingObject(startPosition) , m_lives(lives), m_score(0)
{
	setTextur(sf::Color(128, 0, 128));
    
}

void Player::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

void Player::update(const sf::Time& deltaTime)
{
	
	handleInput();

	sf::Vector2f moveDelta(
		m_direction.x * m_speed * deltaTime.asSeconds(),
		m_direction.y * m_speed * deltaTime.asSeconds()
	);

	sf::Vector2f newPosition = m_position + moveDelta;

	
	InWindow(newPosition);

	m_position = newPosition;
	
	m_sprite.setPosition(m_position);

}

void Player::InWindow(sf::Vector2f& newPosition)
{
	sf::FloatRect bounds = m_sprite.getGlobalBounds();

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

const int Player::getScore() const
{
	return m_score;
}

const int Player::getLive() const
{
	return m_lives;
}




void Player::handleInput()
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



