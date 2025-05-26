//
// Created by Adam Simonov on 12/5/25.
//

#include "../include/GameController.h"
#include "iostream"

GameController::GameController() : m_parser("resources/game_data.txt"),
								   m_gameData(m_parser.parseGameData()),
								   m_levels(m_parser.parseLevelData()),
								   m_board(m_gameData.screenSize),
								   m_window(sf::VideoMode(m_board.getSize().x*CELL_SIZE, m_board.getSize().y*CELL_SIZE),"xonix"),
								   m_player(sf::Vector2i(0, 0), 1000, m_board),
								   m_trail(CELL_SIZE)
{
	
	for (int i = 0; i < m_levels[0].numOfEnemies; ++i) {
		int x = std::rand() % m_board.getSize().x*CELL_SIZE;
		int y = std::rand() % m_board.getSize().y*CELL_SIZE;
		auto enemy = Enemy(sf::Vector2i(x, y));
		m_enemies.push_back(enemy);
	}
	
}

void GameController::loadLevel() 
{
	m_board.loadLevel(m_levels[0]);
}


void GameController::run()
{
	while (m_window.isOpen()) {
		processEvents();
		update();
		render();
	}
}
void GameController::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_window.close();
		}
	}
}

void GameController::update()
{
	sf::Time deltaTime = m_clock.restart();

	m_player.update(deltaTime);
	if(m_player.isWalkingOnEmptyTile())
	{
		m_trail.updatePath(m_player.getOldPosition());
	}
	if (m_board.isCollidewithclosedArea(m_player.getPosOnGrid(), m_player.getDirection()))
	{
		m_board.fillArea(m_trail); // this works, now draw the filled

		std::cout << "Collided with closed area\n";
	}
	
	
	m_player.setCollide(m_player.checkCollisionWithTrail(m_trail));

	for (auto& enemy : m_enemies) {
		//enemy.update(deltaTime);
		m_player.setCollide(enemy.checkCollisionWithTrail(m_trail));

	}

	m_countDown -= deltaTime.asSeconds();
	if (m_countDown < 0)
		m_countDown = 0;
	HUDdata barData = {
		m_player.getScore(),
		m_player.getLive(),
		m_countDown,
		0.

	};
	m_bar.update(barData);
}

void GameController::render()
{
	m_window.clear();
	m_board.render(m_window);
	m_trail.draw(m_window);
	m_player.draw(m_window);
	for (const auto& enemy : m_enemies) {
		enemy.draw(m_window);
	}
	m_bar.draw(m_window);
	m_window.display();

}