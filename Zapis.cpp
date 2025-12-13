#include "Zapis.h"
#include <iostream>
#include <string>



void Zapis::capture(const Paletka& pad,const Pilka& ball, const std::vector<Stone>& stones){
    // Zapis pozycji paletki
    paddlePosition = pad.getPosition();

    // Zapisuj pozycji i prêdkoœci pi³ki
    ballPosition = ball.getPosition();
    ballVelocity = ball.getVelocity();

    // Zapisuj bloki
    blocks.clear();
    blocks.reserve(stones.size());

    for (const auto& block : stones)
    {
        BlockData data;
        data.x = block.getPosition().x;
        data.y = block.getPosition().y;
        data.hp = block.getHP();     
        blocks.push_back(data);
    }
}
bool Zapis::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open())
        return false;

    // Zapis Paletki
    file << paddlePosition.x << " " << paddlePosition.y << std::endl;
    // Zapis Pi³ki
    file << ballPosition.x << " " << ballPosition.y << " " << ballVelocity.x << " " << ballVelocity.y << std::endl;
    // Zapis liczby bloków
    file << blocks.size() << std::endl;
    // Zapis bloków
    for (const auto& block : blocks) {
        file << block.x << " " << block.y << " " << block.hp << std::endl;
    }
    file.close();
    return true;

}
bool Zapis::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;


    // 1. Wczytanie paletki
    if (!(file  >> paddlePosition.x >> paddlePosition.y)) return false;

    // 2. Pi³ki
    if (!(file >> ballPosition.x >> ballPosition.y >> ballVelocity.x >> ballVelocity.y)) return false;

    // 3. Wczytanie liczby bloków
    int blocksCount;
    if (!(file >> blocksCount)) return false;

    blocks.clear();
    for (int i = 0; i < blocksCount; ++i) {
        float x, y;
        int hp;
        if (!(file >> x >> y >> hp)) return false;
        blocks.push_back({ x, y, hp });
    }

    file.close();
    return true;
}

void Zapis::apply(Paletka& pad, Pilka& ball, std::vector<Stone>& stones) {
    // Ustawienie paletki
    pad.setPosition(paddlePosition);

    // Ustawienie pi³ki
    ball.reset(ballPosition, ballVelocity);

    // Odtworzenie bloki
    stones.clear();
    sf::Vector2f size(105.f, 25.f); //wyliczone z game.cpp, uzyto po prostu sta³ych
    for (const auto& data : blocks) {
        stones.emplace_back(sf::Vector2f(data.x, data.y), size, data.hp);
    }
}