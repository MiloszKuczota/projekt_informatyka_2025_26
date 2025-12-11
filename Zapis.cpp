#include "Zapis.h"
#include <iostream>

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