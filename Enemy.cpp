#include "Enemy.h"

Enemy::Enemy(const float& x, const float& y): Tank(x, y, 39, 39, "assets/enemy/enemySprites.png")
{
    time_Before_Shot = 0.f;
    time_Before_Moving = 0.f;
}

void Enemy::move(const float& time)
{
    tank_Speed = 0.1f;
    time_Before_Moving += time;

    if (time_Before_Moving > 1000 + rand() % 250) {
        tank_Dir = rand() % 4;
        time_Before_Moving = 0.f;
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
    if (tank_Collision) tank_interaction();
    tank_X += tank_Dx * time;
    tank_Y += tank_Dy * time;
}

void Enemy::shoot(const float& time)
{
    time_Before_Shot += time;
    if(time_Before_Shot > 1000.f)
    {
	    if(!bullet.present)
	    {
            if (rand() % 2)
            {
            	bullet.present = true;
            }
	    }
        time_Before_Shot = 0.f;
    }
}

void Enemy::update(const float& time, Map& map, const bool& collision)
{
    tank_Collision = collision;
    move(time);

	tank_Speed = 0.f;
    tank_Sprite.setPosition(tank_X, tank_Y);
    animate(time);
	map_interaction(map);

	bullet.update(map, time, tank_X, tank_Y, tank_Dir);
    shoot(time);
}
