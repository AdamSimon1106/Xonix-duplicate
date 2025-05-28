//
// Created by Adam Simonov on 12/5/25.
//

#include "../include/GameController.h"
#include "iostream"

GameController::GameController() 
	:m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Xonix"), m_hud((sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT)))
{
}




void GameController::run()
{
	m_window.setFramerateLimit(60);
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
		m_board.getPercentage()
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



