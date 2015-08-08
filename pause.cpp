#include "pause.h"
#include "mainmenu.hpp"

Pause::Pause(Game *game)
{
    this->game = game;
}

void Pause::draw()
{

    sf::Font font;
    font.loadFromFile("assets/font.ttf");

    sf::Text title("SWAG", font, 120);
    title.setOrigin(title.getLocalBounds().width/2, 0);
    title.setPosition(this->game->window.getSize().x/2, 90);

    sf::Text start("Press [SPACE] to unpause", font, 30);
    start.setOrigin(start.getGlobalBounds().width/2, 0);
    start.setPosition(this->game->window.getSize().x/2, 350);

    sf::Text quit("Press [ESC] to return to main menu", font, 30);
    quit.setOrigin(quit.getGlobalBounds().width/2, 0);
    quit.setPosition(this->game->window.getSize().x/2, start.getPosition().y + start.getGlobalBounds().height + 20);

    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(title);
    this->game->window.draw(start);
    this->game->window.draw(quit);
    return;
}

void Pause::update(sf::Time dT)
{

}

void Pause::handleInput()
{
  sf::Event event;

  while(this->game->window.pollEvent(event))
  {
      switch(event.type)
      {
      case sf::Event::Closed:
          game->window.close();
          break;
      case sf::Event::KeyPressed:
          if (event.key.code == sf::Keyboard::Escape) this->exitGame();
          if (event.key.code == sf::Keyboard::Space) this->game->popState();
          break;

      default: break;
      }
  }
  return;
}

void Pause::exitGame()
{
    this->game->pushState(new MainMenu(this->game));
    return;
}
