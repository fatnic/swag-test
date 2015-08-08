#include "maingame.hpp"
#include "pause.h"

MainGame::MainGame(Game* game)
{
    this->game = game;

    this->player.load("assets/theguy.png");
    this->player.setPosition(this->game->window.getSize().x / 2, this->game->window.getSize().y / 2);

    this->guard.load("assets/guard.png");
    this->guard.setPosition(760, 10);
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

      switch(event.type)
      {
      case sf::Event::Closed:
          game->window.close();
          break;
      case sf::Event::KeyPressed:
          if (event.key.code == sf::Keyboard::Escape) this->game->pushState(new Pause(this->game));
          break;
      }

  }
  return;
}

void MainGame::update()
{
  this->player.update();
  this->guard.setTarget(this->player.getPosition());
  this->guard.update();
}
