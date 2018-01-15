/*****************************
���ݽṹ�γ����
�żѺ� 1552652
ͬ�ô�ѧ �������

T1 ���Ա���ϵͳ
������Ϣ���� 
*****************************/ 




#include "t1_examInfo.h"

int main() {
	pHead = pTail = nullptr;
	prepare(); 
}

void prepare() {
	using namespace std;
	cout << "�����뽨��������Ϣϵͳ��\n";
	cout << "�����뿼��������";
	cin >> nCount;
	if (nCount > 0) {
		cout << "���������뿼���Ŀ��ţ��������Ա����估�������\n";
		for (int i = 0; i < nCount; i++) {
			cin >> num >> name >> sex >> age >> type;
			Node* newNode = new Node();
			while (!newNode->item.revise(num, name, sex, age, type)) {
				cout << "��" << i+1 << "��������Ϣ�������������롣\n";
				cin >> num >> name >> sex >> age >> type;
			}
			newNode->item.revise(num, name, sex, age, type);
			if (!insert(newNode, cCount + 1)) {
				nCount++;
				cout << "һ������ֻ�ܶ�Ӧһλ���������������á�\n";
			}
		}
		chooseOperation();
	}
}

void chooseOperation()
{
	while (true) {
		display();
		std::cout << "��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ��������"
			<< "\n��ѡ����Ҫ���еĲ�����";
		int n;
		std::cin >> n;
		switch (n)
		{
		case 1:
			insertCandidate(); break;	//���뿼�� 
		case 2:
			deleteCandidate(); break;	//ɾ������ 
		case 3:
			searchCandidate(); break;	//���ҿ��� 
		case 4:
			reviseCandidate(); break;	//�޸Ŀ�����Ϣ 
		case 5:
			countCandidate(); break;	//ͳ�ƿ�����Ϣ 
		case 0:
			std::cout << "ллʹ�ã�";	//ȡ������ 
			system("pause");
			exit(0);
		}
	}
}

void insertCandidate()	//���뿼�� 
{
	using namespace std;
	cout << "��������Ҫ����Ŀ�����λ�ã�";
	int location;
	cin >> location;
	while (location > cCount + 1 || location < 1) 
	{
		cout << "�������λ���������������롣\n��������Ҫ����Ŀ�����λ�ã�";
		cin >> location;
	}
	cout << "���������뿼���Ŀ��ţ��������Ա����估�������:\n";
	cin >> num >> name >> sex >> age >> type;
	Node* newNode = new Node();
	while (!newNode->item.revise(num, name, sex, age, type)) {
		cout << "������Ϣ��������������:\n";
		cin >> num >> name >> sex >> age >> type;
	}
	if (!insert(newNode, location))
		cout << "һ������ֻ�ܶ�Ӧһλ���������������á�\n";
}

void deleteCandidate()	//ɾ������ 
{
	using namespace std;
	if (cCount == 0) {
		cout << "��û��¼���κο�����Ϣ��\n";
		return;
	}
	cout << "��������Ҫɾ���Ŀ����Ŀ��ţ�";
	int num;
	cin >> num;
	if (!deleteNode(num))
		cout << "�Ҳ����ÿ�����\n";
	

}

void searchCandidate()	//���ҿ��� 
{
	using namespace std;
	if (cCount == 0) {
		cout << "��û��¼���κο�����Ϣ��\n";
		return;
	}
	cout << "��������Ҫ���ҵĿ����Ŀ��ţ�";
	int num;
	cin >> num;
	Node* p = findNode(num);
	if (cCount == 0 || p == nullptr)
		cout << "�Ҳ����ÿ�����\n";
	else {
		cout << "\n[���ҽ��]\n����\t����\t�Ա�\t����\t��������\n";
		p->item.display();
	}
}

void reviseCandidate()	//�޸Ŀ�����Ϣ 
{
	using namespace std;
	if (cCount == 0) {
		cout << "��û��¼���κο�����Ϣ��\n";
		return;
	}
	cout << "����������Ҫ�޸ĵĿ����Ŀ��ţ��������Ա����估�������\n";
	cin >> num >> name >> sex >> age >> type;
	Node* p = findNode(num);
	while (p == nullptr || !p->item.revise(num, name, sex, age, type)) {
		cout << "��Ϣ�����������������Ҫ�޸ĵĿ����Ŀ��ţ��������Ա����估�������\n";
		cin >> num >> name >> sex >> age >> type;
		p = findNode(num);
	}
}

void countCandidate()	//ͳ�ƿ��� 
{
	using namespace std;
	if (cCount == 0) {
		cout << "��û��¼���κο�����Ϣ��\n";
		return;
	}
	cout << "��������Ҫͳ�Ƶı������";
	cin >> type;
	int tCount = 0;
	for (Node* p = pHead; p != nullptr; p = p->next) {
		if (p->item.getType() == type) {
			tCount++;
		}
	}
	if (tCount == 0)
		cout << "û���ҵ�����������Ŀ�����\n";
	else
		cout << "����" << tCount << "λ��������" << type << "��\n";
}

void display()	//��ʾ������Ϣ 
{
	using namespace std;
	if (cCount == 0) {
		cout << "\n[��ʱû������]\n";
		return;
	}
	cout << "\n����\t����\t�Ա�\t����\t��������\n";
	Node* p = pHead;
	if (cCount >= 1)
	    do {
		    p->item.display();
		    p = p->next;
	    } while (p != pTail);
}

bool insert(Node *source, int location)	//����ڵ� 
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

bool deleteNode(int num)	//ɾ���ڵ� 
{
	if (pHead->item.getNum() == num) {
		std::cout << "��ɾ���Ŀ�����Ϣ�ǣ�";
		pHead->item.display();
        Node* pTemp = pHead->next;
		delete pHead;
		pHead = pTemp;
		cCount--;
		return true;
	}
	for (Node* p = pHead; p->next != nullptr; p = p->next) {
		if (p->next->item.getNum() == num) {
			std::cout << "��ɾ���Ŀ�����Ϣ�ǣ�";
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

Node* findNode(int num)	//���ҽڵ� 
{
	for (Node* p = pHead; p != nullptr; p = p->next) {
		if (p->item.getNum() == num) {
			return p;
		}
	}
	return nullptr;
}
