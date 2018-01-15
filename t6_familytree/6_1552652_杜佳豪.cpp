/*****************************
���ݽṹ�γ����
�żѺ� 1552652
ͬ�ô�ѧ �������

T6 ���׹���ϵͳ 
������ס� 
*****************************/ 

#include "t6_familytree.h"

int main(int argc, const char * argv[]) {
	Family family = prepare(); 
	while (true) ChooseOpreation(family);
	return 0;
}


Family prepare() {
	cout << "**          ���׹���ϵͳ          **\n"
		<< "====================================\n"
		<< "**   ��ѡ����Ҫִ�еĲ�����       **\n"
		<< "**     A ---- ���Ƽ�����Ϣ        **\n"
		<< "**     B ---- ��Ӽ����Ա        **\n"
		<< "**     C ---- ��ɢ�ֲ���ͥ        **\n"
		<< "**     D ---- ���ĳ�Ա����        **\n"
		<< "**     E ---- �˳�����ϵͳ        **\n"
		<< "====================================\n\n���Ƚ���һ�����ף�\n���������ȵ�������";
	Member* ancestor = new Member();
	cin >> ancestor->name;
	cout << "�˼��׵������ǣ� " << ancestor->name << endl;
	return ancestor;
}

bool ChooseOpreation(Family family) {
	cout << "\n��ѡ��Ҫִ�еĲ�����";
	char c;
	cin >> c;
	switch (c) {
	case 'A':	//���Ƽ�����Ϣ 
		completeFamily(family);
		break;
	case 'B':	//��Ӽ����Ա 
		addFamilyMember(family);
		break;
	case 'C':	//��ɢ�ֲ���ͥ 
		dismissFamily(family);
		break;
	case 'D':	//���ĳ�Ա���� 
		reviseName(family);
		break;
	case 'E':	//�˳����� 
		cout << "ллʹ�ã�";
		system("pause");
		exit(0);
		break;
	default:
		break;
	}
	return true;
}

Family addMember(Family father, string sonName) {	//����³�Ա 
	Member *son = new Member();
	son->name = sonName;
	father->son.push_back(son);
	return son;
}

bool deleteMember(Member* father) {	//ɾ����Ա 
	if (father->son.empty())
		delete father;
	else {
		for (auto i : father->son)
			deleteMember(i);
		delete father;
	}
	return true;
}

Family findMember(Family family, string name, bool returnFather) {	//���ҳ�Ա 
	Member* aim = nullptr;
	if (family->name == name) {
		if (returnFather)
			return nullptr;
		else
			return family;
	}
	for (auto i : family->son) {
		if (name == i->name) {
			if (returnFather)
				return family;
			else
				return i;
		}
		if ((aim = findMember(i, name, returnFather)) != nullptr)
			return aim;
	}
	return aim;
}

void completeFamily(Family family) {	//���Ƽ�����Ϣ 
	cout << "������Ҫ������ͥ���˵�������";
	string name;
	cin >> name;
	Family father;
	while ((father = findMember(family, name, false)) == nullptr) {
		cout << "�������Ҳ���" << name << "������������Ҫ������ͥ���˵�������";
		cin >> name;
	}
	cout << "������" << name << "����Ů������";
	int num;
	cin >> num;
	if (num <= 0) {
		cout << "���ڸ�ʲô��\n";
		return;
	}
	cout << "����������" << num << "λ��Ů��������";
	for (int i = 0; i<num; i++) {
		cin >> name;
		while (findMember(family, name, false) != nullptr) {
			cout << "�����д���ͬ��" << name << "���������������Ů������";
			cin >> name;
		}
		addMember(father, name);	//��������³�Ա���� 
	}
	//���������Ϣ 
	cout << father->name << "�ĵ�һ�������ǣ�";
	for (auto i : father->son)
		cout << i->name << "\t";
	cout << endl;
}

void addFamilyMember(Family family)	//��Ӽ�ͥ��Ա 
{
	cout << "������Ҫ��Ӷ��ӣ�Ů�������˵�������";
	string name;
	cin >> name;
	Family father;
	while ((father = findMember(family, name, false)) == nullptr) {
		cout << "�������Ҳ���" << name << "������������Ҫ��Ӷ��ӣ�Ů�������˵�������";
		cin >> name;
	}
	cout << "������" << name << "����ӵĶ��ӣ�Ů������������";
	cin >> name;
	while (findMember(family, name, false) != nullptr) {
		cout << "�����д���ͬ��" << name << "���������������Ů������";
		cin >> name;
	}
	addMember(father, name);	//��������³�Ա���� 
	//���������Ϣ 
	cout << father->name << "�ĵ�һ�������ǣ�";
	for (auto i : father->son)
		cout << i->name << "\t";
	cout << endl;
}

void dismissFamily(Family family) {	//��ɢ�ֲ���ͥ 
	cout << "������Ҫ��ɢ��ͥ���˵�������";
	string name;
	cin >> name;
	Family father, aim;
	while ((aim = findMember(family, name, false)) == nullptr) {
		cout << "�������Ҳ���" << name << "������������Ҫ��ɢ��ͥ���˵�������";
		cin >> name;
	}

	if (aim == family) {
		cout << "��������������ס�\n";
		system("pause");
		exit(0);
	}
	cout << name << "�������ѴӼ������Ƴ���\n";
	//���������Ϣ 
	if (aim->son.empty())
		cout << "��û�����\n";
	else{
		cout << "���ĵ�һ�������ǣ�";
        for (auto i : aim->son)
		    cout << i->name << "\t";
	    cout << endl;
	}
	
	father = findMember(family, name, true);
	
	//�ڴ���� 
	for (auto i = father->son.begin(); i != father->son.end();++i ) {
		if ((*i)->name == name) {
			father->son.erase(i);
			break;
		}
	}
	deleteMember(aim);	
}

void reviseName(Family family)	//�޸ĳ�Ա���� 
{
	cout << "������Ҫ�޸ĵ��˵�ԭ������";
	string name;
	cin >> name;
	Family aim;
	while ((aim = findMember(family, name, false)) == nullptr) {
		cout << "�������Ҳ���" << name << "������������Ҫ�޸ĵ��˵�ԭ������";
		cin >> name;
	}
	cout << "�������޸ĺ��������";
	cin >> name;
	while ((findMember(family, name, false)) != nullptr) {
		cout << "�����д���ͬ��" << name << "�������������޸ĺ��������";
		cin >> name;
	}
	aim->name = name;
	cout << "�޸ĳɹ���\n";
}
