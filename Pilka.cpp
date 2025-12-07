#include "Pilka.h"

Pilka::Pilka(float x_in, float y_in, float vx_in, float vy_in, float radius_in)
{
    if (x_in <= 1) x_in = 0;
    if (x_in > 640) x_in = 640;
    if (y_in <= 0) y_in = 0;
    if (y_in > 480) y_in = 480;

    x = x_in;
    y = y_in;
    vx = vx_in;
    vy = vy_in;
    radius = radius_in;

    ksztalt_kauczuka.setRadius(radius);
    ksztalt_kauczuka.setOrigin(radius, radius);
    ksztalt_kauczuka.setPosition(x, y);
    ksztalt_kauczuka.setFillColor(sf::Color::Red);
}