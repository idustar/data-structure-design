/*****************************
数据结构课程设计
杜佳豪 1552652
同济大学 软件工程

T8 电网建设造价模拟系统 
根据给定电网构建最小生成树。 
*****************************/ 

#include "t8_electricNet.h"


int main() {
	start();
	Net* net = new Net();	//建立新的电网 
	while (net = chooseOperation(net)) { ; }
}

void start() {
	cout << "**      电网造价模拟系统      **\n"
		<< "================================\n"
		<< "** A --- 创建电网顶点         **\n"
		<< "** B --- 添加电网的边         **\n"
		<< "** C --- 构造最小生成树       **\n"
		<< "** D --- 显示最小生成树       **\n"
		<< "** E --- 退出程序             **\n"
		<< "================================\n";
}

Net* chooseOperation(Net* net) {
	cout << "\n请选择操作：";
	char oper;
	cin >> oper;
	int n;
	string v1, v2;
	switch (oper)
	{
	case 'A':	//创建电网顶点 
		net = new Net();
		n = 0;
		string *names;
		while (n <= 0) {
			cout << "请输入顶点的个数：";
			cin >> n;
		}
		cout << "请依次输入各顶点的名称：";
		names = new string[n];
		for (int i = 0; i < n; i++) {
			cin >> names[i];
		}
		net->buildNet(n, names);
		break;
	case 'B':	//添加电网的边 
		int w;
		n = 0;
		if (net->count < 2) {	//电网顶点未创建或不够 
				cout << "请先创建2个或更多电网顶点。\n";
				return net;
			}
		while (n <= 0) {
			cout << "请输入边的条数：";
			cin >> n;
		}
		for (int i = 0; i < n; i++) {		
			do {
				cout << "请输入两个顶点及边，用空格分隔：";
				cin >> v1 >> v2 >> w;
			} while (!net->addEdge(v1, v2, w));
		}
		break;
	case 'C':	//生成最小生成树 
		cout << "请输入起始顶点：";
		cin >> v1;
		int ans;
		if ((ans = net->prim(v1)) > 0 && ans < maxint)
			cout << "生成Prim最小生成树！最少耗费：" << ans << "。\n";
		else
			cout << "生成失败！\n";
		break;
	case 'D':	//显示最小生成树 
		net->print();
		break;
	case 'E':	//退出程序 
		cout << "感谢使用！\n";
		system("pause");
		exit(0);
		break;
	}
	return net;
}

