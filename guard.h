#pragma once

#include "npc.h"
#include "player.h"

class Guard : public NPC
{
public:
  Guard();
  void update(sf::Time dT);
  bool hitPlayer(Player player);
private:
  bool boost;
};
