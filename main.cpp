#include "game.h"
#include "mainmenu.h"

int main()
{
  Game game;
  game.pushState(new MainMenu(&game));
  game.gameLoop();
  return 0;
}
