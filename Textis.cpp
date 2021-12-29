#include "Textis.h"

Textis::Textis(const float& x, const float& y, const sf::String& str)
{
	text_X = x;
	text_Y = y;
	text_Font.loadFromFile("assets/fonts/Press.ttf");
	text_string.setFont(text_Font);
	text_string.setString(str);
	text_string.setPosition(text_X, text_Y);
	text_string.setCharacterSize(25);
}
