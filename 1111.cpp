int RussianShushuki(int& CountUsers, std::string& numberOfRound, int& color, std::string& firstNamePlayer, std::string& secondNamePlayer, int& wins1, int& wins2)
{
    Checker W1(7, 0, true);
    Checker W2(7, 2, true);
    Checker W3(7, 4, true);
    Checker W4(7, 6, true);
    Checker W5(6, 1, true);
    Checker W6(6, 3, true);
    Checker W7(6, 5, true);
    Checker W8(6, 7, true, true);
    Checker W9(5, 0, true, true);
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
    Checker B9(2, 1, false, true);
    Checker B10(2, 3, false, true);
    Checker B11(2, 5, false, true);
    Checker B12(2, 7, false, true);
    Checker*** board1 = new Checker * *[8];
    for (int i = 0; i < 8; ++i)
    {
        board1[i] = new Checker * [8];
        for (int j = 0; j < 8; ++j)
            board1[i][j] = nullptr;
    }
    /*board1[7][0] = &W1; board1[7][2] = &W2; board1[7][4] = &W3; board1[7][6] = &W4; board1[6][1] = &W5; board1[6][3] = &W6; board1[6][5] = &W7;*/ board1[6][7] = &W8;  board1[5][0] = &W9; board1[5][2] = &W10; board1[5][4] = &W11; board1[5][6] = &W12;
    board1[0][1] = &B1; board1[0][3] = &B2; board1[0][5] = &B3; board1[0][7] = &B4; board1[1][0] = &B5; board1[1][2] = &B6; board1[1][4] = &B7; board1[1][6] = &B8; board1[2][1] = &B9; board1[2][3] = &B10; board1[2][5] = &B11; board1[2][7] = &B12;

    sf::RenderWindow windowGame(sf::VideoMode::getDesktopMode(), "Russian Checkers Game");
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
            board[i][j].setPosition(i * TILE_SIZE + 600, j * TILE_SIZE + 200);                                          /////////////////////*********/////////
        }
    }


    int* selectedPos = new int [2] {-1, -1};
    vector<int*> moves;
    vector<int*> attackMoves;
    bool turn = true;
    bool repeatAttack = false;
    Clock clock;
    Clock tempTime;
    Clock gameTimeClock;//переменная игрового времени, будем здесь хранить время игры
    int gameTime = 0;//объявили игровое время, инициализировали.
    int rounds = std::stoi(numberOfRound);
    bool idk = color == 1 ? false : true;

    while (windowGame.isOpen()) {
        gameTime = gameTimeClock.getElapsedTime().asSeconds();//игровое время в секундах
        float time = clock.getElapsedTime().asMicroseconds();


        sf::Event eventGame;

        while (windowGame.pollEvent(eventGame)) {
            if (eventGame.type == sf::Event::Closed)
                windowGame.close();

            if (eventGame.type == Event::KeyPressed)
            {
                int* goPos = new int[2] {};
                if (CountUsers == 1 && turn == idk)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                {
                    std::vector<int*> attackers;
                    for (int i = 0; i < 8; i++)
                        for (int j = 0; j < 8; j++)
                            if (board1[i][j] != nullptr && board1[i][j]->GetColor() == turn && ((board1[i][j]->GetAttackMoves(board1, 8, !turn).size() != 0) || ((board1[i][j]->GetAttackMoves(board1, 8, turn).size() != 0) || ((board1[i][j]->GetAttackMoves(board1, 8, !turn, true)).size() != 0))))
                                attackers.push_back(new int[2] {i, j });
                    std::vector<int*> movers;
                    for (int i = 0; i < 8; i++)
                        for (int j = 0; j < 8; j++)
                            if (board1[i][j] != nullptr && board1[i][j]->GetColor() == turn && (board1[i][j]->GetMoves(board1, 8, !turn, true).size() != 0))
                                movers.push_back(new int[2] {i, j});

                    if (int size = attackers.size() != 0)
                    {
                        ///рандом на атакеров;
                        //выбор рандомного атакующего
                        if (!repeatAttack)
                        {
                            selectedPos = attackers[rand() % size];
                        }

                        if (board1[selectedPos[0]][selectedPos[1]]->isQueen()) {
                            // выбор рандомного хода данной шашки
                            attackMoves = board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 8, turn, true);
                            int attackArrSize = attackMoves.size();
                            goPos = board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 8, turn, true)[rand() % attackArrSize];
                        }
                        else {
                            // выбор рандомного хода данной шашки
                            attackMoves = VectorSum(board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 8, !turn, true), board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 8, turn, true));
                            int attackArrSize = attackMoves.size();
                            goPos = VectorSum(board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 8, !turn, true), board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 8, turn, true))[rand() % attackArrSize];
                        }

                    }
                    else if (int size = movers.size() != 0)
                    {
                        selectedPos = movers[rand() % size];
                        moves = board1[selectedPos[0]][selectedPos[1]]->GetMoves(board1, 8, !turn, true);
                        int movesArrSize = moves.size();
                        goPos = moves[rand() % movesArrSize];
                        // аналогично

                    }
                    else {/// нет ходов гы.
                        return idk ? 2222 : 1111;
                    }
                }


                sf::Vector2i mousePos = sf::Mouse::getPosition(windowGame);
                sf::Vector2i boardPos = (mousePos / TILE_SIZE);
                int* pos = new int[2] {((mousePos.y - 200) / TILE_SIZE), ((mousePos.x - 600) / TILE_SIZE) };
                // Проверка на наличие атаки
                bool hasAttack = false;
                for (int i = 0; i < BOARD_SIZE; i++)
                    for (int j = 0; j < BOARD_SIZE; j++)
                        if (board1[i][j] != nullptr && board1[i][j]->GetColor() == turn && ((board1[i][j]->GetAttackMoves(board1, 8, !turn).size() != 0) || ((board1[i][j]->GetAttackMoves(board1, 8, turn).size() != 0) || ((board1[i][j]->GetAttackMoves(board1, 8, !turn, true)).size() != 0))))
                            hasAttack = true;
                if (isPieceSelected && (inArray(moves, pos) || inArray(attackMoves, pos)) && pos[0] >= 0 && pos[1] >= 0 && pos[0] < 8 && pos[1] < 8 && board1[pos[0]][pos[1]] == nullptr || (CountUsers == 1 && turn == idk))
                {

                    if (CountUsers == 1 && turn == idk)
                    {
                        pos = goPos;
                    }

                    bool isAttack = inArray(attackMoves, pos); // передвижение / взятие
                    board1[selectedPos[0]][selectedPos[1]]->moveTo(board1, pos[0], pos[1], isAttack, 8);
                    hasAttack = false;
                    if (turn && pos[0] == 0)
                    {
                        board1[pos[0]][pos[1]]->SetQueen();
                    }
                    else if (!turn && pos[0] == 7)
                    {
                        board1[pos[0]][pos[1]]->SetQueen();
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
                    if (board1[pos[0]][pos[1]] != nullptr && turn == board1[pos[0]][pos[1]]->GetColor() && !repeatAttack && (!hasAttack || ((board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, !turn).size() != 0) || ((board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, turn)).size() != 0 || (board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, !turn, true).size() != 0)))))
                    {

                        isPieceSelected = true;
                        selectedPos = new int[2] {pos[0], pos[1]};

                        if (!hasAttack)
                        {
                            moves = board1[pos[0]][pos[1]]->GetMoves(board1, 8, !turn, true);

                            for (int i = 0; i < moves.size(); ++i)
                                board[moves[i][1]][moves[i][0]].setFillColor(sf::Color::Blue);
                        }
                        else
                        {
                            attackMoves = VectorSum(board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, !turn), board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, turn));

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
            continue;
        }


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
}





int RussianGiveIn(int& CountUsers, std::string& numberOfRound, int& color, std::string& firstNamePlayer, std::string& secondNamePlayer, int& wins1, int& wins2)
{
    Checker W1(7, 0, true);
    Checker W2(7, 2, true);
    Checker W3(7, 4, true);
    Checker W4(7, 6, true);
    Checker W5(6, 1, true);
    Checker W6(6, 3, true);
    Checker W7(6, 5, true);
    Checker W8(6, 7, true, true);
    Checker W9(5, 0, true, true);
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
    Checker B9(2, 1, false, true);
    Checker B10(2, 3, false, true);
    Checker B11(2, 5, false, true);
    Checker B12(2, 7, false);
    Checker*** board1 = new Checker * *[8];
    for (int i = 0; i < 8; ++i)
    {
        board1[i] = new Checker * [8];
        for (int j = 0; j < 8; ++j)
            board1[i][j] = nullptr;
    }
    /*board1[7][0] = &W1; board1[7][2] = &W2; board1[7][4] = &W3; board1[7][6] = &W4; board1[6][1] = &W5; board1[6][3] = &W6; board1[6][5] = &W7;*/ /*board1[6][7] = &W8;  board1[5][0] = &W9; board1[5][2] = &W10; board1[5][4] = &W11; */board1[5][6] = &W12;
    /*board1[0][1] = &B1; board1[0][3] = &B2; board1[0][5] = &B3; board1[0][7] = &B4; board1[1][0] = &B5; board1[1][2] = &B6; board1[1][4] = &B7; board1[1][6] = &B8; board1[2][1] = &B9; board1[2][3] = &B10; board1[2][5] = &B11;*/ board1[1][6] = &B12;

    //sf::RenderWindow window(sf::VideoMode(BOARD_SIZE * TILE_SIZE, BOARD_SIZE * TILE_SIZE), "Checkers Game");
    sf::RenderWindow windowGame(sf::VideoMode::getDesktopMode(), "Russian Checkers Game");
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
            board[i][j].setPosition(i * TILE_SIZE + 600, j * TILE_SIZE + 200);                                          /////////////////////*********/////////
        }
    }
    int* selectedPos = new int [2] {-1, -1};
    vector<int*> moves;
    vector<int*> attackMoves;
    bool turn = true;
    bool repeatAttack = false;
    Clock clock;
    Clock tempTime;
    Clock gameTimeClock;//переменная игрового времени, будем здесь хранить время игры
    int gameTime = 0;//объявили игровое время, инициализировали.
    int rounds = std::stoi(numberOfRound);

    while (windowGame.isOpen()) {
        gameTime = gameTimeClock.getElapsedTime().asSeconds();//игровое время в секундах
        float time = clock.getElapsedTime().asMicroseconds();


        sf::Event eventGame;

        while (windowGame.pollEvent(eventGame)) {
            if (eventGame.type == sf::Event::Closed)
                windowGame.close();

            if (eventGame.type == Event::KeyPressed)
            {
                if (eventGame.key.code == Keyboard::Escape) {
                    //int tempTime = gameTimeClock.getElapsedTime().asSeconds();
                    tempTime = gameTimeClock;
                    gameTimeClock = clock;
                    int action = Pause();
                    if (action == 1111) {
                        //gameTime = tempTime;
                        gameTimeClock = tempTime;
                    }
                    if (action == 2222) {
                        windowGame.close();
                        return 10;
                    }
                    if (action == 3333) {
                        gameTime = 0;
                        windowGame.close();
                        return 44;
                    }

                    gameTimeClock = tempTime;
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

                    bool idk = false;
                    int* goPos = new int[2] {};
                    if (CountUsers == 1 && turn == idk)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    {
                        std::vector<int*> attackers;
                        for (int i = 0; i < 8; i++)
                            for (int j = 0; j < 8; j++)
                                if (board1[i][j] != nullptr && board1[i][j]->GetColor() == turn && ((board1[i][j]->GetAttackMoves(board1, 8, !turn).size() != 0) || ((board1[i][j]->GetAttackMoves(board1, 8, turn).size() != 0) || ((board1[i][j]->GetAttackMoves(board1, 8, !turn, true)).size() != 0))))
                                    attackers.push_back(new int[2] {i, j });
                        std::vector<int*> movers;
                        for (int i = 0; i < 8; i++)
                            for (int j = 0; j < 8; j++)
                                if (board1[i][j] != nullptr && board1[i][j]->GetColor() == turn && (board1[i][j]->GetMoves(board1, 8, !turn, true).size() != 0))
                                    movers.push_back(new int[2] {i, j});
                        if (int size = attackers.size() != 0)
                        {
                            ///рандом на атакеров;
                            //выбор рандомного атакующего
                            if (!repeatAttack)
                            {
                                selectedPos = attackers[rand() % size];
                            }

                            if (board1[selectedPos[0]][selectedPos[1]]->isQueen()) {
                                // выбор рандомного хода данной шашки
                                attackMoves = board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 8, turn, true);
                                int attackArrSize = attackMoves.size();
                                goPos = board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 8, turn, true)[rand() % attackArrSize];
                            }
                            else {
                                // выбор рандомного хода данной шашки
                                attackMoves = VectorSum(board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 8, !turn, true), board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 8, turn, true));
                                int attackArrSize = attackMoves.size();
                                goPos = VectorSum(board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 8, !turn, true), board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 8, turn, true))[rand() % attackArrSize];
                            }

                        }
                        else if (int size = movers.size() != 0)
                        {
                            selectedPos = movers[rand() % size];
                            moves = board1[selectedPos[0]][selectedPos[1]]->GetMoves(board1, 8, !turn, true);
                            int movesArrSize = moves.size();
                            goPos = moves[rand() % movesArrSize];
                            // аналогично

                        }
                        else {/// нет ходов гы.
                            return idk ? 1111 : 2222;
                        }
                    }

                    sf::Vector2i mousePos = sf::Mouse::getPosition(windowGame);
                    sf::Vector2i boardPos = (mousePos / TILE_SIZE);
                    int* pos = new int[2] {((mousePos.y - 200) / TILE_SIZE), ((mousePos.x - 600) / TILE_SIZE) };
                    // Проверка на наличие атаки
                    bool hasAttack = false;
                    for (int i = 0; i < BOARD_SIZE; i++)
                        for (int j = 0; j < BOARD_SIZE; j++)
                            if (board1[i][j] != nullptr && board1[i][j]->GetColor() == turn && ((board1[i][j]->GetAttackMoves(board1, 8, !turn).size() != 0) || ((board1[i][j]->GetAttackMoves(board1, 8, turn).size() != 0) || ((board1[i][j]->GetAttackMoves(board1, 8, !turn, true)).size() != 0))))
                                hasAttack = true;
                    if (isPieceSelected && (inArray(moves, pos) || inArray(attackMoves, pos)) && pos[0] >= 0 && pos[1] >= 0 && pos[0] < 8 && pos[1] < 8 && board1[pos[0]][pos[1]] == nullptr || (CountUsers == 1 && turn == idk))
                    {

                        if (CountUsers == 1 && turn == idk)
                        {
                            pos = goPos;
                        }

                        bool isAttack = inArray(attackMoves, pos); // передвижение / взятие
                        board1[selectedPos[0]][selectedPos[1]]->moveTo(board1, pos[0], pos[1], isAttack, 8);
                        hasAttack = false;
                        if (turn && pos[0] == 0)
                        {
                            board1[pos[0]][pos[1]]->SetQueen();
                        }
                        else if (!turn && pos[0] == 7)
                        {
                            board1[pos[0]][pos[1]]->SetQueen();
                        }

                        if (isAttack && ((attackMoves = VectorSum(board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, !turn, true), board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, turn, true))).size() != 0))
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

                            for (int i = 0; i < attackMoves.size(); ++i)
                                board[attackMoves[i][1]][attackMoves[i][0]].setFillColor(sf::Color::Yellow);
                            board[pos[1]][pos[0]].setFillColor(sf::Color::Green); // Добавить кнопку отмены хода.

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
                        if (board1[pos[0]][pos[1]] != nullptr && turn == board1[pos[0]][pos[1]]->GetColor() && !repeatAttack && (!hasAttack || ((board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, !turn).size() != 0) || ((board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, turn)).size() != 0 || (board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, !turn, true).size() != 0)))))
                        {

                            isPieceSelected = true;
                            selectedPos = new int[2] {pos[0], pos[1]};

                            if (!hasAttack)
                            {
                                moves = board1[pos[0]][pos[1]]->GetMoves(board1, 8, !turn, true);

                                for (int i = 0; i < moves.size(); ++i)
                                    board[moves[i][1]][moves[i][0]].setFillColor(sf::Color::Blue);
                            }
                            else
                            {
                                attackMoves = VectorSum(board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, !turn), board1[pos[0]][pos[1]]->GetAttackMoves(board1, 8, turn));

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






            int playInternationalCheckers(int& CountUsers, std::string& numberOfRound, int& color, std::string& firstNamePlayer, std::string& secondNamePlayer, int& wins1, int& wins2)
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
                Checker*** board1 = new Checker * *[10];
                for (int i = 0; i < 10; ++i)
                {
                    board1[i] = new Checker * [10];
                    for (int j = 0; j < 10; ++j)
                        board1[i][j] = nullptr;
                }
                board1[7][0] = &W1;/* board1[7][2] = &W2; board1[7][4] = &W3; board1[7][6] = &W4; board1[6][1] = &W5; board1[6][3] = &W6; board1[6][5] = &W7; board1[6][7] = &W8;  board1[5][0] = &W9; board1[5][2] = &W10; */ board1[5][4] = &W11; board1[5][6] = &W12;
                /*board1[0][1] = &B1; board1[0][3] = &B2; board1[0][5] = &B3; board1[0][7] = &B4; board1[1][0] = &B5; board1[1][2] = &B6; board1[1][4] = &B7; board1[1][6] = &B8; board1[2][1] = &B9; board1[2][3] = &B10; board1[2][5] = &B11;*/ board1[2][7] = &B12;

                //sf::RenderWindow window(sf::VideoMode(BOARD_SIZE * TILE_SIZE, BOARD_SIZE * TILE_SIZE), "Checkers Game");
                sf::RenderWindow windowGame(sf::VideoMode::getDesktopMode(), "English Checkers Game");
                RectangleShape background_ab(Vector2f(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));

                Texture texture_ab;
                if (!texture_ab.loadFromFile("images/1111.jpg")) exit(1);
                background_ab.setTexture(&texture_ab);

                Font font;
                if (!font.loadFromFile("font/troika.otf")) return -1;

                sf::RectangleShape board[10][10];
                sf::CircleShape pieces[10][10];

                bool isPieceSelected = false;
                sf::Vector2i selectedPiecePos;


                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        board[i][j].setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));

                        if ((i + j) % 2 == 0)
                            board[i][j].setFillColor(sf::Color::White);
                        else
                            board[i][j].setFillColor(sf::Color::Red);
                        board[i][j].setPosition(i * TILE_SIZE + 600, j * TILE_SIZE + 200);                                          /////////////////////*********/////////
                    }
                }
                int* selectedPos = new int [2] {-1, -1};
                vector<int*> moves;
                vector<int*> attackMoves;
                bool turn = true;
                bool repeatAttack = false;
                Clock clock;
                Clock tempTime;
                Clock gameTimeClock;//переменная игрового времени, будем здесь хранить время игры
                int gameTime = 0;//объявили игровое время, инициализировали.
                int rounds = std::stoi(numberOfRound);

                while (windowGame.isOpen()) {
                    gameTime = gameTimeClock.getElapsedTime().asSeconds();//игровое время в секундах
                    float time = clock.getElapsedTime().asMicroseconds();


                    sf::Event eventGame;

                    while (windowGame.pollEvent(eventGame)) {
                        if (eventGame.type == sf::Event::Closed)
                            windowGame.close();

                        if (eventGame.type == Event::KeyPressed)
                        {
                            if (eventGame.key.code == Keyboard::Escape) {
                                //int tempTime = gameTimeClock.getElapsedTime().asSeconds();
                                tempTime = gameTimeClock;
                                gameTimeClock = clock;
                                int action = Pause();
                                if (action == 1111) {
                                    //gameTime = tempTime;
                                    gameTimeClock = tempTime;
                                }
                                if (action == 2222) {
                                    windowGame.close();
                                    return 10;
                                }
                                if (action == 3333) {
                                    gameTime = 0;
                                    windowGame.close();
                                    return 44;
                                }

                                gameTimeClock = tempTime;
                            }


                            if (eventGame.type == sf::Event::MouseButtonPressed) {

                                if (eventGame.mouseButton.button == sf::Mouse::Left) {



                                    if (!repeatAttack)
                                    {
                                        for (int i = 0; i < 10; i++)
                                        {
                                            for (int j = 0; j < 10; j++)
                                            {
                                                if ((i + j) % 2 == 0)
                                                    board[i][j].setFillColor(sf::Color::White);
                                                else
                                                    board[i][j].setFillColor(sf::Color::Red);
                                            }
                                        }
                                    }
                                    bool idk = false;
                                    int* goPos = new int[2] {};
                                    if (CountUsers == 1 && turn == idk)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                    {
                                        std::vector<int*> attackers;
                                        for (int i = 0; i < 10; i++)
                                            for (int j = 0; j < 10; j++)
                                                if (board1[i][j] != nullptr && board1[i][j]->GetColor() == turn && ((board1[i][j]->GetAttackMoves(board1, 10, !turn).size() != 0) || (board1[i][j]->GetAttackMoves(board1, 10, !((board1[i][j]->isQueen() ^ turn))).size() != 0)))
                                                    attackers.push_back(new int[2] {i, j });
                                        std::vector<int*> movers;
                                        for (int i = 0; i < 10; i++)
                                            for (int j = 0; j < 10; j++)
                                                if (board1[i][j] != nullptr && board1[i][j]->GetColor() == turn && ((board1[i][j]->GetMoves(board1, 10, !turn).size() != 0) || (board1[i][j]->GetMoves(board1, 10, !((board1[i][j]->isQueen() ^ turn))).size() != 0)))
                                                    movers.push_back(new int[2] {i, j});
                                        if (int size = attackers.size() != 0)
                                        {
                                            ///рандом на атакеров;
                                            //выбор рандомного атакующего
                                            if (!repeatAttack)
                                            {
                                                selectedPos = attackers[rand() % size];
                                            }

                                            if (board1[selectedPos[0]][selectedPos[1]]->isQueen()) {
                                                // выбор рандомного хода данной шашки
                                                attackMoves = VectorSum(board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 10, turn), board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 10, !turn));
                                                int attackArrSize = attackMoves.size();
                                                goPos = VectorSum(board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 10, turn), board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 10, !turn))[rand() % attackArrSize];
                                            }
                                            else {
                                                // выбор рандомного хода данной шашки
                                                attackMoves = board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 10, !turn);
                                                int attackArrSize = attackMoves.size();
                                                goPos = board1[selectedPos[0]][selectedPos[1]]->GetAttackMoves(board1, 10, !turn)[rand() % attackArrSize];/*Непонятка с тёрном*/
                                            }

                                        }
                                        else if (int size = movers.size() != 0)
                                        {
                                            selectedPos = movers[rand() % size];
                                            moves = VectorSum(board1[selectedPos[0]][selectedPos[1]]->GetMoves(board1, 10, !turn), board1[selectedPos[0]][selectedPos[1]]->GetMoves(board1, 10, !(board1[selectedPos[0]][selectedPos[1]]->isQueen() ^ turn)));
                                            int movesArrSize = moves.size();
                                            goPos = moves[rand() % movesArrSize];
                                            // аналогично

                                        }
                                        else {/// нет ходов гы.
                                            return idk ? 2222 : 1111;
                                        }
                                    }
                                    sf::Vector2i mousePos = sf::Mouse::getPosition(windowGame);
                                    sf::Vector2i boardPos = (mousePos / TILE_SIZE);
                                    int* pos = new int[2] {((mousePos.y - 200) / TILE_SIZE), ((mousePos.x - 600) / TILE_SIZE) };
                                    // Проверка на наличие атаки
                                    bool hasAttack = false;
                                    for (int i = 0; i < 10; i++)
                                        for (int j = 0; j < 10; j++)
                                            if (board1[i][j] != nullptr && board1[i][j]->GetColor() == turn && ((board1[i][j]->GetAttackMoves(board1, 10, !turn).size() != 0) || (board1[i][j]->GetAttackMoves(board1, 10, !(board1[i][j]->isQueen() ^ turn)).size() != 0)))
                                                hasAttack = true;
                                    if (isPieceSelected && (inArray(moves, pos) || inArray(attackMoves, pos)) && pos[0] >= 0 && pos[1] >= 0 && pos[0] < 10 && pos[1] < 10 && board1[pos[0]][pos[1]] == nullptr || (CountUsers == 1 && turn == idk))
                                    {
                                        if (CountUsers == 1 && turn == idk)
                                        {
                                            pos = goPos;
                                        }

                                        bool isAttack = inArray(attackMoves, pos); // передвижение / взятие
                                        board1[selectedPos[0]][selectedPos[1]]->moveTo(board1, pos[0], pos[1], isAttack, 10);
                                        hasAttack = false;
                                        if (turn && pos[0] == 0)
                                        {
                                            board1[pos[0]][pos[1]]->SetQueen();
                                        }
                                        else if (!turn && pos[0] == 9)
                                        {
                                            board1[pos[0]][pos[1]]->SetQueen();
                                        }

                                        if (isAttack && (attackMoves = VectorSum(board1[pos[0]][pos[1]]->GetAttackMoves(board1, 10, !turn), board1[pos[0]][pos[1]]->GetAttackMoves(board1, 10, board1[pos[0]][pos[1]]->isQueen() ? turn : !turn))).size() != 0)
                                        {
                                            moves.clear();
                                            for (int i = 0; i < 10; i++) // в отдельную функцию.
                                            {
                                                for (int j = 0; j < 10; j++)
                                                {
                                                    if ((i + j) % 2 == 0)
                                                        board[i][j].setFillColor(sf::Color::White);
                                                    else
                                                        board[i][j].setFillColor(sf::Color::Red);
                                                }
                                            }
                                            selectedPos[0] = pos[0]; selectedPos[1] = pos[1];

                                            for (int i = 0; i < attackMoves.size(); ++i)
                                                board[attackMoves[i][1]][attackMoves[i][0]].setFillColor(sf::Color::Yellow);
                                            board[pos[1]][pos[0]].setFillColor(sf::Color::Green); // Добавить кнопку отмены хода.

                                            repeatAttack = true;
                                        }
                                        else
                                        {
                                            isPieceSelected = false; //конец хода.
                                            turn = !turn;
                                            repeatAttack = false;
                                            for (int i = 0; i < 10; i++) // в отдельную функцию.
                                            {
                                                for (int j = 0; j < 10; j++)
                                                {
                                                    if ((i + j) % 2 == 0)
                                                        board[i][j].setFillColor(sf::Color::White);
                                                    else
                                                        board[i][j].setFillColor(sf::Color::Red);
                                                }
                                            }
                                            /*moves.clear();
                                            attackMoves.clear();*/
                                        }
                                    }

                                    else {
                                        if (board1[pos[0]][pos[1]] != nullptr && turn == board1[pos[0]][pos[1]]->GetColor() && !repeatAttack && (!hasAttack || ((board1[pos[0]][pos[1]]->GetAttackMoves(board1, 10, !turn).size() != 0) || (board1[pos[0]][pos[1]]->GetAttackMoves(board1, 10, !(board1[pos[0]][pos[1]]->isQueen() ^ turn)).size() != 0))))
                                        {

                                            isPieceSelected = true;
                                            selectedPos = new int[2] {pos[0], pos[1]};

                                            if (!hasAttack)
                                            {
                                                moves = board1[pos[0]][pos[1]]->GetMoves(board1, 10, !turn);
                                                if (board1[pos[0]][pos[1]]->isQueen())
                                                    moves = VectorSum(board1[pos[0]][pos[1]]->GetMoves(board1, 10, turn), moves);

                                                for (int i = 0; i < moves.size(); ++i)
                                                    board[moves[i][1]][moves[i][0]].setFillColor(sf::Color::Blue);
                                            }
                                            else
                                            {
                                                attackMoves = board1[pos[0]][pos[1]]->GetAttackMoves(board1, 10, !turn);

                                                if (board1[pos[0]][pos[1]]->isQueen())
                                                    attackMoves = VectorSum(board1[pos[0]][pos[1]]->GetAttackMoves(board1, 10, turn), attackMoves);
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
                            for (int i = 0; i < 10; ++i)
                            {
                                for (int j = 0; j < 10; ++j)
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
                                continue;
                            }


                            for (int i = 0; i < 10; i++)
                                for (int j = 0; j < 10; j++)
                                    pieces[i][j].setFillColor(sf::Color::Transparent);

                            for (int i = 0; i < 10; i++) {
                                for (int j = 0; j < 10; j++) {
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

                            for (int i = 0; i < 10; i++)
                            {
                                for (int j = 0; j < 10; j++)
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




int playEnglishCheckers(int& CountUsers, std::string& numberOfRound, int& color, std::string& firstNamePlayer, std::string& secondNamePlayer, int& wins1, int& wins2)
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
    Checker W11(5, 4, true, true);
    Checker W12(5, 6, true, true);

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
    /*board1[7][0] = &W1; board1[7][2] = &W2; board1[7][4] = &W3; board1[7][6] = &W4; board1[6][1] = &W5; board1[6][3] = &W6; board1[6][5] = &W7; board1[6][7] = &W8;  board1[5][0] = &W9; board1[5][2] = &W10; */board1[5][4] = &W11; board1[5][6] = &W12;
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
            board[i][j].setPosition(i * TILE_SIZE + 600, j * TILE_SIZE + 200);                                          /////////////////////*********/////////
        }
    }
    int* selectedPos = new int [2] {-1, -1};
    vector<int*> moves;
    vector<int*> attackMoves;
    bool turn = true;
    bool repeatAttack = false;
    Clock clock;
    Clock tempTime;
    Clock gameTimeClock;//переменная игрового времени, будем здесь хранить время игры
    int gameTime = 0;//объявили игровое время, инициализировали.
    int rounds = std::stoi(numberOfRound);

    while (windowGame.isOpen()) {
        gameTime = gameTimeClock.getElapsedTime().asSeconds();//игровое время в секундах
        float time = clock.getElapsedTime().asMicroseconds();


        sf::Event eventGame;

        while (windowGame.pollEvent(eventGame)) {
            if (eventGame.type == sf::Event::Closed)
                windowGame.close();

            if (eventGame.type == Event::KeyPressed)
            {
                if (eventGame.key.code == Keyboard::Escape) {
                    //int tempTime = gameTimeClock.getElapsedTime().asSeconds();
                    tempTime = gameTimeClock;
                    gameTimeClock = clock;
                    int action = Pause();
                    if (action == 1111) {
                        //gameTime = tempTime;
                        gameTimeClock = tempTime;
                    }
                    if (action == 2222) {
                        windowGame.close();
                        return 10;
                    }
                    if (action == 3333) {
                        gameTime = 0;
                        windowGame.close();
                        return 44;
                    }

                    gameTimeClock = tempTime;
                }

            }
            gameTimeClock = tempTime;
            if (eventGame.key.code == Keyboard::F1) windowGame.close();
            //}

            if (eventGame.type == Event::Closed) windowGame.close();
            if (eventGame.type == Event::KeyPressed)
            {
                //if (eventGame.key.code == Keyboard::Escape) windowGame.close();
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
