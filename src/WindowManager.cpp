// Created by Adam Simonov and Benny Beer, 2025

#include "WindowManager.h"

WindowManager::WindowManager(const std::string& title, int width, int height)
	:m_window(sf::VideoMode(width, height), title), m_player(sf::Vector2i(0, 0), 3),
	m_trail(CELL_SIZE)
{
	for (int i = 0; i < 5; ++i) {
		int x = std::rand() % WINDOW_WIDTH;
		int y = std::rand() % WINDOW_HEIGHT;
		auto enemy = Enemy(sf::Vector2i(x, y));
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
	if (m_player.checkCollisionWithTrail(m_trail)) {
		std::cout << "colide with trail" << std::endl;
	}
	m_trail.updatePath(m_player.getOldPosition());
	for (auto& enemy : m_enemies) {
		
		enemy.update(deltaTime);
	}
	HUDdata barData = {
		m_player.getScore(),
		m_player.getLive(),
		0,
		0.

	};
	m_bar.update(barData);
}

void WindowManager::render()
{
	m_window.clear();
	
	m_trail.draw(m_window);
	m_player.draw(m_window);
	for (const auto& enemy : m_enemies) {
		enemy.draw(m_window);
	}
	m_bar.draw(m_window);
	m_window.display();
}