// Created by Adam Simonov and Benny Beer, 2025
// TODO(benny): implement HUD to display lives, stage, and area percentage
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iomanip>

struct HUDdata {
    int score;
    int live;
    float timer;
    float percentage;
};

class HUD {
public:
    HUD();

    void update(const HUDdata& data);
    void draw(sf::RenderWindow& window);

private:
    sf::Font m_font;
    sf::Text m_scoreText;
    sf::Text m_livesText;
    sf::Text m_timerText;
    sf::Text m_areaText;

    sf::RectangleShape m_border;
};
