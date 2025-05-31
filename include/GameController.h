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
	void switchState(std::unique_ptr<IGameState> state);
	std::vector<LevelData> getLevels() const;
	GameData getGameData() const;
private:
	FileParser m_fileParser;
	GameData m_gameData;
	std::vector<LevelData> m_levels;
	sf::RenderWindow m_window;
	sf::Clock m_clock;
	std::unique_ptr<IGameState> m_currentState;
	std::unique_ptr<IGameState> m_nextState = nullptr;
};
