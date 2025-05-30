#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Board.h"
#include "Hud.h"
#include "FileParser.h"
class GameController {
public:
	GameController();
	void run();
	void handleEvents();
	void update();
	void renderGame();

private:
	FileParser m_fileParser;
	GameData m_gameData;
	std::vector<LevelData> m_levels;
	sf::RenderWindow m_window;
	Board m_board;
	sf::Clock m_clock;
	HUD m_hud;
};
