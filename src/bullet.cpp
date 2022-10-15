#include <iostream>
#include <SFML/Graphics.hpp>
#include "headers/spaceship.h"

Bullet::Bullet( 
    sf::RenderWindow *window,
    float p[2])
{
  pwindow = window;
  position[0] = p[0];
  position[1] = p[1];
}

void Bullet::fire()
{
  // TODO: make the bullet show up
  bullet.setSize(sf::Vector2f(3.f, 30.f)); bullet.setFillColor(sf::Color::Red);
  bullet.setOrigin(sf::Vector2f(        
        -(pwindow -> getSize().x / 2.f) - position[0], 
        -(pwindow -> getSize().y / 1.1f)));
  bullet.setPosition(0.f, 100.f);

  while(shoot)
  {
    position[1] < -1000.f ? shoot = false : position[1] -= 25.f;
    pwindow -> draw(bullet);
  }
}
