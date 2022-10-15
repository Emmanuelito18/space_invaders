#include <iostream>
#include <SFML/Graphics.hpp>
#include "headers/spaceship.h"

Alien::Alien(  
    Spaceship &spaceship, 
    sf::RenderWindow* window)
{
  pwindow = window;
  another_b = &spaceship.bullet; 
}

void Alien::movement( 
    sf::RenderWindow &window)
{
  // TODO: 
  // - move the alien 
}

void Alien::fire(
    sf::RenderWindow &window)
{

}

void Alien::a_display( 
    sf::RenderWindow &window)
{
  sf::Texture a_texture; // spaceship texture

  if (!a_texture.loadFromFile("assets/alien.png"))
  {
    std::cout 
      << "sfml: could not load texture"
      << std::endl;
  }

  // setup the sprite location

  // setup scale and texture
  sf::FloatRect b_bounds = another_b -> getGlobalBounds();

  float row{0};
  float column{-200.f};

  sf::FloatRect bounds[56];

  for (int i{0}; i < 56; i++)
  {
    if (row < -(pwindow -> getSize().x / 0.23f))
    {
      row = 0.f;
      column += -600.f;
    }

    a_model[i].setOrigin(sf::Vector2f(
      row -= 800, 
      column));
    
    a_model[i].setScale(sf::Vector2f(0.2f, 0.2f)); // a_scale
    a_model[i].setTexture(a_texture);              // a_texture

    bounds[i] = a_model[i].getGlobalBounds();

    if (bounds[i].intersects(b_bounds))
    {
      a_model[i].setColor(sf::Color::Black);
    }
    else 
    {
      window.draw(a_model[i]);  
    }
  } 
}
