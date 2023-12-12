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
// Конструктор
game::GameMenu::GameMenu(sf::RenderWindow& window, float menux, float menuy,
                         int index, sf::String name[], int sizeFont, int step)
        :mywindow(window), menu_X(menux), menu_Y(menuy), size_font(sizeFont), menu_Step(step)
{
    // Загрузка шрифта
    if (!font.loadFromFile("font/troika.otf")) exit(32);
    max_menu = index; // Количество єлементов меню
    mainMenu = new sf::Text[max_menu];     // Динамический массив пунктов меню
    // Выстраиваем элементы меню
    for (int i = 0, ypos = menu_Y; i < max_menu; i++, ypos += menu_Step) setInitText(mainMenu[i], name[i], menu_X, ypos);
    //mainMenuSelected = 0; // Задаём начальное положения выбраного пункта меню
    // цвет выбраного пункта меню
    //mainMenu[mainMenuSelected].setFillColor(chose_text_color);
}
// перемещение выбора меню вверх
void game::GameMenu::MoveUp()
{
    mainMenuSelected--;
    // подсвечиваем выбранный пункт меню
    if (mainMenuSelected >= 0) {
        //mainMenu[mainMenuSelected].setFillColor(chose_text_color);
        mainMenu[mainMenuSelected + 1].setFillColor(menu_text_color);
    }
    else
    {
        mainMenu[0].setFillColor(menu_text_color);
        mainMenuSelected = max_menu - 1;
        //mainMenu[mainMenuSelected].setFillColor(chose_text_color);
    }
}
// перемещение выбора меню вниз
void game::GameMenu::MoveDown()
{
    mainMenuSelected++;
// подсвечиваем выбранный пункт меню
    if (mainMenuSelected < max_menu) {
        mainMenu[mainMenuSelected - 1].setFillColor(menu_text_color);
        //mainMenu[mainMenuSelected].setFillColor(chose_text_color);
    }
    else
    {
        mainMenu[max_menu - 1].setFillColor(menu_text_color);
        mainMenuSelected = 0;
        //mainMenu[mainMenuSelected].setFillColor(chose_text_color);
    }

}
// рисуем элементы меню в графическом окне
void game::GameMenu::draw()
{
    // перебираем для отрисовки существующие текстовые объекты пунктов меню
    for (int i = 0; i < max_menu; i++) mywindow.draw(mainMenu[i]);
}


// назначение цвета элементам пунктов меню
void game::GameMenu::setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor)
{
    menu_text_color = menColor;   // цвет пунктов меню
    //chose_text_color = ChoColor; // цвет выбраного пункта меню
    border_color = BordColor;    // цвет контура пунктов меню

    for (int i = 0; i < max_menu; i++) {
        mainMenu[i].setFillColor(menu_text_color);
        mainMenu[i].setOutlineColor(border_color);
    }

    //mainMenu[mainMenuSelected].setFillColor(chose_text_color);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



namespace sdx {
    TextBox::Text::Text(sf::String string, float x, float y) {
        font.loadFromFile("font/troika.otf");
        text.setFont(font);
        text.setString(string);
        text.setFillColor(sf::Color::Black);
        text.setCharacterSize(18);
        text.setPosition(sf::Vector2f(x,y));
        text.setLineSpacing(0);
        text.setOutlineThickness(0);
    }

    sf::Text TextBox::Text::get() { return text; }

    void TextBox::Text::setText(sf::String string) { text.setString(string); }

    void TextBox::Text::setPosition(float x, float y) { text.setPosition(sf::Vector2f(x,y)); }

    void TextBox::Text::setSize(unsigned int x) { text.setCharacterSize(x); }

    //Main TextBox methods start here
    TextBox::TextBox() : inpText("", 6, 5) {
        outerRect.setSize(sf::Vector2f(460,32));
        innerRect.setSize(sf::Vector2f(456,28));
        outerRect.setPosition(sf::Vector2f(0,0));
        innerRect.setPosition(sf::Vector2f(2,2));
        outerRect.setFillColor(sf::Color::Black);
        innerRect.setFillColor(sf::Color::White);

        blinker.setSize(sf::Vector2f(1,26));
        blinker.setPosition(sf::Vector2f(4,3));
        blinker.setFillColor(sf::Color::Black);

        time=sf::Time::Zero;
        textSize=18;
        getPinp="";
        txtInp="";
        thickness=2;
        posX=0;
        posY=0;
        height=32;
        width=460;
        focusChar=0;
        focus=false;
        charWidth=0;
    }
    TextBox::TextBox(float x1, float x2, float y1, float y2, float z) : inpText("", y1+z+2, y2+z-1) {
        outerRect.setSize(sf::Vector2f(x1,x2));
        innerRect.setSize(sf::Vector2f(x1-2*z,x2-2*z));
        outerRect.setPosition(sf::Vector2f(y1,y2));
        innerRect.setPosition(sf::Vector2f(y1+z,y2+z));
        outerRect.setFillColor(sf::Color::Black);
        innerRect.setFillColor(sf::Color::White);

        blinker.setSize(sf::Vector2f(1,x2-2*z-2));
        blinker.setPosition(sf::Vector2f(y1+z+2,y2+z+1));
        blinker.setFillColor(sf::Color::Black);

        time=sf::Time::Zero;
        textSize=(unsigned int)(x2-4-2*z);
        getPinp="";
        txtInp="";
        thickness=z;
        posX=y1;
        posY=y2;
        height=x2;
        width=x1;
        focusChar=0;
        focus=false;
        charWidth=0;

        inpText.setSize(textSize);
    }

    void TextBox::setSize(float x, float y) {
        height=y;
        width=x;
        textSize=(unsigned int)(y-4-2*thickness);
        outerRect.setSize(sf::Vector2f(x,y));
        innerRect.setSize(sf::Vector2f(x-2*thickness,y-2*thickness));
        blinker.setSize(sf::Vector2f(1,y-2*thickness-2));
        inpText.setSize(textSize);
        inpText.setPosition(posX+thickness+2,posY+thickness-1);
    }

    void TextBox::setPosition(float x, float y) {
        posX=x;
        posY=y;
        outerRect.setPosition(sf::Vector2f(x,y));
        innerRect.setPosition(sf::Vector2f(x+thickness,y+thickness));
        blinker.setPosition(sf::Vector2f(x+thickness+2,y+thickness+1));
        inpText.setPosition(x+thickness+2,y+thickness-1);
    }

    void TextBox::setBorder(float x) {
        thickness=x;
        textSize=(unsigned int)(height-4-2*x);
        innerRect.setSize(sf::Vector2f(width-2*x,height-2*x));
        inpText.setSize(textSize);
        setPosition(posX,posY);
    }

    sf::String TextBox::getCurrentText() { return getPinp; }

    sf::String TextBox::getInput() { return txtInp; }



    void TextBox::handleEvent(sf::Event & event)  {
        if(event.type==sf::Event::TextEntered && focus) {
            if((inpText.get().findCharacterPos(focusChar).x+1.2*textSize)<(width+posX) &&31<int(event.text.unicode) && 256>int(event.text.unicode)) {
                if(focusChar==getPinp.getSize()) getPinp+=event.text.unicode;
                else {
                    getPinp=getPinp.substring(0,focusChar)+event.text.unicode+getPinp.substring(focusChar,getPinp.getSize()-focusChar);
                }
                focusChar++;
            }
        }
        if(event.type==sf::Event::KeyPressed && focus) {
            if(event.key.code==sf::Keyboard::BackSpace) {
                if(focusChar!=0){
                    getPinp.erase(focusChar-1,1);
                    if(focusChar>0) focusChar--;
                }
            }
            if(event.key.code==sf::Keyboard::Delete) {
                if(focusChar!=getPinp.getSize()) {
                    getPinp.erase(focusChar);
                }
            }
            if(event.key.code==sf::Keyboard::Enter) {
                if(getPinp.getSize()>0) txtInp=getPinp;
                focusChar=0;
                getPinp.clear();
            }
            else if(event.key.code==sf::Keyboard::Left) {
                if(focusChar>0) {focusChar--;}
            }
            else if(event.key.code==sf::Keyboard::Right) {
                if(focusChar<getPinp.getSize()) focusChar++;
            }
        }
        if(event.type==sf::Event::MouseButtonPressed) {
            if(event.mouseButton.button==sf::Mouse::Left) {
                if(getPinp.getSize()>0) {
                    if(charWidth==0) charWidth=inpText.get().findCharacterPos(1).x-inpText.get().findCharacterPos(0).x;
                    unsigned int temp = (unsigned int)((event.mouseButton.x-posX)/charWidth);
                    if(temp>getPinp.getSize()) focusChar=getPinp.getSize();
                    else focusChar=temp;
                }
                if(event.mouseButton.x >posX && event.mouseButton.x <posX+width && event.mouseButton.y>posY && event.mouseButton.y<posY+height) focus = true;
                else focus = false;
            }
        }
    }

    
