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

    struct {
      sf::RectangleShape b_model;
      bool visible = false;
    } bullet;

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

    struct { // alien structure
      sf::Sprite sprite;
      bool visible = true;
    } a_model[40];

    struct {
      sf::RectangleShape *b_model;
      bool* visible;
    } another_b;
    sf::RenderWindow* pwindow;

  public:

    Alien(
        Spaceship &spaceship, 
        sf::RenderWindow* window);

    void movement();

    void fire();

    void a_display();
};
