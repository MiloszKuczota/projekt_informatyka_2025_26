#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


using namespace std;

class Paletka {
private:
    float x, y, szerokosc, wysokosc, predkosc;
    sf::RectangleShape ksztalt_paletki;
public:
    Paletka(float x, float y, float szerokosc, float wysokosc, float predkosc);
    void RuchWLewo() {
        x -= predkosc;
        ksztalt_paletki.setPosition(x, y);
    }
    void RuchWPrawo() {
        x += predkosc;
        ksztalt_paletki.setPosition(x, y);
    }
    void PozostanWOknie(float width) {
        if (x - szerokosc / 2 < 0) {
            x = szerokosc / 2;
            ksztalt_paletki.setPosition(x, y);
        }
        if (x + szerokosc / 2 > width) {
            x = width - szerokosc / 2;
            ksztalt_paletki.setPosition(x, y);
        }
    }
    void Narysuj(sf::RenderTarget& target) {
        target.draw(ksztalt_paletki);
    }

    float getX() const { return x; };
    float getY() const { return y; };
    float getSzerokosc() const { return szerokosc; };
    float getWysokosc() const { return wysokosc; };
};
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
