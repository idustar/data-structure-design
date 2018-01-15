/*****************************
���ݽṹ�γ����
�żѺ� 1552652
ͬ�ô�ѧ �������

T8 �����������ģ��ϵͳ 
���ݸ�������������С�������� 
*****************************/ 

#include "t8_electricNet.h"


int main() {
	start();
	Net* net = new Net();	//�����µĵ��� 
	while (net = chooseOperation(net)) { ; }
}

void start() {
	cout << "**      �������ģ��ϵͳ      **\n"
		<< "================================\n"
		<< "** A --- ������������         **\n"
		<< "** B --- ��ӵ����ı�         **\n"
		<< "** C --- ������С������       **\n"
		<< "** D --- ��ʾ��С������       **\n"
		<< "** E --- �˳�����             **\n"
		<< "================================\n";
}

Net* chooseOperation(Net* net) {
	cout << "\n��ѡ�������";
	char oper;
	cin >> oper;
	int n;
	string v1, v2;
	switch (oper)
	{
	case 'A':	//������������ 
		net = new Net();
		n = 0;
		string *names;
		while (n <= 0) {
			cout << "�����붥��ĸ�����";
			cin >> n;
		}
		cout << "�������������������ƣ�";
		names = new string[n];
		for (int i = 0; i < n; i++) {
			cin >> names[i];
		}
		net->buildNet(n, names);
		break;
	case 'B':	//��ӵ����ı� 
		int w;
		n = 0;
		if (net->count < 2) {	//��������δ�����򲻹� 
				cout << "���ȴ���2�������������㡣\n";
				return net;
			}
		while (n <= 0) {
			cout << "������ߵ�������";
			cin >> n;
		}
		for (int i = 0; i < n; i++) {		
			do {
				cout << "�������������㼰�ߣ��ÿո�ָ���";
				cin >> v1 >> v2 >> w;
			} while (!net->addEdge(v1, v2, w));
		}
		break;
	case 'C':	//������С������ 
		cout << "��������ʼ���㣺";
		cin >> v1;
		int ans;
		if ((ans = net->prim(v1)) > 0 && ans < maxint)
			cout << "����Prim��С�����������ٺķѣ�" << ans << "��\n";
		else
			cout << "����ʧ�ܣ�\n";
		break;
	case 'D':	//��ʾ��С������ 
		net->print();
		break;
	case 'E':	//�˳����� 
		cout << "��лʹ�ã�\n";
		system("pause");
		exit(0);
		break;
	}
	return net;
}

