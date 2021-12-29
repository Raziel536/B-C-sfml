#pragma once
#include "Tank.h"

class Enemy : public Tank {
private:
    float time_Before_Moving;
    float time_Before_Shot;

public:
    Enemy(const float& x, const float& y);
    Enemy(const Enemy& copy) : Enemy(copy.tank_X, copy.tank_Y) {}

    void move(const float& time);
    void shoot(const float& time);
    void update(const float& time, Map& map, const bool& collision);
};
