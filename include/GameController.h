// Created by Adam Simonov and Benny Beer, 2025
// TODO(adam): implement GameController logic for stage transitions and win conditions
#pragma once
#include <SFML/Graphics.hpp>
#include "FileParser.h"
#include "Board.h"
#include <vector>
#include "MovingObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Trail.h"
#include "Hud.h"

class GameController {
private:
	
	FileParser m_parser;
	GameData m_gameData;
	std::vector<LevelData> m_levels;
	Board m_board;
	Player m_player;
	std::vector<Enemy> m_enemies;
	Trail m_trail;
	HUD m_bar;

	sf::RenderWindow m_window;
	sf::Clock m_clock;
	float m_countDown = 180.f;
	int m_currentLevel = 0;
public:
	GameController();
	
	void loadLevel();
	void render();
	void run();
	void processEvents();
	void update();
};
