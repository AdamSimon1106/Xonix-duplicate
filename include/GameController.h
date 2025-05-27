#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Board.h"

class GameController {
public:
	GameController();
	void run();
	void handleEvents();
	void update();
	void renderGame();

private:
	sf::RenderWindow m_window;
	Board m_board;
	sf::Clock m_clock;
};
