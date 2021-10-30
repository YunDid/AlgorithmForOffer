#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
using namespace std;

namespace T45 {

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	int GetNum(int);
	int GetDiditNums(int);
	int GetNumCore(int, int);
	int GetHead(int);

	int GetHead(int digit) {
		if (digit == 1) {
			return 0;
		}
		else {
			return (int)(pow(10, digit - 1));
		}
	}

	int GetNumCore(int index, int digit) {
		//获取digit位数的首位数字
		int NumHead = GetHead(digit);
		//判断index位数位于哪个数字子序列中
		int indexInNum = NumHead + index / digit;
		//判断index位数于indexInNum子序列中相对于右侧的偏移量
		int offSetRight = digit - index % digit - 1;
		//取终值index数
		for (int i = 0; i < offSetRight; i++) {
			indexInNum /= 10;
		}

		return indexInNum % 10;
	}

	int GetDiditNums(int digit) {
		if (digit == 1) {
			return 10;
		}
		else {
			return 9 * (int)(pow(10, digit - 1));
		}

	}

	int GetNum(int index) {
		//异常判断
		//多测试环境下需复原
		isExcption = false;

		if (index < 0) {
			isExcption = true;
			return 0;
		}

		//范围筛选位于某位数范围中
		int digit = 1;
		while (true) {
			//从1位数开始锁定n位数字所在的位数范围
			int digitNums = GetDiditNums(digit);
			if (index < digitNums * digit) {
				//锁定n位的数在digit位数范围内
				return GetNumCore(index, digit);
			}
			//n位的数不在digit位数的范围内，向下遍历
			index -= digitNums * digit;
			digit++;
		}
	}

	void test() {

		test1();
		test2();
		test3();
		test4();

	}
	void test1() {
		
		cout << "test1:" << endl;
		if (!isExcption) {
			if (GetNum(0) == 0) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
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
		if (!isExcption) {
			if (GetNum(-1) == 0) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
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
		if (!isExcption) {
			if (GetNum(21) == 5) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
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
		if (!isExcption) {
			if (GetNum(10) == 1) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}
	}

}

using namespace T45;

//int main() {
//	test();
//}
