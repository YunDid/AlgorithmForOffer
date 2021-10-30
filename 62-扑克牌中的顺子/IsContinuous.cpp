
#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T62 {

#pragma warning(disable:4996);

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();
	void test5();
	void test6();
	void test7();
	void test8();

	bool isExcption = false;

	//扑克牌中的顺子
	bool IsContinuous(int*, int);
	int Compare(const void*, const void*);

	int Compare(const void* data1, const void* data2) {
		int d1 = *((int*)data1);
		int d2 = *((int*)data2);
		return d1 - d2;
	}


	bool IsContinuous(int* data, int length) {
		//判断异常
		if (data == nullptr || length <= 0) {
			isExcption = true;
			return false;
		}

		//设置记录扑克牌中记录 0:大小王，相邻数字间隙的变量
		int NumOfZero = 0;
		int NumOfGap = 0;

		//对数组进行排序
		qsort(data, length, sizeof(int), Compare);

		//记录数组中0出现的次数
		for (int i = 0; i < length; i++) {
			if (data[i] == 0) {
				NumOfZero++;
				if (NumOfZero > 2) {
					isExcption = true;
					return false;
				}
			}
		}	

		//记录数组中所有数字的相邻数字的间隙大小
		int small = NumOfZero;
		int big = small + 1;

		while (big != length) {
			//排除对子
			if (data[small] == data[big]) {
				return false;
			}
			//累加计算间隙数
			NumOfGap += data[big] - data[small] - 1;
			//向下遍历，移动游标
			small = big++;
		}

		//通过判断0:大小王是否能够填补空隙来判断是否为顺子
		return NumOfZero >= NumOfGap ? true : false;

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

		int data[5] = { 5,4,3,2,1 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == true) {
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

		int data[5] = { 5,3,2,1,0 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == true) {
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

		int data[5] = { 5,1,1,2,3 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == false) {
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

		int data[5] = { 6,1,2,3,4 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == false) {
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

		int data[5] = { 0,0,0,0,0 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == true) {
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

		int data[5] = { 0,0,0,0,0 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == true) {
				if (isContinuous == true) {
					cout << "passed!" << endl;
				}
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

		int data[5] = { 1,2,3,4,5 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == true) {
				if (isContinuous == true) {
					cout << "passed!" << endl;
				}
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

		int data[5] = { 1,2,3,4,5 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == true) {
				if (isContinuous == true) {
					cout << "passed!" << endl;
				}
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

using namespace T62;

//int main() {
//	test();
//}
