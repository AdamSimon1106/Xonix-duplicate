// Created by Adam Simonov and Benny Beer, 2025
// TODO(benny): implement WindowManager to handle rendering and user input
#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Trail.h"
#include "Hud.h"
#include <iostream>


class WindowManager {
public:
	WindowManager(const std::string& title, int width, int height);
	void run();
	void processEvents();
	void update();
	void render();
	

private:
	HUD m_bar;
	Trail m_trail;
	Player m_player;
	std::vector<Enemy> m_enemies;
	sf::RenderWindow m_window;
	sf::Clock m_clock;
	float m_countDown = 180.f;
	


};
