
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T57 {

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

	//找寻数组中只出现一次的两个数字，其余数字均出现两次
	void FindNumsAppearOnce(int*, int, int&, int&);
	int GetIndexOfNum1(int);
	bool isOneInIndex(int, int);

	//找寻数组中只出现一个的唯一一个数字，其余数字均出现三次
	int FindNumAppearOnce(int*, int);

	int FindNumAppearOnce(int* data, int len) {
		//判断异常
		if (data == nullptr || len <= 0) {
			isExcption = true;
			return 0;
		}

		//遍历数组每一个元素，累加计算每个元素每一位上的和
		int indexSum[32] = { 0 };

		for (int i = 0; i < len; i++) {
			//累加当前元素的各位上的和，整型元素共32位

			//各位遍历时不希望右移数据元素更改数据，而选择移动掩码来进行下一位的累加和计算
			int indexMask = 1;

			for (int j = 31; j >= 0; j--) {
				//低位起记录当前位上的值
				int result = data[i] & indexMask;

				if (result != 0) {
					//若当前位值为1，则累加1，而非累加result，是该位的累加和不再考虑低位
					indexSum[j] += 1;
				}

				//进行下一位的判断
				indexMask <<= 1;
			}

		}

		//计算只出现一次数字的值，以位为单位计算最终得到Num值
		int Num = 0;

		for (int i = 0; i < 32; i++) {
			Num <<= 1;
			Num += indexSum[i] % 3;
		}

		return Num;

	}

	bool isOneInIndex(int Num, int index) {
		//右移index次到达index位
		Num >> index;
		//判断该位是否为1
		return Num & 1;
	}

	int GetIndexOfNum1(int Num) {
		int index = 0;
		//自低位开始判断是否为1，若不是则右移，但注意防止溢出，注意边界判断，共 8*sizeof(int) 位
		while (((Num & 1) == 0) && (index < 8 * sizeof(int))) {
			Num >>= 1;
			index++;
		}

		return index;
	}

	void FindNumsAppearOnce(int* data, int len, int& Num1, int& Num2) {
		//判断异常
		if (data == nullptr || len <= 0) {
			isExcption = true;
			return;
		}

		//首次遍历数组，求得所有数字的异或结果
		int ExclusiveOr = 0;
		for (int i = 0; i < len; i++) {
			ExclusiveOr ^= data[i];
		}

		//求得异或结果从低位记起 1 第一次出现的位置
		int FirstIndex = GetIndexOfNum1(ExclusiveOr);

		//将数组分成两组 一组FirstIndex位为0 一组FirstIndex位为1
		//分别计算两组的异或结果，结果即为两个出现次数为1的数字

		Num1 = 0;
		Num2 = 0;

		for (int i = 0; i < len; i++) {
			if (isOneInIndex(data[i], FirstIndex)) {
				Num1 ^= data[i];
			}
			else {
				Num2 ^= data[i];
			}
		}
	}


	void test() {

		test1();	
		test2();
		test3();
		test4();	
		test5();
		
	}
	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		int data[] = { 1,1,2,2,1,2,3 };

		int nums = FindNumAppearOnce(data, 7);

		if (!isExcption) {
			if (nums == 3) {
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

		int data[] = { 1,1,1 };

		int nums = FindNumAppearOnce(data, 3);

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
	void test3() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test3:" << endl;

		int data[] = { 1 };
		int num1;
		int num2;
		int nums = FindNumAppearOnce(data, 1);

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

		int data[] = { 1 };
		int num1;
		int num2;
		int nums = FindNumAppearOnce(nullptr, 7);

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

		int data[] = { -1 };

		int nums = FindNumAppearOnce(data, 1);

		cout << "test5:" << endl;
		if (!isExcption) {
			if (nums == -1) {
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

using namespace T57;

//int main() {
//	test();
//}
