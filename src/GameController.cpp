//
// Created by Adam Simonov on 12/5/25.
//

#include "../include/GameController.h"
#include "iostream"

GameController::GameController() : m_fileParser("game_data.txt"),
								   m_gameData(m_fileParser.parseGameData()),
								   m_levels(m_fileParser.parseLevelData()),
								   m_window(sf::VideoMode(m_gameData.screenSize.x * CELL_SIZE, m_gameData.screenSize.y * CELL_SIZE), "Xonix"),
								   m_hud((sf::Vector2f(m_gameData.screenSize.x, m_gameData.screenSize.y))),
								   m_board(m_gameData,m_levels[0])
{
	std::cout << "FROM GAMECONTROLLER: x - " << m_gameData.screenSize.x << " y - " << m_gameData.screenSize.y << " \n";
}

void GameController::run()
{
	while (m_window.isOpen())
	{
		handleEvents();
		update();
		renderGame();
	}	
}
void GameController::handleEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_window.close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				m_window.close();
			}
		}
	}
}

void GameController::update()
{
	//colisions
	sf::Time deltaTime = m_clock.restart();
	m_board.update(deltaTime);

	HUDdata barData = {
		m_board.getScore(),
		m_board.getLives(),
		m_board.getTime(),
		m_board.getPercentageFilled(),
	};
	m_hud.update(barData);
}

void GameController::renderGame()
{
	m_window.clear();
	m_board.draw(m_window);
	m_hud.draw(m_window);
	m_window.display();
}



