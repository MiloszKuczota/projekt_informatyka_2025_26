#pragma once
#include <SFML/Graphics.hpp>
#include <array>

class Stone : public sf::RectangleShape
{
private:
	int m_Hp; // wytrzyma³oœæ bloku
	bool m_jestZniszczony; // zycie bloku, czy jest lub nie
	static const std::array<sf::Color, 4> m_colorLUT;
public:
	Stone(sf::Vector2f startPos, sf::Vector2f rozmiar, int L);//Schemat konstruktora, w jaki sposób ma powstaæ
	//L = hp
	void trafienie() {
		if (m_jestZniszczony == true) {
			return;
			//zakonczenie dzialania, zniszczony blok
		}
		m_Hp -= 1;//zmniejsza zycie bloku
		aktualizujKolor();//i aktualizuje kolor
		if (m_Hp == 0) {
			m_jestZniszczony = true;
		}//klocek prezstaje istniec
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
	sf::Vector2f getPosition() const {
		return sf::RectangleShape::getPosition();
	}

	sf::Vector2f getSize() const {
		return sf::RectangleShape::getSize();
	}
	int getHP() const { return m_Hp; }

};