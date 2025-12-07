#pragma once
#include <SFML/Graphics.hpp>
#include <array> // U¿yjemy std::array zamiast std::vector

class Stone : public sf::RectangleShape
{
private:
	int m_Hp; //(Bie¿¹ca wytrzyma³oœæ bloku);
	bool m_jestZniszczony; //(Flaga okreœlaj¹ca, czy blok zosta³ zniszczony);
	static const std::array<sf::Color, 4> m_colorLUT;
public:
	Stone(sf::Vector2f startPos, sf::Vector2f rozmiar, int L);//Schemat konstruktora, w jaki sposób ma powstaæ
	//L = hp
	void trafienie() {
		if (m_jestZniszczony == true) {
			return;
			//zakonczenie dzialania
		}
		m_Hp -= 1;
		aktualizujKolor();
		if (m_Hp == 0) {
			m_jestZniszczony = true;
		}
	};

	bool isDestroyed() const {//getter
		return m_jestZniszczony;
	};
	void Narysuj(sf::RenderTarget& target) const {
		if (m_jestZniszczony == false) {
			target.draw(*this);
		}
	};
	void aktualizujKolor() {
		int idx = m_Hp;

		if (idx < 0) {
			idx = 0;
		}
		if (idx > 3) {
			idx = 3;
		}

		this->setFillColor(m_colorLUT[idx]);
	};

};