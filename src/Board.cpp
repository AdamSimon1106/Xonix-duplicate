#include "Board.h"
#include <iostream>

Board::Board()
	: m_player(sf::Vector2f(0, 0), 3, *this), m_gridManager(COLS, ROWS), m_areaCloser(m_gridManager)
{
	for (int i = 0; i < ENEMY_COUNT; ++i)
	{
		// Initialize enemies with random positions
		int x = std::rand() % COLS;
		int y = std::rand() % ROWS;
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
	if (point.x < 0 || point.x >= COLS || point.y < 0 || point.y >= ROWS)
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
	sf::Time elapsed = m_clock.restart(); // כמה זמן עבר מאז העדכון האחרון
	m_countDownTime -= elapsed.asSeconds();

	if (m_countDownTime <= 0)
	{
		// הזמן נגמר! טיפול בכך:
		 // או סיום המשחק
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

float Board::getPercentageFilled() const
{
	return m_areaCloser.getPercentFilled();
}

float Board::getTime() const
{
	return m_countDownTime ;
}



