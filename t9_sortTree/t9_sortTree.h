#pragma once
#include <iostream>

struct Tree {
	int value;
	Tree *left;
	Tree *right;
};

using namespace std;

Tree* root;

void start();
bool chooseOperation();
Tree* add(Tree* tree, int value);
bool find(Tree* tree, int value);
void show(Tree* tree, int layer);