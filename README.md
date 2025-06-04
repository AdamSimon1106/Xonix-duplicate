# Xonix Game Project

## Author Details
Name: Adam Simonov
Name: Benny Beer

## General Description
This exercise is a modern C++ implementation of the classic "Xonix" arcade game. The player moves across a grid, creating trails to claim territory while avoiding enemies. The game iis built using object-oriented principles with the SFML library for rendering and input.

## File List
**main.cpp** – Entry point for the program. Initializes the game controller and starts the main loop.
**GameController.{h,cpp}** – Manages game states, window handling, and the main update-render loop.
**Board.{h,cpp}** – Manages the game grid (tiles), level loading, and area filling logic.
**Tile.{h,cpp}** – Represents individual tiles on the board, including type and color.
**Player.{h,cpp}** – Manages player movement, collision detection, and trail creation.
**Enemy.{h,cpp}** – Controls enemy behavior and movement logic.
**Hud.{h,cpp}** – Displays score and lives remaining.
**FileParser.{h,cpp}** – Loads game configuration and level data from text files.
**IGameState.h** – Interface for implementing different game states.
**WelcomeState.{h,cpp}** – Handles the welcome screen, including the background and "Play" button.
**InGameState.{h,cpp}** – Main gameplay state where the player interacts with the board.
**WinState.{h,cpp}** – Displays the win screen with score and options to restart or quit.
**LoseState.{h,cpp}** – Displays the game-over screen with similar options.
**resources/** – Contains game assets such as game_data.txt and background images.

## Key Data Structures
std::vector<std::vector<Tile>> m_grid – The 2D game board representing the current state of each cell. - using a vector of vectors here is suboptimal, I would probably use a multimap.
std::stack <sf::RectangleShape> m_path – Represents the player’s active trail. - used stack for its O(1) at the edges,
std::vector <Enemy> m_enemies – Stores active enemies in the game. - using vector for it's sequential iterators.

## Notable Algorithms 
Flood Fill – Implemented in Board::floodFillFrom() to detect and fill enclosed areas - a recursive algorithem smartly implemented using the enemies

## Design
The game is designed around a __State Machine__ architecture:
GameController manages the current IGameState object and transitions between states.
Each state class (WelcomeState, InGameState, WinState, LoseState) inherits from IGameState and implements its own logic for rendering, event handling, and updating.
Board handles game logic like tile setting and area filling.
Player manages user input, movement, and interaction with the grid.
Enemy moves independently and poses a threat to the player.
FileParser allows levels and game settings to be modified via external files.

## The interaction flow
The game starts in WelcomeState.
Clicking "Play" switches to InGameState.
Completing a level transitions to WinState; failing transitions to LoseState.
States can request a transition using GameController::switchState().
