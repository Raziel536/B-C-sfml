#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Text {
private:
	float text_X, text_Y;
	sf::Font text_Font;
	sf::Text text_String;
public:
	explicit Text(const float& x, const float& y, const sf::String& string);
	void print(sf::RenderWindow& window);
};