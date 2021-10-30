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
	//异常处理
	if (n <= 0) {
		xxfailed = true;
		return;
	}

	//考虑大数问题，设置字符串或者数组来存放数字(此处选择字符串)
	char* str = new char[n + 1];
	memset(str, '0', n);
	str[n] = '\0';

	//从第一位开始递归排列
	for (int i = 0; i < 10; i++) {
		str[0] = i + '0';
		permutation(str, n, 0);
	}

	//防止内存泄漏
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
	//设置判断是否为第一个非零数的变量
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