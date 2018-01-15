/*****************************
数据结构课程设计
杜佳豪 1552652
同济大学 软件工程

T4 N皇后问题 
通过回溯算法解决N皇后问题。 
*****************************/ 

#include "t4_nqueen.h"

int main()
{
	cout << "现有N*N的棋盘，放入N个皇后，要求所有皇后不在同一行、列和同一斜线上！\n\n请输入皇后的个数：";
	cin >> n;

	//建立棋盘;
	board = new int[n];
	for (int i = 0; i < n; i++)
		board[i] = -1;

	search();
	system("pause");
	return 0;
}

bool check(int x, int y) {
	for (int i = 0; i < x; i++)
		if (board[i] != -1 && (board[i] == y || abs(i - x) == abs(board[i] - y))) //满足同一行、列、对角线没有其它棋子 
			return false;
	return true;
}

void print() {	//输出棋盘 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; ++j)
			cout << ((board[i] == j) ? "X" : "0") << " ";
		cout << endl;
	}
	cout << endl;
}

void search() {	//回溯算法 
	bool flag;
	for (int i = 0; i < n; i++) {
		flag = false;
		for (int j = board[i] + 1; j < n; j++)
			if (check(i, j)) {
				board[i] = j;
				flag = true;
				break;
			}
		if (!flag) {
			if (i <= 0)
				break;
			board[i] = -1;
			i -= 2;
			
		}
		if (i == n - 1) {
			ansCount++;
			print();
			i--;
		}
	}
	cout << "\n共有" << ansCount << "种解法！";
}
