#include "Zapis.h"
#include <iostream>
#include <string>

void Zapis::capture(const Paletka& pad,const Pilka& ball, const std::vector<Stone>& stones){
    // Zapisujemy pozycjê paletki
    paddlePosition = pad.getPosition();

    // Zapisujemy pozycjê i prêdkoœæ pi³ki
    ballPosition = ball.getPosition();
    ballVelocity = ball.getVelocity();   // jeœli jeszcze nie masz getVelocity(), trzeba dodaæ

    // Zapisujemy bloki
    blocks.clear();
    blocks.reserve(stones.size());

    for (const auto& block : stones)
    {
        BlockData data;
        data.x = block.getPosition().x;
        data.y = block.getPosition().y;
        data.hp = block.getHP();             // MUSISZ dodaæ w Stone: int getHP() const;
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

    std::string label;

    // 1. Wczytanie paletki
    if (!(file >> label >> paddlePosition.x >> paddlePosition.y)) return false;

    // 2. Pi³ki
    if (!(file >> label >> ballPosition.x >> ballPosition.y >> ballVelocity.x >> ballVelocity.y)) return false;

    // 3. Wczytanie liczby bloków
    int blocksCount;
    if (!(file >> label >> blocksCount)) return false;

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
    // Ustaw paletkê
    pad.setPosition(paddlePosition);

    // Ustaw pi³kê
    ball.reset(ballPosition, ballVelocity);

    // Odtwórz bloki
    stones.clear();
    sf::Vector2f size(105.f, 25.f); //wyliczone z game.cpp, uzyto po prostu sta³ych
    for (const auto& data : blocks) {
        stones.emplace_back(sf::Vector2f(data.x, data.y), size, data.hp);
    }
}