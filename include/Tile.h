#pragma once
#include <SFML/Graphics.hpp>

enum class TileType {
	Empty, Trail, Filled, Border, temp, Enemy
};

class Tile {
private:
	sf::RectangleShape m_shape;
	TileType m_type;

public:
	Tile();
	void draw(sf::RenderWindow& window);
	void setType(TileType type);
	TileType getType() const;
	void setColor(sf::Color color);
	const sf::Vector2f getPosition() const;
	void setPosition(float x, float y); 
	sf::Color getColor() const { return m_shape.getFillColor(); }
};
