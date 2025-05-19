// Created by Adam Simonov and Benny Beer, 2025
// TODO(benny): implement Player movement and path tracking
#pragma once
#include <SFML/Graphics.hpp>
#include <Unordered_set>
#include "MovingObject.h"
#include "Trail.h"


class Player : public MovingObject{
public:
	Player(const sf::Vector2i& startPosition,int lives);
	void draw(sf::RenderWindow& window) const;
	void update(const sf::Time& deltaTime);
	void InWindow(sf::Vector2f& newPosition);
	
	const int  getScore() const ;
	const int getLive() const ;

	bool checkCollisionWithTraill(const Trail& trail);

private:
	void handleInput();
	
	int m_lives;
	int m_score;
	
};
