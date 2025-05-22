//
// Created by Adam Simonov on 12/5/25.
//

#include "../include/GameController.h"

GameController::GameController() : m_parser("resources/game_data.txt"),
								   m_gameData(m_parser.parseGameData()),
								   m_levels(m_parser.parseLevelData()),
								   m_board(m_gameData.screenSize),
								   m_window(sf::VideoMode(m_board.getSize().x, m_board.getSize().y),"xonix")
{
	
}

void GameController::loadLevel() 
{
	m_board.loadLevel(m_levels[0]);
}

void GameController::render() 
{
	m_window.clear();
	m_window.display();

}
void GameController::run()
{
	while (m_window.isOpen()) {
		processEvents();
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