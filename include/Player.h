// Created by Adam Simonov and Benny Beer, 2025
// TODO(benny): implement Player movement and path tracking
#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"


class Player : public MovingObject{
public:
	Player(const sf::Vector2i& startPosition,int lives);
	void draw(sf::RenderWindow& window) const;
	void update(const sf::Time& deltaTime);
	void InWindow(sf::Vector2f& newPosition);

private:
	void handleInput();
	

	std::vector<sf::Vector2f> m_path;
	int m_lives;
	
	


};
