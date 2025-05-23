// Created by Adam Simonov and Benny Beer, 2025
// TODO(benny): implement Player movement and path tracking
#pragma once
#include <SFML/Graphics.hpp>
#include <Unordered_set>
#include "MovingObject.h"
#include "Trail.h"
#include "Board.h"
#include "Tile.h"


class Player : public MovingObject{
public:
	Player(const sf::Vector2i& startPosition,int lives, Board& board);
	void update(const sf::Time& deltaTime);
	void InWindow(sf::Vector2f& newPosition);
	
	
	const int  getScore() const ;
	const int getLive() const ;

	void setCollide(bool collide);
	sf::Vector2f getOldPosition() const;
	const bool isWalkingOnEmptyTile() const;
private:
	Board* m_board = nullptr;
	void handleInput();
	sf::Vector2f m_oldPosition;
	bool m_isOnEmptyTile = false;
	int m_lives;
	int m_score;
	//TileType m_tileType;
};
