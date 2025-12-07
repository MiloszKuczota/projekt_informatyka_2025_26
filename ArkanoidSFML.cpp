#include <iostream>
#include <SFML/Graphics.hpp>
#include"Pilka.h"
#include"Paletka.h"
#include"Stone.h"

using namespace std;


const std::array<sf::Color, 4> Stone::m_colorLUT = {
   sf::Color::Transparent,
   sf::Color::Red,
   sf::Color::Yellow,
   sf::Color::Blue
};

int main()
{
    std::vector<Stone> bloki; // pusty wektor
    
    const int ILOSC_KOLUMN = 6; //konfiguracja poziomu
    const int ILOSC_WIERSZY = 7;
    const float ROZMIAR_BLOKU_Y = 25.f;
    const float SZEROKOSC_OKNA = 640.f;
    const float ROZMIAR_BLOKU_X = (SZEROKOSC_OKNA - (ILOSC_KOLUMN - 1) * 2.f) / ILOSC_KOLUMN;

    for (int y = 0; y < ILOSC_WIERSZY; y++)
    {
        for (int x = 0; x < ILOSC_KOLUMN; x++)
        {
            float posX = x * (ROZMIAR_BLOKU_X + 2.f);
            float posY = 50.f + y * (ROZMIAR_BLOKU_Y + 2.f);
            int L = (y < 1) ? 3 : (y < 3) ? 2 : 1;
            bloki.emplace_back(sf::Vector2f(posX, posY), sf::Vector2f(ROZMIAR_BLOKU_X, ROZMIAR_BLOKU_Y),L);
        }
    }


    sf::RenderWindow okno(sf::VideoMode(640, 480), "Narkonoid");
    Pilka Kauczuk(320.f, 300.f, 2.f, 1.f, 6.f); // x,y,vx,vy,radius
    Paletka pal(320.f, 440.f, 100.f, 20.f, 8.f);

    while (okno.isOpen())
    {

        sf::Event event;
        okno.setFramerateLimit(130);
        while (okno.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                okno.close();
        }


        //paletka w ruchu ad
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            pal.RuchWLewo();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            pal.RuchWPrawo();
        }
        pal.PozostanWOknie(640);

        Kauczuk.ruch();
        Kauczuk.Kolizja(640, 480);
        
        Kauczuk.collidePaddle(pal);

        okno.clear(sf::Color(20, 20, 30));
        for (auto& panele : bloki) {//pętla potrzebna do stworzenia blokow przy pomocy wczesniejszego wektora
            panele.Narysuj(okno);
            if (!panele.isDestroyed()!=true && Kauczuk.PolozeniePilki().intersects(panele.getGlobalBounds()))
            {
                panele.trafienie();
                Kauczuk.odbijY();
                break;
            }
        }


        Kauczuk.Narysuj(okno);

        pal.Narysuj(okno);
        okno.display();
        Kauczuk.drukuj();

        if (Kauczuk.getY() - Kauczuk.getRadius() > pal.getY()) {
            std::cout << "MISS! KONIEC GRY\n"; okno.close(); // możesz też zrobić break }
        }
    }
    return 0;
}