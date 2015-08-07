#include "entity.h"
#include <string>

Entity::Entity()
{

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

