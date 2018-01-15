/*****************************
数据结构课程设计
杜佳豪 1552652
同济大学 软件工程

T9 二叉排序树 
通过二叉排序树对态维护有序序列。 
*****************************/ 

#include "t9_sortTree.h"

int main(int argc, const char * argv[]) {
	// insert code here...
	start();
	while (chooseOperation()) { ; }
	return 0;
}

void start() {
	cout << "**      二叉排序树      **\n"
		<< "==========================\n"
		<< "** 1 --- 建立二叉排序树 **\n"
		<< "** 2 --- 插入元素       **\n"
		<< "** 3 --- 查询元素       **\n"
		<< "** 4 --- 退出程序       **\n"
		<< "==========================\n";
}

bool chooseOperation() {
	cout << "请选择执行项: ";
	int k, n, value;
	cin >> k;
	switch (k) {
	case 1:	//建立二叉排序树 
		if (root != nullptr) {
			cout << "您已经建立过一棵树了，请尝试插入元素吧~\n";
			break;
		}
		cout << "请输入元素个数: ";
		cin >> n;
		cout << "请依次输入" << n << "个元素值：\n";
		for (int i = 0; i<n; i++) {
			cin >> value;
			root = add(root, value);
		}
		show(root, 0);
		break;
	case 2:	//插入元素 
		if (root == nullptr) {
			cout << "树是空的，请先建立一颗树吧~~~\n";
			break;
		}
		cout << "请输入要插入的元素：";
		cin >> value;
		root = add(root, value);
		show(root, 0);
		break;
	case 3:	//查找元素 
		cout << "请输入要查找的元素：";
		cin >> value;
		if (find(root, value))
			cout << "找到元素" << value << "!\n";
		else
			cout << "没有找到元素" << value << "!\n";
		break;
	case 4:	//退出程序 
		cout << "谢谢使用<二叉排序树>！\n";
		system("pause");
		exit(0);
		break;
	default:
		cout << "输入错误。";
		break;
	}
	return true;
}

Tree* add(Tree* tree, int value) {	//添加新元素 
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
		cout << "元素" << value << "添加失败：已存在该元素。\n";
		return tree;
	}
	return tree;
}

bool find(Tree* tree, int value) {	//查找元素 
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

void show(Tree* tree, int layer) {	//遍历显示所有元素 
	if (layer == 0) cout << "现在这棵树的结构：\n";
	if (tree == nullptr) return;
	show(tree->left, 1);
	cout << tree->value << " ";
	show(tree->right, 1);
	if (layer == 0) cout << endl;
}
