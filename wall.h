#pragma once

#include <SFML/Graphics.hpp>

class Wall : public sf::RectangleShape
{
public:
    Wall(sf::IntRect placement);
};
