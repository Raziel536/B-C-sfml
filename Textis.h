#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Textis 
{
private:
	float text_X, text_Y;
	sf::Font text_Font;
	sf::Text text_string;

public:
	explicit Textis(const float& x, const float& y, const sf::String& str);
	void print(sf::RenderWindow& window)
	{
		window.draw(text_string);
	}
};
