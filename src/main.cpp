#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FileParser.h"
#include "GameController.h"
#include <filesystem>
#include <cstdlib>  
#include <ctime>    
int main() {
	try {


		srand(static_cast<unsigned>(std::time(nullptr)));
		auto controller = GameController();
		controller.run();
	}
	catch (std::exception& e) {
		std::cerr << "got: " << e.what() << std::endl;
		return 3;
	}
	return 0;
}
