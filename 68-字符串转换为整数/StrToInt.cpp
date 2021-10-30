
#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
#include<algorithm>
#include<functional>
#include<list>
#include<string>
using namespace std;

namespace T68 {

	#pragma warning(disable:4996);

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();
	void test5();

	bool isExcption = false;

	//字符串转换为整数
	int StrToInt(char*);
	bool isNumber(char*);
	
	bool isNumber(char* str) {

		bool isNum = true;

		int len = strlen(str);

		//判断空串
		if (len == 0) {
			isNum = false;
		}

		//判断是否为数字字符串，含空格判断，以及正负号判断
		for (int i = 0; i < len; i++) {

			//判断首字符是否为+,-号，若均不是，则进而判断是否为数字字符
			if (i == 0 && str[i] == '+' || i == 0 && str[i] == '-') {
				continue;
			}
			//判断剩余字符是否为数字字符
			if (str[i]<'0' || str[i]>'9') {
				isNum = false;
				break;
			}
		}

		return isNum;
	}

	int StrToInt(char* str) {
		//边界异常判断
		if (str == nullptr || !isNumber(str)) {
			isExcption = true;
			return 0;
		}

		//转换字符串
		char*p = str;

		long long num = 0;

		//判断是否为首位
		bool isFirst = true;
		bool isNegative = false;

		while (*p != '\0') {
			//判断正负号
			if (isFirst && (*p) == '-') {
				isNegative = true;

				//向下遍历
				p++;
				//更新首位判断遍历状态
				isFirst = false;

				continue;
			}
			else if (isFirst && (*p) == '+') {
				//向下遍历
				p++;
				//更新首位判断遍历状态
				isFirst = false;

				continue;
			}

			//累加转换为数字
			num = num * 10 + (*p - '0');

			//进行下次前先判断当前是否产生越界溢出,正数判断最大正整数溢出，负数判断最小负整数溢出
			if ((!isNegative && num > 0x7fffffff) || (isNegative && num < (signed int)0x80000000)) {
				isExcption = true;
				return 0;
			}
		
			//向下遍历
			p++;
			//更新首位判断遍历状态
			isFirst = false;
		}

		return isNegative ? -num : num;

	}

	void test() {

		//test1();
		//test2();
		//test3();
		//test4();
		test5();

	}

	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		char a[] = "2147483647";

		//cout << 0x7fffffff;
		//cout << (signed int)0x80000000;

		//cout << numeric_limits<int>::max() << endl;
		//cout << numeric_limits<int>::min() << endl;

		int sum = StrToInt(a);

		if (!isExcption) {
			if (sum == 2147483647) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << sum << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}

	}

	void test2() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test2:" << endl;

		char a[] = "-2147483648";

		int sum = StrToInt(a);

		if (!isExcption) {
			if (sum == -214748364) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << sum << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}

	}
	void test3() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test3:" << endl;

		char a[] = "123";

		int sum = StrToInt(a);

		if (!isExcption) {
			if (sum == 123) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << sum << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}


	}
	void test4() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test4:" << endl;

		char a[] = "";

		int sum = StrToInt(a);

		if (!isExcption) {
			if (sum == 0) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << sum << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}
	}

	void test5() {

		cout << (int)2147483648 << endl;
	}


}

using namespace T68;

//int main() {
//	test();
//}
