#pragma once

#include <SFML/Graphics.hpp>
#include "gamestate.hpp"

class Pause : public GameState
{
public:

  Pause(Game *game);
  virtual void draw();
  virtual void update();
  void handleInput();
private:
  void exitGame();
};
