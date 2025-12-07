#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include"Paletka.h"

using namespace std;

class Pilka {
public:
    Pilka(float x_in, float y_in, float vx_in, float vy_in, float radius);//konstruktor
    //nowe
    void ruch() {
        x += vx;
        y += vy;
        ksztalt_kauczuka.setPosition(x, y);
    }
    void odbijX() {
        vx = -vx;
    }
    void odbijY() {
        vy = -vy;
    }
    void Kolizja(float szerokosc, float wysokosc) {
        if ((x - radius <= 0) || (x + radius >= szerokosc)) {
            odbijX();
        }
        if ((y - radius <= 0) || (y + radius >= wysokosc)) {
            odbijY();
        }
    }
    bool collidePaddle(const Paletka& Pal) {
        if (x > Pal.getX() - Pal.getSzerokosc() &&
            (x < Pal.getX() + Pal.getSzerokosc()) &&
            (y + radius >= Pal.getY() - Pal.getWysokosc() / 2) &&
            (y - radius < Pal.getY() - Pal.getWysokosc() / 2)) {

            vy = -std::abs(vy);
            y = (Pal.getY() - Pal.getWysokosc() / 2) - radius;
            ksztalt_kauczuka.setPosition(x, y);
            return true;

        }
        else {
            return false;
        }
    }
    void Narysuj(sf::RenderTarget& target) {
        target.draw(ksztalt_kauczuka);
    }

    //stare
    void drukuj() {
        cout << "x= " << getX() << " y= " << getY() << " vx= " << getVX() << " vy= " << getVY() << endl;
    }
    sf::FloatRect PolozeniePilki() const {
        return ksztalt_kauczuka.getGlobalBounds();  //zwraca po³o¿enie pi³ki jako kwadrat - przydatne do sprawdzania kolizji
    }
    float getX() const { return x; }
    float getY() const { return y; }
    float getVX() const { return vx; }
    float getVY() const { return vy; }
    float getRadius() const { return radius; }
    void przesun() {
        x = x + vx;
        y = y + vy;
    }
    //funkcje pobierajace dane

private:
    float x, y, vx, vy, radius;
    sf::CircleShape ksztalt_kauczuka;
};
Pilka::Pilka(float x_in, float y_in, float vx_in, float vy_in, float radius_in) {
    if (x_in <= 1) {
        x_in = 0;
    }
    if (x_in > 640) {
        x_in = 640;
    }
    if (y_in <= 0) {
        y_in = 0;
    }
    if (y_in > 480) {
        y_in = 480;
    }
    x = x_in;
    y = y_in;
    vx = vx_in;
    vy = vy_in;
    radius = radius_in;
    ksztalt_kauczuka.setRadius(radius);
    ksztalt_kauczuka.setOrigin(radius, radius); // ¿eby (x,y) by³o œrodkiem
    ksztalt_kauczuka.setPosition(x, y);
    ksztalt_kauczuka.setFillColor(sf::Color::Red);
}
//zrobic kolizje z paletka