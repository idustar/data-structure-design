/*****************************
���ݽṹ�γ����
�żѺ� 1552652
ͬ�ô�ѧ �������

T10 8�������㷨�Ƚϰ��� 
�Ƚ�ð������ѡ������ֱ�Ӳ�
������ϣ�����򡢿������򡢶�
���򡢹鲢���򡢻������������
ʱ�䡢�Ƚϴ����ͽ��������� 
*****************************/ 

#include "t10_sort.h"

int main() {
	start();
	while (true) chooseOperation();
}

void start() {
	cout << "**      �����㷨�Ƚ�      **\n"
		<< "============================\n"
		<< "** 1 --- ð������         **\n"
		<< "** 2 --- ѡ������         **\n"
		<< "** 3 --- ֱ�Ӳ�������     **\n"
		<< "** 4 --- ϣ������         **\n"
		<< "** 5 --- ��������         **\n"
		<< "** 6 --- ������           **\n"
		<< "** 7 --- �鲢����         **\n"
		<< "** 8 --- ��������         **\n"
		<< "** 9 --- �˳�����         **\n"
		<< "============================\n"
		<< "\n������Ҫ������������ĸ�����";
	cin >> n;
	while (n < 2) {
		cout << "���벻�Ϸ�������������Ҫ������������ĸ�����";
		cin >> n;
	}
	//��������� 
	srand(time(0));
	num = new int[n];
	for (int i = 0; i < n; i++)
		num[i] = rand();
}

int* copyArray(int n, int num[]){	//�������� 
	int *newArray = new int[n];
	for (int i = 0; i < n; i++)
		newArray[i] = num[i];
	return newArray;
}

void chooseOperation() {
	cout << "\n��ѡ�������㷨��\t";
	int oper;
	int* num_copy;
	long start, end;
	cin >> oper;
	switch (oper)
	{
	case 1:
		swapTime = 0;
		compareTime = 0;
		num_copy = copyArray(n, num);
		start = clock();
		bubble(n, num_copy);
		end = clock();
		cout << "ð����������ʱ�䣺\t" << TIMER << "��\nð�����򽻻�������\t" << swapTime << "\nð������Ƚϴ�����\t"<<compareTime <<endl;
		break;
	case 2:
		swapTime = 0;
		compareTime = 0;
		num_copy = copyArray(n, num);
		start = clock();
		selection(n, num_copy);
		end = clock();
		cout << "ѡ����������ʱ�䣺\t" << TIMER << "��\nѡ�����򽻻�������\t" << swapTime << "\nѡ������Ƚϴ�����\t" << compareTime << endl;
		break;
	case 3:
		compareTime = 0;
		num_copy = copyArray(n, num);
		start = clock();
		insertion(n, num_copy);
		end = clock();
		cout << "ֱ�Ӳ�����������ʱ�䣺\t" << TIMER << "��\nֱ�Ӳ�������Ƚϴ�����\t" << compareTime << endl;
		break;
	case 4:
		compareTime = 0;
		num_copy = copyArray(n, num);
		start = clock();
		shell(n, num_copy);
		end = clock();
		cout << "ϣ����������ʱ�䣺\t" << TIMER << "��\nϣ������Ƚϴ�����\t" << compareTime << endl;
		break;
	case 5:
		swapTime = 0;
		compareTime = 0;
		num_copy = copyArray(n, num);
		start = clock();
		quick(0, n-1, num_copy);
		end = clock();
		cout << "������������ʱ�䣺\t" << TIMER << "��\n�������򽻻�������\t" << swapTime << "\n��������Ƚϴ�����\t" << compareTime << endl;
		break;
	case 6:
		swapTime = 0;
		compareTime = 0;
		num_copy = copyArray(n, num);
		start = clock();
		heap(n, num_copy);
		end = clock();
		cout << "����������ʱ�䣺\t" << TIMER << "��\n�����򽻻�������\t" << swapTime << "\n������Ƚϴ�����\t" << compareTime << endl;
		
		break;
	case 7:
		compareTime = 0;
		num_copy = copyArray(n, num);
		start = clock();
		merge(0, n - 1, num_copy);
		end = clock();
		cout << "�鲢��������ʱ�䣺\t" << TIMER << "��\n�鲢����Ƚϴ�����\t" << compareTime << endl;
		break;
	case 8:
		num_copy = copyArray(n, num);
		start = clock();
		radix(n, num_copy);
		end = clock();
		cout << "������������ʱ�䣺\t" << TIMER << "��\n";
		break;
	case 9:
		cout << "ллʹ�ã�\n";
		system("pause");
		exit(0);
		break;
	default:
		cout << "δ���������\n";
		break;
	}
}

void swap(int &a, int &b) {	//����Ԫ�� 
	int temp;
	temp = a;
	a = b;
	b = temp;
	swapTime++;
}

bool compare(int a, int b)	//�Ƚ�Ԫ�� 
{
	compareTime++;
	if (a < b) return true; else return false;
}

int power10(int x)	//����10��x�η� 
{
	int ans = 1;
	for (int i = 0; i < x; i++)
		ans *= 10;
	return ans;
}

void bubble(int n, int num[])	//ð������ 
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--)
			if (compare(num[j], num[j - 1]))
				swap(num[j], num[j - 1]);
	}
}

void selection(int n, int num[])	//ѡ������ 
{;
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = n - 1; j > i; j--)
			if (compare(num[j],num[min]))
				min = j;
		swap(num[i], num[min]);
	}
}

void insertion(int n, int num[])	//ֱ�Ӳ������� 
{
	int temp;
	for (int i = 1; i < n; i++) {
		temp = num[i];
		int j = i - 1;
		while (j >= 0 && compare(temp, num[j])) {
			num[j + 1] = num[j];
			j--;
		}
		num[j + 1] = temp;
	}
}

void shell(int n, int num[])	//ϣ������ 
{
	int p;
	for (p = n/2; p > 0; p/=2)
		for (int i = 0; i < p; i++)
			for (int j = i + p; j < n; j = j + p)
				if (compare(num[j], num[j - p])) {
					int temp = num[j];
					int k = j - p;
					while (k >= 0 && compare(temp, num[k])) {
						num[k + p] = num[k];
						k -= p;
					}
					num[k + p] = temp;
				}
}

void quick(int l,int r, int num[])	//�������� 
{
	int mid = num[(l + r) / 2];
	int tl = l - 1;
	int tr = r;
	if (l>r)
		return;
	swap(num[(l + r) / 2], num[r]);
	do {
		while (compare(num[++tl], mid));
		while (tr != 0 && compare(mid, num[--tr]));
		swap(num[tl], num[tr]);
	} while (tl < tr);
	swap(num[tl], num[tr]);
	swap(num[tl], num[r]);
	quick(l, tl-1, num);
	quick(tl+1, r, num);
}


void heapify(int n, int num[], int it)	//����� 
{
	while (it * 2 + 2 < n) {
		if (compare(num[it * 2 + 1], num[it]) && compare(num[it * 2 + 2], num[it]))
			return;
		if (compare(num[it * 2 + 1], num[it * 2 + 2])){
			swap(num[it], num[it * 2 + 2]);
			it = it * 2 + 2;
		} else {
			swap(num[it], num[it * 2 + 1]);
			it = it * 2 + 1;
		}
	}
	if (it * 2 + 1 < n && compare(num[it], num[it * 2 + 1])) {
		swap(num[it], num[it * 2 + 1]);
	}
}

void heap(int n, int num[])	//������ 
{
	for (int i = n - 1; i >= 0; i--) {
		heapify(n, num, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(num[i], num[0]);
		heapify(i, num, 0);
	}
	return;
}

void mergeArr(int l, int mid, int r, int num[])	//�鲢�������� 
{
	int i = l, j = mid + 1, k = 0;
	int* temp = new int[r - l + 1];
	while (i <= mid && j <= r)
		if (compare(num[i],num[j])) {
			temp[k] = num[i];
			i++;
			k++;
		}
		else {
			temp[k] = num[j];
			j++;
			k++;
		}

	while (i <= mid) {
		temp[k] = num[i];
		i++;
		k++;
	}
	while (j <= r) {
		temp[k] = num[j];
		j++;
		k++;
	}

	for (k = 0, i = l; i <= r; i++, k++) {
		num[i] = temp[k];
	}
}

void merge(int l, int r, int num[])	//�鲢���� 
{
	if (l >= r) return;
	int mid = (l + r) / 2;
	merge(l, mid, num);
	merge(mid + 1, r, num);
	mergeArr(l, mid, r, num);
}

void radix(int n, int num[])	//�������� 
{
	int** rd = new int*[10];
	for (int j = 0; j < 10; j++)
		rd[j] = new int[n];

	for (int i = 0; i < 6; i++) {
		for (int x = 0; x < 10; x++)
			for (int y = 0; y < n; y++)
				rd[x][y] = 0;
		for (int m = 0; m < n; m++) {
			int temp = (num[m] / power10(i)) % 10;
			for (int k = 0; k < n; k++)
				if (rd[temp][k] == 0) {
					rd[temp][k] = num[m];
					break;
				}
		}
		for (int j = 0, l = 0; j < 10; j++)
			for (int k = 0; k < n; k++) {
				if (rd[j][k] == 0) continue;
				num[l++] = rd[j][k];
			}
		
	}
}
