#include "npc.h"
#include <math.h>
#include <iostream>

NPC::NPC()
{
}

void NPC::setTarget(sf::Vector2f target)
{
  this->target = target;
}

void NPC::doMove(sf::Time dT)
{
  float speed = this->speed * dT.asSeconds();

  sf::Vector2f diff(this->getPosition() - this->target);
  float rotation = std::atan2(diff.y, diff.x);

  this->setRotation(rotation * 180 / 3.142);

  float dX = -std::cos(rotation) * speed;
  float dY = -std::sin(rotation) * speed;
  this->move(dX, dY);
}

