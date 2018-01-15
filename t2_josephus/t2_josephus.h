#pragma once

#include <iostream>

using namespace std;

int n, s, m, k;

struct Node
{
	int location;
	Node* next;
};

void prepare();
Node* createList();
Node* deleteNode(Node* head, int &location);
void printLiving(Node* head);