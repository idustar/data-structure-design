#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define TIMER (double)(end-start)/CLOCKS_PER_SEC
#define VIEW for (int i = 0; i < n - 1; i++) cout << num[i] << " ";

using namespace std;

void start();
int* copyArray(int n, int num[]);
void chooseOperation();

void swap(int &a, int &b);
bool compare(int a, int b);
int power10(int x);

void bubble(int n, int num[]);
void selection(int n, int num[]);
void insertion(int n, int num[]);
void shell(int n, int num[]);
void quick(int l, int r, int num[]);
void heap(int n, int num[]);
void merge(int l, int r, int num[]);
void radix(int n, int num[]);

int* num;
int n, swapTime, compareTime;

