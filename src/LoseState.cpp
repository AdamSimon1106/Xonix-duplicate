#include "LoseState.h"
#include "GameController.h"
#include "WelcomeState.h"
#include <iostream>
#include <stdexcept> 

LoseState::LoseState(sf::RenderWindow& window, GameController& controller, int score)
    : IGameState(window, controller)
{
    // Load font
    if (!m_font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        throw std::runtime_error("failed to load font");
    }

    // Main message
    m_message.setFont(m_font);
    m_message.setString("You Lost :(");
    m_message.setCharacterSize(80);
    m_message.setFillColor(sf::Color::White);
    m_message.setStyle(sf::Text::Bold);

    // Score text
    m_score.setFont(m_font);
    m_score.setString("Your Score: " + std::to_string(score));
    m_score.setCharacterSize(50);
    m_score.setFillColor(sf::Color::White);
    m_score.setStyle(sf::Text::Bold);

    // Buttons
    m_restartButton.setSize({ 200.f, 60.f });
    m_restartButton.setFillColor(sf::Color(200, 200, 200));
    m_restartButton.setOutlineThickness(2.f);
    m_restartButton.setOutlineColor(sf::Color::White);

    m_quitButton.setSize({ 200.f, 60.f });
    m_quitButton.setFillColor(sf::Color(200, 200, 200));
    m_quitButton.setOutlineThickness(2.f);
    m_quitButton.setOutlineColor(sf::Color::White);

    // Restart text
    m_restartText.setFont(m_font);
    m_restartText.setString("Restart");
    m_restartText.setCharacterSize(24);
    m_restartText.setFillColor(sf::Color::Black);

    // Quit text
    m_quitText.setFont(m_font);
    m_quitText.setString("Quit");
    m_quitText.setCharacterSize(24);
    m_quitText.setFillColor(sf::Color::Black);

    // Positioning
    sf::FloatRect msgBounds = m_message.getLocalBounds();
    m_message.setOrigin(msgBounds.width / 2, msgBounds.height / 2);
    m_message.setPosition(m_window.getSize().x / 2.f, m_window.getSize().y * 0.2f);

    sf::FloatRect scoreBounds = m_score.getLocalBounds();
    m_score.setOrigin(scoreBounds.width / 2, scoreBounds.height / 2);
    m_score.setPosition(m_window.getSize().x / 2.f, m_window.getSize().y * 0.35f);

    float spacing = 40.f;
    float totalWidth = m_restartButton.getSize().x + spacing + m_quitButton.getSize().x;
    float startX = (m_window.getSize().x - totalWidth) / 2.f;
    float yPos = m_window.getSize().y * 0.75f;

    m_restartButton.setPosition(startX, yPos);
    sf::FloatRect restartTextBounds = m_restartText.getLocalBounds();
    m_restartText.setOrigin(restartTextBounds.width / 2, restartTextBounds.height / 2);
    m_restartText.setPosition(startX + 100.f, yPos + 30.f); // center text

    float quitX = startX + m_restartButton.getSize().x + spacing;
    m_quitButton.setPosition(quitX, yPos);
    sf::FloatRect quitTextBounds = m_quitText.getLocalBounds();
    m_quitText.setOrigin(quitTextBounds.width / 2, quitTextBounds.height / 2);
    m_quitText.setPosition(quitX + 100.f, yPos + 30.f); // center text
}

void LoseState::handleEvents(sf::Event& ev)
{
    if (ev.type == sf::Event::Closed) {
        m_window.close();
        return;
    }

    if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos = m_window.mapPixelToCoords({ ev.mouseButton.x, ev.mouseButton.y });

        if (m_restartButton.getGlobalBounds().contains(mousePos)) {
            m_controller.switchState(std::make_unique<WelcomeState>(m_window, m_controller));
        }
        else if (m_quitButton.getGlobalBounds().contains(mousePos)) {
            m_window.close();
        }
    }
}

void LoseState::update(sf::Time) {
    // No update logic needed for now
}

void LoseState::render()
{
    m_window.draw(m_message);
    m_window.draw(m_score);
    m_window.draw(m_restartButton);
    m_window.draw(m_restartText);
    m_window.draw(m_quitButton);
    m_window.draw(m_quitText);
}

void LoseState::onEnter(GameController&) {}
void LoseState::onExit(GameController&) {}
