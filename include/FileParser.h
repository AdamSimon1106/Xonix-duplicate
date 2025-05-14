// Created by Adam Simonov and Benny Beer, 2025
// TODO(adam): implement FileParser::readFile and handle invalid input
#pragma once
#include<string>
#include<SFML/System/Vector2.hpp>
#include<vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Enemy.h"
//---structs---
struct LevelData{
	int numOfEnemies;
	int requiredPresentage;
	std::vector<Enemy> enemies
	
};
struct GameData {
	int numOfLives;
	sf::Vector2i screenSize;
	std::string toString();
};

class FileParser {
private:
	std::ifstream m_file;
public:
	FileParser(const std::string& path) : m_file(path){
		if (!m_file.is_open()) { throw std::runtime_error("failed to open file at " + path);}
	}
	GameData parseGameData();
	std::vector<LevelData> parseLevelData();
};
