#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Paletka.h"
#include "Pilka.h"
#include "Stone.h"

class Game
{
private:
    Paletka pal;
    Pilka Kauczuk;
    std::vector<Stone> bloki;

public:
    Game();

    void update(sf::Time dt);
    bool render(sf::RenderTarget& target);
};