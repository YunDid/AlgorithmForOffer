
#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
#include<algorithm>
#include<functional>
#include<list>
#include<string>
using namespace std;

namespace T64 {

#pragma warning(disable:4996);

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();
	void test5();
	//void test6();
	//void test7();
	//void test8();

	bool isExcption = false;

	//股票的最大利润
	int MaxDiff(const int*, int);

	int MaxDiff(const int* data, int length) {
		//判断异常
		if (data == nullptr || length < 2) {
			isExcption = true;
			return 0;
		}

		//设置记录股票最小买入点与当前卖出点的指针
		int smallestBuy = 0;
		int curSell = 1;

		//打擂记录big指向的元素作卖出点的最大利润
		int maxDiff = data[curSell] - data[smallestBuy];

		//记录上一次卖出点的价格并向下遍历
		int preSell = curSell++;

		//遍历剩余元素，记录剩余元素作卖出点的最大利润
		while (curSell < length) {
			//若上一次卖出点的值小于最小买入点的值，则应在上一点买入，更新最小买入点
			if (data[preSell] < data[smallestBuy]) {
				smallestBuy = preSell;
			}

			//计算当前最大利润
			int curDiff = data[curSell] - data[smallestBuy];
			//打擂记录到目前为止的最大利润
			if (curDiff >= maxDiff) {
				maxDiff = curDiff;
			}

			//向后遍历
			preSell = curSell;
			curSell++;
		}

		return maxDiff;

	}

	void test() {

		test1();
		test2();
		test3();
		test4();
		test5();
		/*
		test6();
		test7();
		test8();
		*/

	}

	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		int data[] = { 9,11,8,5,7,12,16,14 };
		int maxDiff = MaxDiff(data, 8);

		if (!isExcption) {
			if (maxDiff == 11) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
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

		int data[] = { 9,11 };
		int maxDiff = MaxDiff(data, 2);

		if (!isExcption) {
			if (maxDiff == 2) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
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

		int data[] = { 11,9 };
		int maxDiff = MaxDiff(data, 2);

		if (!isExcption) {
			if (maxDiff == -2) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
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

		int data[] = { 9,11,8,5,7,12,16,14 };
		int maxDiff = MaxDiff(data, 8);

		if (!isExcption) {
			if (maxDiff == 11) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}
	}
	void test5() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test5:" << endl;

		int data[] = { 9,11,8,5,7,12,16,14 };
		int maxDiff = MaxDiff(data, 8);

		if (!isExcption) {
			if (maxDiff == 11) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}
	}

	void test6() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test6:" << endl;

		int data[] = { 9,11,8,5,7,12,16,14 };
		int maxDiff = MaxDiff(data, 8);

		if (!isExcption) {
			if (maxDiff == 11) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}
	}

	void test7() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test7:" << endl;

		int data[] = { 9,11,8,5,7,12,16,14 };
		int maxDiff = MaxDiff(data, 8);

		if (!isExcption) {
			if (maxDiff == 11) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}

	}

	void test8() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test8:" << endl;

		int data[] = { 9,11,8,5,7,12,16,14 };
		int maxDiff = MaxDiff(data, 8);

		if (!isExcption) {
			if (maxDiff == 11) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}
	}


}

using namespace T64;

//int main() {
//	test();
//}
