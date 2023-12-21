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
