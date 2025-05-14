//
// Created by Adam Simonov on 12/5/25.
//

#include "../include/FileParser.h"

GameData FileParser::parseGameData()
{
	GameData data;
	std::string line;
	std::getline(m_file, line);

	std::istringstream iss(line);
	iss >> data.screenSize.x >> data.screenSize.y >> data.numOfLives;
	return data;
}

std::vector<LevelData> FileParser::parseLevelData()
{
	std::vector<LevelData> levels;
	LevelData level;
	
	std::istringstream iss;
	
	while (!m_file.eof()) {
		std::string line, next;
		std::getline(m_file, line);
		iss.clear();
		iss.str(line);
		//read presentage
		iss >> level.requiredPresentage;
		//read enemy data
		int count = 0;
		while (iss >> next) {
			if (std::isdigit(next[0])) {
				count = std::stoi(next);
				TODO : level.generatePositions(count);
			}
			else if (next.front() == '(' && next.back() == ')') {
				while (true) {
					count++;
					int x = std::stoi(next);
					iss >> next;
					int y = std::stoi(next);
					level.addEnemy(x, y);
					if (iss.eof()) {
						break;
					}
					iss >> next;
				}
			}
			else {
				throw std::runtime_error("invalid level formatting");
			}
			level.numOfEnemies = count;
		}
	}
}

std::string GameData::toString()
{
	std::ostringstream oss;
	oss << "screen size is: " << this->screenSize.x << " x " << this->screenSize.y << "num of lives: " << this->numOfLives << "\n";
	return oss.str();
}

void LevelData::generatePositions(const int& count)
{
	this->numOfEnemies = count;
	//TODO - make this smarter
	for (int i = 0; i < count; i++) {
		this->enemies.push_back(new Enemy(10, 10));
	}
}
