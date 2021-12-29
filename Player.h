#pragma once
#include <SFML/Window/Keyboard.hpp>
#include "Tank.h"


using namespace sf;

class Player : public Tank
{
public:
	Player();

	void move(const float& time);
	void update(const float& time, Map& map, const bool &collision);
	
	
};
