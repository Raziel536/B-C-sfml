#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Map;
class Bullet
{
private:
	float bullet_X, bullet_Y, bullet_Dx, bullet_Dy;
	int bullet_Dir;
	sf::Texture bullet_Texture;
public:
	bool present; //был выстрел или нет ,  когда true - пулька летит, когда false - пульки нет
	float time_Before_Shot;
	sf::Sprite bullet_Sprite;

	
	explicit Bullet(const float& x, const float& y);

	void shoot();
	void move(const float& time);
	void update(Map &map, const float& time, float& x, float& y, int& dir);
	void map_interaction(Map& map);
};