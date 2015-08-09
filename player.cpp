#include "player.h"
#include <iostream>

Player::Player()
{
  this->load("assets/theguy.png");
  this->boost = false;

  this->movingUp = false;
  this->movingDown = false;
  this->movingLeft = false;
  this->movingRight = false;
}

void Player::handleInput()
{
  this->movingUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
  this->movingDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
  this->movingLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
  this->movingRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

  this->boost = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
  this->boost = sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);
}

void Player::doMove()
{

  if (this->movingUp && this->movingRight)
    {
      this->move(speed, -speed);
      this->setRotation(45);
    }
  else if (this->movingUp && this->movingLeft)
    {
      this->move(-speed, -speed);
      this->setRotation(-45);
    }
  else if (this->movingDown && this->movingRight)
    {
      this->move(speed, speed);
      this->setRotation(125);
    }
  else if (this->movingDown && this->movingLeft)
    {
      this->move(-speed, speed);
      this->setRotation(-125);
    }
  else if (this->movingUp)
    {
      this->move(0, -speed);
      this->setRotation(0);
    }
  else if (this->movingDown)
    {
      this->move(0, speed);
      this->setRotation(180);
    }
  else if (this->movingLeft)
    {
      this->move(-speed, 0);
      this->setRotation(-90);
    }
  else if (this->movingRight)
    {
      this->move(speed, 0);
      this->setRotation(90);
  }
}

bool Player::checkWallCollision(Wall *wall)
{
  if (this->getGlobalBounds().intersects(wall->getGlobalBounds()))
    {
      wall->setFillColor(sf::Color::Red);
    }
  else
    {
      wall->setFillColor(sf::Color::Green);
    }
}

void Player::update(sf::Time dT)
{
  this->speed = (this->boost) ? 150.f * dT.asSeconds() : 100.f * dT.asSeconds();
  this->doMove();
}


