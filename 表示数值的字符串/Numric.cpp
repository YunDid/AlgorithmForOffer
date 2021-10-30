#include<iostream>
using namespace std;

bool isNum(const char*);
bool isInteger(const char**);
bool isUInteger(const char**);
void test21();

//int main() {
//	test21();
//}

bool isNum(const char* str) {
	
	//�쳣�ж�
	if (str == nullptr) {
		return false;
	}
	//�����ж�A���������Ƿ���������
	bool numric = isInteger(&str);

	//�ж�BС�������Ƿ���������
	if (*str == '.') {
		str++;

		numric = isUInteger(&str) || numric;
	}

	//�ж�Cָ�������Ƿ���������
	if (*str == 'e' || *str == 'E') {
		str++;
		numric = isInteger(&str) && numric;
	}

	//�ж��ַ����Ƿ���ʣ��������ַ�

	numric = numric && *str == '\0';

	return numric;
}

bool isUInteger(const char** str) {
	const char *temp = *str;

	while (**str != '\0' && **str >= '0' && **str <= '9') {
		(*str)++;
	}

	return *str > temp;
}

bool isInteger(const char** str) {
	if (**str == '+' || **str == '-') {
		(*str)++;
	}
	return isUInteger(str);
}

void test21() {
	char str1[] = ".1";
	char str2[] = "1.23";
	char str3[] = "+1.23e+1";
	char str4[] = "+123";
	char str5[] = "-123";
	char str6[] = ".23e10";

	if (isNum(str1))
		cout << str1 << "yes" << endl;
	if (isNum(str2))
		cout << str2 << "yes" << endl;
	if (isNum(str3))
		cout << str3 << "yes" << endl;
	if (isNum(str4))
		cout << str4 << "yes" << endl;
	if (isNum(str5))
		cout << str5 << "yes" << endl;
	if (isNum(str6))
		cout << str6 << "yes" << endl;
}