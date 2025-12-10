#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Paletka.h"
#include "Pilka.h"
#include "Stone.h"

struct BlockData {
    float x, y;
    int hp;
};

class GameState
{
private:
    sf::Vector2f paddlePosition;
    sf::Vector2f ballPosition;
    sf::Vector2f ballVelocity;
    std::vector<BlockData> blocks;

public:
    void capture(
        const Paletka& pad,
        const Pilka& ball,
        const std::vector<Stone>& stones
    );
};
