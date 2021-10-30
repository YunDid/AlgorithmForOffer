
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T58 {

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
	//排序数组中和为s的数字
	bool FindNumWithSum(int*, int, int, int&, int&);
	//和为s的连续正数序列
	void FindContinuousSequene(int);

	void printSequene(int, int);

	void printSequene(int start, int end) {
		for (int i = start; i <= end; i++) {
			cout << i << " ";
		}
		cout << endl;
	}

	void FindContinuousSequene(int sum) {
		//判断异常
		if (sum < 3) {
			isExcption = true;
			return;
		}
		//设置序列范围指针
		int start = 1;
		int end = 2;

		//记录序列范围中所有数字的和
		int curSum = start + end;

		//遍历找寻满足条件的序列
		while (start < (sum + 1) / 2) {
			//简化版
			if (curSum == sum) {
				printSequene(start, end);
			}

			while (curSum > sum && start < (sum + 1) / 2) {
				//剔除序列中最小的正数，先累减后++
				curSum -= start;
				start++;

				if (curSum == sum) {
					printSequene(start, end);
				}
			}

			//扩大序列的范围，先++后累加
			end++;
			curSum += end;		

			//冗余版
			//if (curSum == sum) {
			//	printSequene(start, end);

			//	end++;
			//	curSum += end;
			//}
			//else if (curSum > sum) {
			//	curSum -= start;
			//	start++;

			//	if (curSum == sum) {
			//		printSequene(start, end);

			//		end++;
			//		curSum += end;
			//	}
			//}
			//else {
			//	//扩大序列的范围，先++后累加
			//	end++;
			//	curSum += end;
			//}
		}
	}

	bool FindNumWithSum(int* data, int length, int Sum, int& Num1, int& Num2) {
		//判断异常
		if (data == nullptr || length <= 0) {
			isExcption = true;
			return false;
		}

		//设置返回值
		bool find = false;

		//设置两个指针分别用于指向Num1与Num2，初始化为排序数组最大值与最小值
		int maxIndex = length - 1;
		int minIndex = 0;

		while (minIndex < maxIndex) {
			int sum = data[maxIndex] + data[minIndex];
			if (sum == Sum) {
				find = true;
				Num2 = data[maxIndex];
				Num1 = data[minIndex];
				break;
			}
			else if (sum < Sum) {
				//若此时指针指向的两个元素和小于Sum,则将指向较小元素的指针后移(数组由小到大排序)
				minIndex++;
			}
			else {
				//若此时指针指向的两个元素和大于Sum,则将指向较大元素的指针后移(数组由小到大排序)
				maxIndex--;
			}
		}

		return find;
	}


	void test() {

		/*test1();
		test2();
		test3();
		test4();
		test5();*/
		test6();
		test7();
		test8();

	}
	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		int data[] = { 1,1,2,2,1,2,3 };
		int num1;
		int num2;
		bool find = FindNumWithSum(data, 7, 3, num1, num2);

		if (!isExcption) {
			if (find == true) {
				if (num1 == 1 && num2 == 2) {
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

	void test2() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test2:" << endl;

		int data[] = { 1,1,2,2,1,2,3 };
		int num1;
		int num2;
		bool find = FindNumWithSum(data, 7, 10, num1, num2);

		if (!isExcption) {
			if (find == true) {
				if (num1 == 1 && num2 == 2) {
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
	void test3() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test3:" << endl;

		int data[] = { 1,1 };
		int num1;
		int num2;
		bool find = FindNumWithSum(data, 2, 2, num1, num2);

		if (!isExcption) {
			if (find == true) {
				if (num1 == 1 && num2 == 1) {
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
	void test4() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test4:" << endl;

		int data[] = { 1 };
		int num1;
		int num2;
		bool find = FindNumWithSum(nullptr, 7, 10, num1, num2);

		if (!isExcption) {
			if (find == true) {
				if (num1 == 1 && num2 == 2) {
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
	void test5() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test5:" << endl;

		int data[] = { 1,1,2,2,1,2,3 };
		int num1;
		int num2;
		bool find = FindNumWithSum(data, 7, 10, num1, num2);

		if (!isExcption) {
			if (find == true) {
				if (num1 == 1 && num2 == 2) {
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

	void test6() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test6:" << endl;

		FindContinuousSequene(3);

		if (!isExcption) {
		}
		else {
			cout << "异常!" << endl;
		}
	}

	void test7() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test7:" << endl;

		FindContinuousSequene(15);

		if (!isExcption) {
		}
		else {
			cout << "异常!" << endl;
		}
	}

	void test8() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test8:" << endl;

		FindContinuousSequene(4);

		if (!isExcption) {
		}
		else {
			cout << "异常!" << endl;
		}
	}


}

using namespace T58;

//int main() {
//	test();
//}
