/*****************************
数据结构课程设计
杜佳豪 1552652
同济大学 软件工程

T2 约瑟夫生者死者游戏 
模拟解决约瑟夫问题。 
*****************************/ 

#include "t2_josephus.h"

int main() {
	//Prepare
	prepare();
	Node* pHead = createList();	//建立单循环链表 
	int count = 0, location;
	while (count < n - k) {
		pHead = deleteNode(pHead, location);
		cout << "第" << ++count << "个死者的位置是：\t" << location << endl;
	}
	printLiving(pHead);	//输出存活信息 
	system("pause");
};

void prepare() {
	cout << "现有N人围成一圈，从第S个人开始依次报数，报M的人出局，再由下一个人开始报数，如此循环，直到剩下K个人为止。\n\n";
	cout << "请输入生死游戏的总人数N：";
	cin >> n;
	while (n <= 0) {
		cout << "数据不合法，请重新输入生死游戏的总人数N：";
		cin >> n;
	}
	cout << "请输入游戏开始的位置S：";
	cin >> s;
	while (s <= 0 || s > n) {
		cout << "S的取值在1-" << n << "之间，请重新输入游戏开始的位置S：";
		cin >> s;
	}
	cout << "请输入死亡数字M：";
	cin >> m;
	while (m <= 0) {
		cout << "数据不合法，请重新输入死亡数字M：";
		cin >> m;
	}
	cout << "请输入剩余的生者人数K：";
	cin >> k;
	while (k < 0 || k > n) {
		cout << "K的取值在1-" << n << "之间，请重新输入剩余的生者人数K：";
		cin >> k;
	}
	cout << endl;
}

Node* createList(){	//创建单循环链表 
	Node *head, *ptr = nullptr, *temp;
	head = new Node;
	head->next = nullptr;
	head->location = s;
	temp = head;
	for (int i = 1; i < n; i++) {
		ptr = new Node;
		ptr->next = nullptr;
		ptr->location = (s + i - 1) % n + 1;
		temp->next = ptr;
		temp = temp->next;
	}
	ptr->next = head;	//最后一个节点的后继指向head 
	return head;
}

Node* deleteNode(Node* head, int &location) {	//删除节点 
	Node* ptr, *temp;
	int count = 0;
	ptr = temp = head;
	while (++count < m) {
		ptr = ptr->next;
	}
	location = ptr->location;
	while (temp->next != ptr)
		temp = temp->next;
	temp->next = ptr->next;
	delete ptr;
	return temp->next;
}

void printLiving(Node * head)	//输出存活信息 
{
	if (k == 0) {
		cout << "所有人都死了。\n";
		return;
	}
	cout << "\n\n最后剩下：\t" << k << "人。\n";
	cout << "剩余的生者位置为：";
	Node* ptr = head, *temp;
	while (ptr->location < ptr->next->location)
		ptr = ptr->next;
	ptr = temp = ptr->next;
	while (ptr->next != temp) {
		cout << "\t" << ptr->location;
		ptr = ptr->next;
	}
	cout << "\t" << ptr->location << endl;
}

