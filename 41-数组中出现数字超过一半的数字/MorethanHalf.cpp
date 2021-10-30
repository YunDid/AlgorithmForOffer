#include<iostream>
#include<vector>
using namespace std;

namespace T41 {

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	int LikelyMoreThanHalf(int*,int);
	bool IsValidInput(int*, int);
	bool IsMoreThanHalf(int*, int, int);

	int Partition(int*, int, int, int);
	int MedianMoreThanHalf(int*, int);

	int MedianMoreThanHalf(int* arr, int len) {
		//异常判断
		if (IsValidInput(arr, len)) {
			isExcption = true;
			return 0;
		}

		//记录数组的中位数位置
		int median = len >> 1;

		//获取当前快排划分得到的基数位置
		int start = 0;
		int end = len - 1;
		int pivot = Partition(arr, len, start, end);

		//若此基数位置不为中位数，则在划分后的数中进而求基数位置直到基数位置等于median
		while (median != pivot) {
			if (pivot > median) {
				//在基数左边的数字中寻找
				end = pivot - 1;
				pivot = Partition(arr, len, start, end);
			}
			else {
				//在基数右边的数字中寻找
				start = pivot + 1;
				pivot = Partition(arr, len, start, end);
			}
		}

		//此时基数位置即为中位数位置，该基数可能为要求数，进一步判断
		int result = arr[pivot];

		if (!IsMoreThanHalf(arr, len, result)) {
			isExcption = true;
			result = 0;
		}

		return result;
	}

	int Partition(int* arr, int len, int start, int end) {
		//异常判断
		if (arr == nullptr || len <= 0 || start < 0 || end >= len) {
			isExcption = true;
			return 0;
		}

		//设置small时刻指向当前最后一个比small小的元素
		int small = start - 1;
		//数组某位暂存pivot基数 默认取start元素，此处并未随机

		int pivot = arr[start];
			
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;	

		//遍历数组，以基数为基准进行划分
		for (int index = start; index < end; index++) {
			//若遍历元素比pivot基数小，则small后移，否则不作处理
			if (arr[index] < pivot) {

				small++;
				//若遇到比pivot大的元素后又遇到比pivot小的元素，则small++后交换这两个元素位置
				if (index != small) {
					int temp = arr[index];
					arr[index] = arr[small];
					arr[small] = temp;
				}
			
			}
		}

		//将small指针指向pivot基数应存放位置
		small++;

		//交换基数与第一个比其大的元素
		temp = arr[small];
		arr[small] = arr[end];
		arr[end] = temp;

		return small;
	}

	bool IsMoreThanHalf(int* arr, int len, int result) {

		//设置bool变量返回值
		bool isMoreThanHalf = false;

		//记录result在数组中的出现次数
		int num = 0;
		for (int i = 0; i < len; i++) {
			if (arr[i] == result) {
				num++;
			}
		}

		//设置全局异常判断变量初始为true
		isExcption = true;

		if (num > (len / 2)) {

			isExcption = false;
			isMoreThanHalf = true;
		}

		return isMoreThanHalf;
	}

	bool IsValidInput(int* arr, int len) {
		bool isExc = false;
		if (arr == nullptr || len <= 0) {
			isExc = true;
		}
		return isExc;
	}

	int LikelyMoreThanHalf(int* arr, int len) {
		//异常判断
		if (IsValidInput(arr, len)) {
			isExcption = true;
			return 0;
		}

		//设置变量记录可能数字
		int result = arr[0];
		//设置其可能系数
		int coefficient = 1;

		//挑选出数组中最可能成为result的数字
		for (int i = 0; i < len; i++) {
			if (coefficient == 0) {

				//若此系数减弱至0，则表示该数字不可能为终值，切换至下一个值				
				result = arr[i];
				//重新设置系数为1
				coefficient = 1;

			}
			else if (result == arr[i]) {
				//系数增强
				coefficient++;
			}
			else {
				//系数减弱
				coefficient--;
			}
		}

		//检查result是否为终值
		if (!IsMoreThanHalf(arr, len, result)) {
			isExcption = true;
			result = 0;
		}

		return result;
	}

	void test() {

		/*test1();
		test2();
		test3();*/
		test4();

	}
	void test1() {

	}
	void test2() {

	}
	void test3() {

	}

	void test4() {
		int a[1] = { 1 };
		int result = MedianMoreThanHalf(a, 1);
		if (!isExcption) {
			cout << result << endl;
		}
		else {
			cout << "异常!";
		}
	}

}

using namespace T41;

//int main() {
//	test();
//}