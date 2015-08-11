#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "gamestate.h"
#include "player.h"
#include "guard.h"
#include "wall.h"
#include "tmx/MapLoader.h"

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
  tmx::MapLoader ml;
};
