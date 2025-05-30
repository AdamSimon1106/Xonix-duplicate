// Created by Adam Simonov and Benny Beer, 2025
#pragma once
#include<string>
#include<SFML/System/Vector2.hpp>
#include<vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Enemy.h"
#include "Exception.h"
#include <iostream>

//---structs---
struct LevelData{
	int numOfEnemies;
	int requiredPresentage;
	//std::vector<Enemy> enemies;
	void generatePositions(const int& count);
	void addEnemy(const int& x, const int& y);
	std::string toString();
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
		if (!m_file.is_open())  throw FileNotFound(path);
	}
	GameData parseGameData();
	std::vector<LevelData> parseLevelData();
};
