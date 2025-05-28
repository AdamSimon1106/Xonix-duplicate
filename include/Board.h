#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Player.h"
#include "GridManager.h"
#include <vector>
#include "Object.h"
#include "Enemy.h" 
#include "AreaCloser.h"


class Player; // Forward declaration of Player class

class Board {
public:
	Board();
	void update(sf::Time deltaTime);
	void draw(sf::RenderWindow& window);

	bool isOnFilledTile(sf::Vector2i) const;
	void setOnClosedArea(const std::vector<sf::Vector2f>& path) const;

	void checkColisions();
	void collied(Object& obj1, Object& obj2);
	

	int getScore() const;
	int	getLives() const;
	float getTime() const;
	float getPercentage() const;
private:
	std::vector<Enemy> m_enemies;
	Player m_player;
	GridManager m_gridManager;
	AreaCloser m_areaCloser;
};