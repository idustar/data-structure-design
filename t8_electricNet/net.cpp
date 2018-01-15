#include "net.h"

int Net::prim(string v_begin)	//用prim算法生成最小生成树 
{
	lastPrim.clear();	//初始化lastPrim 
	if (vertices.count(v_begin) == 0) {
		cout << "您输入的顶点名不存在。请重新输入。";
		return -1;
	}

	int min, sum = 0;
	bool *visited = new bool[count];
	int *distance = new int[count];
	int begin = vertices[v_begin];

	int now = begin;
	for (int i = 0; i < count; i++) {
		distance[i] = g[now][i];
		visited[i] = false;
	}
	visited[begin] = true;	//节点染色 

	for (int i = 0; i < count - 1; i++)
	{
		min = maxint;
		//找到最小边 
		for (int j = 0; j < count; j++) {
			if (!visited[j] && distance[j] < min) {
				min = distance[j];
				now = j;
			}
		}
		lastPrim.push_back(pair<int, int>(now, min));
		sum += min;
		visited[now] = true;
		//替换最小边权distance[i] 
		for (int j = 0; j < count; j++)
			if (!visited[j] && g[now][j]<distance[j])
				distance[j] = g[now][j];
	}
	return sum;
}

void Net::buildNet(int n, string names[])	//建立电网 
{
	count = n;
	vertice_names = new string[count];
	for (int i = 0; i < n; i++) {
		vertices.insert(pair<string, int>(names[i], i));
		vertice_names[i] = names[i];
	}
	g = new int*[n];
	for (int i = 0; i < n; i++)
		g[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j)
				g[i][j] = 0;
			else
				g[i][j] = maxint;
		}
}

bool Net::addEdge(string v1, string v2, int w)	//添加边 
{
	if (vertices.count(v1) == 0 || vertices.count(v2) == 0) {
		cout << "您输入的顶点名不存在。请重新输入。\n";
		return false;
	}
	if (w <= 0) {
		cout << "您输入的边不合法。请重新输入。\n";
		return false;
	}
	if (v1 == v2) {
		cout << "必须为两个不同顶点。请重新输入。\n";
		return false;
	}
	if (g[vertices[v1]][vertices[v2]] != maxint) {
		cout << "警告：您的这次添加操作将覆盖" << v1 << "和" << v2 << "原有的边。请确认(Y/N)：";
		char ch;
		cin >> ch;
		while (ch != 'Y' && ch != 'N') {
			cout << "请确认(Y/N)：";
			cin >> ch;
		}
		if (ch == 'N')
			return false;
	}
	g[vertices[v1]][vertices[v2]] = g[vertices[v2]][vertices[v1]] = w;
	return true;
}
