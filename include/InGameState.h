#pragma once
#include<SFML/Graphics.hpp>

class GameController; //Forward Declaration

class InGameState {
public:
	~IGameState() = default;
	IGameState(sf::RenderWindow& window) : m_window(window) {};
	void handleEvents(sf::Event& ev) override;
	void update(sf::Time deltaTime) override;
	void render() override;
	void onEnter(GameController& controller) override;
	void onExit(GameController& controller) override;
protected:
	sf::RenderWindow& m_window;
};