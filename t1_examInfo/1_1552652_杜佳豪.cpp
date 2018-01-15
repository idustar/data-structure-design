/*****************************
数据结构课程设计
杜佳豪 1552652
同济大学 软件工程

T1 考试报名系统
考生信息管理。 
*****************************/ 




#include "t1_examInfo.h"

int main() {
	pHead = pTail = nullptr;
	prepare(); 
}

void prepare() {
	using namespace std;
	cout << "首先请建立考生信息系统！\n";
	cout << "请输入考生人数：";
	cin >> nCount;
	if (nCount > 0) {
		cout << "请依次输入考生的考号，姓名，性别，年龄及报考类别！\n";
		for (int i = 0; i < nCount; i++) {
			cin >> num >> name >> sex >> age >> type;
			Node* newNode = new Node();
			while (!newNode->item.revise(num, name, sex, age, type)) {
				cout << "第" << i+1 << "组输入信息有误，请重新输入。\n";
				cin >> num >> name >> sex >> age >> type;
			}
			newNode->item.revise(num, name, sex, age, type);
			if (!insert(newNode, cCount + 1)) {
				nCount++;
				cout << "一个考号只能对应一位考生，请重新设置。\n";
			}
		}
		chooseOperation();
	}
}

void chooseOperation()
{
	while (true) {
		display();
		std::cout << "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）"
			<< "\n请选择您要进行的操作：";
		int n;
		std::cin >> n;
		switch (n)
		{
		case 1:
			insertCandidate(); break;	//插入考生 
		case 2:
			deleteCandidate(); break;	//删除考生 
		case 3:
			searchCandidate(); break;	//查找考生 
		case 4:
			reviseCandidate(); break;	//修改考生信息 
		case 5:
			countCandidate(); break;	//统计考生信息 
		case 0:
			std::cout << "谢谢使用！";	//取消操作 
			system("pause");
			exit(0);
		}
	}
}

void insertCandidate()	//插入考生 
{
	using namespace std;
	cout << "请输入你要插入的考生的位置：";
	int location;
	cin >> location;
	while (location > cCount + 1 || location < 1) 
	{
		cout << "您输入的位置有误，请重新输入。\n请输入你要插入的考生的位置：";
		cin >> location;
	}
	cout << "请依次输入考生的考号，姓名，性别，年龄及报考类别:\n";
	cin >> num >> name >> sex >> age >> type;
	Node* newNode = new Node();
	while (!newNode->item.revise(num, name, sex, age, type)) {
		cout << "输入信息有误，请重新输入:\n";
		cin >> num >> name >> sex >> age >> type;
	}
	if (!insert(newNode, location))
		cout << "一个考号只能对应一位考生，请重新设置。\n";
}

void deleteCandidate()	//删除考生 
{
	using namespace std;
	if (cCount == 0) {
		cout << "您没有录入任何考生信息。\n";
		return;
	}
	cout << "请输入你要删除的考生的考号：";
	int num;
	cin >> num;
	if (!deleteNode(num))
		cout << "找不到该考生。\n";
	

}

void searchCandidate()	//查找考生 
{
	using namespace std;
	if (cCount == 0) {
		cout << "您没有录入任何考生信息。\n";
		return;
	}
	cout << "请输入你要查找的考生的考号：";
	int num;
	cin >> num;
	Node* p = findNode(num);
	if (cCount == 0 || p == nullptr)
		cout << "找不到该考生。\n";
	else {
		cout << "\n[查找结果]\n考号\t姓名\t性别\t年龄\t报考类型\n";
		p->item.display();
	}
}

void reviseCandidate()	//修改考生信息 
{
	using namespace std;
	if (cCount == 0) {
		cout << "您没有录入任何考生信息。\n";
		return;
	}
	cout << "请依次输入要修改的考生的考号，姓名，性别，年龄及报考类别！\n";
	cin >> num >> name >> sex >> age >> type;
	Node* p = findNode(num);
	while (p == nullptr || !p->item.revise(num, name, sex, age, type)) {
		cout << "信息输入错误，请重新输入要修改的考生的考号，姓名，性别，年龄及报考类别！\n";
		cin >> num >> name >> sex >> age >> type;
		p = findNode(num);
	}
}

void countCandidate()	//统计考生 
{
	using namespace std;
	if (cCount == 0) {
		cout << "您没有录入任何考生信息。\n";
		return;
	}
	cout << "请输入您要统计的报考类别：";
	cin >> type;
	int tCount = 0;
	for (Node* p = pHead; p != nullptr; p = p->next) {
		if (p->item.getType() == type) {
			tCount++;
		}
	}
	if (tCount == 0)
		cout << "没有找到报考这个类别的考生。\n";
	else
		cout << "共有" << tCount << "位考生报考" << type << "。\n";
}

void display()	//显示考生信息 
{
	using namespace std;
	if (cCount == 0) {
		cout << "\n[暂时没有数据]\n";
		return;
	}
	cout << "\n考号\t姓名\t性别\t年龄\t报考类型\n";
	Node* p = pHead;
	if (cCount >= 1)
	    do {
		    p->item.display();
		    p = p->next;
	    } while (p != pTail);
}

bool insert(Node *source, int location)	//插入节点 
{
	Node *p;
	for (p = pHead; p != pTail; p = p->next)
		if (p->item.getNum() == source->item.getNum())
			return false;
	p = pHead;
	int pCount = 1;
	cCount++;
	if (location == 1) {
		source->next = pHead;
		pHead = source;
		return true;
	}

	while (pCount < location - 1) {
		p = p->next;
		pCount++;
	}

	if (p == pTail) {
		pTail->next = source;
		pTail = source;
	}
	else {
		source->next = p->next;
		p->next = source;
	}

	return true;
}

bool deleteNode(int num)	//删除节点 
{
	if (pHead->item.getNum() == num) {
		std::cout << "您删除的考生信息是：";
		pHead->item.display();
        Node* pTemp = pHead->next;
		delete pHead;
		pHead = pTemp;
		cCount--;
		return true;
	}
	for (Node* p = pHead; p->next != nullptr; p = p->next) {
		if (p->next->item.getNum() == num) {
			std::cout << "您删除的考生信息是：";
			p->next->item.display();
            if (p->next == pTail) {
				delete p->next;
				pTail = p;
				p->next = nullptr;
			}
			else {
				p->next = p->next->next;
				delete p->next;
			}
			cCount--;
			return true;
		}
	}
	return false;
}

Node* findNode(int num)	//查找节点 
{
	for (Node* p = pHead; p != nullptr; p = p->next) {
		if (p->item.getNum() == num) {
			return p;
		}
	}
	return nullptr;
}
