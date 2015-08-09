#include "wall.h"

Wall::Wall(sf::IntRect placement)
{
  this->setPosition(placement.left, placement.top);
  this->setSize(sf::Vector2f(placement.width, placement.height));
  this->setFillColor(sf::Color::Green);
}

