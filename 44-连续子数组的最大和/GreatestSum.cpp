#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

namespace T44 {

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	int GetGreatestNum(int*, int);

	int GetGreatestNum(int* arr, int len) {
		
		//异常判断
		if (arr == nullptr || len <= 0) {
			isExcption = true;
			return 0;
		}

		//记录第 i-1 元素为尾的最大子数组的和
		int currentSum = 0;
		//记录最大子数组的和
		int MaxNum = arr[0];
		//正向迭代 求i元素为尾的最大子数组和
		for (int i = 0; i < len; i++) {
			if (currentSum <= 0) {
				//如果第 i-1 元素为尾的最大子数组和小于等于0，则舍弃之前元素，当前元素构成的子数组和即为当前位置的最大和
				currentSum = arr[i];
			}
			else {
				//如果第 i-1 元素为尾的最大子数组和大于0，则累加
				currentSum += arr[i];
			}

			//打擂记录最大子数组和
			if (currentSum >= MaxNum) {
				MaxNum = currentSum;
			}
	
		}

		return MaxNum;
	}

	void test() {

		test1();
		test2();
		test3();
		test4();

	}
	void test1() {
		int a[] = { -7,-2,-3,-10,-4,-7,-2,-5 };
		int num = GetGreatestNum(a, 8);

		if (!isExcption) {
			cout << num << endl;
		}
		else {
			cout << "异常！" << endl;
		}
		
	}
	void test2() {

	}
	void test3() {

	}
	void test4() {
				
	}

}

using namespace T44;

//int main() {
//	test();
//}
