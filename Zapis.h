#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Paletka.h"
#include "Pilka.h"
#include "Stone.h"
#include <fstream>

using namespace std;

struct BlockData {      //przechochowuje pozycjê (X, Y) oraz punkty¿ycia(HP).
    float x, y;
    int hp;
};

class Zapis
{
private:
    sf::Vector2f paddlePosition;    //pozycja paletki.
    sf::Vector2f ballPosition;      //pozycja pi³ki.
    sf::Vector2f ballVelocity;      //wektor prêdkoœci pi³ki (niezbêdny, by po wczytaniu pi³ka lecia³a w tê sam¹ stronê).
    std::vector<BlockData> blocks;  //lista stanów wszystkich klocków.

public:
    void capture(const Paletka& pad, const Pilka& ball, const std::vector<Stone>& stones);
    bool saveToFile(const std::string& filename);
};
