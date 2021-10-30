
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T54 {

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

	//在排序数组中查找数字
	int GetNumOfK(int*, int, int);
	int GetFirstK(int*, int, int, int, int);
	int GetLastK(int*, int, int, int, int);

	//0 - n-1 缺失的数字
	int GetMissingNum(int*, int);

	//数组中数值与下标相等的元素
	int GetNumberSameAsIndex(int*, int);

	int GetNumberSameAsIndex(int* data, int len) {
		//判断异常
		if (data == nullptr || len <= 0) {
			isExcption = true;
			return -1;
		}

		int start = 0;
		int end = len - 1;

		while (start <= end) {

			int mid = (start + end) >> 1;
			if (data[mid] == mid) {
				return mid;
			}
			else if (data[mid] < mid) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}		
		}

		return -1;
	}

	int GetMissingNum(int* data, int len) {
		//判断异常
		if (data == nullptr || len <= 0) {
			isExcption = true;
			return -1;
		}

		//二分查找第一个元素值不等于下标的元素
		int start = 0;
		int end = len - 1;

		while(start <= end) {
			int mid = (start + end) >> 1;
			if (data[mid] != mid) {
				//首先判断该元素是否为非法元素
				if (data[mid] >= len) {
					isExcption = true;
					return -1;
				}
				//进一步判断该元素是否为第一个下标不等于元素值的元素，两种可能
				//- 是首位元素且为缺失元素
				//- 不是首位元素且为缺失元素

				//若数组有序，则该元素与对应角标差值不超过1 --预防性处理
				bool isSort = data[mid] - mid == 1;
				//判断非首位的元素是否为第一个值不等于下标的元素
				bool isMFirst = mid > 0 && data[mid - 1] == mid - 1;
				//判断首位元素是否为第一个一个值不等于下标的元素 --预防性处理
				bool isFFirst = (mid == 0) && isSort;

				if (isFFirst || isMFirst) {
					return mid;
				}
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}

		//考虑仅一个元素0的情况返回1
		if (start == len) {
			return len;
		}

		//若二分遍历完都没有找到，则存在异常
		//非法数字，数组不是排序的
		isExcption = true;
		return -1;

	}

	int GetNumOfK(int* data, int length, int k) {
		//判断异常
		if (data == nullptr || length <= 0) {
			isExcption = true;
			return -1;
		}

		int num = 0;

		//获取基于二分查找的k第一次出现的位置
		int first = GetFirstK(data, length, k, 0, length - 1);
		int last = GetLastK(data, length, k, 0, length - 1);

		if (first != -1 && last != -1) {
			num = last - first + 1;
		}

		return num;

	}

	int GetFirstK(int* data, int len, int k, int start, int end) {
		//base case
		if (start > end) {
			return -1;
		}

		int mid = (start + end) / 2;
		if (data[mid] == k) {
			//若当前中值等于k，判断该值是否为第一个值为k的元素
			if (mid == 0 || (mid > 0 && data[mid - 1] != k)) {
				return mid;
			}
			//若不是，则继续在该元素之前的子数组中查找
			end = mid - 1;

		}
		else if (data[mid] < k) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}

		//二分递归
		GetFirstK(data, len, k, start, end);
	}

	int GetLastK(int* data, int len, int k, int start, int end) {
		//base case
		if (start > end) {
			return -1;
		}

		int mid = (start + end) / 2;
		if (data[mid] == k) {
			//若当前中值等于k，判断该值是否为最后一个值为k的元素
			if (mid == len - 1 || ((mid < (len - 1)) && data[mid + 1] != k)) {
				return mid;
			}
			//若不是，则继续在该元素之后的子数组中查找
			start = mid + 1;

		}
		else if (data[mid] < k) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}

		//二分递归
		GetLastK(data, len, k, start, end);
	}

	void test() {

		/*test1();
		test2();
		test3();
		test4();*/
		test5();
		test6();
		test7();
		test8();

	}
	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		int data[] = { 1,2,3,4 };
		int nums = GetMissingNum(data, 4);

		if (!isExcption) {
			if (nums == 0) {
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

		int data[] = { 0 };
		int nums = GetMissingNum(data, 1);

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
	void test3() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test3:" << endl;

		//int data[] = { 5,4,8,9 };
		int data[] = { 3,2,0,1 };
		int nums = GetMissingNum(data, 4);

		if (!isExcption) {
			if (nums == 0) {
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

		int nums = GetNumOfK(nullptr, 0, 0);

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
	void test5() {
		//多测试环境下需复原
		isExcption = false;

		int nums = GetNumberSameAsIndex(nullptr, 0);

		cout << "test5:" << endl;
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

	void test6() {
		//多测试环境下需复原
		isExcption = false;

		int data[] = { 0,1,2,3 };
		int nums = GetNumberSameAsIndex(data, 4);

		cout << "test6:" << endl;
		if (!isExcption) {
			if (nums == 1) {
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

		int data[] = { -4,-3,-2,5 };
		int nums = GetNumberSameAsIndex(data, 4);

		cout << "test7:" << endl;
		if (!isExcption) {
			if (nums == -1) {
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

	void test8() {
		//多测试环境下需复原
		isExcption = false;

		int data[] = { 0 };
		int nums = GetNumberSameAsIndex(data, 1);

		cout << "test8:" << endl;
		if (!isExcption) {
			if (nums == 0) {
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

using namespace T54;

//int main() {
//	test();
//}
