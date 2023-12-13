#include <iostream>
#include "menu.h"
#include "Checker.h"

using namespace sf;


// функция настройки текста
void InitText(Text& mtext, float xpos, float ypos, String str, int size_font = 60,
              Color menu_text_color = Color::White, int bord = 0, Color border_color = Color::Black);

// Функция перехода к игре  bool GamеStart(int CountUsers, std::string numberOfRound, int typyOfCheckers, int color)
bool GamеStart(int &CountUsers, std::string &numberOfRound, int &typyOfCheckers, int &color)
{
    setlocale(LC_ALL, "Russian");
    RenderWindow Play(sf::VideoMode::getDesktopMode(), L"Начало игры");
    //sf::VideoMode(800, 600);
    //VideoMode::getDesktopMode()

    RectangleShape background_play(Vector2f(1920, 1080));

    Font font;
    if (!font.loadFromFile("font/troika.otf")) return false;

    Texture texture_play;
    if (!texture_play.loadFromFile("images/1111.jpg")) exit(1);
    background_play.setTexture(&texture_play);

    /*sdx::TextBox::Text text1("",534,320);
    text1.setSize(20);
    sdx::TextBox textBox(260,32,230,160,2);
    sdx::TextBox textBox2;
    textBox2.setPosition(250,300);
    textBox2.setSize(460,24);
    textBox2.setBorder(1);*/


//////////////////*********************************      Color(237, 147, 0)

    sf::Text CountOfUsers;
    CountOfUsers.setFont(font);
    CountOfUsers.setString(L"Выберите количество игроков:");
    CountOfUsers.setCharacterSize(37);
    CountOfUsers.setFillColor(sf::Color(237, 147, 0));
    CountOfUsers.setOutlineThickness(3);
    CountOfUsers.setOutlineColor(sf::Color::Black);
    CountOfUsers.setPosition(100, 90);

    //choose
    CountUsers = 1;
    Texture user1, user2;

//    user1.loadFromFile("images/1.png");
//    user2.loadFromFile("images/2.png");
//    Sprite us1(user1), us2(user2);
//    us1.setPosition(600, 55);
//    us2.setPosition(680, 50);
//    us2.setColor(Color::Blue);

