#pragma once

#include "candidate.h"

struct Node {
	Candidate item;
	Node *next = nullptr;
};

void prepare();
void chooseOperation();
void insertCandidate();
void deleteCandidate();
void searchCandidate();
void reviseCandidate();
void countCandidate();
void display();

bool insert(Node* source, int location);
bool deleteNode(int num);
Node* findNode(int num);


Node *pHead, *pTail;
int num, age, cCount, nCount;
std::string name, sex, type;