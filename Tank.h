#pragma once
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <utility>
#include "bullet.h"


class Map;

class Tank : private sf::NonCopyable
{
protected:
	float tank_X, tank_Y, tank_Width, tank_Height, tank_Dx, tank_Dy, tank_Speed;
	int tank_Dir;
	float tank_CurrentFrame;
	bool tank_Collision;
	sf::String tank_File;
	sf::Texture tank_Texture;
public:
	explicit Tank(const float& x, const float& y, const float& width, const float& height, const sf::String& file);
	bool life;
	int health;

	Bullet bullet;

	sf::Sprite tank_Sprite;
	void animate(const sf::Int64& time);
	void collapse();
	virtual void move(const sf::Int64& time) {}
	void map_interaction(Map& map);
	void tank_interaction();
};
