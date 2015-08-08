#pragma once

#include <SFML/Graphics.hpp>
#include "entity.h"

class NPC : public Entity
{
public:
    NPC();
    void setTarget(sf::Vector2f target);
    void doMove(sf::Time dT);
private:
    sf::Vector2f target;
};
