#pragma once

#include <SFML/Graphics.hpp>
#include "gamestate.h"

class Pause : public GameState
{
public:

  Pause(Game *game);
  virtual void draw();
  virtual void update(sf::Time dT);
  void handleInput();
private:
  void exitGame();
};
