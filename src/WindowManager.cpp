// Created by Adam Simonov and Benny Beer, 2025

#include "WindowManager.h"

WindowManager::WindowManager(const std::string& title, int width, int height)
	:m_window(sf::VideoMode(width, height), title), m_player(sf::Vector2i(0, 0), 3)
{
	int spacing = 150;
	for (int i = 0; i < 5; ++i) {
		auto enemy = Enemy(sf::Vector2i(i*spacing, i*spacing));
		m_enemies.push_back(enemy);
	}
}

void WindowManager::run()
{
	while (m_window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void WindowManager::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_window.close();
		}
	}
}

void WindowManager::update()
{
	sf::Time deltaTime = m_clock.restart();
	m_player.update(deltaTime);
	for (auto& enemy : m_enemies) {
		enemy.update(deltaTime);
	}
}

void WindowManager::render()
{
	m_window.clear();
	m_player.draw(m_window);
	for (const auto& enemy : m_enemies) {
		enemy.draw(m_window);
	}
	m_window.display();
}