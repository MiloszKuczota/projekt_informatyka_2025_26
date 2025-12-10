#include "GameState.h"

void GameState::capture(
    const Paletka& pad,
    const Pilka& ball,
    const std::vector<Stone>& stones)
{
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