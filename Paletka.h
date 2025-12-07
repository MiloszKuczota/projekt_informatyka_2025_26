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