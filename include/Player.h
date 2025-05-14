// Created by Adam Simonov and Benny Beer, 2025
// TODO(benny): implement Player movement and path tracking
#pragma once
#include <SFML/Graphics.hpp>
#include <Unordered_set>
#include "MovingObject.h"

struct Vector2iHash {
	std::size_t operator()(const sf::Vector2i& v) const noexcept {
		return std::hash<int>()(v.x) ^ (std::hash<int>()(v.y) << 1);
	}
};


class Player : public MovingObject{
public:
	Player(const sf::Vector2i& startPosition,int lives);
	void draw(sf::RenderWindow& window) const;
	void update(const sf::Time& deltaTime);
	void InWindow(sf::Vector2f& newPosition);

private:
	void handleInput();
	

	std::vector<sf::Vector2f> m_path;
	std::unordered_set<sf::Vector2i, Vector2iHash> m_pathSet;
	int m_lives;
	
};
