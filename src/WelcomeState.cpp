#include "WelcomeState.h"
#include "GameController.h"
#include "InGameState.h"
#include <iostream>
#include <Exception>
WelcomeState::WelcomeState(sf::RenderWindow& window, GameController& controller) : IGameState(window, controller)
{
	//background image
	if (!m_bgTexture.loadFromFile("welcome_bg.png")) {
		throw std::runtime_error("welcome_bg.png not found");
	}
	m_bgSprite.setTexture(m_bgTexture);
	m_bgSprite.setScale(
		m_window.getSize().x / static_cast<float>(m_bgTexture.getSize().x),
		m_window.getSize().y / static_cast<float>(m_bgTexture.getSize().y)
	);

	//button
	if (!m_font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
		throw std::runtime_error("failed to load font");
	}
	m_playButton.setFont(m_font);
	m_playButton.setString("Play");
	m_playButton.setCharacterSize(80);
	m_playButton.setFillColor(sf::Color::Black);
	m_playButton.setStyle(sf::Text::Bold);
	

	sf::FloatRect bounds = m_playButton.getLocalBounds();
	m_playButton.setOrigin(bounds.width / 2, bounds.height / 2);
	m_playButton.setPosition(m_window.getSize().x / 2, m_window.getSize().y * 0.75f);
}
void WelcomeState::handleEvents(sf::Event& ev)
{
	sf::Vector2f mousePos(ev.mouseButton.x, ev.mouseButton.y);
		if (m_playButton.getGlobalBounds().contains(mousePos)) {
			m_playButton.setFillColor(sf::Color::White);
			if (ev.type == sf::Event::MouseButtonReleased && ev.mouseButton.button == sf::Mouse::Left)
			{
				if (m_playButton.getGlobalBounds().contains(mousePos)) m_switchState = true;	
			}
		}
}
void WelcomeState::update(sf::Time deltaTime)
{
	sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
	if (m_playButton.getGlobalBounds().contains(mousePos))	m_playButton.setFillColor(sf::Color::White);
	else m_playButton.setFillColor(sf::Color::Black);
	if (m_switchState) {
		m_controller.switchState(std::make_unique<InGameState>(m_window, m_controller,0,0));
	}
}
void WelcomeState::render()
{
	m_window.draw(m_bgSprite);
	m_window.draw(m_playButton);
}

void WelcomeState::onEnter(GameController& controller)
{

}

void WelcomeState::onExit(GameController& controller)
{
}


