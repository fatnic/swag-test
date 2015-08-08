#include "npc.h"
#include <math.h>

NPC::NPC()
{
}

void NPC::setTarget(sf::Vector2f target)
{
  this->target = target;
}

void NPC::doMove()
{
  sf::Vector2f diff(this->getPosition() - this->target);
  float rotation = (std::atan2(diff.y, diff.x)) * 180 / 3.142;

  this->setRotation(rotation);
  this->setPosition(this->getPosition() + (this->target - this->getPosition()) * 0.001f);
}

