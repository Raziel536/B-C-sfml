#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Map : sf::NonCopyable
{
private:
	static const int HEIGHT_MAP = 28;
	static const int WIDTH_MAP = 30;
	sf::String* TileMap;
	sf::Texture map_texture;
	sf::Sprite map_sprite;
public:
	Map();
	void break_wall(const int& i, const int& j);
	const char get_tile(const int& i, const int& j);
	void draw(sf::RenderWindow& window);
};

