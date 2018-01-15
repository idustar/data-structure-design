#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int maxint = 10000000;

class Net {
public:
	int prim(string v_begin);
	void print() {
		if (lastPrim.empty()) {
			cout << "����δ������С�������������ɺ����ԡ�\n";
			return;
		}
		cout << "��С�������Ķ���ͱ�Ϊ��\n\n";
		for (auto i = lastPrim.begin(); i != lastPrim.end(); i++) {
			cout << "��" << i - lastPrim.begin() + 1 << "��: " << vertice_names[i->first] << "(" << i->second << ")\n";
		}
	}
	void buildNet(int n, string names[]);
	bool addEdge(string v1, string v2, int w);
	int count;
	map<string, int> vertices;
	string* vertice_names;
	int** g;
	vector<pair<int, int>> lastPrim;
};