// Created by Adam Simonov and Benny Beer, 2025
// TODO(adam): implement GameController logic for stage transitions and win conditions
#pragma once
#include "FileParser.h"
#include "Board.h"
#include <vector>
class GameController {
private:
	FileParser m_parser;
	GameData m_gameData;
	std::vector<LevelData> m_levels;
	Board m_board;

	sf::RenderWindow m_window;

public:
	GameController();
	void processEvents();
	void loadLevel();
	void render();
	void run();
};
