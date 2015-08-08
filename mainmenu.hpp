#pragma once

#include <SFML/Graphics.hpp>
#include "gamestate.hpp"

class MainMenu : public GameState
{
public:

  MainMenu(Game *game);
  virtual void draw();
  virtual void update(sf::Time dt);
  void handleInput();
private:
  void loadGame();
};
