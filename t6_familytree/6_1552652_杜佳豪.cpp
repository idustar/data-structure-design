/*****************************
数据结构课程设计
杜佳豪 1552652
同济大学 软件工程

T6 家谱管理系统 
管理家谱。 
*****************************/ 

#include "t6_familytree.h"

int main(int argc, const char * argv[]) {
	Family family = prepare(); 
	while (true) ChooseOpreation(family);
	return 0;
}


Family prepare() {
	cout << "**          家谱管理系统          **\n"
		<< "====================================\n"
		<< "**   请选择您要执行的操作：       **\n"
		<< "**     A ---- 完善家谱信息        **\n"
		<< "**     B ---- 添加家族成员        **\n"
		<< "**     C ---- 解散局部家庭        **\n"
		<< "**     D ---- 更改成员姓名        **\n"
		<< "**     E ---- 退出管理系统        **\n"
		<< "====================================\n\n首先建立一个家谱！\n请输入祖先的姓名：";
	Member* ancestor = new Member();
	cin >> ancestor->name;
	cout << "此家谱的祖先是： " << ancestor->name << endl;
	return ancestor;
}

bool ChooseOpreation(Family family) {
	cout << "\n请选择要执行的操作：";
	char c;
	cin >> c;
	switch (c) {
	case 'A':	//完善家谱信息 
		completeFamily(family);
		break;
	case 'B':	//添加家族成员 
		addFamilyMember(family);
		break;
	case 'C':	//解散局部家庭 
		dismissFamily(family);
		break;
	case 'D':	//更改成员姓名 
		reviseName(family);
		break;
	case 'E':	//退出程序 
		cout << "谢谢使用！";
		system("pause");
		exit(0);
		break;
	default:
		break;
	}
	return true;
}

Family addMember(Family father, string sonName) {	//添加新成员 
	Member *son = new Member();
	son->name = sonName;
	father->son.push_back(son);
	return son;
}

bool deleteMember(Member* father) {	//删除成员 
	if (father->son.empty())
		delete father;
	else {
		for (auto i : father->son)
			deleteMember(i);
		delete father;
	}
	return true;
}

Family findMember(Family family, string name, bool returnFather) {	//查找成员 
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

void completeFamily(Family family) {	//完善家谱信息 
	cout << "请输入要建立家庭的人的姓名：";
	string name;
	cin >> name;
	Family father;
	while ((father = findMember(family, name, false)) == nullptr) {
		cout << "家谱中找不到" << name << "，请重新输入要建立家庭的人的姓名：";
		cin >> name;
	}
	cout << "请输入" << name << "的子女个数：";
	int num;
	cin >> num;
	if (num <= 0) {
		cout << "你在搞什么？\n";
		return;
	}
	cout << "请依次输入" << num << "位子女的姓名：";
	for (int i = 0; i<num; i++) {
		cin >> name;
		while (findMember(family, name, false) != nullptr) {
			cout << "家谱中存在同名" << name << "，请重新输入该子女姓名：";
			cin >> name;
		}
		addMember(father, name);	//调用添加新成员函数 
	}
	//输出子孙信息 
	cout << father->name << "的第一代子孙是：";
	for (auto i : father->son)
		cout << i->name << "\t";
	cout << endl;
}

void addFamilyMember(Family family)	//添加家庭成员 
{
	cout << "请输入要添加儿子（女儿）的人的姓名：";
	string name;
	cin >> name;
	Family father;
	while ((father = findMember(family, name, false)) == nullptr) {
		cout << "家谱中找不到" << name << "，请重新输入要添加儿子（女儿）的人的姓名：";
		cin >> name;
	}
	cout << "请输入" << name << "新添加的儿子（女儿）的姓名：";
	cin >> name;
	while (findMember(family, name, false) != nullptr) {
		cout << "家谱中存在同名" << name << "，请重新输入该子女姓名：";
		cin >> name;
	}
	addMember(father, name);	//调用添加新成员函数 
	//输出子孙信息 
	cout << father->name << "的第一代子孙是：";
	for (auto i : father->son)
		cout << i->name << "\t";
	cout << endl;
}

void dismissFamily(Family family) {	//解散局部家庭 
	cout << "请输入要解散家庭的人的姓名：";
	string name;
	cin >> name;
	Family father, aim;
	while ((aim = findMember(family, name, false)) == nullptr) {
		cout << "家谱中找不到" << name << "，请重新输入要解散家庭的人的姓名：";
		cin >> name;
	}

	if (aim == family) {
		cout << "您已清空整个家谱。\n";
		system("pause");
		exit(0);
	}
	cout << name << "及其后代已从家谱中移除。\n";
	//输出子孙信息 
	if (aim->son.empty())
		cout << "他没有子孙。\n";
	else{
		cout << "他的第一代子孙是：";
        for (auto i : aim->son)
		    cout << i->name << "\t";
	    cout << endl;
	}
	
	father = findMember(family, name, true);
	
	//内存清空 
	for (auto i = father->son.begin(); i != father->son.end();++i ) {
		if ((*i)->name == name) {
			father->son.erase(i);
			break;
		}
	}
	deleteMember(aim);	
}

void reviseName(Family family)	//修改成员姓名 
{
	cout << "请输入要修改的人的原姓名：";
	string name;
	cin >> name;
	Family aim;
	while ((aim = findMember(family, name, false)) == nullptr) {
		cout << "家谱中找不到" << name << "，请重新输入要修改的人的原姓名：";
		cin >> name;
	}
	cout << "请输入修改后的姓名：";
	cin >> name;
	while ((findMember(family, name, false)) != nullptr) {
		cout << "家谱中存在同名" << name << "，请重新输入修改后的姓名：";
		cin >> name;
	}
	aim->name = name;
	cout << "修改成功！\n";
}
