#include <iostream>
#include "menu.h"
#include "Checker.h"

using namespace sf;


// функция настройки текста
void InitText(Text& mtext, float xpos, float ypos, String str, int size_font = 60,
              Color menu_text_color = Color::White, int bord = 0, Color border_color = Color::Black);

// Функция перехода к игре  bool GamеStart(int CountUsers, std::string numberOfRound, int typyOfCheckers, int color)
bool GamеStart(int CountUsers, std::string numberOfRound, int typyOfCheckers, int color)
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
                if (event_play.key.code == Keyboard::Escape) { Play.close(); }
            }
        }



        Play.clear();
        Play.draw(background_play);
        Play.draw(countUser1);
        Play.draw(countUser2);
        Play.draw(CountOfUsers);
        Play.draw(CountORounds);
        Play.draw(typeOfPlay);
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
int Options()
{
    RenderWindow Options(VideoMode::getDesktopMode(), L"Настройки");

    RectangleShape background_opt(Vector2f(1920, 1080));

    Font font;
    if (!font.loadFromFile("font/troika.otf")) return -1;

    Texture texture_opt;
    if (!texture_opt.loadFromFile("images/1111.jpg")) exit(1);
    background_opt.setTexture(&texture_opt);


    int hardLevel = 1;
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
                hardLevel = 1;
                easy.setOutlineThickness(3);
                easy.setOutlineColor(sf::Color(237, 147, 0));

                medium.setOutlineThickness(0);
                hard.setOutlineThickness(0);
            }

            if ((IntRect(995, 95, 150, 60).contains(Mouse::getPosition(Options))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            {
                hardLevel = 2;
                medium.setOutlineThickness(3);
                medium.setOutlineColor(sf::Color(237, 147, 0));

                easy.setOutlineThickness(0);
                hard.setOutlineThickness(0);
            }

            if ((IntRect(1195, 95, 150, 60).contains(Mouse::getPosition(Options))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            {
                hardLevel = 3;
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
                if (event_opt.key.code == Keyboard::Escape) Options.close();
            }
        }
        Options.clear();
        Options.draw(background_opt);
        Options.draw(hardly);
        Options.draw(easy);
        Options.draw(medium);
        Options.draw(hard);
        Options.draw(save);
        Options.display();

        if (isPres == true )
        {
            Options.close();
            return hardLevel;
        }
    }

    return hardLevel;
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
                if (event_play.key.code == Keyboard::Escape) About.close();
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

int playCheckers()
{
    	Checker W1 (7, 0, true);
		Checker W2 (7, 2, true);
		Checker W3 (7, 4, true);
		Checker W4 (7, 6, true);
		Checker W5 (6, 1, true);
		Checker W6 (6, 3, true);
		Checker W7 (6, 5, true);
		Checker W8 (6, 7, true);
		Checker W9 (5, 0, true);
		Checker W10(5, 2, true);
		Checker W11(5, 4, true);
		Checker W12(5, 6, true);

		Checker B1 (0, 1, false);
		Checker B2 (0, 3, false);
		Checker B3 (0, 5, false);
		Checker B4 (0, 7, false);
		Checker B5 (1, 0, false);
		Checker B6 (1, 2, false);
		Checker B7 (1, 4, false);
		Checker B8 (1, 6, false);
		Checker B9 (2, 1, false);
		Checker B10(2, 3, false);
		Checker B11(2, 5, false);
		Checker B12(2, 7, false);
        Checker*** board1 = new Checker * *[8];
        for (int i = 0; i < 8; ++i)
       	{
       		board1[i] = new Checker* [8];
       		for (int j = 0; j < 8; ++j)
       			board1[i][j] = nullptr;
       	}
        board1[7][0] = &W1; board1[7][2] = &W2; board1[7][4] = &W3; board1[7][6] = &W4; board1[6][1] = &W5; board1[6][3] = &W6; board1[6][5] = &W7; board1[6][7] = &W8;  board1[5][0] = &W9; board1[5][2] = &W10; board1[5][4] = &W11; board1[5][6] = &W12;
        board1[0][1] = &B1; board1[0][3] = &B2; board1[0][5] = &B3; board1[0][7] = &B4; board1[1][0] = &B5; board1[1][2] = &B6; board1[1][4] = &B7; board1[1][6] = &B8; board1[2][1] = &B9; board1[2][3] = &B10; board1[2][5] = &B11; board1[2][7] = &B12;

    sf::RenderWindow window(sf::VideoMode(BOARD_SIZE * TILE_SIZE, BOARD_SIZE * TILE_SIZE), "Checkers Game");

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
                board[i][j].setFillColor(sf::Color::Magenta);
            board[i][j].setPosition(i * TILE_SIZE, j * TILE_SIZE);
        }
    }
    int* selectedPos = new int [2]{-1,-1};
    vector<int*> moves;
    vector<int*> attackMoves;
    bool turn = true;
    bool repeatAttack = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape) window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (!repeatAttack)
                    {
                        for (int i = 0; i < BOARD_SIZE; i++) // в отдельную функцию.
                        {
                            for (int j = 0; j < BOARD_SIZE; j++)
                            {
                                if ((i + j) % 2 == 0)
                                    board[i][j].setFillColor(sf::Color::White);
                                else
                                    board[i][j].setFillColor(sf::Color::Magenta);
                            }
                        }
                    }
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2i boardPos = (mousePos / TILE_SIZE);
                    int* pos = new int[2] {(mousePos.y / TILE_SIZE), mousePos.x / TILE_SIZE};
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
                                        board[i][j].setFillColor(sf::Color::Magenta);
                                }
                            }
                            selectedPos[0] = pos[0]; selectedPos[1] = pos[1];
                            //sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                            //sf::Vector2i boardPos = (mousePos / TILE_SIZE);
                            //int* pos = new int[2] {(mousePos.y / TILE_SIZE), mousePos.x / TILE_SIZE};
                            for (int i = 0; i < attackMoves.size(); ++i)
                                board[attackMoves[i][1]][attackMoves[i][0]].setFillColor(sf::Color::Red);
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
                                        board[i][j].setFillColor(sf::Color::Magenta);
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
                                board[attackMoves[i][1]][attackMoves[i][0]].setFillColor(sf::Color::Red);
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
            if (!isWhiteWon && !isBlackWon)
                continue;
            if (isWhiteWon)
                return 1;
            if (isBlackWon)
                return 2;
        }

        window.clear();
       for (int i = 0; i < BOARD_SIZE; i++) 
            for (int j = 0; j < BOARD_SIZE; j++) 
                pieces[i][j].setFillColor(sf::Color::Transparent);

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board1[j][i] != nullptr && board1[j][i]->GetColor() == true) { // otdelynaya function pzlst
                    pieces[i][j].setRadius(TILE_SIZE / 2 - 10);
                    pieces[i][j].setFillColor(sf::Color::White);
                    pieces[i][j].setPosition(i * TILE_SIZE + 10, j * TILE_SIZE + 10);
                }

                if (board1[j][i] != nullptr && board1[j][i]->GetColor() == false) {
                    pieces[i][j].setRadius(TILE_SIZE / 2 - 10);
                    pieces[i][j].setFillColor(sf::Color::Black);
                    pieces[i][j].setPosition(i * TILE_SIZE + 10, j * TILE_SIZE + 10);
                }
            }
        }

        for (int i = 0; i < BOARD_SIZE; i++) 
        {
            for (int j = 0; j < BOARD_SIZE; j++) 
            {
                window.draw(board[i][j]);

                if (pieces[i][j].getFillColor() != sf::Color::Transparent) 
                    window.draw(pieces[i][j]);
            }
        }
    

        window.display();
    }

    return 0;

};


// пока ничего не делал.
int RussianShushuki()
{
    Checker W1(7, 0, true);
    Checker W2(7, 2, true);
    Checker W3(7, 4, true);
    Checker W4(7, 6, true);
    Checker W5(6, 1, true);
    Checker W6(6, 3, true);
    Checker W7(6, 5, true);
    Checker W8(6, 7, true);
    Checker W9(5, 0, true);
    Checker W10(5, 2, true);
    Checker W11(5, 4, true);
    Checker W12(5, 6, true);

    Checker B1(0, 1, false);
    Checker B2(0, 3, false);
    Checker B3(0, 5, false);
    Checker B4(0, 7, false);
    Checker B5(1, 0, false);
    Checker B6(1, 2, false);
    Checker B7(1, 4, false);
    Checker B8(1, 6, false);
    Checker B9(2, 1, false);
    Checker B10(2, 3, false);
    Checker B11(2, 5, false);
    Checker B12(2, 7, false);
    Checker*** board1 = new Checker * *[8];
    for (int i = 0; i < 8; ++i)
    {
        board1[i] = new Checker * [8];
        for (int j = 0; j < 8; ++j)
            board1[i][j] = nullptr;
    }
    board1[7][0] = &W1; board1[7][2] = &W2; board1[7][4] = &W3; board1[7][6] = &W4; board1[6][1] = &W5; board1[6][3] = &W6; board1[6][5] = &W7; board1[6][7] = &W8;  board1[5][0] = &W9; board1[5][2] = &W10; board1[5][4] = &W11; board1[5][6] = &W12;
    board1[0][1] = &B1; board1[0][3] = &B2; board1[0][5] = &B3; board1[0][7] = &B4; board1[1][0] = &B5; board1[1][2] = &B6; board1[1][4] = &B7; board1[1][6] = &B8; board1[2][1] = &B9; board1[2][3] = &B10; board1[2][5] = &B11; board1[2][7] = &B12;

    sf::RenderWindow window(sf::VideoMode(BOARD_SIZE * TILE_SIZE, BOARD_SIZE * TILE_SIZE), "Checkers Game");

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
                board[i][j].setFillColor(sf::Color::Magenta);
            board[i][j].setPosition(i * TILE_SIZE, j * TILE_SIZE);
        }
    }
    int* selectedPos = new int [2] {-1, -1};
    vector<int*> moves;
    vector<int*> attackMoves;
    bool turn = true;
    bool repeatAttack = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape) window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (!repeatAttack)
                    {
                        for (int i = 0; i < BOARD_SIZE; i++) // в отдельную функцию.
                        {
                            for (int j = 0; j < BOARD_SIZE; j++)
                            {
                                if ((i + j) % 2 == 0)
                                    board[i][j].setFillColor(sf::Color::White);
                                else
                                    board[i][j].setFillColor(sf::Color::Magenta);
                            }
                        }
                    }
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2i boardPos = (mousePos / TILE_SIZE);
                    int* pos = new int[2] {(mousePos.y / TILE_SIZE), mousePos.x / TILE_SIZE};
                    if (isPieceSelected && (inArray(moves, pos) || inArray(attackMoves, pos)))
                    {
                        // Move the selected piece to the new position
                        //pieces[boardPos.x][boardPos.y] = pieces[selectedPiecePos.x][selectedPiecePos.y];
                        //pieces[selectedPiecePos.x][selectedPiecePos.y].setFillColor(sf::Color::Transparent);

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

                        if (isAttack && (attackMoves = VectorSum(board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, !turn), board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, board1[pos[0]][pos[1]]->isQueen() ? turn : !turn, true))).size() != 0)
                        {
                            moves.clear();
                            for (int i = 0; i < BOARD_SIZE; i++) // в отдельную функцию.
                            {
                                for (int j = 0; j < BOARD_SIZE; j++)
                                {
                                    if ((i + j) % 2 == 0)
                                        board[i][j].setFillColor(sf::Color::White);
                                    else
                                        board[i][j].setFillColor(sf::Color::Magenta);
                                }
                            }
                            selectedPos[0] = pos[0]; selectedPos[1] = pos[1];
                            //sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                            //sf::Vector2i boardPos = (mousePos / TILE_SIZE);
                            //int* pos = new int[2] {(mousePos.y / TILE_SIZE), mousePos.x / TILE_SIZE};
                            for (int i = 0; i < attackMoves.size(); ++i)
                                board[attackMoves[i][1]][attackMoves[i][0]].setFillColor(sf::Color::Red);
                            board[pos[1]][pos[0]].setFillColor(sf::Color::Green); // Добавить кнопку отмены хода.
                            /*if (inArray(attackMoves, pos))
                                board1[selectedPos[0]][selectedPos[1]]->moveTo(board1, pos[0], pos[1], isAttack, 8);
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
                                        board[i][j].setFillColor(sf::Color::Magenta);
                                }
                            }
                        }
                    }

                    else {
                        // Select the piece on the clicked position
                        //if (pieces[boardPos.x][boardPos.y].getFillColor() != sf::Color::Transparent)
                        if (board1[pos[0]][pos[1]] != nullptr && turn == board1[pos[0]][pos[1]]->GetColor() && !repeatAttack)
                        {
                            isPieceSelected = true;
                            selectedPos = new int[2] {pos[0], pos[1]};
                            moves = board1[pos[0]][pos[1]]->GetMoves(board1, 8, !turn);
                            attackMoves = board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, !turn);
                            if (board1[pos[0]][pos[1]]->isQueen())
                            {
                                moves = VectorSum(board1[pos[0]][pos[1]]->GetMoves(board1, 8, turn), moves);
                                attackMoves = VectorSum(board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, turn), attackMoves);
                            }
                            board[pos[1]][pos[0]].setFillColor(sf::Color::Green);
                            for (int i = 0; i < moves.size(); ++i)
                                board[moves[i][1]][moves[i][0]].setFillColor(sf::Color::Blue);
                            for (int i = 0; i < attackMoves.size(); ++i)
                                board[attackMoves[i][1]][attackMoves[i][0]].setFillColor(sf::Color::Red);
                        }
                    }
                }
            }
            return 0;
}




















/*
int main()
{

    // Создаём окно windows
    RenderWindow window;
    // Параметры: размер окна установить согласно текущему разрешению экрана
    // название моя игра, развернуть графическое окно на весь размер экрана
    window.create(sf::VideoMode::getDesktopMode(), L"Шашки", Style::Fullscreen);


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



            if (IntRect(widthScreen / 2 - 110, hightScreen / 3, 300, 90).contains(Mouse::getPosition(window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            { isStart = GamеStart(CountUsers, numberOfRound, typyOfCheckers, color); }
                //sf::Mouse::isButtonPressed(sf::Mouse::Left)) { isStart = GamеStart(CountUsers, numberOfRound, typyOfCheckers, color); }

            /////////////************///////////

            if (isStart == true) {
                playCheckers();
            }

            /////////////************///////////

            if (IntRect(widthScreen / 2 - 110, hightScreen / 3 + hightScreen/7, 300, 90).contains(Mouse::getPosition(window)) &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) { complexity = Options(); }
            if (IntRect(widthScreen / 2 - 110, hightScreen / 3 + 2 * (hightScreen/7), 300, 90).contains(Mouse::getPosition(window)) &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) { About_Game(); }
            if (IntRect(widthScreen / 2 - 110, hightScreen / 3 + 3 * (hightScreen/7), 300, 90).contains(Mouse::getPosition(window)) &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) { window.close(); }
            if (event.key.code == Keyboard::Escape) { window.close(); }
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

    return 0;
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