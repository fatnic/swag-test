#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite
{
public:
    Entity();
    void load(std::string filename);
    ~Entity();
private:
    sf::Texture texture;
protected:
    float speed;
};
