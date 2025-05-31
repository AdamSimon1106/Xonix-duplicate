#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Player.h"
#include "GridManager.h"
#include <vector>
#include "Object.h"
#include "Enemy.h" 
#include "AreaCloser.h"
#include "FileParser.h"

class Player; // Forward declaration of Player class

class Board {
public:
	Board(GameData gameData, LevelData level, int score);
	void update(sf::Time deltaTime);
	void draw(sf::RenderWindow& window);

	bool isOnFilledTile(sf::Vector2i) const;
	void setOnClosedArea(const std::vector<sf::Vector2f>& path) ;

	void checkColisions();
	void collied(Object& obj1, Object& obj2);
	void updateTimer();

	int getScore() const;
	int	getLives() const;
	int getScreenWidth() const;
	int getScreenHeight() const;
	int getGridWidth() const;
	int getGridHeight() const;
	float getPercentageFilled() const;
	float getTime() const;
	
private:
	GameData m_gameData;
	LevelData m_level;
	std::vector<Enemy> m_enemies;
	int m_currScore;
	Player m_player;
	GridManager m_gridManager;
	AreaCloser m_areaCloser;
	sf::Clock m_clock;
	float m_countDownTime = 180.f;
	
};