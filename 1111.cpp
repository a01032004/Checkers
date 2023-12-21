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