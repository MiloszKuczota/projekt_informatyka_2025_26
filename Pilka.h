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
        if (y - radius <= 0) { //zmienione na brak kolizji z podloga  (y + radius >= wysokosc)
            odbijY();
        }
        if (y + radius >= wysokosc) {
            return;
        }
    }
    bool collidePaddle(const Paletka& Pal) {
        if (x > Pal.getX() - Pal.getSzerokosc() &&(x < Pal.getX() + Pal.getSzerokosc()) &&
           (y + radius >= Pal.getY() - Pal.getWysokosc() / 2) &&(y - radius < Pal.getY() - Pal.getWysokosc() / 2)) {

            odbijY();
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
    }// stara funkcja ktora nie jest uzywana
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
    sf::Vector2f getPosition() const {//te 2 dodane na nowo xddddddddd
        return sf::Vector2f(x, y);
    }

    sf::Vector2f getVelocity() const {
        return sf::Vector2f(vx, vy);
    }
    void reset(const sf::Vector2f& pos, const sf::Vector2f& vel)
    {
        // ustawiamy pozycjê pi³ki
        x = pos.x;
        y = pos.y;
        ksztalt_kauczuka.setPosition(pos);

        // ustawiamy prêdkoœæ
        vx = vel.x;
        vy = vel.y;
    }

private:
    float x, y, vx, vy, radius;
    sf::CircleShape ksztalt_kauczuka;
};
