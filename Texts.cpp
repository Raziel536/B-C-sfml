#include "Texts.h"

Text::Text(const float& x, const float& y, const sf::String& string)
{
	text_X = x;
	text_Y = y;

	text_Font.loadFromFile("assets/fonts/Press.ttf");
	text_String.setFont(text_Font);
	text_String.setString(string);
	text_String.setPosition(text_X, text_Y);
	text_String.setCharacterSize(40)

}

void Text::print(sf::RenderWindow& window)
{
}
