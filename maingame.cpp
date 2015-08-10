#include "maingame.hpp"
#include "mainmenu.hpp"
#include "pause.h"
#include <iostream>

MainGame::MainGame(Game* game)
{
  this->game = game;

  this->player.setPosition(this->game->window.getSize().x / 2, this->game->window.getSize().y / 2);

  this->guard.setPosition(400, 100);

  //Use sf::IntRect in the future when loading from tilemap
  Wall wall1(sf::IntRect(0,0,50,400));
  Wall wall2(sf::IntRect(600,200,100,100));
  this->walls.push_back(wall1);
  this->walls.push_back(wall2);
}

void MainGame::draw()
{
  for (auto& wall : this->walls) { this->game->window.draw(wall); }
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
  for (auto& wall : walls) { this->player.checkWallCollision(&wall); }
  this->guard.setTarget(this->player.getPosition());
  this->guard.update(dT);

//  if (this->guard.hitPlayer(this->player))
//    this->game->pushState(new MainMenu(this->game));
}
