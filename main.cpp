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

    sf::Text typeColor;
    typeColor.setFont(font);
    typeColor.setString(L"Выберите цвет шашек:");
    typeColor.setCharacterSize(37);
    typeColor.setFillColor(sf::Color(237, 147, 0));
    typeColor.setOutlineThickness(3);
    typeColor.setOutlineColor(sf::Color::Black);
    typeColor.setPosition(100, 430);

    color = 0; //1-white    2-black

    sf::Text whiteColor;
    whiteColor.setFont(font);
    whiteColor.setString(L"Белый");
    whiteColor.setCharacterSize(36);
    whiteColor.setFillColor(sf::Color::Black);
    whiteColor.setPosition(700, 430);

    sf::Text blackolor;
    blackolor.setFont(font);
    blackolor.setString(L"Чёрный");
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






    while (Play.isOpen())
    {



        Event event_play;
        while (Play.pollEvent(event_play))
        {
            if ((IntRect(690, 85, 50, 60).contains(Mouse::getPosition(Play))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
                {
                    CountUsers = 1;
                    countUser1.setOutlineThickness(3);
                    countUser1.setOutlineColor(sf::Color(237, 147, 0));
                    countUser2.setOutlineThickness(0);
                }

            if ((IntRect(790, 85, 50, 60).contains(Mouse::getPosition(Play))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    CountUsers = 2;
                    countUser2.setOutlineThickness(3);
                    countUser2.setOutlineColor(sf::Color(237, 147, 0));
                    countUser1.setOutlineThickness(0);
                }

            if ((IntRect(970, 195, 200, 60).contains(Mouse::getPosition(Play))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                numberOfRound = 1;
                fastPlay.setOutlineThickness(3);
                fastPlay.setOutlineColor(sf::Color(237, 147, 0));
            }

            if ((IntRect(690, 195, 100, 60).contains(Mouse::getPosition(Play))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                numberOfRound = 1;
                fastPlay.setOutlineThickness(0);
                fastPlay.setOutlineColor(sf::Color::Black);
                fastPlay.setOutlineThickness(0);
            }


            float Mx = sf::Mouse::getPosition().x;
            float My = sf::Mouse::getPosition().y;

            if ((IntRect(695, 310, 140, 60).contains(Mouse::getPosition(Play))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            {
                typyOfCheckers = 1;
                type1.setOutlineThickness(3);
                type1.setOutlineColor(sf::Color(237, 147, 0));

                type2.setOutlineThickness(0);
                type3.setOutlineThickness(0);
                type4.setOutlineThickness(0);

            }

            if ((IntRect(895, 310, 180, 60).contains(Mouse::getPosition(Play))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                typyOfCheckers = 2;
                type2.setOutlineThickness(3);
                type2.setOutlineColor(sf::Color(237, 147, 0));

                type1.setOutlineThickness(0);
                type3.setOutlineThickness(0);
                type4.setOutlineThickness(0);
            }

            if ((IntRect(1140, 310, 220, 60).contains(Mouse::getPosition(Play))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            {
                typyOfCheckers = 3;
                type3.setOutlineThickness(3);
                type3.setOutlineColor(sf::Color(237, 147, 0));

                type2.setOutlineThickness(0);
                type1.setOutlineThickness(0);
                type4.setOutlineThickness(0);
            }

            if ((IntRect(1410, 310, 310, 60).contains(Mouse::getPosition(Play))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                typyOfCheckers = 4;
                type4.setOutlineThickness(3);
                type4.setOutlineColor(sf::Color(237, 147, 0));

                type2.setOutlineThickness(0);
                type3.setOutlineThickness(0);
                type1.setOutlineThickness(0);
            }


            if ((IntRect(695, 425, 150, 60).contains(Mouse::getPosition(Play))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            {
                color = 1;
                whiteColor.setOutlineThickness(3);
                whiteColor.setOutlineColor(sf::Color(237, 147, 0));

                blackolor.setOutlineThickness(0);
            }
            if ((IntRect(895, 425, 150, 60).contains(Mouse::getPosition(Play))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            {
                color = 2;
                blackolor.setOutlineThickness(3);
                blackolor.setOutlineColor(sf::Color(237, 147, 0));

                whiteColor.setOutlineThickness(0);
            }


            if ((IntRect(width - 405, height - 265, 170, 60).contains(Mouse::getPosition(Play))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            { isButtonPressed = true; }

            if ((IntRect(100, height - 265, 170, 60).contains(Mouse::getPosition(Play))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            { Play.close(); }



            enterCountRounds.handleEvent(event_play);


            if(event_play.type==sf::Event::Closed) {
                Play.close();
            }

            if (event_play.type == Event::KeyPressed)
            {
                //if (event_play.key.code == Keyboard::Escape) { Play.close(); }
            }
        }



        Play.clear();
        Play.draw(background_play);
        Play.draw(countUser1);
        Play.draw(countUser2);
        Play.draw(CountOfUsers);
        Play.draw(CountORounds);
        Play.draw(typeOfPlay);
        Play.draw(orChoose);
        Play.draw(fastPlay);

        Play.draw(type1);
        Play.draw(type2);
        Play.draw(type3);
        Play.draw(type4);
        Play.draw(typeColor);
        Play.draw(whiteColor);
        Play.draw(blackolor);
        Play.draw(startPlay);
        Play.draw(goBack);

        //box
        enterCountRounds.draw(Play);
        Play.draw(rounds.get());



        Play.display();

        if (isButtonPressed == true) {Play.close();}
    }


    numberOfRound = enterCountRounds.getCurrentText();

    if (numberOfRound == "") {numberOfRound = "1";}
    std::cout << CountUsers;
    std::cout << numberOfRound;
    std::cout << typyOfCheckers;
    std::cout << color;
    std::cout << isButtonPressed;

    return (isButtonPressed);

}







// Функция настройки игры
int Options(int &hardlevel)
{
    RenderWindow Options(VideoMode::getDesktopMode(), L"Настройки");

    RectangleShape background_opt(Vector2f(1920, 1080));

    Font font;
    if (!font.loadFromFile("font/troika.otf")) return -1;

    Texture texture_opt;
    if (!texture_opt.loadFromFile("images/1111.jpg")) exit(1);
    background_opt.setTexture(&texture_opt);



    bool isPres = false;

    //////////////***********************Сложность
    sf::Text hardly;
    hardly.setFont(font);
    hardly.setString(L"Выберите уровень сложности:");
    hardly.setCharacterSize(40);
    hardly.setFillColor(sf::Color(237, 147, 0));
    hardly.setOutlineThickness(3);
    hardly.setOutlineColor(sf::Color::Black);
    hardly.setPosition(100, 100);


    sf::Text easy;
    easy.setFont(font);
    easy.setString(L"лёгкий");
    easy.setCharacterSize(36);
    easy.setFillColor(sf::Color::Black);
    easy.setPosition(800, 100);

    sf::Text medium;
    medium.setFont(font);
    medium.setString(L"средний");
    medium.setCharacterSize(36);
    medium.setFillColor(sf::Color::Black);
    medium.setPosition(1000, 100);

    sf::Text hard;
    hard.setFont(font);
    hard.setString(L"тяжёлый");
    hard.setCharacterSize(36);
    hard.setFillColor(sf::Color::Black);
    hard.setPosition(1200, 100);

    if (hardlevel == 1) {
        easy.setOutlineThickness(3);
        easy.setOutlineColor(sf::Color(237, 147, 0));
    }
    if (hardlevel == 2) {
        medium.setOutlineThickness(3);
        medium.setOutlineColor(sf::Color(237, 147, 0));
    }
    if (hardlevel == 3) {
        hard.setOutlineThickness(3);
        hard.setOutlineColor(sf::Color(237, 147, 0));
    }


    /////////////////////////////////////*******************************************************
    //box
    sdx::TextBox::Text f1("",534,320);
    f1.setSize(34);
    sdx::TextBox firstname;
    firstname.setPosition(700, 200);
    firstname.setSize(100,40);
    firstname.setBorder(1);



    ///////////////////////////////////////////////////////////////////////////////////////*******


    ////////////***********************************************  save
    sf::Text save;
    save.setFont(font);
    save.setString(L"Сохранить");
    save.setCharacterSize(48);
    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;
    save.setFillColor(sf::Color(237, 147, 0));
    save.setOutlineThickness(4);
    save.setOutlineColor(sf::Color::Black);

    save.setPosition(width - 400, height - 260);




    while (Options.isOpen())
    {
        Event event_opt;
        while (Options.pollEvent(event_opt))
        {

            if ((IntRect(795, 95, 150, 60).contains(Mouse::getPosition(Options))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            {
                hardlevel = 1;
                easy.setOutlineThickness(3);
                easy.setOutlineColor(sf::Color(237, 147, 0));

                medium.setOutlineThickness(0);
                hard.setOutlineThickness(0);
            }

            if ((IntRect(995, 95, 150, 60).contains(Mouse::getPosition(Options))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            {
                hardlevel = 2;
                medium.setOutlineThickness(3);
                medium.setOutlineColor(sf::Color(237, 147, 0));

                easy.setOutlineThickness(0);
                hard.setOutlineThickness(0);
            }

            if ((IntRect(1195, 95, 150, 60).contains(Mouse::getPosition(Options))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            {
                hardlevel = 3;
                hard.setOutlineThickness(3);
                hard.setOutlineColor(sf::Color(237, 147, 0));

                medium.setOutlineThickness(0);
                easy.setOutlineThickness(0);
            }

            if ((IntRect(width - 405, height - 265, 170, 60).contains(Mouse::getPosition(Options))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            { isPres = true;}


            if (event_opt.type == Event::Closed) Options.close();
            if (event_opt.type == Event::KeyPressed)


             {
                //if (event_opt.key.code == Keyboard::Escape) Options.close();
            }
        }
        Options.clear();
        Options.draw(background_opt);
        Options.draw(hardly);
        Options.draw(easy);
        Options.draw(medium);
        Options.draw(hard);
        Options.draw(save);
        //Options.display();

        firstname.draw(Options);
        Options.draw(f1.get());

        Options.display();

        if (isPres == true )
        {
            Options.close();
            return hardlevel;
        }
    }


    /*
     *
     *     sdx::TextBox::Text f1("",534,320);
    f1.setSize(34);
    sdx::TextBox firstname;
    firstname.setPosition(700, 200);
    firstname.setSize(100,40);
    firstname.setBorder(1);
     *
     * sdx::TextBox::Text rounds("",534,320);
    rounds.setSize(34);
    sdx::TextBox enterCountRounds;
    enterCountRounds.setPosition(700, 200);
    enterCountRounds.setSize(100,40);
    enterCountRounds.setBorder(1);

            //box
        enterCountRounds.draw(Play);
        Play.draw(rounds.get());

     numberOfRound = enterCountRounds.getCurrentText();
     */

    std::string  firstNamePlayer = firstname.getCurrentText();

    return hardlevel;
}

