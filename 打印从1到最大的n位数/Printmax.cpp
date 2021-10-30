#include<iostream>
using namespace std;

bool increment(char*);
void printNum(int);
void printNumCore(char*);
void test7();

bool xfailed = false;

//int main() {
//	test7();
//}

void printNum(int n) {
	//异常处理
	if (n <= 0) {
		xfailed = true;
		return;
	}
	
	//考虑大数问题，设置字符串或者数组来存放数字(此处选择字符串)
	char* str = new char[n + 1];
	memset(str, '0', n);
	str[n] = '\0';

	while (!increment(str)) {
		printNumCore(str);
	}

	//防止内存泄漏
	delete[] str;
}

bool increment(char* str){
	//记录字符串长度
	int len = strlen(str);
	//设置进位值
	int carry = 0;
	//设置返回值判断是否至最大数进位
	bool arrive = false;
	

	for (int i = len - 1; i >= 0; i--) {
		//设置模拟加法的临时数字变量
		int num = str[i] - '0' + carry;
		//若为个位，则直接进行加1即可
		if (i == len - 1) {
			num++;
		}

		if (num >= 10) {
			if (i == 0) {
				arrive = true;
			}
			else {
				//设置进位后，将本位设置为0后写回
				num -= 10;
				str[i] = num + '0';
				carry = 1;
			}
		}
		else {
			//直接写回
			str[i] = num + '0';
			//break作用为:所有的直接加一运算仅作用于个位，其余位的加1运算均来自carry的进位
			break;
		}
	}

	return arrive;
}

void printNumCore(char* str) {
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

void test7() {
	int n = -1;
	printNum(n);
}