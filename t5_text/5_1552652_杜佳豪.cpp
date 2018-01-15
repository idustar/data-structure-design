/*****************************
数据结构课程设计
杜佳豪 1552652
同济大学 软件工程

T5 关键词检索系统 
将文本信息储存在指定文件内，
并检索关键词出现次数。 
*****************************/ 

#include "t5_text.h"

int main(int argc, const char * argv[]) {
	read();		//读入被匹配串 
	cout << "请输入要检索的关键词：";
	cin >> key;	//读入匹配串 
	key_length = key.length();
	key.erase(0, key.find_first_not_of(" "));
	key.erase(key.find_last_not_of(" ") + 1);
	cout << "\n以下是您要检索的内容：";
	cout << article;
	int *next = getNext(key);	//预处理匹配值 
	key_count = kmp(key, article, next);	//KMP算法 
	cout << "\n\n共找到关键词“" << key << "”" << key_count << "次。\n";
	system("pause");
}

void read() {
	cout << "关键词检索系统\n请输入文件名：";
	string path;
	cin >> path;
	ofstream fout(path, ios::out);
	if (!fout.is_open()) {
		cout << "文件错误。\n";
		system("pause");
		exit(0);
	}
	cout << "\n请输入文件内容，以^结束：\n";
	char c = cin.get();
	while (c != '^') {
		article += c;
		fout << c;
		c = cin.get();
	}
	cout << endl << article;
	fout.close();
	cout << "\n本段文本已成功保存到“" << path << "”文件中。\n\n";
}

int* getNext(string key)	//预处理匹配值 
{
	int i = 0, j = -1;
	int *next = new int[key.size()+1];
	next[0] = -1;
	while (i < key.size())
		if (j == -1 || key[i] == key[j])
			next[++i] = ++j;
		else
			j = next[j];
	return next;
}

int kmp(string sub, string str, int next[])	//KMP算法 
{
	int i = 0, j = 0, ans = 0;
	while (i < str.size()) {
		if (j == -1 || str[i] == sub[j]) {
			i++;
			j++;
		} else
			j = next[j];
		if (j == sub.size()) {
			ans++;
			j = next[j - 1];
			i--;
		}
	}
	return ans;	//返回匹配次数 
}
