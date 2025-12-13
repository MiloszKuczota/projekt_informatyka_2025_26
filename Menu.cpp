#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height)
{
    selectedIndex = 0;

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Nie znaleziono czcionki arial.ttf!" << std::endl;
    }

    // DODAJEMY POZYCJE MENU
    items.resize(3);

    items[0].setFont(font);
    items[0].setFillColor(sf::Color::Red);      // wybrane
    items[0].setString("Nowa gra");
    items[0].setCharacterSize(40);
    items[0].setPosition({ width / 2.f - 100.f, height / 2.f - 50.f });

    items[1].setFont(font);
    items[1].setFillColor(sf::Color::White);    // nie wybrane
    items[1].setString("Wczytaj gre");
    items[1].setCharacterSize(40);
    items[1].setPosition({ width / 2.f - 100.f, height / 2.f + 10.f });

    items[2].setFont(font);
    items[2].setFillColor(sf::Color::White);    // nie wybrane
    items[2].setString("Wyjscie");
    items[2].setCharacterSize(40);
    items[2].setPosition({ width / 2.f - 100.f, height / 2.f + 70.f });
}

void Menu::draw(sf::RenderWindow& window)
{
    for (auto& item : items)
        window.draw(item);
}

void Menu::moveUp()
{
    if (selectedIndex - 1 >= 0)
    {
        items[selectedIndex].setFillColor(sf::Color::White);
        selectedIndex--;
        items[selectedIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown()
{
    if (selectedIndex + 1 < items.size())
    {
        items[selectedIndex].setFillColor(sf::Color::White);
        selectedIndex++;
        items[selectedIndex].setFillColor(sf::Color::Red);
    }
}