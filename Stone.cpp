#include "Stone.h"

const std::array<sf::Color, 4> Stone::m_colorLUT = {
    sf::Color::White,
    sf::Color::Yellow,
    sf::Color::Blue,
    sf::Color::Red
};

Stone::Stone(sf::Vector2f PozycjaStartowa, sf::Vector2f Rozmiar, int L)//Konstruktor, tworzy obiekt
{
    m_Hp = L;
    m_jestZniszczony = false;
    setPosition(PozycjaStartowa);
    setSize(Rozmiar);
    setOutlineThickness(2.f);
    aktualizujKolor();
}