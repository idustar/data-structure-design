#include "net.h"

int Net::prim(string v_begin)	//��prim�㷨������С������ 
{
	lastPrim.clear();	//��ʼ��lastPrim 
	if (vertices.count(v_begin) == 0) {
		cout << "������Ķ����������ڡ����������롣";
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
	visited[begin] = true;	//�ڵ�Ⱦɫ 

	for (int i = 0; i < count - 1; i++)
	{
		min = maxint;
		//�ҵ���С�� 
		for (int j = 0; j < count; j++) {
			if (!visited[j] && distance[j] < min) {
				min = distance[j];
				now = j;
			}
		}
		lastPrim.push_back(pair<int, int>(now, min));
		sum += min;
		visited[now] = true;
		//�滻��С��Ȩdistance[i] 
		for (int j = 0; j < count; j++)
			if (!visited[j] && g[now][j]<distance[j])
				distance[j] = g[now][j];
	}
	return sum;
}

void Net::buildNet(int n, string names[])	//�������� 
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

bool Net::addEdge(string v1, string v2, int w)	//��ӱ� 
{
	if (vertices.count(v1) == 0 || vertices.count(v2) == 0) {
		cout << "������Ķ����������ڡ����������롣\n";
		return false;
	}
	if (w <= 0) {
		cout << "������ı߲��Ϸ������������롣\n";
		return false;
	}
	if (v1 == v2) {
		cout << "����Ϊ������ͬ���㡣���������롣\n";
		return false;
	}
	if (g[vertices[v1]][vertices[v2]] != maxint) {
		cout << "���棺���������Ӳ���������" << v1 << "��" << v2 << "ԭ�еıߡ���ȷ��(Y/N)��";
		char ch;
		cin >> ch;
		while (ch != 'Y' && ch != 'N') {
			cout << "��ȷ��(Y/N)��";
			cin >> ch;
		}
		if (ch == 'N')
			return false;
	}
	g[vertices[v1]][vertices[v2]] = g[vertices[v2]][vertices[v1]] = w;
	return true;
}
