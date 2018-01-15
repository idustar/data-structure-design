#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Member {
	string name;
	vector<Member*> son;
};

typedef Member* Family;


Family prepare();
bool ChooseOpreation(Family family);
Family addMember(Family father, string sonName);
bool deleteMember(Member* father);
Family findMember(Family family, string name, bool returnFather = false);
void completeFamily(Family family);
void addFamilyMember(Family family);
void dismissFamily(Family family);
void reviseName(Family family);