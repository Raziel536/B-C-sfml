#include "Tank.h"
#include "Map.h"

Tank::Tank(const float& x, const float& y, const float& width, const float& height, const sf::String& file): bullet(x, y)
{

	health = 100;
	if (health == 0)
		life = false;
	else if (health > 0)
		life = true;
	tank_X = x;
	tank_Y = y;
	tank_Dx = 0.f;
	tank_Dy = 0.f;
	tank_File = file;
	tank_Dir = 0;
	tank_Collision = false;
	tank_CurrentFrame = 0.f;
	tank_Speed = 0.f;
	tank_Width = width;
	tank_Height = height;
	tank_Texture.loadFromFile(file);
	tank_Sprite.setTexture(tank_Texture);
	tank_Sprite.setTextureRect(sf::IntRect(78, 39, tank_Width, tank_Height));
	tank_Sprite.setPosition(x, y);
}

void Tank::animate(const float& time)
{
	tank_CurrentFrame += 0.005f * time;
	if(tank_CurrentFrame >= 2)
	{
		tank_CurrentFrame -= 2;
	}
	if (tank_Dx > 0.f)
		tank_Sprite.setTextureRect(sf::IntRect(0 + 39 * static_cast<int>(tank_CurrentFrame), 0, 39, 39));
	if (tank_Dx < 0.f)
		tank_Sprite.setTextureRect(sf::IntRect(78 + 39 * static_cast<int>(tank_CurrentFrame), 0, 39, 39));
	if (tank_Dy > 0.0f)
		tank_Sprite.setTextureRect(sf::IntRect(0 + 39 * static_cast<int>(tank_CurrentFrame), 39, 39, 39));
	if (tank_Dy < 0.0f)
		tank_Sprite.setTextureRect(sf::IntRect(78 + 39 * static_cast<int>(tank_CurrentFrame), 39, 39, 39));
}

void Tank::collapse()
{
	life = false;
	bullet.present = false;
	tank_Sprite.setPosition(0, 0);
}

void Tank::map_interaction(Map& map)
{
	for (int i = tank_Y / 24; i < (tank_Y + tank_Height) / 24; ++i)
		for (int j = tank_X / 24; j < (tank_X + tank_Width) / 24; ++j) {
			char tile = map.get_tile(i, j);

			if (tile >= '0' && tile <= 's') {
				if (tank_Dy > 0.f)
					tank_Y = i * 24 - tank_Height;

				if (tank_Dy < 0.f)
					tank_Y = static_cast<float>(i) * 24 + 24;

				if (tank_Dx > 0.f)
					tank_X = j * 24 - tank_Width;

				if (tank_Dx < 0.f)
					tank_X = static_cast<float>(j) * 24 + 24;
			}
			if (tile == 'h') {
				health += 100;
				map.break_wall(i, j);
			}
		}
}

void Tank::tank_interaction()
{
	if (tank_Dy > 0.f)
		tank_Y -= 0.3f;

	if (tank_Dy < 0.f)
		tank_Y += 0.3f;

	if (tank_Dx > 0.f)
		tank_X -= 0.3f;

	if (tank_Dx < 0.f)
		tank_X += 0.3f;
}
