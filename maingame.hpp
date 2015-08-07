#pragma once

#include <SFML/Graphics.hpp>
#include "gamestate.hpp"
#include "player.h"
#include "guard.h"

class MainGame : public GameState
{
public:
  MainGame(Game* game);
  virtual void draw();
  void handleInput();
  virtual void update();
private:
  Player player;
  Guard guard;
};
