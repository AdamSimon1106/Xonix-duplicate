//
// Created by Adam Simonov on 12/5/25.
//

#include "../include/GameController.h"
#include "iostream"
#include "WelcomeState.h"
#include <exception>

GameController::GameController() : m_fileParser("game_data.txt"),
								   m_gameData(m_fileParser.parseGameData()),
								   m_levels(m_fileParser.parseLevelData()),
								   m_window(sf::VideoMode(m_gameData.screenSize.x * CELL_SIZE, m_gameData.screenSize.y * CELL_SIZE), "Xonix"),
								   m_currentState(std::make_unique<WelcomeState>(m_window, *this))
{
}

void GameController::run()
{
	sf::Clock clock;
	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) m_window.close();
			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) m_window.close();
			m_currentState->handleEvents(event);
		}
		sf::Time deltaTime = clock.restart();
		m_currentState->update(deltaTime);

		m_window.clear();
		m_currentState->render();
		m_window.display();

		if (m_nextState) {
			m_currentState = std::move(m_nextState);
		}

	}	
}

void GameController::switchState(std::unique_ptr<IGameState> state)
{
	m_nextState = std::move(state);
}

std::vector<LevelData> GameController::getLevels() const
{
	return m_levels;
}

GameData GameController::getGameData() const
{
	return m_gameData;
}



