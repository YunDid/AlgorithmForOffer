
#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
#include<algorithm>
#include<functional>
#include<list>
#include<string>
using namespace std;

namespace T66 {

	#pragma warning(disable:4996);

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	//加法计算 - 循环
	int PlusNotByRecursive(int, int);

	int PlusNotByRecursive(int num1, int num2) {


		do {

			//a 记录两数不产生进位的和 异或运算结果
			int NoCarrySum = num1 ^ num2;
			//b 记录两数产生进位的和 与运算结果后左移一位
			int Carry = (num1 & num2) << 1;
			//下次循环计算a+b，但是在进行下次计算之前需要记录本次计算的结果作下次的加数
			num1 = NoCarrySum;
			num2 = Carry;

		} while (num2 != 0);
	
		return num1;
	}

	//加法计算 - 递归
	int PlusByRecursive(int, int);

	int PlusByRecursive(int num1, int num2) {

		//base case 
		if (num2 == 0) {
			return num1;
		}

		//记录两数不产生进位的和 异或运算结果
		int NoCarrySum = num1 ^ num2;
		//记录两数产生进位的和 与运算结果后左移一位
		int Carry = (num1 & num2) << 1;
		//计算上述两个结果的和
		return PlusByRecursive(NoCarrySum, Carry);
	}

	void test() {

		test1();
		test2();
		test3();
		test4();

	}

	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		int sum = PlusNotByRecursive(0, 0);

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

	void test2() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test2:" << endl;

		int sum = PlusNotByRecursive(5, 17);

		if (!isExcption) {
			if (sum == 22) {
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

		int sum = PlusNotByRecursive(-100, 100);

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
	void test4() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test4:" << endl;

		int sum = PlusNotByRecursive(0, 10);

		if (!isExcption) {
			if (sum == 10) {
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


}

using namespace T66;

//int main() {
//	test();
//}
