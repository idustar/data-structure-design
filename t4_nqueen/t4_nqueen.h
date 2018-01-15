#pragma once

#include <iostream>

using namespace std;

int n, ansCount, *board;

bool check(int x, int y);
void print();
void search();