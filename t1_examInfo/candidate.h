#pragma once

#include <iostream>
#include <string>

enum SexType {ÄÐ, Å®};

class Candidate
{
public:
	Candidate();
	void display();
	bool revise(int num, std::string name, std::string sex, int age, std::string type);
	int getNum();
	std::string getType();

private:
	int _num;
	std::string _name;
	enum SexType _sex;
	int _age;
	std::string _type;
};