// Created by Adam Simonov and Benny Beer, 2025
// TODO(benny): implement WindowManager to handle rendering and user input
#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"


class WindowManager {
public:
	WindowManager(const std::string& title, int width, int height);
	void run();
	void processEvents();
	void update();
	void render();
	

private:
	Player m_player;
	std::vector<Enemy> m_enemies;
	sf::RenderWindow m_window;
	sf::Clock m_clock;
	


};
