#include <SFML/Window/Keyboard.hpp>
#include "Player.h"
#include "Map.h"


using sf::Keyboard;



Player::Player()
	: Tank(244, 600, 39, 39, "assets/player/playerSprites.png")
{
}

void Player::move(const float& time)
{
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		tank_Dir = 1;
		tank_Speed = 0.11f;
	}

	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		tank_Dir = 0;
		tank_Speed= 0.11f;
	}

	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		tank_Dir = 3;
		tank_Speed = 0.11f;
	}

	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		tank_Dir = 2;
		tank_Speed = 0.11f;
	}

	switch (tank_Dir) {
	case 0:
		tank_Dx = tank_Speed;
		tank_Dy = 0;
		break;

	case 1:
		tank_Dx = -tank_Speed;
		tank_Dy = 0;
		break;

	case 2:
		tank_Dx = 0;
		tank_Dy = tank_Speed;
		break;

	case 3:
		tank_Dx = 0;
		tank_Dy = -tank_Speed;
		break;
	}
	if (tank_Collision) 
		tank_interaction();
	tank_X += tank_Dx * time;
	tank_Y += tank_Dy * time;
}

void Player::update(const float& time, Map& map, const bool &collision)
{
	tank_Collision = collision;
	move(time);
	tank_Speed = 0.f;
	tank_Sprite.setPosition(tank_X, tank_Y);
	animate(time);
	map_interaction(map);

	bullet.update(map, time, tank_X, tank_Y, tank_Dir);
	if(!bullet.present)
	{
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			bullet.time_Before_Shot += time;
			if(bullet.time_Before_Shot > 10.f)
			{
				bullet.present = true;
				bullet.time_Before_Shot = 0.f;
			}
		}
	}
}
