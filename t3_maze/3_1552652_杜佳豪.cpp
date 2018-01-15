/*****************************
数据结构课程设计
杜佳豪 1552652
同济大学 软件工程

T3 勇闯迷宫游戏 
寻找给定迷宫通路并输出。 
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
	cout << "勇闯迷宫，智者为王。\n\n（请用一个矩阵表示迷宫，x表示通路，其他字符为障碍）\n例:\n#######\n#x#000#\n#x#0###";
	cout << "\n#xxx#0#\n#0#xxx#\n#0#0#x#\n#######\n\n请依次输入迷宫的长（行数）和宽（列数）：";
	cin >> sizeX >> sizeY;
	while (!cin || sizeX <= 0 || sizeY <= 0)
	{
		while ((ch = getchar()) != '\n')
			continue;
		cout << "输入有误，请重新依次输入迷宫的长（行数）和宽（列数）：";
		cin.clear();
		cin >> sizeX >> sizeY;
	}

	cout << "好的，那请输入这个" << sizeX << "X" << sizeY << "的迷宫矩阵：\n";
	maze = new int*[sizeX];
	for (int i = 0; i < sizeX; i++)
		maze[i] = new int[sizeY];
	
	for (int i = 0; i < sizeX; i++) {
		cin >> str;
		while (sizeY != str.length()) {
			cout << "数据不合法，请重新输入第" << i << "行数据(从0开始计数）。";
			cin >> str;
		}
		for (int j = 0; j < sizeY; j++)
			maze[i][j] = str[j] == 'x' ? 1 : 0;
	}

	//检查是否合法
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
		cout << "边界必须为障碍物，您的迷宫不合法。\n";
		return false;
	}

	//Show
	cout << "\n[这是我要挑战的迷宫]\n     列: ";
	for (int i = 0; i < sizeY; i++)
		cout << setw(2) << i % 100;
	cout << endl;
	for (int i = 0; i < sizeX; i++) {
		cout << "第" << setw(3) << i % 1000 << "行: ";
		for (int j = 0; j < sizeY; j++)
			if (maze[i][j] == 1)
				cout << "　";
			else
				cout << "■";
		cout << endl;
	}

	while (!specialPointIn()) {};

	return true;
}

bool specialPointIn() {
	char ch;
	cout << "\n请输入起点的坐标：";
	cin >> stX >> stY;
	while (!cin || stX < 0 || stY < 0 || stX >= sizeX || stY >= sizeY || !maze[stX][stY])
	{
		while ((ch = getchar()) != '\n')
			continue;
		cout << "您输入的数据不能作为起点，请重新输入起点的坐标：";
		cin.clear();
		cin >> stX >> stY;
	}
	cout << "请输入终点的坐标：";
	cin >> teX >> teY;
	while (!cin || teX < 0 || teY < 0 || teX >= sizeX || teY >= sizeY || !maze[teX][teY])
	{
		while ((ch = getchar()) != '\n')
			continue;
		cout << "您输入的数据不能作为终点，请重新输入终点的坐标：";
		cin.clear();
		cin >> teX >> teY;
	}
	if (teX == stX && teY == stY) {
		cout << "起点和终点一样，那你为什么要找我解决呢？\n";
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
			cout << "\n[我成功走出这个迷宫啦！]\n     列: ";
			for (int i = 0; i < sizeY; i++)
				cout << setw(2) << i % 100;
			cout << endl;
			//输出迷宫地图 
			for (int i = 0; i < sizeX; i++) {
				cout << "第" << setw(3) << i % 1000 << "行: ";
				for (int j = 0; j < sizeY; j++)
					switch (maze[i][j])
					{
					case 0:
						cout << "■"; break;
					case 1:
						cout << "　"; break;
					case 7:
						cout << "终"; break;
					case 3:
						cout << "↓"; break;
					case 4:
						cout << "→"; break;
					case 5:
						cout << "↑"; break;
					case 6:
						cout << "←"; break;
					default:
						break;
					}
						
				cout << endl;
			}

			//输出迷宫路径 
			cout << "迷宫路径如下：\n";
			for (int i = 0; i < top; i++)
			{
				cout << "(" << route[i].x << "," << route[i].y << ") ---> ";
			}
			cout << "(" << route[top].x << "," << route[top].y << ")" << endl;
			return;
		}

		flag = false;
		//继续向下一个方向搜索 
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
	cout << "没有找到路径。\n";
	char c;
	cin >> c;
}

