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

	//首先判断当前判定模式字符的下一位是否为*
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
			//第一个字符匹配,两个匹配字符串指针均后移一位
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
		cout << "异常";
	}
	else {
		cout << "failed";
	}
}