#include "Paletka.h"

Paletka::Paletka(float x_in, float y_in, float szerokosc_in, float wysokosc_in, float predkosc_in) {
    x = x_in;
    y = y_in;
    szerokosc = szerokosc_in;
    wysokosc = wysokosc_in;
    predkosc = predkosc_in;

    ksztalt_paletki.setSize({ szerokosc, wysokosc });
    ksztalt_paletki.setOrigin(szerokosc / 2, wysokosc / 2);
    ksztalt_paletki.setPosition(x, y);
    ksztalt_paletki.setFillColor(sf::Color::Blue);
}
