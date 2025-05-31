#pragma once
#include<SFML/Graphics.hpp>

class GameController; //Forward Declaration

class IGameState {
public:
	virtual ~IGameState() = default; 
	virtual void handleEvents(sf::RenderWindow& window) = 0;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void onEnter(GameController& controller) = 0;
	virtual void onExit(GameController& controller) = 0;
};