#include "guard.h"
#include <iostream>

Guard::Guard()
{
  this->boost = false;
}

void Guard::update(sf::Time dT)
{
  this->doMove(dT);
}




