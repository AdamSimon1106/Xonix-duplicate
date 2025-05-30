#pragma once
#include <exception>
#include <string>
#include <SFML/Graphics.hpp>


class GameException : public std::runtime_error
{
public:
	GameException(const std::string& msg) : std::runtime_error(msg)
	{
	}
};

class FileNotFound : public GameException {
public:
	FileNotFound(const std::string& path): GameException("Path " + path + " not found")
	{}
};

class OutOfBounds : public GameException {
public:
	OutOfBounds(const sf::Vector2i& pos)
		: GameException("Position (" + std::to_string(pos.x) + ", " + std::to_string(pos.y) + ") is out of bounds") {}
};

class InvalidInput : public GameException {
public:
	InvalidInput(const std::string& s)
		: GameException("Invalid input: \"" + s + "\" for game format") {}
private:
	
};

