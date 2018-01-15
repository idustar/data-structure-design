#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

typedef int** Maze;

struct Attempt {
	int x;
	int y;
	enum DIRECTION next;
};

Maze maze;
enum DIRECTION { NONE, DOWN, RIGHT, UP, LEFT };
int dirX[]{ 0,1,0,-1,0 };
int dirY[]{ 0,0,1,0,-1 };
int sizeX = 0, sizeY = 0, stX, stY, teX, teY, top = 0;
Attempt* route;

bool mazeIn();
bool specialPointIn();
void search(int x1, int y1, int x2, int y2);
