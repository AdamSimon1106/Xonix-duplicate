#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Player.h"
#include "GridManager.h"
#include <vector>
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
	
private:
	std::vector<Enemy> m_enemies;
	Player m_player;
	GridManager m_gridManager;
	AreaCloser m_areaCloser;
};