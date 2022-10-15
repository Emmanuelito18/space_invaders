#include <SFML/Graphics.hpp>
#include <iostream>
#include "headers/spaceship.h"

Spaceship::Spaceship( 
    sf::Event* event, 
    sf::RenderWindow* window)
{
  pwindow = window;
  pevent = event;
}

// control movement and fire
void Spaceship::input(sf::Event* pevent)
{
  if(pevent -> type == sf::Event::KeyPressed)
  {
    switch(pevent   ->   key.code)
    {
      case sf::Keyboard::A: 
        Spaceship::left();
        break;

      case sf::Keyboard::D: 
        Spaceship::right();
        break;

      case sf::Keyboard::Space:
        shoot = true;
        break;

      default:
        break;
    }
  }
}

// movement
void Spaceship::left()
{
  if(position[0] > -(pwindow  ->  getSize().x / 2.1f)) 
  {
    ss_model.setPosition(sf::Vector2f((position[0] -= 20.f), 0.f));
  }
}

void Spaceship::right()
{
  if(position[0] < (pwindow -> getSize().x / 2.1f))
  {
    ss_model.setPosition(sf::Vector2f((position[0] += 20.f), 0.f));
  }
}

// display spaceship
void Spaceship::ss_display()
{
  sf::Texture ss_texture; // spaceship texture

  if (!ss_texture.loadFromFile("assets/spaceship.png"))
  {
    std::cout 
      << "sfml: could not load texture"
      << std::endl;
  }

  // setup the sprite location
  ss_model.setOrigin(sf::Vector2f(
        -(pwindow -> getSize().x * 4.8f) / 2.f, 
        -(pwindow -> getSize().y * 4.5f)));

  // setup scale and texture
  ss_model.setScale(sf::Vector2f(0.2f, 0.2f)); // ss_scale
  ss_model.setTexture(ss_texture);             // ss_texture

  // draw this bad boi
  pwindow -> draw(ss_model); 
  shot();
}

void Spaceship::shot()
{
  // TODO: make the bullet show up

  bullet.setSize(sf::Vector2f(3.f, 30.f)); bullet.setFillColor(sf::Color::Red);
  bullet.setOrigin(sf::Vector2f( // set origin at spaceship position        
        -(pwindow -> getSize().x / 2.f) - position[0], 
        -(pwindow -> getSize().y / 1.15f)));

  bullet.setPosition(0.f, position[1]);

  if(shoot)
  {
    position[1] < -1000.f ? shoot = false : position[1] -= 25.f;
    pwindow -> draw(bullet);
  }
  else
  {
    position[1] = { 0 };
  }
}
