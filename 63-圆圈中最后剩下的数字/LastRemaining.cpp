
#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
#include<algorithm>
#include<functional>
#include<list>
#include<string>
using namespace std;

namespace T63 {

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

	//圆圈中最后剩下的数字
	int LastRemaining(int, int);

	int LastRemaining(int n, int m) {
		//判断异常
		if (n <= 0 || m <= 0) {
			isExcption = true;
			return -1;
		}

		//使用双向链表模拟环状链表
		list<int> RingList;

		//将0至n-1的元素压入到链表中
		for (int i = 0; i < n; i++) {
			RingList.push_back(i);
		}

		//设置遍历迭代器
		auto currentIte = RingList.begin();

		//剔除自0起的第m个元素,直至仅剩一个元素
		while (RingList.size() > 1) {
			//定位迭代器于自当前元素起的第m个元素
			for (int i = 1; i < m; i++) {
				currentIte++;
				if (currentIte == RingList.end()) {
					//通过手动设置来模拟环形链表
					currentIte = RingList.begin();
				}
			}

			//记录环状链表中当前元素的下一个元素
			auto nextIte = ++currentIte;
			if (nextIte == RingList.end()) {
				nextIte = RingList.begin();
			}

			//恢复currentIte迭代器指向元素
			currentIte--;

			//剔除元素
			RingList.erase(currentIte);

			//向下遍历
			currentIte = nextIte;
		}

		return *currentIte;

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

		int lastRemaining = LastRemaining(5, 3);

		if (!isExcption) {
			if (lastRemaining == 3) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << lastRemaining << endl;
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

		int lastRemaining = LastRemaining(0, 0);

		if (!isExcption) {
			if (true) {
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

		int lastRemaining = LastRemaining(1, 2);

		if (!isExcption) {
			if (lastRemaining == 0) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << lastRemaining << endl;
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

		int lastRemaining = LastRemaining(5, 3);

		if (!isExcption) {
			if (lastRemaining == 4) {
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
	void test5() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test5:" << endl;

		int lastRemaining = LastRemaining(4000, 997);

		if (!isExcption) {
			if (lastRemaining == 1027) {
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

	void test6() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test6:" << endl;

		int lastRemaining = LastRemaining(5, 3);

		if (!isExcption) {
			if (lastRemaining == 4) {
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

	void test7() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test7:" << endl;

		int lastRemaining = LastRemaining(5, 3);

		if (!isExcption) {
			if (lastRemaining == 4) {
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

	void test8() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test8:" << endl;

		int lastRemaining = LastRemaining(5, 3);

		if (!isExcption) {
			if (lastRemaining == 4) {
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

using namespace T63;

//int main() {
//	test();
//}
