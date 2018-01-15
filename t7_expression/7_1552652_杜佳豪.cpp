/*****************************
数据结构课程设计
杜佳豪 1552652
同济大学 软件工程

T7 表达式求值 
给定中缀表达式，将其转化成二叉
树，并输出前缀表达式和后缀表达
式。 
*****************************/ 

#include "t7_expression.h"

int main() {
	//输入中缀表达式 
	cout << "表达式：";
	string str,str_in;
	cin >> str_in;	
	for (int i = 0; i < str_in.length(); i++) {
		if (str_in[i] != ' ')
			str += str_in[i];
	}
	//转化为二叉树 
	ExpressionTree* tree = buildTree(transform(str));
	//输出波兰表达式和逆波兰表达式 
	cout << "波兰表达式：";
	dlr(tree);
	cout << "\n中缀表达式：" << str << "\n逆波兰表达式：";
	lrd(tree);
	cout << endl;
	system("pause");
}

int Priority(char oper) {	//判断运算符优先度 
	if (oper == '(')
		return 0;
	else if (oper == '+' || oper == '-')
		return 1;
	else if (oper == '/' || oper == '*')
		return 2;
}

string transform(string str) {	//中缀表达式转化为后缀表达式 
	string lastExpression = ""; 
	string num = "";
	char x;
	stack<char> oper;	//表达式栈 
	for (int i = 0; i < str.length();) {
		if (i == 0 && str[i] == '-') {
			num = "-";
			i++;
		}
		x = str[i];
		if ((x >= '0' && x <= '9') || num == "-" || x == '.') {	//遇到数字 
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
				num += str[i];
				i++;
			}
			lastExpression += num + " ";
			num = "";
			continue;
		}
		else {
			if (x == '(') {	//遇到左括号压栈 
				oper.push(x);
				if (str[i + 1] == '-') {
					num = "-";
					i++;
				}
			}
			else {
				if (x == ')') {	//遇到右括号 
					while (oper.top() != '(') {
						lastExpression = lastExpression + oper.top() + " ";
						oper.pop();
					}
					oper.pop();
				}
				else {	//遇到四则运算福 
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

ExpressionTree* buildTree(string lastExpression) {	//由逆波兰表达式建立二叉树 
	stack <ExpressionTree*> nodes;	//树栈 
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

void dlr(ExpressionTree* tree) {	//前序遍历 
	if (tree == nullptr)
		return;
	else {
		cout << tree->data << " ";
		dlr(tree->left);
		dlr(tree->right);
	}
}

void lrd(ExpressionTree* tree) {	//后序遍历 
	if (tree == nullptr)
		return;
	else {
		lrd(tree->left);
		lrd(tree->right);
		cout << tree->data << " ";
	}
}





