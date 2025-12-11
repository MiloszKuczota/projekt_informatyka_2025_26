#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Game.h"
#include "Zapis.h" //gamestate.h - musi być zmiana nazwy

enum class GameState{ Menu, Playing, Scores, Exiting };
bool f5PressedLastFrame = false; //Dodane, żeby dla pojedynczego kliknięcia zapisało raz, a nie kilka
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
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
                    if (!f5PressedLastFrame) {
                        // zapis
                        Zapis snapshot;
                        snapshot.capture(game.getPaddle(), game.getBall(), game.getStones());
                        if (snapshot.saveToFile("zapis.txt"))
                            std::cout << "Gra zapisana" << std::endl;

                        f5PressedLastFrame = true;
                    }
                    f5PressedLastFrame = false;
                }
            }
        }

        sf::Time dt = clock.restart();

        // aktualizacja gry
        if (state == GameState::Playing)
        {
            game.update(dt);

            if (game.isGameOver())
            {
                state = GameState::Menu;     // po przegranej powrót do menu
            }
        }

        // renderowanie się gry
        window.clear(sf::Color(20, 20, 30));

        if (state == GameState::Menu)
            menu.draw(window);
        else if (state == GameState::Playing)
            game.render(window);

        window.display();
    }

    return 0;
}