#include <iostream>
#include <SFML/Graphics.hpp>
#include"Pilka.h"
#include"Paletka.h"
#include"Stone.h"
#include"Game.h"
#include"Menu.h"

using namespace std;

enum class GameState { Menu, Playing, Scores, Exiting }; //może przyjmować tylko jedną z czterech nazwanych wartości

int main()
{

    // Tworzymy główne okno
    sf::RenderWindow window(sf::VideoMode(640, 480), "Arkanoid");
    window.setFramerateLimit(120);

    // Tworzymy instancje potrzebnych klas
    Game game; // Załaduje bloki, paletkę itp.
    Menu menu(window.getSize().x, window.getSize().y);

    GameState currentState = GameState::Menu;

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }



        sf::Time dt = clock.restart();

        game.update(dt);

        window.clear(sf::Color(20, 20, 30));
        game.render(window);
        window.display();
    }

    return 0;
}