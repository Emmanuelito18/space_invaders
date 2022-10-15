#include <iostream>
#include "headers/spaceship.h"
#include <SFML/Graphics.hpp>
// #include <SFML/OpenGL.hpp>

sf::RenderWindow window; // window
sf::Event        event;  // events
Spaceship        player(&event, &window); // player
Alien            alien(player, &window);  // Alien

void handle_events(sf::RenderWindow &window, sf::Event &event)
{
  while(window.pollEvent(event)) 
  {
      if(event.type == sf::Event::Closed)
      {
        window.close();
        return;
      }
      player.input(&event);
  }
}

void game_window(sf::RenderWindow &window)
{

  window.create(
    sf::VideoMode(2560, 1080),
    "Space Invaders",
    sf::Style::Fullscreen
      );

  window.setVerticalSyncEnabled(true);
  sf::Event events;

  while(window.isOpen())
  {
    handle_events(window, events);

    window.clear();

    player.ss_display();
    alien.a_display();
    window.display();
  }
}

int 
main()
{
  game_window(window);

  return 0;
}
