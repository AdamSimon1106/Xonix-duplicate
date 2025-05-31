#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Board.h"
#include "Hud.h"
#include "FileParser.h"
#include "IGameState.h"
class GameController {
public:
	GameController();
	void run();
	void handleEvents();
	void update();
	void renderGame();
	void switchState(std::unique_ptr<IGameState> state);

private:
	FileParser m_fileParser;
	GameData m_gameData;
	std::vector<LevelData> m_levels;
	sf::RenderWindow m_window;
	Board m_board;
	sf::Clock m_clock;
	HUD m_hud;
	std::unique_ptr<IGameState> m_currentState;
};
