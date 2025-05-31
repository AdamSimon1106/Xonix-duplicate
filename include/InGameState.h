#pragma once
#include<SFML/Graphics.hpp>
#include"IGameState.h"
#include"Hud.h"
#include"FileParser.h"
#include"Board.h"

class GameController; //Forward Declaration

class InGameState : public IGameState {
public:
	~InGameState() = default;
	InGameState(sf::RenderWindow& window, GameController& controller, int level, int score);
	void handleEvents(sf::Event& ev) override;
	void update(sf::Time deltaTime) override;
	void render() override;
	void onEnter(GameController& controller) override;
	void onExit(GameController& controller) override;
	void loadLevel(const LevelData& level) const;
private:
	GameData m_gameData;
	std::vector<LevelData> m_levels;
	int m_currLevel;
	int m_score;
	Board m_board;
	HUD m_hud;
	


};