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
  float radians = std::atan2(diff.y, diff.x);
  float rotation = radians * 180 / 3.142;

  this->setRotation(rotation);

  float dX = -std::cos(radians) * speed;
  float dY = -std::sin(radians) * speed;
  this->move(dX, dY);
}

