#include "bullet.h"
#include "Map.h"

Bullet::Bullet(const float& x, const float& y)
{
	present = false;
	bullet_X = x;
	bullet_Y = y;
	bullet_Dir = 0;
	bullet_Dx = 0.f;
	bullet_Dy = 0.f;
	time_Before_Shot = 0.f;

    //загрузка текстурки пули и установка спрайта
	bullet_Texture.loadFromFile("assets/bullet/bulletSprite.png");
	bullet_Sprite.setTexture(bullet_Texture);
	bullet_Sprite.setTextureRect(sf::IntRect(0, 0, 9, 12));
	bullet_Sprite.setPosition(x, y);
}


void Bullet::shoot()
{
    present = true;
}

void Bullet::move(const float& time)
{
    //возможные случаи направления пульки и её поведение в этих случаях Dx, Dy - скорости пули по координатам
    switch (bullet_Dir) {
    case 0: //вправо
        bullet_Dx = 0.3f;
        bullet_Dy = 0;
        bullet_Sprite.setRotation(90.f);
        break;

    case 1: //влево
        bullet_Dx = -0.3f;
        bullet_Dy = 0;
        bullet_Sprite.setRotation(-90.f);
        break;

    case 2://вниз
        bullet_Dx = 0;
        bullet_Dy  = 0.3f;
        bullet_Sprite.setRotation(180.f);
        break;

    case 3://вверх
        bullet_Dx = 0;
        bullet_Dy = -0.3f;
        bullet_Sprite.setRotation(0.f);
        break;
    }
    //как изменяются координаты пульки
    bullet_X += bullet_Dx * time; 
    bullet_Y += bullet_Dy * time;
    bullet_Sprite.setPosition(bullet_X, bullet_Y); //изменение позиции пульки на карте
}

void Bullet::update(Map& map, const float& time, float& x, float& y, int& dir)
{
    if(present)
    {
        move(time);
        map_interaction(map);
    } else {
        //привязка пули к дулу танка в зависимости от его направления
    	bullet_Dir = dir;
        switch (bullet_Dir) {
        case 0: //вправо
            bullet_X = x + 35.f;
            bullet_Y = y + 15.f;
            break;

        case 1: //влево
            bullet_X = x + 7.f;
            bullet_Y = y + 23.f;
            break;

        case 2://вниз
            bullet_X = x + 23.f;
            bullet_Y = y + 32.f;
            break;

        case 3://вверх
            bullet_X = x + 15.f;
            bullet_Y = y + 5.f;
            break;
        }
        bullet_Sprite.setPosition(bullet_X, bullet_Y);
    }
}

void Bullet::map_interaction(Map& map)
{
    for (int i = bullet_Y / 24; i < (bullet_Y + 12) / 24; ++i)
        for (int j = bullet_X / 24; j < (bullet_X + 9) / 24; ++j) {
            char tile = map.get_tile(i, j);
            if (tile == '0' || tile == '2')
            {
                present = false;
            }

            if (tile == '1')
            {
                map.break_wall(i, j);
                present = false;
            }
        }
}
