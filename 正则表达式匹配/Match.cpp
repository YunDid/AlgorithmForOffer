#include<iostream>
using namespace std;

bool match(char*, char*);
bool matchCore(char*, char*);
void test20();

//int main() {
//	test20();
//}

bool isfalse = false;

bool match(char* str, char* pattern) {
	if (str == nullptr || pattern == nullptr) {
		isfalse = true;
		return false;
	}

	return matchCore(str, pattern);

}
bool matchCore(char* str, char* pattern) {
	//base case
	if (*str == '\0'&&*pattern == '\0') {
		return true;
	}

	if (*str != '\0'&&*pattern == '\0') {
		return false;
	}

	//�����жϵ�ǰ�ж�ģʽ�ַ�����һλ�Ƿ�Ϊ*
	if (*(pattern + 1) == '*') {
		if (*str == *pattern || *pattern == '.'&&*str != '\0') {
			return matchCore(str, pattern + 2) || matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern);
		}
		else {
			return matchCore(str, pattern + 2);
		}
	}
	else {
		if (*str == *pattern || *pattern == '.'&&*str != '\0') {
			//��һ���ַ�ƥ��,����ƥ���ַ���ָ�������һλ
			return matchCore(str + 1, pattern + 1);
		}
	}

	return false;

}
void test20() {
	char str[] = "";
	char pattern[] = "";
	if (match(nullptr, nullptr) == false && !isfalse) {
		cout << "passed";
	}
	else if(isfalse) {
		cout << "�쳣";
	}
	else {
		cout << "failed";
	}
}