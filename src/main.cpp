#include <iostream>
// TODO(adam): implement main.cpp to initialize GameController and start the game
#include "WindowManager.h"
#include <cstdlib>
#include <ctime>



int main() {
	// Seed the random number generator
	srand(static_cast<unsigned>(std::time(nullptr)));
	WindowManager windowManager("Test", WINDOW_WIDTH, WINDOW_HEIGHT);
	windowManager.run();
	return 0;

};
