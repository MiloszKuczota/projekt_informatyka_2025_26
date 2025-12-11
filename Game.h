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
    void render(sf::RenderTarget& target);
    bool gameOver = false;
    bool isGameOver() const { return gameOver; } // <-- DODANE
    const Paletka& getPaddle() const { return pal; }
    const Pilka& getBall() const { return Kauczuk; }
    const std::vector<Stone>& getStones() const { return bloki; }

};