#pragma once
#include "IGameState.h"
#include <SFML/Graphics.hpp>
class GameController;

class WelcomeState : public IGameState {
public:
	WelcomeState(sf::RenderWindow& window, GameController& controller);
	~WelcomeState() override = default;
	void handleEvents(sf::Event& ev) override;
	void update(sf::Time deltaTime) override;
	void render() override;
	void onEnter(GameController& controller) override;
	void onExit(GameController& controller) override;
private:
	GameController& m_controller;
	sf::Texture m_bgTexture;
	sf::Sprite m_bgSprite;
	sf::Font m_font;
	sf::Text m_playButton;
};


