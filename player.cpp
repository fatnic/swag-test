#include "player.h"
#include <iostream>

Player::Player()
{
  this->movingUp = false;
  this->movingDown = false;
  this->movingLeft = false;
  this->movingRight = false;

  this->boost = false;
}

void Player::handleInput()
{
  movingUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
  movingDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
  movingLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
  movingRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

  boost = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
  boost = sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);

}

void Player::update()
{

  // DELETE ME!
  std::cout << this->movingUp << ":" << this->movingDown << ":" << this->movingLeft << ":" << this->movingRight << ":" << this->boost << std::endl;

  float speed = (this->boost) ? 4.f : 2.f;

  // TODO: Fix boost UL + DL
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


