#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "gamestate.hpp"
#include "player.h"
#include "guard.h"
#include "wall.h"

class MainGame : public GameState
{
public:
  MainGame(Game* game);
  virtual void draw();
  void handleInput();
  virtual void update(sf::Time dT);
private:
  Player player;
  Guard guard;
  std::vector<Wall> walls;
};
