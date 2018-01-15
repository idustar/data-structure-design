/*****************************
���ݽṹ�γ����
�żѺ� 1552652
ͬ�ô�ѧ �������

T4 N�ʺ����� 
ͨ�������㷨���N�ʺ����⡣ 
*****************************/ 

#include "t4_nqueen.h"

int main()
{
	cout << "����N*N�����̣�����N���ʺ�Ҫ�����лʺ���ͬһ�С��к�ͬһб���ϣ�\n\n������ʺ�ĸ�����";
	cin >> n;

	//��������;
	board = new int[n];
	for (int i = 0; i < n; i++)
		board[i] = -1;

	search();
	system("pause");
	return 0;
}

bool check(int x, int y) {
	for (int i = 0; i < x; i++)
		if (board[i] != -1 && (board[i] == y || abs(i - x) == abs(board[i] - y))) //����ͬһ�С��С��Խ���û���������� 
			return false;
	return true;
}

void print() {	//������� 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; ++j)
			cout << ((board[i] == j) ? "X" : "0") << " ";
		cout << endl;
	}
	cout << endl;
}

void search() {	//�����㷨 
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
	cout << "\n����" << ansCount << "�ֽⷨ��";
}
