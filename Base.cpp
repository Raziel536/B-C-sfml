#include "Base.h"

Base::Base(const float& x, const float& y)
{
	base_X = x;
	base_y = y;
	life = true;
	base_Texture.loadFromFile("assets/base/baseSprite.png");
	base_Sprite.setTexture(base_Texture);
	base_Sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
	base_Sprite.setPosition(base_X, base_y);
}
