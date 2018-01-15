#include "candidate.h"

Candidate::Candidate()
{
}

void Candidate::display() {	//��ʾ������Ϣ 
	std::cout << _num << "\t" << _name << "\t";
	if (_sex == SexType::��) std::cout << "��";
	else std::cout << "Ů";
	std::cout << "\t"<< _age << "\t" << _type << std::endl;
}

bool Candidate::revise(int num, std::string name, std::string sex, int age, std::string type) {	//�޸Ŀ�����Ϣ 
	
	if (sex == "��")
		_sex = SexType::��;
	else if (sex == "Ů")
		_sex = SexType::Ů;
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
