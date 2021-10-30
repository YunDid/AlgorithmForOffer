
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T52 {

	#pragma warning(disable:4996);

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	//int copy[4];

	bool isExcption = false;

	int InversePair(int*, int);
	int InversePairCore(int*, int*, int, int);

	int InversePair(int* data, int len) {
		//判断异常
		if (data == nullptr || len <= 0) {
			isExcption = true;
			return 0;
		}

		//设置辅助暂存数组,并初始化为arr
		int* copy = new int[len];
		for (int i = 0; i < len; i++) {
			copy[i] = data[i];
		}

		int count = InversePairCore(data, copy, 0, len - 1);

		//清理内存
		delete[] copy;

		return count;
	}

	int InversePairCore(int* data, int* copy, int start, int end) {
		//base case
		if (start == end) {
			//递归终止条件为划分至仅有一个元素,此时子数组的逆序数为0
			//保证数组有序，将值存入暂存数组
			copy[start] = data[start];
			return 0;
		}

		//设置划分界限,对半划分
		int len = (end - start) / 2;

		//获取左子数组中的逆序数
		int left = InversePairCore(copy, data, start, start + len);
		//获取右子数组中的逆序数
		int right = InversePairCore(copy, data, start + len + 1, end);
		//获取左右子数组合并后的逆序数
		int inNum = 0;
		//设置三个指针，分别指向左右与合并后子数组的末位
		int Lend = start + len;
		int Rend = end;
		int Mend = end;
		//从后向前遍历左右子数组所有元素进行合并
		while (Lend >= start && Rend >= start + len + 1) {
			if (data[Lend] > data[Rend]) {
				//若左子数组的末位元素大于右子树组的末位元素，将大者写入暂存数组
				copy[Mend] = data[Lend];
				//并将相应指针前移
				Mend--;
				Lend--;
				//根据右子数组末位元素位置计算此时逆序数
				inNum += Rend - start - len;
			}else{
				//若左子数组的末位元素小于等于右子树组的末位元素，将大者写入暂存数组
				//此时不构成逆序数
				//并将相应指针前移			
				copy[Mend] = data[Rend];
				Mend--;
				Rend--;
			}
		}

		//定有一个子数组率先存入暂存数组，此时将另一数组元素按序存入暂存数组
		while (Lend >= start) {
			copy[Mend] = data[Lend];
			Mend--;
			Lend--;
		}

		while (Rend >= start + len + 1) {
			copy[Mend] = data[Rend];
			Mend--;
			Rend--;
		}

		return left + right + inNum;
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

		int data[] = { 7,5,6,4 };
		int nums = InversePair(data, 4);

		for (int i : data) {
			cout << i << " ";
		}
		
		cout << endl;

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

	void test2() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test2:" << endl;

		int data[] = { 6,5 };
		int nums = InversePair(data, 2);

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

		int data[] = { 6 };
		int nums = InversePair(data, 1);

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

		int nums = InversePair(nullptr, 0);

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

using namespace T52;

//int main() {
//	test();
//}
