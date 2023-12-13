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

    sf::Text countUser1;
    countUser1.setFont(font);
    countUser1.setString(L"1");
    countUser1.setCharacterSize(45);
    countUser1.setFillColor(sf::Color::Black);
    countUser1.setPosition(700, 87);

    sf::Text countUser2;
    countUser2.setFont(font);
    countUser2.setString(L"2");
    countUser2.setCharacterSize(45);
    countUser2.setFillColor(sf::Color::Black);
    countUser2.setPosition(800, 87);



    //***********************************

    sf::Text CountORounds;
    CountORounds.setFont(font);
    CountORounds.setString(L"Введите количество раундов:");
    CountORounds.setCharacterSize(37);
    CountORounds.setFillColor(sf::Color(237, 147, 0));
    CountORounds.setOutlineThickness(3);
    CountORounds.setOutlineColor(sf::Color::Black);
    CountORounds.setPosition(100, 200);

    sdx::TextBox::Text rounds("",534,320);
    rounds.setSize(34);
    sdx::TextBox enterCountRounds;
    enterCountRounds.setPosition(700, 200);
    enterCountRounds.setSize(100,40);
    enterCountRounds.setBorder(1);


    sf::Text orChoose;
    orChoose.setFont(font);
    orChoose.setString(L"или");
    orChoose.setCharacterSize(37);
    orChoose.setFillColor(sf::Color::Black);
    orChoose.setPosition(850, 200);

    sf::Text fastPlay;
    fastPlay.setFont(font);
    fastPlay.setString(L"быстрая игра");
    fastPlay.setCharacterSize(37);
    fastPlay.setFillColor(sf::Color::Black);
    fastPlay.setPosition(980, 200);

    //////************************************

    sf::Text typeOfPlay;
    typeOfPlay.setFont(font);
    typeOfPlay.setString(L"Выберите вариант игры:");
    typeOfPlay.setCharacterSize(37);
    typeOfPlay.setFillColor(sf::Color(237, 147, 0));
    typeOfPlay.setOutlineThickness(3);
    typeOfPlay.setOutlineColor(sf::Color::Black);
    typeOfPlay.setPosition(100, 315);

    typyOfCheckers = 1;
//    Texture types;
//
//    types.loadFromFile("images/type.png");
//    Sprite t(types);
//    t.setPosition(600, 300);

    sf::Text type1;
    type1.setFont(font);
    type1.setString(L"русские");
    type1.setCharacterSize(36);
    type1.setFillColor(sf::Color::Black);
    type1.setPosition(700, 315);

    sf::Text type2;
    type2.setFont(font);
    type2.setString(L"поддавки");
    type2.setCharacterSize(36);
    type2.setFillColor(sf::Color::Black);
    type2.setPosition(900, 315);

    sf::Text type3;
    type3.setFont(font);
    type3.setString(L"английские");
    type3.setCharacterSize(36);
    type3.setFillColor(sf::Color::Black);
    type3.setPosition(1150, 315);

    sf::Text type4;
    type4.setFont(font);
    type4.setString(L"международные");
    type4.setCharacterSize(36);
    type4.setFillColor(sf::Color::Black);
    type4.setPosition(1420, 315);


    /////**********************color

