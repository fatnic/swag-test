#include "maingame.hpp"
#include "pause.h"

MainGame::MainGame(Game* game)
{
    this->game = game;

    this->player.load("assets/theguy.png");
    this->player.setPosition(this->game->window.getSize().x/2, this->game->window.getSize().y/2);

    this->guard.load("assets/guard.png");
    this->guard.setPosition(this->player.getPosition().x, this->player.getPosition().y-100);
    this->guard.scale(0.8f, 0.8f);
    this->guard.setRotation(180);
}

void MainGame::draw()
{
    this->game->window.draw(this->player);
    this->game->window.draw(this->guard);
    return;
}

void MainGame::handleInput()
{

  this->player.handleInput();

  sf::Event event;
  while(this->game->window.pollEvent(event))
  {

      if (event.key.code == sf::Keyboard::Escape) this->game->pushState(new Pause(this->game));
      break;

      switch(event.type)
      {
      case sf::Event::Closed:
          game->window.close();
          break;
      default: break;
      }
  }
  return;
}

void MainGame::update()
{
  this->player.update();
}
