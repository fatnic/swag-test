#include "game.hpp"
#include "mainmenu.hpp"

int main()
{
  Game game;
  game.pushState(new MainMenu(&game));
  game.gameLoop();
  return 0;
}
