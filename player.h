#pragma once

#include <SFML/Window.hpp>
#include "entity.h"
#include "wall.h"

class Player : public Entity
{
public:
  Player();
  void handleInput();
  void update(sf::Time dT);
  void doMove();
  bool checkWallCollision(Wall* wall);
private:
  bool movingUp;
  bool movingDown;
  bool movingLeft;
  bool movingRight;

  bool boost;
};
