#include "Stone.h"

const std::array<sf::Color, 4> Stone::m_colorLUT = {
    sf::Color::White,
    sf::Color::Green,
    sf::Color::Blue,
    sf::Color::Red
};

Stone::Stone(sf::Vector2f PozycjaStartowa, sf::Vector2f Rozmiar, int L)//Konstruktor, tworzy obiekt
{
    setPosition(PozycjaStartowa);
    setSize(Rozmiar);

    m_Hp = L;
    m_jestZniszczony = (m_Hp <= 0);
    setOutlineThickness(3.f);
    aktualizujKolor();
}