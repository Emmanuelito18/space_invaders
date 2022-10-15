#include <SFML/Graphics.hpp>

class Spaceship
{
  protected:
    float position[2]{};
    bool shoot = false;

    sf::Sprite ss_model;
    sf::Event* pevent;
    sf::RenderWindow* pwindow;

  public:

    sf::RectangleShape bullet;

    Spaceship( 
        sf::Event* event,
        sf::RenderWindow* window); 
    // -------- movement ---------
    void input(sf::Event* pevent);

    void left();

    void right();

    // -------- firing ----------
    void shot();

    // ------ displaying --------
    void ss_display();
};

class Alien
{
  protected:
    float position[2]{};
    bool visible = true;

    sf::Sprite a_model[56];
    sf::RectangleShape* another_b;
    sf::RenderWindow* pwindow;

  public:

    Alien(
        Spaceship &spaceship, 
        sf::RenderWindow* window);

    void movement(
        sf::RenderWindow &window);

    void fire(
        sf::RenderWindow &window);

    void a_display(
        sf::RenderWindow &window);
};

class Bullet
{
  protected:
    bool shoot = true;
    float position[2]{};

    sf::RenderWindow* pwindow;
    sf::RectangleShape bullet;

  public:
    
    Bullet( 
        sf::RenderWindow* window,
        float p[2]);

    void fire();
};
