#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void read();
int kmp(string sub, string str, int next[]);
int* getNext(string key);

string article = "";
string key;
int key_length, key_count = 0;