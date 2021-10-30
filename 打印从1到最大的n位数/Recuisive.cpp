#include<iostream>
using namespace std;

void printNumCore2(char*);
void permutation(char*, int, int);
void printNum2(int);

void test8();

bool xxfailed = false;

//int main() {
//	test8();
//}

void printNum2(int n) {
	//�쳣����
	if (n <= 0) {
		xxfailed = true;
		return;
	}

	//���Ǵ������⣬�����ַ��������������������(�˴�ѡ���ַ���)
	char* str = new char[n + 1];
	memset(str, '0', n);
	str[n] = '\0';

	//�ӵ�һλ��ʼ�ݹ�����
	for (int i = 0; i < 10; i++) {
		str[0] = i + '0';
		permutation(str, n, 0);
	}

	//��ֹ�ڴ�й©
	delete[] str;
}

void permutation(char* str, int length, int index) {
	
	//base case
	if (index == length - 1) {
		printNumCore2(str);
		return;
	}

	for (int i = 0; i < 10; i++) {
		str[index + 1] = i + '0';
		permutation(str, length, index + 1);
	}
}

void printNumCore2(char* str) {
	//�����ж��Ƿ�Ϊ��һ���������ı���
	bool first = false;
	int len = strlen(str);
	for (int i = 0; i <= len; i++) {

		if (!first&&str[i] != '0') {
			first = true;
		}
		if (first)
			cout << str[i];
	}
	cout << " ";
}

void test8() {
	int n = 2;
	printNum2(n);
}