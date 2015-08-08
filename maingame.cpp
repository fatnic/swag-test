#include "maingame.hpp"
#include "mainmenu.hpp"
#include "pause.h"
#include <iostream>

MainGame::MainGame(Game* game)
{
  this->game = game;

  this->player.load("assets/theguy.png");
  this->player.setPosition(this->game->window.getSize().x / 2, this->game->window.getSize().y / 2);

  this->guard.load("assets/guard.png");
  this->guard.setPosition(400, 100);
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

void MainGame::update(sf::Time dT)
{
  this->player.update(dT);
  this->guard.setTarget(this->player.getPosition());
  this->guard.update(dT);

  if (this->guard.hitPlayer(this->player))
    this->game->pushState(new MainMenu(this->game));
}
