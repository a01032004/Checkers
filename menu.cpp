//
// Created by user on 24.11.2023.
//

#include "menu.h"
using namespace sf;
using namespace std;

// метод настройки текстовых объектов пунктов игрового меню
void game::GameMenu::setInitText(sf::Text& text, sf::String str, float xpos, float ypos)
{
    text.setFont(font);                 // шрифт
    text.setFillColor(menu_text_color); // цвет
    text.setString(str);                // текст
    text.setCharacterSize(size_font);   // размер шрифта
    text.setPosition(xpos, ypos);       // координаты текстового объекта
    text.setOutlineThickness(3);        // толщина контура обводки текста
    text.setOutlineColor(border_color); // цвет контура обводки текста
}
// Выравнивание пунктов меню по левому по правому по центру
void game::GameMenu::AlignMenu(int posx)
{
    float nullx = 0;
    for (int i = 0; i < max_menu; i++) {
        switch (posx)
        {
            case 0:
                nullx = 0; // выравнивание по правому краю от установленных координат
                break;
            case 1:
                nullx = mainMenu[i].getLocalBounds().width;  // по левому краю
                break;
            case 2:
                nullx = nullx = mainMenu[i].getLocalBounds().width / 2;  // по центру
                break;
        }
        mainMenu[i].setPosition(mainMenu[i].getPosition().x - nullx, mainMenu[i].getPosition().y);
    }

}