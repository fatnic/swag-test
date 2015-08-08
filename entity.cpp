#include "entity.h"
#include <string>

Entity::Entity()
{
  this->speed = 100.f;
}

void Entity::load(std::string filename)
{
  this->texture.loadFromFile(filename);
  this->setTexture(this->texture);
  this->setOrigin(this->getGlobalBounds().width/2, this->getGlobalBounds().height/2);
}

Entity::~Entity()
{
}

sf::RectangleShape Entity::getHitbox()
{
  this->hitbox = sf::RectangleShape(sf::Vector2f(this->getLocalBounds().width, this->getLocalBounds().height));
  this->hitbox.setOrigin(this->getOrigin());
  this->hitbox.setRotation(this->getRotation());
  this->hitbox.setFillColor(sf::Color(120,0,0,150));
  this->hitbox.setPosition(this->getPosition());
  return this->hitbox;
}

