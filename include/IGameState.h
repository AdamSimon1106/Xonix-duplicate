#pragma once
#include<SFML/Graphics.hpp>

class GameController; //Forward Declaration

class IGameState {
public:
	virtual ~IGameState() = default;
	IGameState(sf::RenderWindow& window) : m_window(window) {};
	virtual void handleEvents(sf::Event& ev) = 0;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void render() = 0;
	virtual void onEnter(GameController& controller) = 0;
	virtual void onExit(GameController& controller) = 0;
protected:
	sf::RenderWindow& m_window;
};