#pragma once
#include<iostream>
#include<string>
#include<stack>
#include<sstream>
#include<math.h>

using namespace std;

struct ExpressionTree {
	string data;
	ExpressionTree *left;
	ExpressionTree *right;
};

int Priority(char oper);
string transform(string str);
ExpressionTree* buildTree(string lastExpression);
void dlr(ExpressionTree* tree);
void lrd(ExpressionTree* tree);
