/*****************************
���ݽṹ�γ����
�żѺ� 1552652
ͬ�ô�ѧ �������

T5 �ؼ��ʼ���ϵͳ 
���ı���Ϣ������ָ���ļ��ڣ�
�������ؼ��ʳ��ִ����� 
*****************************/ 

#include "t5_text.h"

int main(int argc, const char * argv[]) {
	read();		//���뱻ƥ�䴮 
	cout << "������Ҫ�����Ĺؼ��ʣ�";
	cin >> key;	//����ƥ�䴮 
	key_length = key.length();
	key.erase(0, key.find_first_not_of(" "));
	key.erase(key.find_last_not_of(" ") + 1);
	cout << "\n��������Ҫ���������ݣ�";
	cout << article;
	int *next = getNext(key);	//Ԥ����ƥ��ֵ 
	key_count = kmp(key, article, next);	//KMP�㷨 
	cout << "\n\n���ҵ��ؼ��ʡ�" << key << "��" << key_count << "�Ρ�\n";
	system("pause");
}

void read() {
	cout << "�ؼ��ʼ���ϵͳ\n�������ļ�����";
	string path;
	cin >> path;
	ofstream fout(path, ios::out);
	if (!fout.is_open()) {
		cout << "�ļ�����\n";
		system("pause");
		exit(0);
	}
	cout << "\n�������ļ����ݣ���^������\n";
	char c = cin.get();
	while (c != '^') {
		article += c;
		fout << c;
		c = cin.get();
	}
	cout << endl << article;
	fout.close();
	cout << "\n�����ı��ѳɹ����浽��" << path << "���ļ��С�\n\n";
}

int* getNext(string key)	//Ԥ����ƥ��ֵ 
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

int kmp(string sub, string str, int next[])	//KMP�㷨 
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
	return ans;	//����ƥ����� 
}
