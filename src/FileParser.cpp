//
// Created by Adam Simonov on 12/5/25.
//
#include <iostream>
#include "../include/FileParser.h"

GameData FileParser::parseGameData()
{
	GameData data;
	std::string line;
	std::getline(m_file, line);

	std::istringstream iss(line);
	iss >> data.screenSize.x >> data.screenSize.y >> data.numOfLives;
	std::cout << data.screenSize.x;
	return data;
}

std::vector<LevelData> FileParser::parseLevelData()
{
	std::vector<LevelData> levels;
	std::istringstream iss;
	std::string line, next;

	while (std::getline(m_file, line)) {
		if (line.empty()) continue;

		LevelData level;
		iss.clear();
		iss.str(line);
		//read presentage
		iss >> level.requiredPresentage;
		//read enemy data
		int count = 0;

		while (iss >> next) {
			if (std::isdigit(next[0])) {
				count = std::stoi(next);
				level.generatePositions(count);
			}
			else if (next.front() == '(' && next.back() == ')') {
				do {
					// Remove parentheses
					next = next.substr(1, next.size() - 2);
					auto comma = next.find(',');
					if (comma == std::string::npos) throw std::runtime_error("invalid tuple format");

					int x = std::stoi(next.substr(0, comma));
					int y = std::stoi(next.substr(comma + 1));
					level.addEnemy(x, y);
					count++;

				} while (iss >> next);
			}
			else {
				throw std::runtime_error("invalid level formatting");
			}
		}
		level.numOfEnemies = count;
		levels.push_back(level);
	}
	return levels;
}
std::string LevelData::toString()
{
	std::ostringstream oss;
	oss << "num of enemies: " << this->numOfEnemies << "req presentage: " << this->requiredPresentage << " \n";
	return oss.str();

}
std::string GameData::toString()
{
	std::ostringstream oss;
	oss << "screen size is: " << this->screenSize.x << " x " << this->screenSize.y <<  " num of lives: " << this->numOfLives << "\n";
	return oss.str();
}

void LevelData::generatePositions(const int& count)
{
	this->numOfEnemies = count;
	//TODO - make this smarter
	for (int i = 0; i < count; i++) {
		this->enemies.push_back(Enemy(sf::Vector2i(10, 10)));
	}
}

void LevelData::addEnemy(const int& x, const int& y)
{
	this->enemies.push_back(Enemy(sf::Vector2i(x, y)));
	this->numOfEnemies += 1;
}
