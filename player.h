#pragma once

#include <SFML/Window.hpp>
#include "entity.h"

class Player : public Entity
{
public:
  Player();
  void handleInput();
  void update();
  void doMove();
private:
  bool movingUp;
  bool movingDown;
  bool movingLeft;
  bool movingRight;

  bool boost;
};
