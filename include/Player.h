#pragma once
#include "MovingObject.h"
#include "Trail.h"
#include "Enemy.h"


class Board; // Forward declaration


class Player : public MovingObject {
public:
	Player(sf::Vector2f pos, int lives, const Board& board, int score, sf::Color color = sf::Color::Red);
	void update(sf::Time deltaTime) override;
	void setDirectionByInput(); //handle input
	void move(sf::Vector2f moveDelta);
	void draw(sf::RenderWindow& window) const override;

	bool checkColisionsWithTrail();
	bool checkCollisions(Enemy& enemy);
	void handleCollisions();
	void resetPosition();

	int getScore() const;
	int getLives() const; 
private:
	void InWindow(sf::Vector2f& newPosition);
	int m_lives;
	int m_score;
	sf::Vector2f m_startPosition;
	sf::Vector2f m_oldPosition;
	
	Trail m_trail;

	Board* m_board = nullptr;
};