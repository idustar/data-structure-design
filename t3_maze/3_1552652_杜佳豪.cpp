/*****************************
���ݽṹ�γ����
�żѺ� 1552652
ͬ�ô�ѧ �������

T3 �´��Թ���Ϸ 
Ѱ�Ҹ����Թ�ͨ·������� 
*****************************/ 

#include "t3_maze.h"

int main(int argc, const char * argv[]) {
	// insert code here...
	while (!mazeIn()){}
	route = new Attempt[sizeX*sizeY];
	search(stX,stY,teX,teY);
	system("pause");
	return 0;
}

bool mazeIn() {
	int count = 0;
	string str;
	char ch;
	cout << "�´��Թ�������Ϊ����\n\n������һ�������ʾ�Թ���x��ʾͨ·�������ַ�Ϊ�ϰ���\n��:\n#######\n#x#000#\n#x#0###";
	cout << "\n#xxx#0#\n#0#xxx#\n#0#0#x#\n#######\n\n�����������Թ��ĳ����������Ϳ���������";
	cin >> sizeX >> sizeY;
	while (!cin || sizeX <= 0 || sizeY <= 0)
	{
		while ((ch = getchar()) != '\n')
			continue;
		cout << "�����������������������Թ��ĳ����������Ϳ���������";
		cin.clear();
		cin >> sizeX >> sizeY;
	}

	cout << "�õģ������������" << sizeX << "X" << sizeY << "���Թ�����\n";
	maze = new int*[sizeX];
	for (int i = 0; i < sizeX; i++)
		maze[i] = new int[sizeY];
	
	for (int i = 0; i < sizeX; i++) {
		cin >> str;
		while (sizeY != str.length()) {
			cout << "���ݲ��Ϸ��������������" << i << "������(��0��ʼ��������";
			cin >> str;
		}
		for (int j = 0; j < sizeY; j++)
			maze[i][j] = str[j] == 'x' ? 1 : 0;
	}

	//����Ƿ�Ϸ�
	bool check = true;
	for (int i = 0; i < sizeY; i++) {
		if (maze[0][i])  check = false; 
		if (maze[sizeX - 1][i]) check = false;
	}
	for (int i = 0; i < sizeX; i++) {
		if (maze[i][0]) check = false;
		if (maze[i][sizeY - 1]) check = false;
	}

	if (!check) {
		cout << "�߽����Ϊ�ϰ�������Թ����Ϸ���\n";
		return false;
	}

	//Show
	cout << "\n[������Ҫ��ս���Թ�]\n     ��: ";
	for (int i = 0; i < sizeY; i++)
		cout << setw(2) << i % 100;
	cout << endl;
	for (int i = 0; i < sizeX; i++) {
		cout << "��" << setw(3) << i % 1000 << "��: ";
		for (int j = 0; j < sizeY; j++)
			if (maze[i][j] == 1)
				cout << "��";
			else
				cout << "��";
		cout << endl;
	}

	while (!specialPointIn()) {};

	return true;
}

bool specialPointIn() {
	char ch;
	cout << "\n�������������꣺";
	cin >> stX >> stY;
	while (!cin || stX < 0 || stY < 0 || stX >= sizeX || stY >= sizeY || !maze[stX][stY])
	{
		while ((ch = getchar()) != '\n')
			continue;
		cout << "����������ݲ�����Ϊ��㣬�����������������꣺";
		cin.clear();
		cin >> stX >> stY;
	}
	cout << "�������յ�����꣺";
	cin >> teX >> teY;
	while (!cin || teX < 0 || teY < 0 || teX >= sizeX || teY >= sizeY || !maze[teX][teY])
	{
		while ((ch = getchar()) != '\n')
			continue;
		cout << "����������ݲ�����Ϊ�յ㣬�����������յ�����꣺";
		cin.clear();
		cin >> teX >> teY;
	}
	if (teX == stX && teY == stY) {
		cout << "�����յ�һ��������ΪʲôҪ���ҽ���أ�\n";
		return false;
	}
	return true;
}

void search(int x1, int y1, int x2, int y2) {
	int x, y, next;
	bool flag; 
	route[top].x = x1;
	route[top].y = y1;
	route[top].next = DIRECTION::NONE;
	maze[x1][y1] = 2;
	while (top >= 0) {
		x = route[top].x;
		y = route[top].y;
		next = route[top].next;
		if (x == x2 && y == y2) {
			maze[x][y] = 7;
			cout << "\n[�ҳɹ��߳�����Թ�����]\n     ��: ";
			for (int i = 0; i < sizeY; i++)
				cout << setw(2) << i % 100;
			cout << endl;
			//����Թ���ͼ 
			for (int i = 0; i < sizeX; i++) {
				cout << "��" << setw(3) << i % 1000 << "��: ";
				for (int j = 0; j < sizeY; j++)
					switch (maze[i][j])
					{
					case 0:
						cout << "��"; break;
					case 1:
						cout << "��"; break;
					case 7:
						cout << "��"; break;
					case 3:
						cout << "��"; break;
					case 4:
						cout << "��"; break;
					case 5:
						cout << "��"; break;
					case 6:
						cout << "��"; break;
					default:
						break;
					}
						
				cout << endl;
			}

			//����Թ�·�� 
			cout << "�Թ�·�����£�\n";
			for (int i = 0; i < top; i++)
			{
				cout << "(" << route[i].x << "," << route[i].y << ") ---> ";
			}
			cout << "(" << route[top].x << "," << route[top].y << ")" << endl;
			return;
		}

		flag = false;
		//��������һ���������� 
		for (int i = next + 1; i <= 4; i++) {
			x = route[top].x + dirX[i];
			y = route[top].y + dirY[i];
			if (maze[x][y] == 1) {
				flag = true;
				route[top].next = DIRECTION(i);
				maze[route[top].x][route[top].y] = route[top].next + 2;
				top++;
				route[top].x = x;
				route[top].y = y;
				route[top].next = DIRECTION::NONE;
				//cout << "\t(" << route[top].x << "," << route[top].y  << ")" << i;
				break;
			}
		}

		if (!flag){
			maze[route[top].x][route[top].y] = 1;
			top--;
		}
	}
	cout << "û���ҵ�·����\n";
	char c;
	cin >> c;
}

