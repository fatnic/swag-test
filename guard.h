#pragma once

#include "npc.h"

class Guard : public NPC
{
public:
    Guard();
    void update(sf::Time dT);
private:
  bool boost;
};
