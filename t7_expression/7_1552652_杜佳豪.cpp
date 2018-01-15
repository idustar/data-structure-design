/*****************************
���ݽṹ�γ����
�żѺ� 1552652
ͬ�ô�ѧ �������

T7 ���ʽ��ֵ 
������׺���ʽ������ת���ɶ���
���������ǰ׺���ʽ�ͺ�׺���
ʽ�� 
*****************************/ 

#include "t7_expression.h"

int main() {
	//������׺���ʽ 
	cout << "���ʽ��";
	string str,str_in;
	cin >> str_in;	
	for (int i = 0; i < str_in.length(); i++) {
		if (str_in[i] != ' ')
			str += str_in[i];
	}
	//ת��Ϊ������ 
	ExpressionTree* tree = buildTree(transform(str));
	//����������ʽ���沨�����ʽ 
	cout << "�������ʽ��";
	dlr(tree);
	cout << "\n��׺���ʽ��" << str << "\n�沨�����ʽ��";
	lrd(tree);
	cout << endl;
	system("pause");
}

int Priority(char oper) {	//�ж���������ȶ� 
	if (oper == '(')
		return 0;
	else if (oper == '+' || oper == '-')
		return 1;
	else if (oper == '/' || oper == '*')
		return 2;
}

string transform(string str) {	//��׺���ʽת��Ϊ��׺���ʽ 
	string lastExpression = ""; 
	string num = "";
	char x;
	stack<char> oper;	//���ʽջ 
	for (int i = 0; i < str.length();) {
		if (i == 0 && str[i] == '-') {
			num = "-";
			i++;
		}
		x = str[i];
		if ((x >= '0' && x <= '9') || num == "-" || x == '.') {	//�������� 
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
				num += str[i];
				i++;
			}
			lastExpression += num + " ";
			num = "";
			continue;
		}
		else {
			if (x == '(') {	//����������ѹջ 
				oper.push(x);
				if (str[i + 1] == '-') {
					num = "-";
					i++;
				}
			}
			else {
				if (x == ')') {	//���������� 
					while (oper.top() != '(') {
						lastExpression = lastExpression + oper.top() + " ";
						oper.pop();
					}
					oper.pop();
				}
				else {	//�����������㸣 
					while (!oper.empty() && (Priority(oper.top()) >= Priority(x))) {
						lastExpression = lastExpression + oper.top() + " ";
						oper.pop();
					}
					if (str[i + 1] == '-') {
						num = "-";
						i++;
					}
					oper.push(x);
				}
			}
		}
		i++;
	}
	while (!oper.empty()) {
		lastExpression = lastExpression + oper.top() + " ";
		oper.pop();
	}
	return lastExpression;
}

ExpressionTree* buildTree(string lastExpression) {	//���沨�����ʽ���������� 
	stack <ExpressionTree*> nodes;	//��ջ 
	string temp = "";
	for (int i = 0; i < lastExpression.length(); ) {
		while (lastExpression[i] != ' ') {
			temp += lastExpression[i];
			i++;
		}
		if (temp.length() > 1 || (temp.length() == 1 && temp[0] >= '0' && temp[0] <= '9')) {
			ExpressionTree* t = new ExpressionTree();
			t->data = temp;
			nodes.push(t);
		}
		else {
			if (nodes.empty()) {
				temp = "-";
				i++;
				continue;
			}
			ExpressionTree* t = new ExpressionTree();
			t->data = temp;
			if (!nodes.empty()) {
				t->right = nodes.top();
				nodes.pop();
			}
			if (!nodes.empty()) {
				t->left = nodes.top();
				nodes.pop();
			}
			nodes.push(t);
		}
		i++;
		temp = "";
	}
	return nodes.top();
}

void dlr(ExpressionTree* tree) {	//ǰ����� 
	if (tree == nullptr)
		return;
	else {
		cout << tree->data << " ";
		dlr(tree->left);
		dlr(tree->right);
	}
}

void lrd(ExpressionTree* tree) {	//������� 
	if (tree == nullptr)
		return;
	else {
		lrd(tree->left);
		lrd(tree->right);
		cout << tree->data << " ";
	}
}





