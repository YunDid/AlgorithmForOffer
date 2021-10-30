
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T50 {

	#pragma warning(disable:4996);

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	bool isUglyNum(int);
	int getUglyNum(int);

	int getUglyNum2(int);
	int getMin(int, int, int);

	int getMin(int n1, int n2, int n3) {
		int min;
		if (n1 < n2) {
			min = n1;
		}
		else {
			min = n2;
		}
		if (n3 < min) {
			min = n3;
		}

		return min;
	}

	int getUglyNum2(int num) {
		//异常判断
		if (num <= 0) {
			isExcption = true;
			return 0;
		}

		//设置由小到大排序的丑数数组
		int* Ugly = new int[num];
		Ugly[0] = 1;

		//三个标志指针，分别指向第一个 ×2，×3，×5 大于目前最大丑数的丑数元素
		int* Multiply2 = Ugly;
		int* Multiply3 = Ugly;
		int* Multiply5 = Ugly;

		//设置指向下一个丑数的角标标志,用于遍历记录前num个丑数
		int pNextUgly = 1;

		while (pNextUgly < num) {
			//获取当前最大丑数
			int min = getMin(*Multiply2 * 2, *Multiply3 * 3, *Multiply5 * 5);
			Ugly[pNextUgly] = min;

			//重新定位三个标志指针,使分别指向第一个 ×2，×3，×5 大于目前最大丑数的丑数元素
			//分别×2，×3，×5 小于等于目前最大丑数的丑数元素一定已经位于丑数数组中
			while (*Multiply2 * 2 <= min) {
				Multiply2++;
			}
			while (*Multiply3 * 3 <= min) {
				Multiply3++;
			}
			while (*Multiply5 * 5 <= min) {
				Multiply5++;
			}

			//向下遍历，直至丑数数组元素满num个，即得出第num个丑数
			pNextUgly++;
		}

		int uglyNum = Ugly[pNextUgly - 1];

		//清理内存
		delete[] Ugly;
		Ugly = nullptr;
		Multiply2 = nullptr;
		Multiply3 = nullptr;
		Multiply5 = nullptr;

		return uglyNum;
	}

	bool isUglyNum(int num) {
		//丑数只含有2,3,5因子，将每个因子除尽若为1则为丑数
		while (num % 2 == 0) {
			num /= 2;
		}
		while (num % 3 == 0) {
			num /= 3;
		}
		while (num % 5 == 0) {
			num /= 5;
		}

		if (num == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	int getUglyNum(int num) {
		//异常判断
		if (num <= 0) {
			isExcption = true;
			return 0;
		}

		//记录当前数字与丑数
		int number = 0;
		int uglyNum = 0;

		while (uglyNum < num) {
			//遍历自1开始的数字
			number++;

			if (isUglyNum(number)) {
				uglyNum++;
			}		
		}

		return number;
	}

	void test() {

		test1();
		test2();
		test3();
		//test4();

	}
	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		int nums = getUglyNum2(1);
		if (!isExcption) {
			if (nums == 1) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << nums << endl;
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

		int nums = getUglyNum2(1500);
		if (!isExcption) {
			if (nums == 5) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << nums << endl;
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

		int nums = getUglyNum2(0);
		if (!isExcption) {
			if (nums == 1) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << nums << endl;
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
			if (0) {
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

using namespace T50;

//int main() {
//	test();
//}
