#include <iostream>
#include "WindowManager.h"
#include <cstdlib>
#include <ctime>
#include "FileParser.h"
#include <filesystem>
int main() {
	try {
		std::cout << "Working directory: " << std::filesystem::current_path() << "\n";
		FileParser parser("resources/game_data.txt");

		//Parse game-wide settings
		GameData gameData = parser.parseGameData();
		std::cout << gameData.toString();

		std::vector<LevelData> levelData = parser.parseLevelData();
		for (LevelData& level : levelData) {
			std::cout << level.toString();
		}

	}
	catch (std::exception& e) {
		std::cerr << "got: " << e.what() << std::endl;
		return 3;
	}
	return 0;
}
