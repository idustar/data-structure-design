#include "candidate.h"

Candidate::Candidate()
{
}

void Candidate::display() {	//显示考生信息 
	std::cout << _num << "\t" << _name << "\t";
	if (_sex == SexType::男) std::cout << "男";
	else std::cout << "女";
	std::cout << "\t"<< _age << "\t" << _type << std::endl;
}

bool Candidate::revise(int num, std::string name, std::string sex, int age, std::string type) {	//修改考生信息 
	
	if (sex == "男")
		_sex = SexType::男;
	else if (sex == "女")
		_sex = SexType::女;
	else
		return false;
	_num = num;
	_name = name;
	_age = age;
	_type = type;
	return true;
}

int Candidate::getNum() {
	return _num;
}

std::string Candidate::getType() {
	return _type;
}
