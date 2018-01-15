/*****************************
���ݽṹ�γ����
�żѺ� 1552652
ͬ�ô�ѧ �������

T2 Լɪ������������Ϸ 
ģ����Լɪ�����⡣ 
*****************************/ 

#include "t2_josephus.h"

int main() {
	//Prepare
	prepare();
	Node* pHead = createList();	//������ѭ������ 
	int count = 0, location;
	while (count < n - k) {
		pHead = deleteNode(pHead, location);
		cout << "��" << ++count << "�����ߵ�λ���ǣ�\t" << location << endl;
	}
	printLiving(pHead);	//��������Ϣ 
	system("pause");
};

void prepare() {
	cout << "����N��Χ��һȦ���ӵ�S���˿�ʼ���α�������M���˳��֣�������һ���˿�ʼ���������ѭ����ֱ��ʣ��K����Ϊֹ��\n\n";
	cout << "������������Ϸ��������N��";
	cin >> n;
	while (n <= 0) {
		cout << "���ݲ��Ϸ�������������������Ϸ��������N��";
		cin >> n;
	}
	cout << "��������Ϸ��ʼ��λ��S��";
	cin >> s;
	while (s <= 0 || s > n) {
		cout << "S��ȡֵ��1-" << n << "֮�䣬������������Ϸ��ʼ��λ��S��";
		cin >> s;
	}
	cout << "��������������M��";
	cin >> m;
	while (m <= 0) {
		cout << "���ݲ��Ϸ���������������������M��";
		cin >> m;
	}
	cout << "������ʣ�����������K��";
	cin >> k;
	while (k < 0 || k > n) {
		cout << "K��ȡֵ��1-" << n << "֮�䣬����������ʣ�����������K��";
		cin >> k;
	}
	cout << endl;
}

Node* createList(){	//������ѭ������ 
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
	ptr->next = head;	//���һ���ڵ�ĺ��ָ��head 
	return head;
}

Node* deleteNode(Node* head, int &location) {	//ɾ���ڵ� 
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

void printLiving(Node * head)	//��������Ϣ 
{
	if (k == 0) {
		cout << "�����˶����ˡ�\n";
		return;
	}
	cout << "\n\n���ʣ�£�\t" << k << "�ˡ�\n";
	cout << "ʣ�������λ��Ϊ��";
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

