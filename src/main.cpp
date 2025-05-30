#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FileParser.h"
#include "GameController.h"
#include <filesystem>
#include <cstdlib>  
#include <ctime>  
#include "Exception.h"


int main() {
	try {


		srand(static_cast<unsigned>(std::time(nullptr)));
		auto controller = GameController();
		controller.run();
	}
	catch (const FileNotFound& e) {

	}
	catch (std::exception& e) {
		std::cerr << "got: " << e.what() << std::endl;
		return 3;
	}
	return 0;
}
