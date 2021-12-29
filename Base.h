#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Base : private sf::NonCopyable {
private:
    sf::Texture base_Texture;
    float base_X, base_y;
public:
    sf::Sprite base_Sprite;
    bool life;

    Base(const float& x, const float& y);
};
