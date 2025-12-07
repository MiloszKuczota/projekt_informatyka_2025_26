#include "Game.h"
#include <iostream>

Game::Game() :
    pal(320.f, 440.f, 100.f, 20.f, 8.f),
    Kauczuk(320.f, 300.f, 2.f, 1.f, 6.f)
{
    const int ILOSC_KOLUMN = 6;
    const int ILOSC_WIERSZY = 7;
    const float ROZMIAR_BLOKU_Y = 25.f;
    const float SZEROKOSC_OKNA = 640.f;
    const float ROZMIAR_BLOKU_X = (SZEROKOSC_OKNA - (ILOSC_KOLUMN - 1) * 2.f) / ILOSC_KOLUMN;

    bloki.reserve(ILOSC_KOLUMN * ILOSC_WIERSZY);

    for (int y = 0; y < ILOSC_WIERSZY; y++)
    {
        for (int x = 0; x < ILOSC_KOLUMN; x++)
        {
            float posX = x * (ROZMIAR_BLOKU_X + 2.f);
            float posY = 50.f + y * (ROZMIAR_BLOKU_Y + 2.f);
            int L = (y < 1) ? 3 : (y < 3) ? 2 : 1;
            bloki.emplace_back(sf::Vector2f(posX, posY),
                sf::Vector2f(ROZMIAR_BLOKU_X, ROZMIAR_BLOKU_Y), L);
        }
    }
}

void Game::update(sf::Time dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        pal.RuchWLewo();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        pal.RuchWPrawo();

    pal.PozostanWOknie(640);

    Kauczuk.ruch();
    Kauczuk.Kolizja(640, 480);

    Kauczuk.collidePaddle(pal);

    for (auto& panele : bloki)
    {
        if (!panele.isDestroyed() &&
            Kauczuk.PolozeniePilki().intersects(panele.getGlobalBounds()))
        {
            panele.trafienie();
            Kauczuk.odbijY();
            break;
        }
    }
}

void Game::render(sf::RenderTarget& target)
{
    for (auto& panele : bloki)
        panele.Narysuj(target);

    Kauczuk.Narysuj(target);
    pal.Narysuj(target);
}