#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu
{
private:
    int selectedIndex;
    sf::Font font;
    std::vector<sf::Text> items;

public:
    Menu(float width, float height);

    void draw(sf::RenderWindow& window);

    void moveUp();
    void moveDown();

    int getSelectedItem() const { return selectedIndex; }
};