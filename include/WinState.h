#pragma once
#include "IGameState.h"
#include <SFML/Graphics.hpp>
class GameController;

class WinState : public IGameState {
public:
	WinState(sf::RenderWindow& window, GameController& controller , int score);
	~WinState() override = default;
	void handleEvents(sf::Event& ev) override;
	void update(sf::Time deltaTime) override;
	void render() override;
	void onEnter(GameController& controller) override;
	void onExit(GameController& controller) override;
private:
	sf::Font m_font;
	sf::Text m_message;
	sf::Text m_score;
	sf::RectangleShape m_restartButton;
	sf::Text m_restartText;
	sf::RectangleShape m_quitButton;
	sf::Text m_quitText;

};


