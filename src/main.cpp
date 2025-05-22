#include <iostream>
#include "WindowManager.h"
#include <cstdlib>
#include <ctime>
#include "FileParser.h"
#include "GameController.h"
#include <filesystem>
int main() {
	try {
		auto controller = GameController();
		controller.run();
	}
	catch (std::exception& e) {
		std::cerr << "got: " << e.what() << std::endl;
		return 3;
	}
	return 0;
}
