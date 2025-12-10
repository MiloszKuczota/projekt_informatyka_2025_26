#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Game.h"

enum class GameState { Menu, Playing, Scores, Exiting };

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Arkanoid");
    window.setFramerateLimit(120);

    // Obiekty
    Menu menu(window.getSize().x, window.getSize().y);
    Game game;

    GameState state = GameState::Menu;

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (state == GameState::Menu)               //menu
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up)
                        menu.moveUp();  
                    else if (event.key.code == sf::Keyboard::Down)
                        menu.moveDown();
                    else if (event.key.code == sf::Keyboard::Enter)
                    {
                        if (menu.getSelectedItem() == 0)       // NOWA GRA
                        {
                            game = Game();                      // restart gry
                            state = GameState::Playing;
                        }
                        else if (menu.getSelectedItem() == 1)  // WYJŚCIE
                        {
                            window.close();
                        }
                    }
                }
            }

            // --------------------
            // OBSŁUGA GRY
            // --------------------
            else if (state == GameState::Playing)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        state = GameState::Menu;
                    }
                }
            }
        }

        sf::Time dt = clock.restart();

        // --------------------
        // UPDATE
        // --------------------
        if (state == GameState::Playing)
        {
            game.update(dt);

            if (game.isGameOver())
            {
                state = GameState::Menu;     // po przegranej → powrót do menu
            }
        }

        // --------------------
        // RENDER
        // --------------------
        window.clear(sf::Color(20, 20, 30));

        if (state == GameState::Menu)
            menu.draw(window);
        else if (state == GameState::Playing)
            game.render(window);

        window.display();
    }

    return 0;
}