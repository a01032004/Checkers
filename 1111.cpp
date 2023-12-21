#pragma once
#include <string> 
#include <vector> 
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "TaskApi.h"

using namespace std;
TASK_API vector<int*> VectorSum(vector<int*> vector1, vector<int*> vector2);
vector<int*> VectorSum(vector<int*> vector1, vector<int*> vector2)
{
	int size = vector1.size();
	for (int i = 0; i < size; ++i)
		vector2.push_back(vector1[i]);

	return vector2;
}
//TASK_API bool inArray(vector<int*> arr, int* element);
bool inArray(vector<int*> arr, int* element)
{
	for (int i = 0; i < arr.size(); ++i)
		if (element[0] == arr[i][0] && element[1] == arr[i][1])
			return true;
	return false;
}

TASK_API class Checker
{
private:
	int _x; // Вертикальная координата              (да, я 47%)
	int _y; // Горизонтальная координата			(да, я 53%)
	bool _isQueen;
	bool _isWhite;
public:
	Checker(int x, int y, bool isWhite, bool isQueen = 0) { _x = x; _y = y; _isWhite = isWhite; _isQueen = isQueen; };

	void moveTo(Checker*** board, int x, int y, bool isAttack, int size)
	{
		board[_x][_y] = nullptr;
		board[x][y] = this;

		/*if (isAttack)
		{
			board[x][y] = nullptr;
			board[x + ((x - _x) / abs(x - _x))][y + ((y - _y) / abs(y - _y))] = this;
		}*/
		if (isAttack)
		{
			for (int i = 1; i < size; ++i)
			{
				if (board[x - i * ((x - _x) / abs(x - _x))][y - i * ((y - _y) / abs(y - _y))] != nullptr)
				{
					board[x - i * ((x - _x) / abs(x - _x))][y - i * ((y - _y) / abs(y - _y))] = nullptr;
					break;
				}
			}
		}
		_x = x; _y = y;

	};

	vector<int*> RussianQueenAttackMoves(Checker*** board, int size)
	{
		vector<int*> coordsMoves;

		for (int i = 1; i + _x < size && i + _y < size; ++i)
		{
			if (board[_x + i][_y + i] != nullptr && board[_x + i][_y + i]->GetColor() != board[_x][_y]->GetColor())
			{
				for (int j = 1; j + i + _x < size && j + i + _y < size && board[_x + i + j][_y + i + j] == nullptr; ++j)
					coordsMoves.push_back(new int[2] {_x + i + j, _y + i + j});
				break;
			}
			else if (board[_x + i][_y + i] != nullptr && board[_x + i][_y + i]->GetColor() == board[_x][_y]->GetColor())
				break;
		}

		if (board[_x + i][_y - i] != nullptr && board[_x + i][_y - i]->GetColor() != board[_x][_y]->GetColor())
		{
			for (int j = 1; j + i + _x < size && _y - j - i >= 0 && board[_x + i + j][_y - j - i] == nullptr; ++j)
				coordsMoves.push_back(new int[2] {_x + i + j, _y - j - i});
			break;
		}
		else if (board[_x + i][_y - i] != nullptr && board[_x + i][_y - i]->GetColor() == board[_x][_y]->GetColor())
			break;

		for (int i = 1; _x - i >= 0 && i + _y < size; ++i)
			if (board[_x - i][_y + i] != nullptr && board[_x - i][_y + i]->GetColor() != board[_x][_y]->GetColor())
			{
				for (int j = 1; _x - i - j >= 0 && j + i + _y < size && board[_x - i - j][_y + i + j] == nullptr; ++j)
					coordsMoves.push_back(new int[2] {_x - i - j, _y + i + j});
				break;
			}
			else if (board[_x - i][_y + i] != nullptr && board[_x - i][_y + i]->GetColor() == board[_x][_y]->GetColor())
				break;