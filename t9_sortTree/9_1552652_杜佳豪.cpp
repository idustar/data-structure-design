/*****************************
���ݽṹ�γ����
�żѺ� 1552652
ͬ�ô�ѧ �������

T9 ���������� 
ͨ��������������̬ά���������С� 
*****************************/ 

#include "t9_sortTree.h"

int main(int argc, const char * argv[]) {
	// insert code here...
	start();
	while (chooseOperation()) { ; }
	return 0;
}

void start() {
	cout << "**      ����������      **\n"
		<< "==========================\n"
		<< "** 1 --- �������������� **\n"
		<< "** 2 --- ����Ԫ��       **\n"
		<< "** 3 --- ��ѯԪ��       **\n"
		<< "** 4 --- �˳�����       **\n"
		<< "==========================\n";
}

bool chooseOperation() {
	cout << "��ѡ��ִ����: ";
	int k, n, value;
	cin >> k;
	switch (k) {
	case 1:	//�������������� 
		if (root != nullptr) {
			cout << "���Ѿ�������һ�����ˣ��볢�Բ���Ԫ�ذ�~\n";
			break;
		}
		cout << "������Ԫ�ظ���: ";
		cin >> n;
		cout << "����������" << n << "��Ԫ��ֵ��\n";
		for (int i = 0; i<n; i++) {
			cin >> value;
			root = add(root, value);
		}
		show(root, 0);
		break;
	case 2:	//����Ԫ�� 
		if (root == nullptr) {
			cout << "���ǿյģ����Ƚ���һ������~~~\n";
			break;
		}
		cout << "������Ҫ�����Ԫ�أ�";
		cin >> value;
		root = add(root, value);
		show(root, 0);
		break;
	case 3:	//����Ԫ�� 
		cout << "������Ҫ���ҵ�Ԫ�أ�";
		cin >> value;
		if (find(root, value))
			cout << "�ҵ�Ԫ��" << value << "!\n";
		else
			cout << "û���ҵ�Ԫ��" << value << "!\n";
		break;
	case 4:	//�˳����� 
		cout << "ллʹ��<����������>��\n";
		system("pause");
		exit(0);
		break;
	default:
		cout << "�������";
		break;
	}
	return true;
}

Tree* add(Tree* tree, int value) {	//�����Ԫ�� 
	if (tree == nullptr) {
		Tree* temp = new struct Tree();
		temp->value = value;
		tree = temp;
		return tree;
	}
	if (value < tree->value)
		tree->left = add(tree->left, value);
	else if (value > tree->value)
		tree->right = add(tree->right, value);
	else {
		cout << "Ԫ��" << value << "���ʧ�ܣ��Ѵ��ڸ�Ԫ�ء�\n";
		return tree;
	}
	return tree;
}

bool find(Tree* tree, int value) {	//����Ԫ�� 
	if (tree == nullptr) {
		return false;
	}
	if (value < tree->value)
		return find(tree->left, value);
	else if (value > tree->value)
		return find(tree->right, value);
	else {
		return true;
	}
	return false;
}

void show(Tree* tree, int layer) {	//������ʾ����Ԫ�� 
	if (layer == 0) cout << "����������Ľṹ��\n";
	if (tree == nullptr) return;
	show(tree->left, 1);
	cout << tree->value << " ";
	show(tree->right, 1);
	if (layer == 0) cout << endl;
}
