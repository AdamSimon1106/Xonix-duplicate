#include "InGameState.h"
#include "GameController.h"
#include "WinState.h"
#include "LoseState.h"
InGameState::InGameState(sf::RenderWindow& window, GameController& controller, int level, int score) : IGameState(window, controller),	
																				 m_gameData(m_controller.getGameData()),
																				 m_levels(m_controller.getLevels()),
																				 m_currLevel(level),
																				 m_hud((sf::Vector2f(m_gameData.screenSize.x, m_gameData.screenSize.y))),
																				 m_score(score),
																				 m_board(m_gameData, m_levels[level], m_score)
{
}
void InGameState::handleEvents(sf::Event& ev)
{
};

void InGameState::update(sf::Time deltaTime)
{
	m_board.update(deltaTime);

	HUDdata barData = {
		m_board.getScore(),
		m_board.getLives(),
		m_board.getTime(),
		m_board.getPercentageFilled(),
		m_currLevel+1,
	};
	m_hud.update(barData);

	if(!m_board.getLives()) m_controller.switchState(std::make_unique<LoseState>(m_window, m_controller, m_score));

	if (m_board.getPercentageFilled() >= m_levels[m_currLevel].requiredPresentage)
	{
		m_score += m_board.getScore();
		if (m_currLevel < m_levels.size() - 1)
		{
			//im not on the final level
			
			m_controller.switchState(std::make_unique<InGameState>(m_window, m_controller, ++m_currLevel, m_score));
		}
		else m_controller.switchState(std::make_unique<WinState>(m_window, m_controller, m_score));
	}
};


void InGameState::render()
{
	m_board.draw(m_window);
	m_hud.draw(m_window);
};
void InGameState::onEnter(GameController& controller)
{
};
void InGameState::onExit(GameController& controller)
{
}
void InGameState::loadLevel(const LevelData& level) const
{
}
