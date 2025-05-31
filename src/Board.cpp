#include "Board.h"
#include <iostream>

Board::Board(GameData gameData, LevelData level, int score) : m_gameData(gameData),
												   m_level(level),
												   m_currScore(score),
									               m_player(sf::Vector2f(0, 0), m_gameData.numOfLives, *this, m_currScore),
									               m_gridManager(m_gameData.screenSize.x, m_gameData.screenSize.y),
									               m_areaCloser(m_gridManager)
						   
{
	int cols = m_gridManager.getWidth();
	int rows = m_gridManager.getHeight();

	//TODO - generate the enemies at fileParser
	for (int i = 0; i < level.numOfEnemies; ++i)
	{
		// Initialize enemies with random positions
		int x = 1 + std::rand() % (cols - 2); 
		int y = 1 + std::rand() % (rows - 2);
		
		sf::Vector2f enemyPosition(x * CELL_SIZE, y * CELL_SIZE);
		m_enemies.emplace_back(enemyPosition, *this);
	}
}

void Board::update(sf::Time deltaTime)
{
	updateTimer();
	
	m_player.update(deltaTime);
	for (auto& enemy : m_enemies)
	{
		//enemy.update(deltaTime);
	}
	checkColisions();
}

void Board::draw(sf::RenderWindow& window)
{
	m_gridManager.draw(window);
	m_player.draw(window);
	for (const auto& enemy : m_enemies)
	{
		enemy.draw(window);
	}
}

bool Board::isOnFilledTile(sf::Vector2i point) const
{
	if (point.x < 0 || point.x >= getGridWidth() || point.y < 0 || point.y >= getGridHeight())
		return false; // Out of bounds check
	return m_gridManager.isOnFilledTile(point);
}

void Board::setOnClosedArea(const std::vector<sf::Vector2f>& path) 
{
	if (path.size() < 3) return;
	m_areaCloser.fillArea(path, m_enemies);
}

void Board::checkColisions()
{
	for (auto& enemy : m_enemies)
	{
		collied(m_player, enemy);
	}
}

void Board::collied(Object& obj1, Object& obj2)
{
	Player* player = dynamic_cast<Player*>(&obj1);
	Enemy* enemy = dynamic_cast<Enemy*>(&obj2);

	if (player && enemy) {
		player->checkCollisions(*enemy); 
	}
}

void Board::updateTimer()
{
	sf::Time elapsed = m_clock.restart(); 
	m_countDownTime -= elapsed.asSeconds();

	if (m_countDownTime <= 0)
	{
	
	}
}

int Board::getScore() const
{
	return m_player.getScore();
}

int Board::getLives() const
{
	return m_player.getLives();
}

int Board::getScreenWidth() const
{
	return m_gameData.screenSize.x * CELL_SIZE;
}

int Board::getScreenHeight() const
{
	return m_gameData.screenSize.y * CELL_SIZE;
}

int Board::getGridWidth() const
{
	return m_gameData.screenSize.x;
}

int Board::getGridHeight() const
{
	return m_gameData.screenSize.y;
}

float Board::getPercentageFilled() const
{
	return m_areaCloser.getPercentFilled();
}

float Board::getTime() const
{
	return m_countDownTime ;
}



