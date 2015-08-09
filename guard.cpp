#include "guard.h"
#include <iostream>

Guard::Guard()
{
  this->load("assets/guard.png");
  this->boost = false;
}

void Guard::update(sf::Time dT)
{
  this->doMove(dT);
}

bool Guard::hitPlayer(Player player)
{
  return (this->getGlobalBounds().intersects(player.getGlobalBounds()));
}




