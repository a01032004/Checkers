#include <iostream>
#include "menu.h"
#include "Checker.h"

using namespace sf;


// функция настройки текста
void InitText(Text& mtext, float xpos, float ypos, String str, int size_font = 60,
              Color menu_text_color = Color::White, int bord = 0, Color border_color = Color::Black);

bool GoOut1();
int finalWin(int, std::string, int, int);
bool Draw();
int Pause();

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
                numberOfRound = "1";
                fastPlay.setOutlineThickness(3);
                fastPlay.setOutlineColor(sf::Color(237, 147, 0));
                rounds.setText("");
                enterCountRounds.draw(Play);
                Play.draw(rounds.get());

            }

            if ((IntRect(690, 195, 100, 60).contains(Mouse::getPosition(Play))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                numberOfRound = "";
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

    if (numberOfRound != "1") {
        numberOfRound = enterCountRounds.getCurrentText();
    }



    if (numberOfRound == "") {numberOfRound = "1";}
    std::cout << CountUsers;
    std::cout << numberOfRound;
    std::cout << typyOfCheckers;
    std::cout << color;
    std::cout << isButtonPressed;

    return (isButtonPressed);

}





// Функция настройки игры
int Options(int &hardlevel, std::string &firstNamePlayer, std::string &secondNamePlayer)
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
    if (firstNamePlayer == "guest1") {
        firstNamePlayer = "";
    }
    if (secondNamePlayer == "guest2") {
        secondNamePlayer = "";
    }

    sdx::TextBox::Text f1(firstNamePlayer,600,300);
    f1.setSize(34);
    sdx::TextBox firstname;
    firstname.setPosition(600, 300);
    firstname.setSize(280,40);
    firstname.setBorder(1);


    sdx::TextBox::Text f2(secondNamePlayer,600,400);
    f2.setSize(34);
    sdx::TextBox secondname;
    secondname.setPosition(600, 400);
    secondname.setSize(280,40);
    secondname.setBorder(1);

    sf::Text text1;
    text1.setFont(font);
    text1.setString(L"Введите имя 1 игрока");
    text1.setCharacterSize(36);
    text1.setFillColor(sf::Color(237, 147, 0));
    text1.setPosition(100, 300);
    text1.setOutlineThickness(3);
    text1.setOutlineColor(sf::Color::Black);

    sf::Text text2;
    text2.setFont(font);
    text2.setString(L"Введите имя 2 игрока");
    text2.setCharacterSize(36);
    text2.setFillColor(sf::Color(237, 147, 0));
    text2.setPosition(100, 400);
    text2.setOutlineThickness(3);
    text2.setOutlineColor(sf::Color::Black);

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
            if (event_opt.type == Event::KeyPressed){}

            firstname.handleEvent(event_opt);
            secondname.handleEvent(event_opt);


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
        Options.draw(text1);
        Options.draw(text2);

        if (firstname.getCurrentText() != "") {
            firstNamePlayer = firstname.getCurrentText();
            f1.setText(firstname.getCurrentText());
        }
        if (secondname.getCurrentText() != "") {
            secondNamePlayer = secondname.getCurrentText();
        }

        firstname.draw(Options);
        if (firstname.getCurrentText() == "") {
            Options.draw(f1.get());
        }

        secondname.draw(Options);
        if (secondname.getCurrentText() == "") {
            Options.draw(f2.get());
        }




        Options.display();


        if (isPres == true )
        {
            Options.close();
            return hardlevel;
        }
    }


    firstNamePlayer = firstname.getCurrentText();
    secondNamePlayer = secondname.getCurrentText();
    std::cout<<firstNamePlayer;
    std::cout<<secondNamePlayer;

    return hardlevel;
}

// Функция с описанием игры
int About_Game()
{
    RenderWindow About(VideoMode::getDesktopMode(), L"О игре");
    RectangleShape background_ab(Vector2f(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));

    Font font;
    if (!font.loadFromFile("font/troika.otf")) return -1;

    Texture texture_ab;
    if (!texture_ab.loadFromFile("images/1111.jpg")) exit(1);
    background_ab.setTexture(&texture_ab);


    ///////////*****************************************back
    sf::Text goBack;
    goBack.setFont(font);
    goBack.setString(L"Назад");
    goBack.setCharacterSize(48);
    goBack.setFillColor(sf::Color(237, 147, 0));
    goBack.setOutlineThickness(4);
    goBack.setOutlineColor(sf::Color::Black);
    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;

    goBack.setPosition(100, height - 260);


    ///////////////******************************************** description
    sf::Text read;
    read.setFont(font);
    read.setString(L"Игра: шашки");
    read.setCharacterSize(40);
    read.setFillColor(sf::Color(237, 147, 0));
    read.setOutlineThickness(2);
    read.setOutlineColor(sf::Color::Black);
    read.setPosition(width / 2 - 150, 100);

    ///////////////******************************************** description
    sf::Text read2;
    read2.setFont(font);
    read2.setString(L"Правила игры всем известны:)      Цель - съесть все фигуры противника");
    read2.setCharacterSize(40);
    read2.setFillColor(sf::Color(237, 147, 0));
    read2.setOutlineThickness(2);
    read2.setOutlineColor(sf::Color::Black);
    read2.setPosition(100, 250);

    ///////////////******************************************** description
    sf::Text read3;
    read3.setFont(font);
    read3.setString(L"Работу выполнили слушатели гр. 7322 Бархаткин, Павлов, Тихомиров");
    read3.setCharacterSize(40);
    read3.setFillColor(sf::Color(237, 147, 0));
    read3.setOutlineThickness(2);
    read3.setOutlineColor(sf::Color::Black);
    read3.setPosition(100, 400);


    while (About.isOpen())
    {
        Event event_play;
        while (About.pollEvent(event_play))
        {
            if ((IntRect(100, height - 265, 170, 60).contains(Mouse::getPosition(About))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            { About.close(); }


            if (event_play.type == Event::Closed) About.close();
            if (event_play.type == Event::KeyPressed)
            {
                //if (event_play.key.code == Keyboard::Escape) About.close();
            }
        }
        About.clear();
        About.draw(background_ab);
        About.draw(goBack);
        About.draw(read);
        About.draw(read2);
        About.draw(read3);
        About.display();
    }
}

























const int BOARD_SIZE = 8;
const int TILE_SIZE = 80;


#define BOARD_SIZE 8
#define SQUARE_SIZE 80

enum class PieceType { Pawn, King };
enum class PieceColor { White, Black };

struct Piece {
    PieceType type;
    PieceColor color;
};

int playEnglishCheckers(int &CountUsers, std::string &numberOfRound, int &color, std::string &firstNamePlayer, std::string &secondNamePlayer, int &wins1, int &wins2)
{
    	Checker W1 (7, 0, color == 1);
		Checker W2 (7, 2, color == 1);
		Checker W3 (7, 4, color == 1);
		Checker W4 (7, 6, color == 1);
		Checker W5 (6, 1, color == 1);
		Checker W6 (6, 3, color == 1);
		Checker W7 (6, 5, color == 1);
		Checker W8 (6, 7, color == 1);
		Checker W9 (5, 0, color == 1);
		Checker W10(5, 2, color == 1);
		Checker W11(5, 4, color == 1);
		Checker W12(5, 6, color == 1);

		Checker B1 (0, 1, color == 2);
		Checker B2 (0, 3, color == 2);
		Checker B3 (0, 5, color == 2);
		Checker B4 (0, 7, color == 2);
		Checker B5 (1, 0, color == 2);
		Checker B6 (1, 2, color == 2);
		Checker B7 (1, 4, color == 2);
		Checker B8 (1, 6, color == 2);
		Checker B9 (2, 1, color == 2);
		Checker B10(2, 3, color == 2);
		Checker B11(2, 5, color == 2);
		Checker B12(2, 7, color == 2);
        Checker*** board1 = new Checker * *[8];
        for (int i = 0; i < 8; ++i)
       	{
       		board1[i] = new Checker* [8];
       		for (int j = 0; j < 8; ++j)
       			board1[i][j] = nullptr;
       	}
        /*board1[7][0] = &W1; board1[7][2] = &W2; board1[7][4] = &W3; board1[7][6] = &W4; board1[6][1] = &W5; board1[6][3] = &W6; board1[6][5] = &W7; board1[6][7] = &W8;  board1[5][0] = &W9; board1[5][2] = &W10; board1[5][4] = &W11;*/ board1[5][6] = &W12;
        board1[0][1] = &B1; board1[0][3] = &B2; board1[0][5] = &B3; board1[0][7] = &B4; board1[1][0] = &B5; board1[1][2] = &B6; board1[1][4] = &B7; board1[1][6] = &B8; board1[2][1] = &B9; board1[2][3] = &B10; board1[2][5] = &B11; board1[2][7] = &B12;

    //sf::RenderWindow window(sf::VideoMode(BOARD_SIZE * TILE_SIZE, BOARD_SIZE * TILE_SIZE), "Checkers Game");
    sf::RenderWindow windowGame(sf::VideoMode::getDesktopMode(), "English Checkers Game");
    RectangleShape background_ab(Vector2f(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));

    Texture texture_ab;
    if (!texture_ab.loadFromFile("images/1111.jpg")) exit(1);
    background_ab.setTexture(&texture_ab);

    Font font;
    if (!font.loadFromFile("font/troika.otf")) return -1;

    sf::RectangleShape board[BOARD_SIZE][BOARD_SIZE];
    sf::CircleShape pieces[BOARD_SIZE][BOARD_SIZE];

    bool isPieceSelected = false;
    sf::Vector2i selectedPiecePos;


    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j].setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));

            if ((i + j) % 2 == 0)
                board[i][j].setFillColor(sf::Color::White);
            else
                board[i][j].setFillColor(sf::Color::Red);
            board[i][j].setPosition(i * TILE_SIZE+600, j * TILE_SIZE+200);                                          /////////////////////*********/////////
        }
    }
    int* selectedPos = new int [2]{-1,-1};
    vector<int*> moves;
    vector<int*> attackMoves;
    bool turn = true;
    bool repeatAttack = false;
    Clock clock;
    Clock gameTimeClock;//переменная игрового времени, будем здесь хранить время игры
    int gameTime = 0;//объявили игровое время, инициализировали.
    int rounds = std::stoi(numberOfRound);




    while (windowGame.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();


        sf::Event eventGame;

        while (windowGame.pollEvent(eventGame)) {
            if (eventGame.type == sf::Event::Closed)
                windowGame.close();

            if (eventGame.type == Event::KeyPressed)
            {
                if (eventGame.key.code == Keyboard::Escape) {
                    int tempTime = gameTimeClock.getElapsedTime().asSeconds();;
                    int action = Pause();
                    if (action == 1111) {
                        gameTime = tempTime;
                    }
                    if (action == 2222) {
                        return 10;
                        windowGame.close();
                    }
                    if (action == 3333) {
                        return 44;
                        windowGame.close();
                    }

                    gameTime = tempTime;
                }
                }
                if (eventGame.key.code == Keyboard::F1) windowGame.close();
            //}

            if (eventGame.type == Event::Closed) windowGame.close();
            if (eventGame.type == Event::KeyPressed)
            {
                if (eventGame.key.code == Keyboard::Escape) windowGame.close();
            }

            //Если нажали на рестарт
            if ((IntRect(10, 690, 220, 50).contains(Mouse::getPosition(windowGame))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            {
                return 44;
                windowGame.close();
            }

            //Если нажали на Выход
            if ((IntRect(10, 780, 220, 50).contains(Mouse::getPosition(windowGame))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            {
                return 10;
                windowGame.close();
            }
            //Если нажали на предложение о Ничьей
            if ((IntRect(10, 880, 220, 50).contains(Mouse::getPosition(windowGame))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            {
                bool agree = Draw(); ///if yes no
                if (agree == true) {
                    wins1 = 0;
                    wins2 = 0;
                    windowGame.close();
                    return 1123;
                }
            }




            if (eventGame.type == sf::Event::MouseButtonPressed) {

                if (eventGame.mouseButton.button == sf::Mouse::Left) {



                    if (!repeatAttack)
                    {
                        for (int i = 0; i < BOARD_SIZE; i++) // в отдельную функцию.
                        {
                            for (int j = 0; j < BOARD_SIZE; j++)
                            {
                                if ((i + j) % 2 == 0)
                                    board[i][j].setFillColor(sf::Color::White);
                                else
                                    board[i][j].setFillColor(sf::Color::Red);
                            }
                        }
                    }
                    sf::Vector2i mousePos = sf::Mouse::getPosition(windowGame);
                    sf::Vector2i boardPos = (mousePos / TILE_SIZE);
                    int* pos = new int[2] {((mousePos.y - 200)/ TILE_SIZE) , ((mousePos.x - 600)/ TILE_SIZE) };
                    if (isPieceSelected && (inArray(moves, pos) || inArray(attackMoves, pos)))
                    {


                        // Move the selected piece to the new position
                        /*pieces[boardPos.x][boardPos.y] = pieces[selectedPiecePos.x][selectedPiecePos.y];
                        pieces[selectedPiecePos.x][selectedPiecePos.y].setFillColor(sf::Color::Transparent);*/

                        bool isAttack = inArray(attackMoves, pos); // передвижение / взятие
                        board1[selectedPos[0]][selectedPos[1]]->moveTo(board1, pos[0], pos[1], isAttack, 8);

                        if (turn && pos[0] == 0)
                        {
                            board1[pos[0]][pos[1]]->SetQueen();
                        }
                        else if (!turn && pos[0] == 7)
                        {
                            board1[pos[0]][pos[1]]->SetQueen();
                        }

                        if (isAttack && (attackMoves = VectorSum(board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, !turn), board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, board1[pos[0]][pos[1]]->isQueen() ? turn : !turn))).size() != 0)
                        {
                            moves.clear();
                            for (int i = 0; i < BOARD_SIZE; i++) // в отдельную функцию.
                            {
                                for (int j = 0; j < BOARD_SIZE; j++)
                                {
                                    if ((i + j) % 2 == 0)
                                        board[i][j].setFillColor(sf::Color::White);
                                    else
                                        board[i][j].setFillColor(sf::Color::Red);
                                }
                            }
                            selectedPos[0] = pos[0]; selectedPos[1] = pos[1];
                            //sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                            //sf::Vector2i boardPos = (mousePos / TILE_SIZE);
                            //int* pos = new int[2] {(mousePos.y / TILE_SIZE), mousePos.x / TILE_SIZE};
                            for (int i = 0; i < attackMoves.size(); ++i)
                                board[attackMoves[i][1]][attackMoves[i][0]].setFillColor(sf::Color::Yellow);
                            board[pos[1]][pos[0]].setFillColor(sf::Color::Green); // Добавить кнопку отмены хода.
                            /*if (inArray(attackMoves, pos))
                                board1[selectedPos[0]][selectedPos[1]]->moveTo(board1, pos[0], pos[1], isAttack, 8);*/
                            repeatAttack = true;
                        }
                        else
                        {
                            isPieceSelected = false; //конец хода.
                            turn = !turn;
                            repeatAttack = false;
                            for (int i = 0; i < BOARD_SIZE; i++) // в отдельную функцию.
                            {
                                for (int j = 0; j < BOARD_SIZE; j++)
                                {
                                    if ((i + j) % 2 == 0)
                                        board[i][j].setFillColor(sf::Color::White);
                                    else
                                        board[i][j].setFillColor(sf::Color::Red);
                                }
                            }
                        }
                    }

                    else {
                        // Select the piece on the clicked position
                        //if (pieces[boardPos.x][boardPos.y].getFillColor() != sf::Color::Transparent)
                        if ( board1[pos[0]][pos[1]] != nullptr && turn == board1[pos[0]][pos[1]]->GetColor() && !repeatAttack)
                        {
                            isPieceSelected = true;
                            selectedPos = new int[2] {pos[0], pos[1]};
                            moves = board1[pos[0]][pos[1]]->GetMoves(board1, 8, !turn);
                            attackMoves = board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, !turn);
                            if (board1[pos[0]][pos[1]]->isQueen())
                            {
                                moves = VectorSum(board1[pos[0]][pos[1]]->GetMoves(board1, 8, turn),moves);
                                attackMoves = VectorSum(board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, turn), attackMoves);
                            }
                            board[pos[1]][pos[0]].setFillColor(sf::Color::Green);
                            for (int i = 0; i < moves.size(); ++i)
                                board[moves[i][1]][moves[i][0]].setFillColor(sf::Color::Blue);
                            for (int i = 0; i < attackMoves.size(); ++i)
                                board[attackMoves[i][1]][attackMoves[i][0]].setFillColor(sf::Color::Yellow);
                        }
                    }
                }
            }
            //////////////////////////////////////////////////////////////////
            bool isWhiteWon = true;
            bool isBlackWon = true;
            for (int i = 0; i < BOARD_SIZE; ++i)
            {
                for (int j = 0; j < BOARD_SIZE; ++j)
                {
                    if (board1[i][j] != nullptr)
                    {
                        if (board1[i][j]->GetColor() == true)
                            isBlackWon = false;
                        else
                            isWhiteWon = false;
                    }
                }
            }
            if (!isWhiteWon && !isBlackWon) {
                //windowGame.draw(read3);

                //gameTime=gameTimeClock.getElapsedTime().asSeconds();//игровое время в секундах
                continue;
            }

            //clock.restart();
            std::cout<<"gameTime;";
            std::cout<<gameTime;
            std::cout<<"    ";
            int temp= 0;

            if (isWhiteWon) {
                wins1 = wins1 + 1;
                numberOfRound = std::to_string(rounds - 1);
                if (std::stoi(numberOfRound) > 0) {
                    return(11);
                }
                if (std::stoi(numberOfRound) == 0) {
                    return (111);
                }
                return 1111;
            }

            if (isBlackWon){
                wins2 = wins2 + 1;
                numberOfRound = std::to_string(rounds - 1);
                if (std::stoi(numberOfRound) == 0) {
                    return (222);
                }
                if (std::stoi(numberOfRound) > 0) {
                    return (22);
                }

                return 2222;
            }
        }


        ///////////////*********************************************************************************************************** description time




        sf::Text restart;
        restart.setFont(font);
        restart.setString(L"Начать заново");
        restart.setCharacterSize(30);
        restart.setFillColor(sf::Color(237, 147, 0));
        restart.setOutlineThickness(2);
        restart.setOutlineColor(sf::Color::Black);
        restart.setPosition(20, 700);


        sf::Text time1;
        time1.setFont(font);
        time1.setString(L"Время с начала партии:  ");
        time1.setCharacterSize(30);
        time1.setFillColor(sf::Color(237, 147, 0));
        time1.setOutlineThickness(2);
        time1.setOutlineColor(sf::Color::Black);
        time1.setPosition(20, 240);

        gameTime=gameTimeClock.getElapsedTime().asSeconds();//игровое время в секундах
        sf::Text time2;
        time2.setFont(font);
        int min = gameTime / 60 ;
        int sec = gameTime - (60 * min);
        time2.setString(std::to_string(min) + " : " + std::to_string(sec));
        time2.setCharacterSize(30);
        time2.setFillColor(sf::Color(237, 147, 0));
        time2.setOutlineThickness(2);
        time2.setOutlineColor(sf::Color::Black);
        time2.setPosition(400, 240);


        sf::Text rounds1;
        rounds1.setFont(font);
        rounds1.setString(L"Количество оставшихся партий в игре:");
        rounds1.setCharacterSize(30);
        rounds1.setFillColor(sf::Color(237, 147, 0));
        rounds1.setOutlineThickness(2);
        rounds1.setOutlineColor(sf::Color::Black);
        rounds1.setPosition(20, 80);

        //rounds = rounds - 1;

        sf::Text rounds2;
        rounds2.setFont(font);
        rounds2.setString(std::to_string(rounds - 1));
        rounds2.setCharacterSize(30);
        rounds2.setFillColor(sf::Color(237, 147, 0));
        rounds2.setOutlineThickness(2);
        rounds2.setOutlineColor(sf::Color::Black);
        rounds2.setPosition(610, 80);



        sf::Text resultText;
        resultText.setFont(font);
        resultText.setString(L"Счёт по партиям:");
        resultText.setCharacterSize(30);
        resultText.setFillColor(sf::Color(237, 147, 0));
        resultText.setOutlineThickness(2);
        resultText.setOutlineColor(sf::Color::Black);
        resultText.setPosition(20, 160);

        sf::Text result;
        //int firstwins = 0;
        //int seconwins = 0;
        result.setFont(font);
        result.setString(std::to_string(wins1) + " : " + std::to_string(wins2));
        result.setCharacterSize(30);
        result.setFillColor(sf::Color(237, 147, 0));
        result.setOutlineThickness(2);
        result.setOutlineColor(sf::Color::Black);
        result.setPosition(300, 160);

        sf::Text backToMenu;
        backToMenu.setFont(font);
        backToMenu.setString(L"Выйти из игры");
        backToMenu.setCharacterSize(30);
        backToMenu.setFillColor(sf::Color(237, 147, 0));
        backToMenu.setOutlineThickness(2);
        backToMenu.setOutlineColor(sf::Color::Black);
        backToMenu.setPosition(20, 790);

        sf::Text name1;
        name1.setFont(font);
        name1.setString(firstNamePlayer + "  VS  " + secondNamePlayer);
        name1.setCharacterSize(30);
        name1.setFillColor(sf::Color(237, 147, 0));
        name1.setOutlineThickness(2);
        name1.setOutlineColor(sf::Color::Black);
        name1.setPosition(790, 20);

        sf::Text draw;
        draw.setFont(font);
        draw.setString(L"Предложить ничью");
        backToMenu.setCharacterSize(30);
        draw.setFillColor(sf::Color(237, 147, 0));
        draw.setOutlineThickness(2);
        draw.setOutlineColor(sf::Color::Black);
        draw.setPosition(20, 880);



        ///////////////********************************************



        windowGame.clear();
        windowGame.draw(background_ab);
        windowGame.draw(time1);
        windowGame.draw(time2);
        windowGame.draw(rounds1);
        windowGame.draw(rounds2);
        windowGame.draw(resultText);
        windowGame.draw(result);
        windowGame.draw(restart);
        windowGame.draw(name1);
        windowGame.draw(backToMenu);
        windowGame.draw(draw);









        for (int i = 0; i < BOARD_SIZE; i++)
            for (int j = 0; j < BOARD_SIZE; j++)
                pieces[i][j].setFillColor(sf::Color::Transparent);

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board1[j][i] != nullptr && board1[j][i]->GetColor() == true) { // otdelynaya function pzlst
                    pieces[i][j].setRadius(TILE_SIZE / 2 - 10);
                    pieces[i][j].setFillColor(sf::Color::White);
                    pieces[i][j].setPosition(i * TILE_SIZE + 610, j * TILE_SIZE + 210);
                }

                if (board1[j][i] != nullptr && board1[j][i]->GetColor() == false) {
                    pieces[i][j].setRadius(TILE_SIZE / 2 - 10);
                    pieces[i][j].setFillColor(sf::Color::Black);
                    pieces[i][j].setPosition(i * TILE_SIZE + 610, j * TILE_SIZE + 210);
                }
            }
        }

        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                windowGame.draw(board[i][j]);

                if (pieces[i][j].getFillColor() != sf::Color::Transparent)
                    windowGame.draw(pieces[i][j]);
            }
        }


        windowGame.display();

    }

    return 0;

};


// пока ничего не делал.
int RussianShushuki(int &CountUsers, std::string &numberOfRound, int &color, std::string &firstNamePlayer, std::string &secondNamePlayer, int &wins1, int &wins2)
{
    	Checker W1 (7, 0, color == 1);
		Checker W2 (7, 2, color == 1);
		Checker W3 (7, 4, color == 1);
		Checker W4 (7, 6, color == 1);
		Checker W5 (6, 1, color == 1);
		Checker W6 (6, 3, color == 1);
		Checker W7 (6, 5, color == 1);
		Checker W8 (6, 7, color == 1);
		Checker W9 (5, 0, color == 1);
		Checker W10(5, 2, color == 1);
		Checker W11(5, 4, color == 1);
		Checker W12(5, 6, color == 1);

		Checker B1 (0, 1, color == 2);
		Checker B2 (0, 3, color == 2);
		Checker B3 (0, 5, color == 2);
		Checker B4 (0, 7, color == 2);
		Checker B5 (1, 0, color == 2);
		Checker B6 (1, 2, color == 2);
		Checker B7 (1, 4, color == 2);
		Checker B8 (1, 6, color == 2);
		Checker B9 (2, 1, color == 2);
		Checker B10(2, 3, color == 2);
		Checker B11(2, 5, color == 2);
		Checker B12(2, 7, color == 2);
        Checker*** board1 = new Checker * *[8];
        for (int i = 0; i < 8; ++i)
       	{
       		board1[i] = new Checker* [8];
       		for (int j = 0; j < 8; ++j)
       			board1[i][j] = nullptr;
       	}
        /*board1[7][0] = &W1; board1[7][2] = &W2; board1[7][4] = &W3; board1[7][6] = &W4; board1[6][1] = &W5; board1[6][3] = &W6; board1[6][5] = &W7; board1[6][7] = &W8;  board1[5][0] = &W9; board1[5][2] = &W10; board1[5][4] = &W11;*/ board1[5][6] = &W12;
        board1[0][1] = &B1; board1[0][3] = &B2; board1[0][5] = &B3; board1[0][7] = &B4; board1[1][0] = &B5; board1[1][2] = &B6; board1[1][4] = &B7; board1[1][6] = &B8; board1[2][1] = &B9; board1[2][3] = &B10; board1[2][5] = &B11; board1[2][7] = &B12;

        //sf::RenderWindow window(sf::VideoMode(BOARD_SIZE * TILE_SIZE, BOARD_SIZE * TILE_SIZE), "Checkers Game");
        sf::RenderWindow windowGame(sf::VideoMode::getDesktopMode(), "English Checkers Game");
        RectangleShape background_ab(Vector2f(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));

        Texture texture_ab;
        if (!texture_ab.loadFromFile("images/1111.jpg")) exit(1);
        background_ab.setTexture(&texture_ab);

        Font font;
        if (!font.loadFromFile("font/troika.otf")) return -1;

        sf::RectangleShape board[BOARD_SIZE][BOARD_SIZE];
        sf::CircleShape pieces[BOARD_SIZE][BOARD_SIZE];

        bool isPieceSelected = false;
        sf::Vector2i selectedPiecePos;


        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                board[i][j].setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));

                if ((i + j) % 2 == 0)
                    board[i][j].setFillColor(sf::Color::White);
                else
                    board[i][j].setFillColor(sf::Color::Red);
                board[i][j].setPosition(i * TILE_SIZE + 600, j * TILE_SIZE + 200);
            }
        }
        int* selectedPos = new int [2] {-1, -1};
        vector<int*> moves;
        vector<int*> attackMoves;
        bool turn = true;
        bool repeatAttack = false;
        Clock clock;
        Clock gameTimeClock;//переменная игрового времени, будем здесь хранить время игры
        int gameTime = 0;//объявили игровое время, инициализировали.
        int rounds = std::stoi(numberOfRound);
              





        while (windowGame.isOpen()) {
            float time = clock.getElapsedTime().asMicroseconds();


            sf::Event eventGame;

            while (windowGame.pollEvent(eventGame)) {
                if (eventGame.type == sf::Event::Closed)
                    windowGame.close();

                if (eventGame.type == Event::KeyPressed)
                {
                    if (eventGame.key.code == Keyboard::Escape) {
                        int tempTime = gameTimeClock.getElapsedTime().asSeconds();;
                        int action = Pause();
                        if (action == 1111) {
                            gameTime = tempTime;
                        }
                        if (action == 2222) {
                            return 10;
                            windowGame.close();
                        }
                        if (action == 3333) {
                            return 44;
                            windowGame.close();
                        }

                        gameTime = tempTime;
                    }
                }
                if (eventGame.key.code == Keyboard::F1) windowGame.close();
                //}

                if (eventGame.type == Event::Closed) windowGame.close();
                if (eventGame.type == Event::KeyPressed)
                {
                    if (eventGame.key.code == Keyboard::Escape) windowGame.close();
                }

                //Если нажали на рестарт
                if ((IntRect(10, 690, 220, 50).contains(Mouse::getPosition(windowGame))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    return 44;
                    windowGame.close();
                }

                //Если нажали на Выход
                if ((IntRect(10, 780, 220, 50).contains(Mouse::getPosition(windowGame))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    return 10;
                    windowGame.close();
                }
                //Если нажали на предложение о Ничьей
                if ((IntRect(10, 880, 220, 50).contains(Mouse::getPosition(windowGame))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    bool agree = Draw(); ///if yes no
                    if (agree == true) {
                        wins1 = 0;
                        wins2 = 0;
                        windowGame.close();
                        return 1123;
                    }
                }




                if (eventGame.type == sf::Event::MouseButtonPressed) {

                    if (eventGame.mouseButton.button == sf::Mouse::Left) {



                        if (!repeatAttack)
                        {
                            for (int i = 0; i < BOARD_SIZE; i++) // в отдельную функцию.
                            {
                                for (int j = 0; j < BOARD_SIZE; j++)
                                {
                                    if ((i + j) % 2 == 0)
                                        board[i][j].setFillColor(sf::Color::White);
                                    else
                                        board[i][j].setFillColor(sf::Color::Red);
                                }
                            }
                        }////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        sf::Vector2i mousePos = sf::Mouse::getPosition(windowGame);
                        sf::Vector2i boardPos = (mousePos / TILE_SIZE);
                        int* pos = new int[2] {((mousePos.y - 200) / TILE_SIZE), ((mousePos.x - 600) / TILE_SIZE) };

                        // Проверка на наличие атаки
                        bool hasAttack = false;
                        for (int i = 0; i < BOARD_SIZE; i++)
                            for (int j = 0; j < BOARD_SIZE; j++)
                                if (board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, !turn, true).size() != 0)
                                    hasAttack = true;

                        if (isPieceSelected && (inArray(moves, pos) || inArray(attackMoves, pos)))
                        {

                            bool isAttack = inArray(attackMoves, pos); // передвижение / взятие
                            board1[selectedPos[0]][selectedPos[1]]->moveTo(board1, pos[0], pos[1], isAttack, 8);

                            if (turn && pos[0] == 0)
                            {
                                board1[pos[0]][pos[1]]->SetQueen();
                            }
                            else if (!turn && pos[0] == 7)
                            {
                                board1[pos[0]][pos[1]]->SetQueen();
                            }

                            if (isAttack && (attackMoves = VectorSum(board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, !turn, true), board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, board1[pos[0]][pos[1]]->isQueen() ? turn : !turn, true))).size() != 0)
                            {
                                moves.clear();
                                for (int i = 0; i < BOARD_SIZE; i++) // в отдельную функцию.
                                {
                                    for (int j = 0; j < BOARD_SIZE; j++)
                                    {
                                        if ((i + j) % 2 == 0)
                                            board[i][j].setFillColor(sf::Color::White);
                                        else
                                            board[i][j].setFillColor(sf::Color::Red);
                                    }
                                }
                                selectedPos[0] = pos[0]; selectedPos[1] = pos[1];
                                //sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                                //sf::Vector2i boardPos = (mousePos / TILE_SIZE);
                                //int* pos = new int[2] {(mousePos.y / TILE_SIZE), mousePos.x / TILE_SIZE};
                                for (int i = 0; i < attackMoves.size(); ++i)
                                    board[attackMoves[i][1]][attackMoves[i][0]].setFillColor(sf::Color::Yellow);
                                board[pos[1]][pos[0]].setFillColor(sf::Color::Green); // Добавить кнопку отмены хода.
                                /*if (inArray(attackMoves, pos))
                                    board1[selectedPos[0]][selectedPos[1]]->moveTo(board1, pos[0], pos[1], isAttack, 8);*/
                                repeatAttack = true;
                            }
                            else
                            {
                                isPieceSelected = false; //конец хода.
                                turn = !turn;
                                repeatAttack = false;
                                for (int i = 0; i < BOARD_SIZE; i++) // в отдельную функцию.
                                {
                                    for (int j = 0; j < BOARD_SIZE; j++)
                                    {
                                        if ((i + j) % 2 == 0)
                                            board[i][j].setFillColor(sf::Color::White);
                                        else
                                            board[i][j].setFillColor(sf::Color::Red);
                                    }
                                }
                            }
                        }

                        else {
                            // Select the piece on the clicked position
                            //if (pieces[boardPos.x][boardPos.y].getFillColor() != sf::Color::Transparent)
                            if (board1[pos[0]][pos[1]] != nullptr && turn == board1[pos[0]][pos[1]]->GetColor() && !repeatAttack && (!hasAttack || board1[pos[0]][pos[1]]->GetAttackMoves().size()!= 0))
                            {
                               
                                    isPieceSelected = true;
                                    selectedPos = new int[2] {pos[0], pos[1]};
                           
                                    if (!hasAttack)
                                    {
                                        moves = board1[pos[0]][pos[1]]->GetMoves(board1, 8, !turn);
                                        if (board1[pos[0]][pos[1]]->isQueen())
                                            moves = VectorSum(board1[pos[0]][pos[1]]->GetMoves(board1, 8, turn), moves);

                                        for (int i = 0; i < moves.size(); ++i)
                                            board[moves[i][1]][moves[i][0]].setFillColor(sf::Color::Blue);
                                    }
                                    else
                                    {
                                        attackMoves = board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, !turn, true);

                                        if (board1[pos[0]][pos[1]]->isQueen())
                                            attackMoves = VectorSum(board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, turn, true), attackMoves);
                                        for (int i = 0; i < attackMoves.size(); ++i)
                                            board[attackMoves[i][1]][attackMoves[i][0]].setFillColor(sf::Color::Yellow);
                                    }
                                board[pos[1]][pos[0]].setFillColor(sf::Color::Green);
                                
                                
                            }
                        }
                    }
                }
                //////////////////////////////////////////////////////////////////
                bool isWhiteWon = true;
                bool isBlackWon = true;
                for (int i = 0; i < BOARD_SIZE; ++i)
                {
                    for (int j = 0; j < BOARD_SIZE; ++j)
                    {
                        if (board1[i][j] != nullptr)
                        {
                            if (board1[i][j]->GetColor() == true)
                                isBlackWon = false;
                            else
                                isWhiteWon = false;
                        }
                    }
                }
                if (!isWhiteWon && !isBlackWon) {
                    //windowGame.draw(read3);

                    //gameTime=gameTimeClock.getElapsedTime().asSeconds();//игровое время в секундах
                    continue;
                }

                //clock.restart();
                std::cout << "gameTime;";
                std::cout << gameTime;
                std::cout << "    ";
                int temp = 0;

                if (isWhiteWon) {
                    wins1 = wins1 + 1;
                    numberOfRound = std::to_string(rounds - 1);
                    if (std::stoi(numberOfRound) > 0) {
                        return(11);
                    }
                    if (std::stoi(numberOfRound) == 0) {
                        return (111);
                    }
                    return 1111;
                }

                if (isBlackWon) {
                    wins2 = wins2 + 1;
                    numberOfRound = std::to_string(rounds - 1);
                    if (std::stoi(numberOfRound) == 0) {
                        return (222);
                    }
                    if (std::stoi(numberOfRound) > 0) {
                        return (22);
                    }

                    return 2222;
                }
            }


            ///////////////*********************************************************************************************************** description time




            sf::Text restart;
            restart.setFont(font);
            restart.setString(L"Начать заново");
            restart.setCharacterSize(30);
            restart.setFillColor(sf::Color(237, 147, 0));
            restart.setOutlineThickness(2);
            restart.setOutlineColor(sf::Color::Black);
            restart.setPosition(20, 700);


            sf::Text time1;
            time1.setFont(font);
            time1.setString(L"Время с начала партии:  ");
            time1.setCharacterSize(30);
            time1.setFillColor(sf::Color(237, 147, 0));
            time1.setOutlineThickness(2);
            time1.setOutlineColor(sf::Color::Black);
            time1.setPosition(20, 240);

            gameTime = gameTimeClock.getElapsedTime().asSeconds();//игровое время в секундах
            sf::Text time2;
            time2.setFont(font);
            int min = gameTime / 60;
            int sec = gameTime - (60 * min);
            time2.setString(std::to_string(min) + " : " + std::to_string(sec));
            time2.setCharacterSize(30);
            time2.setFillColor(sf::Color(237, 147, 0));
            time2.setOutlineThickness(2);
            time2.setOutlineColor(sf::Color::Black);
            time2.setPosition(400, 240);


            sf::Text rounds1;
            rounds1.setFont(font);
            rounds1.setString(L"Количество оставшихся партий в игре:");
            rounds1.setCharacterSize(30);
            rounds1.setFillColor(sf::Color(237, 147, 0));
            rounds1.setOutlineThickness(2);
            rounds1.setOutlineColor(sf::Color::Black);
            rounds1.setPosition(20, 80);

            //rounds = rounds - 1;

            sf::Text rounds2;
            rounds2.setFont(font);
            rounds2.setString(std::to_string(rounds - 1));
            rounds2.setCharacterSize(30);
            rounds2.setFillColor(sf::Color(237, 147, 0));
            rounds2.setOutlineThickness(2);
            rounds2.setOutlineColor(sf::Color::Black);
            rounds2.setPosition(610, 80);



            sf::Text resultText;
            resultText.setFont(font);
            resultText.setString(L"Счёт по партиям:");
            resultText.setCharacterSize(30);
            resultText.setFillColor(sf::Color(237, 147, 0));
            resultText.setOutlineThickness(2);
            resultText.setOutlineColor(sf::Color::Black);
            resultText.setPosition(20, 160);

            sf::Text result;
            //int firstwins = 0;
            //int seconwins = 0;
            result.setFont(font);
            result.setString(std::to_string(wins1) + " : " + std::to_string(wins2));
            result.setCharacterSize(30);
            result.setFillColor(sf::Color(237, 147, 0));
            result.setOutlineThickness(2);
            result.setOutlineColor(sf::Color::Black);
            result.setPosition(300, 160);

            sf::Text backToMenu;
            backToMenu.setFont(font);
            backToMenu.setString(L"Выйти из игры");
            backToMenu.setCharacterSize(30);
            backToMenu.setFillColor(sf::Color(237, 147, 0));
            backToMenu.setOutlineThickness(2);
            backToMenu.setOutlineColor(sf::Color::Black);
            backToMenu.setPosition(20, 790);

            sf::Text name1;
            name1.setFont(font);
            name1.setString(firstNamePlayer + "  VS  " + secondNamePlayer);
            name1.setCharacterSize(30);
            name1.setFillColor(sf::Color(237, 147, 0));
            name1.setOutlineThickness(2);
            name1.setOutlineColor(sf::Color::Black);
            name1.setPosition(790, 20);

            sf::Text draw;
            draw.setFont(font);
            draw.setString(L"Предложить ничью");
            backToMenu.setCharacterSize(30);
            draw.setFillColor(sf::Color(237, 147, 0));
            draw.setOutlineThickness(2);
            draw.setOutlineColor(sf::Color::Black);
            draw.setPosition(20, 880);



            ///////////////********************************************



            windowGame.clear();
            windowGame.draw(background_ab);
            windowGame.draw(time1);
            windowGame.draw(time2);
            windowGame.draw(rounds1);
            windowGame.draw(rounds2);
            windowGame.draw(resultText);
            windowGame.draw(result);
            windowGame.draw(restart);
            windowGame.draw(name1);
            windowGame.draw(backToMenu);
            windowGame.draw(draw);



            for (int i = 0; i < BOARD_SIZE; i++)
                for (int j = 0; j < BOARD_SIZE; j++)
                    pieces[i][j].setFillColor(sf::Color::Transparent);

            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board1[j][i] != nullptr && board1[j][i]->GetColor() == true) { // otdelynaya function pzlst
                        pieces[i][j].setRadius(TILE_SIZE / 2 - 10);
                        pieces[i][j].setFillColor(sf::Color::White);
                        pieces[i][j].setPosition(i * TILE_SIZE + 610, j * TILE_SIZE + 210);
                    }

                    if (board1[j][i] != nullptr && board1[j][i]->GetColor() == false) {
                        pieces[i][j].setRadius(TILE_SIZE / 2 - 10);
                        pieces[i][j].setFillColor(sf::Color::Black);
                        pieces[i][j].setPosition(i * TILE_SIZE + 610, j * TILE_SIZE + 210);
                    }
                }
            }

            for (int i = 0; i < BOARD_SIZE; i++)
            {
                for (int j = 0; j < BOARD_SIZE; j++)
                {
                    windowGame.draw(board[i][j]);

                    if (pieces[i][j].getFillColor() != sf::Color::Transparent)
                        windowGame.draw(pieces[i][j]);
                }
            }


            windowGame.display();

        }

        return 0;

};

















int main()
{

    // Создаём окно windows
    RenderWindow window;
    window.create(sf::VideoMode::getDesktopMode(), L"Шашки", Style::Fullscreen);
    // Параметры: размер окна установить согласно текущему разрешению экрана
    // название моя игра, развернуть графическое окно на весь размер экрана


    // получаем текущий размер экрана
    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;

    //
    bool isStart = false;
    int CountUsers = 0;
    std::string  numberOfRound = "";
    int  typyOfCheckers = 0;
    int  color = 0;
    int complexity = 0;
    int hardlevel = 1;
    std::string firstNamePlayer = "guest1";
    std::string secondNamePlayer = "guest2";
    int wins1 = 0;
    int wins2 = 0;

    int widthScreen = sf::VideoMode::getDesktopMode().width;
    int hightScreen = sf::VideoMode::getDesktopMode().height;

    // Устанавливаем фон для графического окна
    // Создаём прямоугольник
    RectangleShape background(Vector2f(widthScreen, hightScreen));
    // Загружаем в прямоугольник текстуру с изображением 1111.jpg
    Texture texture_window;
    if (!texture_window.loadFromFile("images/1111.jpg")) return 4;
    background.setTexture(&texture_window);

    // Устанавливаем шрифт для названия игры
    Font font;
    if (!font.loadFromFile("font/troika.otf")) return 5;
    Text Titul;
    Titul.setFont(font);
    // Текст с названием игры
    InitText(Titul, widthScreen / 2 - 244, 50, L"Шашки", 150, Color(237, 147, 0), 3);

    // Название пунктов меню
    String name_menu[]{ L"Старт",L"Настройки", L"О игре",L"Выход"};

    // Объект игровое меню
    game::GameMenu mymenu(window, widthScreen / 2, hightScreen / 3, 4, name_menu, 100, 120);

    // Установка цвета элементов пунктов меню
    mymenu.setColorTextMenu(Color(237, 147, 0), Color::Red, Color::Black);
    // выравнивание по центру пунктов меню
    mymenu.AlignMenu(2);




    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) window.close();
            //if (event.type == Event::KeyPressed)
            //{
            if (IntRect(widthScreen / 2 - 110, hightScreen / 3 + hightScreen/7, 300, 90).contains(Mouse::getPosition(window)) &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) {  Options(hardlevel, firstNamePlayer, secondNamePlayer);
                std::cout<<hardlevel;
                std::cout<<firstNamePlayer;
                std::cout<<secondNamePlayer;
            }

                if (IntRect(widthScreen / 2 - 115, hightScreen / 3, 300, 90).contains(Mouse::getPosition(window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                    isStart = GamеStart(CountUsers, numberOfRound, typyOfCheckers, color);
                    std::string saveNumberOfRounds = numberOfRound;
                    if (CountUsers == 1) {
                        secondNamePlayer = "Bot4";
                    }
                    std::cout << typyOfCheckers;

                    /*
                     * while (numberOfRound != std::strtoint(numberOfRound))
                    if (typyOfCheckers == 1 && isStart == true) {
                        playRussianheckers();

                        isStart = false;
                    }
                     if (typyOfCheckers == 2 && isStart == true) {
                        playPoddavkiCheckers();

                        isStart = false;
                    }
                     if (typyOfCheckers == 4 && isStart == true) {
                        playWorldCheckers();

                        isStart = false;
                    }

                     */
                    int temp = 0;
                    while (typyOfCheckers == 3 && std::stoi(numberOfRound) != 0 && isStart == true && CountUsers == 2) {
                        temp = playEnglishCheckers(CountUsers, numberOfRound, color, firstNamePlayer, secondNamePlayer,
                                                   wins1, wins2);


                        //restart
                        if (temp == 44) {
                            temp = 0;
                            numberOfRound = saveNumberOfRounds;
                            wins1 = 0;
                            wins2 = 0;
                            //temp = playEnglishCheckers(CountUsers, numberOfRound, color,  firstNamePlayer, secondNamePlayer, wins1, wins2);
                            //isStart = false;
                        }

                        //Выход
                        if (temp == 10) {
                            isStart = false;
                            window.close();
                        }

                        //выйграл 1 но не последний раунд
                        if (temp == 11) {
                            temp = 0;
                            //temp = playEnglishCheckers(CountUsers, numberOfRound, color,  firstNamePlayer, secondNamePlayer, wins1, wins2);
                            //isStart = false;
                        }
                        //Выйграл2 но нне последний раунд
                        if (temp == 22) {
                            temp = 0;
                            //temp = playEnglishCheckers(CountUsers, numberOfRound, color,  firstNamePlayer, secondNamePlayer, wins1, wins2);
                            //isStart = false;
                        }

                        ///Выйграл окончательно 1
                        if (temp == 111) {
                            temp = 0;
                            temp = finalWin(1, firstNamePlayer, wins1, wins2);
                            isStart = false;
                        }
                        ///Выйграл окончательно 2
                        if (temp == 222) {
                            temp = 0;
                            temp = finalWin(2, secondNamePlayer, wins1, wins2);
                            isStart = false;
                        }
                        //restart
                        if (temp == 2) {
                            numberOfRound = saveNumberOfRounds;
                            temp = 0;
                            wins1 = 0;
                            wins2 = 0;
                            //temp = playEnglishCheckers(CountUsers, numberOfRound, color,  firstNamePlayer, secondNamePlayer, wins1, wins2);
                            //isStart = false;
                        }

                        //Выход
                        if (temp == 1) {
                            isStart = false;
                            window.close();
                        }
                        //Ничья
                        if (temp == 1123) {
                            isStart = false;
                            wins1 = 0;
                            wins2 = 0;
                            temp = finalWin(0, "Nobody", wins1, wins2);
                            window.close();
                        }

                    }
                }

                //if (event.key.code == Keyboard::Escape) window.close();
            //}







            /////////////************///////////



            if (IntRect(widthScreen / 2 - 110, hightScreen / 3 + 2 * (hightScreen/7), 300, 90).contains(Mouse::getPosition(window)) &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) { About_Game(); }
            if (IntRect(widthScreen / 2 - 110, hightScreen / 3 + 3 * (hightScreen/7), 300, 90).contains(Mouse::getPosition(window)) &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    bool exir = GoOut1();
                    if (exir == 1) {
                        window.close();

                    }
            }
            //if (event.key.code == Keyboard::Escape) { window.close(); }
        }



        /*
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyReleased)
            {
                // События выбра пунктов меню
                // нажати на клавиатуре стрелки вверх
                if (event.key.code == Keyboard::Up) { mymenu.MoveUp(); }
                // нажати на клавиатуре стрелки вниз
                if (event.key.code == Keyboard::Down) { mymenu.MoveDown(); }
                // нажати на клавиатуре клавиши Enter
                if (event.key.code == Keyboard::Return)
                {
                    // Переходим на выбранный пункт меню
                    switch (mymenu.getSelectedMenuNumber())
                    {
                        case 0:GamеStart();   break;
                        case 1:Options();     break;
                        case 2:About_Game();  break;
                        case 3:window.close(); break;

                    }

                }
            }
        }*/

        window.clear();
        window.draw(background);
        window.draw(Titul);
        mymenu.draw();
        window.display();
    }
    /*std::cout<<hardlevel;
    std::cout<<firstNamePlayer;
    std::cout<<secondNamePlayer;*/

    return 0;
}



bool GoOut1() {
    RenderWindow window;
    window.create(sf::VideoMode::getDesktopMode(), L"Шашки");
    ///sf::Window window(sf::VideoMode(500, 500), "Output Window&");
    Texture texture_window;
    if (!texture_window.loadFromFile("images/1111.jpg")) return 4;





    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;


    int widthScreen = sf::VideoMode::getDesktopMode().width;
    int hightScreen = sf::VideoMode::getDesktopMode().height;

    // Устанавливаем фон для графического окна
    // Создаём прямоугольник
    RectangleShape background(Vector2f(widthScreen, hightScreen));



    background.setTexture(&texture_window);

    int isPressed = 4;

    // Устанавливаем шрифт для названия игры
    Font font;
    if (!font.loadFromFile("font/troika.otf")) return 5;


    sf::Text question;
    question.setFont(font);
    question.setString(L"Выйти из игры");
    question.setCharacterSize(60);
    question.setFillColor(sf::Color(237, 147, 0));

    question.setPosition(750, 140);

    sf::Text yes;
    yes.setFont(font);
    yes.setString(L"Да");
    yes.setCharacterSize(45);
    yes.setFillColor(sf::Color::Black);

    yes.setPosition(700, 350);

    sf::Text no;
    no.setFont(font);
    no.setString(L"Нет");
    no.setCharacterSize(45);
    no.setFillColor(sf::Color::Black);

    no.setPosition(1200, 350);

    while (window.isOpen()) {


        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) window.close();
            }

            if ((IntRect(700, 350, 150, 60).contains(Mouse::getPosition(window))) &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                yes.setOutlineThickness(3);
                yes.setOutlineColor(sf::Color(237, 147, 0));
                no.setOutlineThickness(0);
                isPressed = 1;
                window.close();
            }


            if ((IntRect(1200, 350, 150, 60).contains(Mouse::getPosition(window))) &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                no.setOutlineThickness(3);
                no.setOutlineColor(sf::Color(237, 147, 0));
                yes.setOutlineThickness(0);
                isPressed = 0;
                window.close();
            }
        }

        window.clear();
        window.draw(background);
        window.draw(question);
        window.draw(yes);
        window.draw(no);
        window.display();

    }


    if (isPressed == 1) {
        window.close();
        return true;
    }
    else {
        window.close();
        return false;
    }


    return true;
}



// функция настройки текста
void InitText(Text& mtext, float xpos, float ypos, String str, int size_font,
              Color menu_text_color, int bord, Color border_color)
{
    mtext.setCharacterSize(size_font);
    mtext.setPosition(xpos, ypos);
    mtext.setString(str);
    mtext.setFillColor(menu_text_color);
    mtext.setOutlineThickness(bord);
    mtext.setOutlineColor(border_color);
}









int finalWin(int whoWin, std::string name, int wins1, int wins2) {
    RenderWindow window;
    window.create(sf::VideoMode::getDesktopMode(), L"Шашки");
    ///sf::Window window(sf::VideoMode(500, 500), "Output Window&");
    Texture texture_window;
    if (!texture_window.loadFromFile("images/1111.jpg")) return 4;


    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;


    int widthScreen = sf::VideoMode::getDesktopMode().width;
    int hightScreen = sf::VideoMode::getDesktopMode().height;

    // Устанавливаем фон для графического окна
    // Создаём прямоугольник
    RectangleShape background(Vector2f(widthScreen, hightScreen));


    background.setTexture(&texture_window);

    int isPressed = 4;

    // Устанавливаем шрифт для названия игры
    Font font;
    if (!font.loadFromFile("font/troika.otf")) return 5;


    sf::Text text1;
    text1.setFont(font);
    text1.setString(L"Выйграл: " + name);
    text1.setCharacterSize(40);
    text1.setFillColor(sf::Color(237, 147, 0));
    text1.setOutlineThickness(2);
    text1.setOutlineColor(sf::Color::Black);
    text1.setPosition(750, 150);

    sf::Text text2;
    text2.setFont(font);
    text2.setString(L"Поздравляем!!!!");
    text2.setCharacterSize(40);
    text2.setFillColor(sf::Color(237, 147, 0));
    text2.setOutlineThickness(2);
    text2.setOutlineColor(sf::Color::Black);
    text2.setPosition(750, 300);


    sf::Text text3;
    text3.setFont(font);
    text3.setString(L"Со счётом:");
    text3.setCharacterSize(40);
    text3.setFillColor(sf::Color(237, 147, 0));
    text3.setOutlineThickness(2);
    text3.setOutlineColor(sf::Color::Black);
    text3.setPosition(750, 225);

    sf::Text text4;
    text4.setFont(font);
    text4.setString(std::to_string(wins1) + ":" + std::to_string(wins2));
    text4.setCharacterSize(40);
    text4.setFillColor(sf::Color(237, 147, 0));
    text4.setOutlineThickness(2);
    text4.setOutlineColor(sf::Color::Black);
    text4.setPosition(990, 225);


    sf::Text backToMenu;
    backToMenu.setFont(font);
    backToMenu.setString(L"Выйти из игры");
    backToMenu.setCharacterSize(40);
    backToMenu.setFillColor(sf::Color(237, 147, 0));
    backToMenu.setOutlineThickness(2);
    backToMenu.setOutlineColor(sf::Color::Black);
    backToMenu.setPosition(450, 550);

    sf::Text restart;
    restart.setFont(font);
    restart.setString(L"Начать заново");
    restart.setCharacterSize(40);
    restart.setFillColor(sf::Color(237, 147, 0));
    restart.setOutlineThickness(2);
    restart.setOutlineColor(sf::Color::Black);
    restart.setPosition(1250, 550);


    while (window.isOpen()) {


        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) window.close();
            }

            if ((IntRect(540, 540, 250, 60).contains(Mouse::getPosition(window))) &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                isPressed = 1;
                //window.close();
            }


            if ((IntRect(1240, 540, 250, 60).contains(Mouse::getPosition(window))) &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                isPressed = 2;
                //window.close();
            }
        }

        window.clear();
        window.draw(background);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(backToMenu);
        window.draw(restart);
        window.display();

        if (isPressed == 1) {
            window.close();
            return 1;
        }
        if (isPressed == 2)  {
            window.close();
            return 2;
        }


    }
    return isPressed;
}


bool Draw() {
    RenderWindow window;
    window.create(sf::VideoMode::getDesktopMode(), L"Шашки");
    ///sf::Window window(sf::VideoMode(500, 500), "Output Window&");
    Texture texture_window;
    if (!texture_window.loadFromFile("images/1111.jpg")) return 4;


    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;


    int widthScreen = sf::VideoMode::getDesktopMode().width;
    int hightScreen = sf::VideoMode::getDesktopMode().height;

    // Устанавливаем фон для графического окна
    // Создаём прямоугольник
    RectangleShape background(Vector2f(widthScreen, hightScreen));


    background.setTexture(&texture_window);

    int isPressed = 4;

    // Устанавливаем шрифт для названия игры
    Font font;
    if (!font.loadFromFile("font/troika.otf")) return 5;


    sf::Text text1;
    text1.setFont(font);
    text1.setString(L"Вам предложили ничью. Вы согласны?");
    text1.setCharacterSize(48);
    text1.setFillColor(sf::Color(237, 147, 0));
    text1.setOutlineThickness(2);
    text1.setOutlineColor(sf::Color::Black);
    text1.setPosition(420, 150);

    sf::Text text2;
    text2.setFont(font);
    text2.setString(L"Да");
    text2.setCharacterSize(48);
    text2.setFillColor(sf::Color(237, 147, 0));
    text2.setOutlineThickness(2);
    text2.setOutlineColor(sf::Color::Black);
    text2.setPosition(400, 280);

    sf::Text text3;
    text3.setFont(font);
    text3.setString(L"Нет");
    text3.setCharacterSize(48);
    text3.setFillColor(sf::Color(237, 147, 0));
    text3.setOutlineThickness(2);
    text3.setOutlineColor(sf::Color::Black);
    text3.setPosition(1200, 280);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) window.close();
            }

            if ((IntRect(390, 270, 250, 60).contains(Mouse::getPosition(window))) &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                isPressed = 1;
            }

            if ((IntRect(1190, 270, 250, 60).contains(Mouse::getPosition(window))) &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                isPressed = 2;
            }
        }

        window.clear();
        window.draw(background);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.display();

        if (isPressed == 1) {
            window.close();
            return true;
        }
        if (isPressed == 2)  {
            window.close();
            return false;
        }
    }
    //return false;
    }





    int Pause() {
        RenderWindow window;
        window.create(sf::VideoMode::getDesktopMode(), L"Шашки");
        ///sf::Window window(sf::VideoMode(500, 500), "Output Window&");
        Texture texture_window;
        if (!texture_window.loadFromFile("images/1111.jpg")) return 4;


        float width = VideoMode::getDesktopMode().width;
        float height = VideoMode::getDesktopMode().height;


        int widthScreen = sf::VideoMode::getDesktopMode().width;
        int hightScreen = sf::VideoMode::getDesktopMode().height;

        // Устанавливаем фон для графического окна
        // Создаём прямоугольник
        RectangleShape background(Vector2f(widthScreen, hightScreen));


        background.setTexture(&texture_window);

        int isPressed = 4;

        // Устанавливаем шрифт для названия игры
        Font font;
        if (!font.loadFromFile("font/troika.otf")) return 5;

        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"Возобновить игру");
        text1.setCharacterSize(48);
        text1.setFillColor(sf::Color(237, 147, 0));
        text1.setOutlineThickness(2);
        text1.setOutlineColor(sf::Color::Black);
        text1.setPosition(700, 150);

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"Выйти из игры");
        text2.setCharacterSize(48);
        text2.setFillColor(sf::Color(237, 147, 0));
        text2.setOutlineThickness(2);
        text2.setOutlineColor(sf::Color::Black);
        text2.setPosition(700, 300);

        sf::Text text3;
        text3.setFont(font);
        text3.setString(L"Рестарт");
        text3.setCharacterSize(48);
        text3.setFillColor(sf::Color(237, 147, 0));
        text3.setOutlineThickness(2);
        text3.setOutlineColor(sf::Color::Black);
        text3.setPosition(700, 450);

        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {

                if (event.type == Event::Closed) window.close();
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::Escape) {
                        window.close();
                        return 1111;
                    }
                }

                if ((IntRect(690, 140, 250, 60).contains(Mouse::getPosition(window))) &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    isPressed = 1111;
                    window.close();
                }
                if ((IntRect(690, 290, 250, 60).contains(Mouse::getPosition(window))) &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    isPressed = 2222;
                    window.close();
                }
                if ((IntRect(690, 440, 250, 60).contains(Mouse::getPosition(window))) &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    isPressed = 3333;
                    window.close();
                }
            }

            window.clear();
            window.draw(background);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.display();
        }
        return 1111;
    }
