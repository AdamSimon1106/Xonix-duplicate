// Created by Adam Simonov and Benny Beer, 2025

#include "../include/Hud.h"


HUD::HUD() {
    m_font.loadFromFile("C:/Windows/Fonts/arial.ttf");
    auto setupText = [&](sf::Text& text, float x) {
        text.setFont(m_font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(x, 10);
        };

    setupText(m_scoreText, 180);
    setupText(m_livesText, 290);
    setupText(m_timerText, 400);
    setupText(m_areaText, 510);

    m_border.setSize(sf::Vector2f(480, 30));
    m_border.setPosition(150, 10);
    m_border.setFillColor(sf::Color(0, 0, 0, 150));
    m_border.setOutlineColor(sf::Color::White);
    m_border.setOutlineThickness(2.f);
}

void HUD::update(const HUDdata& data) {
    m_scoreText.setString("Score: " + std::to_string(data.score));
    m_livesText.setString("Lives: " + std::to_string(data.live));

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << data.timer;
    m_timerText.setString("Time: " + oss.str());

    m_areaText.setString("Area: " + std::to_string(static_cast<int>(data.percentage)) + "%");
}

void HUD::draw(sf::RenderWindow& window) {
    window.draw(m_border);
    window.draw(m_scoreText);
    window.draw(m_livesText);
    window.draw(m_timerText);
    window.draw(m_areaText);
}

