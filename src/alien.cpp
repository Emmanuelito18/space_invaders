#include <iostream>
#include <SFML/Graphics.hpp>
#include "headers/spaceship.h"

Alien::Alien(  
    Spaceship &spaceship, 
    sf::RenderWindow* window)
{
  pwindow = window;
  another_b.b_model = &spaceship.bullet.b_model; 
  another_b.visible = &spaceship.bullet.visible; 
}

void Alien::movement()
{
  // TODO: 
}

void Alien::fire()
{
  // TODO: fire 
}

void Alien::a_display()
{
  sf::Texture a_texture; // spaceship texture

  if (!a_texture.loadFromFile("assets/alien.png"))
  {
    std::cout 
      << "sfml: could not load texture"
      << std::endl;
  }

  // set bounds of bullet
  sf::FloatRect b_bounds = another_b.b_model -> getGlobalBounds();

  float row{};
  float column{-200.f};

  int column_count{};
  int row_count{};
   
  sf::FloatRect bounds[40];
  
  for (int i{}; i < 40; i++)
  {
    if (column_count > 9)
    {
      row = 0.f;
      column += -600.f;
      column_count = 0;
      row_count += 1;
    }

    // setup the sprite location
    a_model[i].sprite.setOrigin(sf::Vector2f(
      row -= (pwindow -> getSize().x / 10.f) + 400, 
      column));
    column_count++;
    
    // scale and texture alien
    a_model[i].sprite.setScale(sf::Vector2f(0.15f, 0.15f)); // a_scale
    a_model[i].sprite.setTexture(a_texture);              // a_texture

    // get bounds only if visible
    if (a_model[i].visible)
    {
      bounds[i] = a_model[i].sprite.getGlobalBounds();
    }

    // change visibility if touch bullet
    if (bounds[i].intersects(b_bounds))
    {
      a_model[i].visible = false;
      *another_b.visible = false;
    }
    else 
    {
      // draw aliens
      if (a_model[i].visible)
      {
        pwindow -> draw(a_model[i].sprite);
      }
    }
  } 
}
