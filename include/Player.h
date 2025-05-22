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
	void update(const sf::Time& deltaTime);
	void InWindow(sf::Vector2f& newPosition);
	
	
	const int  getScore() const ;
	const int getLive() const ;

	
	sf::Vector2f getOldPosition() const;
	void setCollide(bool collide);
private:
	
	void handleInput();
	sf::Vector2f m_oldPosition;
	
	int m_lives;
	int m_score;
	
	
};
