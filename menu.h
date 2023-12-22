//
// Created by user on 22.11.2023.
//

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace game {

    class GameMenu
    {
        float menu_X;                   // Координаты меню по X
        float menu_Y;				    // Координаты меню по Y
        int menu_Step;                  // Расстояние между пунктами меню
        int max_menu;                   // Максимальное количество пунктов меню
        int size_font;                  // Размер шрифта
        int mainMenuSelected;           // Номер текущего пункта меню
        sf::Font font;                  // Шрифт меню
        // Динамический массив текстовых объектов названий пунктов меню
        sf::Text* mainMenu;
        sf::Color menu_text_color = sf::Color::White;    // Цвет пунктов меню
        sf::Color chose_text_color = sf::Color::Yellow;  // Цвет выбора пункта меню
        sf::Color border_color = sf::Color::Black;       // Цвет обводки текста пунктов меню

        // Настройка текста пунктов меню
        // Параметры: ссылка на текстовый объект, текст, координаты текста
        void setInitText(sf::Text& text, sf::String str, float xpos, float ypos);
        // Ссылка на графическое окно
        sf::RenderWindow& mywindow;
    public:
        // Конструктор
        // Параметры: ссылка на графическое окно, координаты игрового меню по x и y
        // количество пунктов меню, массив названий пунктов меню, размер шрифта, шаг между пунктами меню
        GameMenu(sf::RenderWindow& window, float menux, float menuy,
                 int index, sf::String name[], int sizeFont = 60, int step = 80);

        ~GameMenu()
        {
            delete[] mainMenu;
        }

        void draw();        // Рисуем меню

        void MoveUp();     // Перемещение выбора меню вверх

        void MoveDown();   // Перемещение выбора меню вниз

        // Цвет элементов игрового меню
        void setColorTextMenu(sf::Color menColor, sf::Color ChoColor,
                              sf::Color BordColor);

        void AlignMenu(int posx);   // Выравнивание положения меню

        int getSelectedMenuNumber() // Возвращает номер выбранного элемента меню
        {
            return mainMenuSelected;
        }
    };
}








namespace sdx {
    class TextBox {
    private:
        sf::RectangleShape outerRect;
        sf::RectangleShape innerRect;
        sf::RectangleShape blinker;
        sf::String getPinp;
        sf::String txtInp;
        sf::Clock clock;
        sf::Time time;
        //sf::Cursor cursor;
        unsigned int textSize;
        unsigned int focusChar;
        float charWidth;
        float thickness;
        float posX;
        float posY;
        float height;
        float width;
        bool focus;
    public:
        class Text {
        private:
            sf::Font font;
            sf::Text text;
        public:
            Text(sf::String, float, float); //constructior, first parameter is text string, second is x position, third y position.
            sf::Text get(); //returns the drawable sf::Text class
            void setText(sf::String); //update the text
            void setPosition(float, float); //update text position
            void setSize(unsigned int); //update text size
        };
        TextBox();  //constructor
        TextBox(float, float, float, float, float); //first two parameter for size, second two for position and the last one for thickness.
        void draw(sf::RenderWindow &);  //it'll go to the main event loop, after event handler, it draws in the window.
        void handleEvent(sf::Event &); //handles text input and press enter evernt. place it inside pollEvent loop inside the main event loop.
        sf::String getCurrentText();  //get what is written in the text box right now
        sf::String getInput();  //updates last text after pressing enter.
    public:
        void setSize(float,float);  //update box size first parameter for x, second for y.
        void setPosition(float, float); //update (x,y) position of top-left corner
        void setBorder(float);  //update border thickness.
    private:
        Text inpText;
    };
}




