#include <iostream>
#include "menu.h"
#include "Checker.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace sf;


// функция настройки текста
void InitText(Text& mtext, float xpos, float ypos, String str, int size_font = 60,
    Color menu_text_color = Color::White, int bord = 0, Color border_color = Color::Black);

bool GoOut1();
int finalWin(int, std::string, int, int, std::string);
bool Draw();
int Pause();

// Функция перехода к игре  bool GamеStart(int CountUsers, std::string numberOfRound, int typyOfCheckers, int color)
bool GamеStart(int& CountUsers, std::string& numberOfRound, int& typyOfCheckers, int& color)
{
    setlocale(LC_ALL, "Russian");
    RenderWindow Play(sf::VideoMode::getDesktopMode(), L"Начало игры");


    RectangleShape background_play(Vector2f(1920, 1080));

    Font font;
    if (!font.loadFromFile("font/troika.otf")) return false;

    Texture texture_play;
    if (!texture_play.loadFromFile("images/1111.jpg")) exit(1);
    background_play.setTexture(&texture_play);


    //////////////////*********************************      Color(237, 147, 0)

    sf::Text CountOfUsers;
    CountOfUsers.setFont(font);
    CountOfUsers.setString(L"Choose amount of players"/*"Выберите количество игроков:"*/);
    CountOfUsers.setCharacterSize(37);
    CountOfUsers.setFillColor(sf::Color(237, 147, 0));
    CountOfUsers.setOutlineThickness(3);
    CountOfUsers.setOutlineColor(sf::Color::Black);
    CountOfUsers.setPosition(100, 90);

    //choose
    CountUsers = 1;
    Texture user1, user2;


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
    CountORounds.setString(L"Choose amount of rounds"/*"Введите количество раундов:"*/);
    CountORounds.setCharacterSize(37);
    CountORounds.setFillColor(sf::Color(237, 147, 0));
    CountORounds.setOutlineThickness(3);
    CountORounds.setOutlineColor(sf::Color::Black);
    CountORounds.setPosition(100, 200);

    sdx::TextBox::Text rounds("", 534, 320);
    rounds.setSize(34);
    sdx::TextBox enterCountRounds;
    enterCountRounds.setPosition(700, 200);
    enterCountRounds.setSize(100, 40);
    enterCountRounds.setBorder(1);


    sf::Text orChoose;
    orChoose.setFont(font);
    orChoose.setString(L"or"/*"или"*/);
    orChoose.setCharacterSize(37);
    orChoose.setFillColor(sf::Color::Black);
    orChoose.setPosition(850, 200);

    sf::Text fastPlay;
    fastPlay.setFont(font);
    fastPlay.setString(L"fast Game"/*"быстрая игра"*/);
    fastPlay.setCharacterSize(37);
    fastPlay.setFillColor(sf::Color::Black);
    fastPlay.setPosition(980, 200);

    //////************************************

    sf::Text typeOfPlay;
    typeOfPlay.setFont(font);
    typeOfPlay.setString(L"Choose var of game"/*"Выберите вариант игры:"*/);
    typeOfPlay.setCharacterSize(37);
    typeOfPlay.setFillColor(sf::Color(237, 147, 0));
    typeOfPlay.setOutlineThickness(3);
    typeOfPlay.setOutlineColor(sf::Color::Black);
    typeOfPlay.setPosition(100, 315);

    typyOfCheckers = 1;

    sf::Text type1;
    type1.setFont(font);
    type1.setString(L"Russian"/*"русские"*/);
    type1.setCharacterSize(36);
    type1.setFillColor(sf::Color::Black);
    type1.setPosition(700, 315);

    sf::Text type2;
    type2.setFont(font);
    type2.setString(L"surrender"/*"поддавки"*/);
    type2.setCharacterSize(36);
    type2.setFillColor(sf::Color::Black);
    type2.setPosition(900, 315);

    sf::Text type3;
    type3.setFont(font);
    type3.setString(L"English"/*"английские"*/);
    type3.setCharacterSize(36);
    type3.setFillColor(sf::Color::Black);
    type3.setPosition(1150, 315);

    sf::Text type4;
    type4.setFont(font);
    type4.setString(L"International"/*"международные"*/);
    type4.setCharacterSize(36);
    type4.setFillColor(sf::Color::Black);
    type4.setPosition(1420, 315);


    /////**********************color

    sf::Text typeColor;
    typeColor.setFont(font);
    typeColor.setString(L"Choose color of checkers"/*"Выберите цвет шашек:"*/);
    typeColor.setCharacterSize(37);
    typeColor.setFillColor(sf::Color(237, 147, 0));
    typeColor.setOutlineThickness(3);
    typeColor.setOutlineColor(sf::Color::Black);
    typeColor.setPosition(100, 430);

    color = 0; //1-white    2-black

    sf::Text whiteColor;
    whiteColor.setFont(font);
    whiteColor.setString(L"White"/*"Белый"*/);
    whiteColor.setCharacterSize(36);
    whiteColor.setFillColor(sf::Color::Black);
    whiteColor.setPosition(700, 430);

    sf::Text blackolor;
    blackolor.setFont(font);
    blackolor.setString(L"Black"/*"Чёрный"*/);
    blackolor.setCharacterSize(36);
    blackolor.setFillColor(sf::Color::Black);
    blackolor.setPosition(900, 430);


    //////************************startplay

    bool isButtonPressed = false;
    sf::Text startPlay;
    startPlay.setFont(font);
    startPlay.setString(L"Начать игру");
    startPlay.setCharacterSize(48);
    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;
    startPlay.setFillColor(sf::Color(237, 147, 0));
    startPlay.setOutlineThickness(4);
    startPlay.setOutlineColor(sf::Color::Black);

    startPlay.setPosition(width - 400, height - 260);

    ///////////*****************************************back
    sf::Text goBack;
    goBack.setFont(font);
    goBack.setString(L"Назад");
    goBack.setCharacterSize(48);
    goBack.setFillColor(sf::Color(237, 147, 0));
    goBack.setOutlineThickness(4);
    goBack.setOutlineColor(sf::Color::Black);

    goBack.setPosition(100, height - 260);


