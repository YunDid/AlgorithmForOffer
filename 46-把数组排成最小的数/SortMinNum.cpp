

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
using namespace std;

namespace T46 {

	#pragma warning(disable:4996);

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	//设置全局拼接数暂存字符串
	int MaxLen = 10;
	char* PlusOne = new char[MaxLen * 2 + 1];
	char* PlusTwo = new char[MaxLen * 2 + 1];

	int Compare(const void*, const void*);
	void SortMinNum(int*, int);
	
	//比较规则
	int Compare(const void* strNum1, const void* strNum2) {
		//拼接后字符串PlusOne strNum1在前，strNum2在后
		strcpy(PlusOne, *(char**)strNum1);
		strcat(PlusOne, *(char**)strNum2);

		//拼接后字符串PlusTwo strNum2在前，strNum1在后
		strcpy(PlusTwo, *(char**)strNum2);
		strcat(PlusTwo, *(char**)strNum1);

		//若返回值小于0 strNum1在前，大于0 strNum1在后，等于0 无法确定
		return strcmp(PlusOne, PlusTwo);
	}

	void SortMinNum(int* intNum, int len) {
		//异常判断
		if (intNum == nullptr || len <= 0) {
			isExcption = true;
			return;
		}

		//将整数数组元素存于二维字符数组中
		char** strNum = new char* [len];

		for (int i = 0; i < len; i++) {
			strNum[i] = new char[MaxLen + 1];
			//将整数输入到字符串中
			sprintf(strNum[i], "%d", intNum[i]);
		}

		//对该二维字符数组进行排序
		qsort(strNum, len, sizeof(char*), Compare);

		//输出拼接后的最小数字
		cout << "最小数字:" << endl;

		for (int i = 0; i < len; i++) {
			cout << strNum[i];
		}

		//内存回收
		for (int i = 0; i < len; i++) {
			delete[] strNum[i];
		}

		delete strNum;
	}

	void test() {

		test1();
		/*test2();
		test3();
		test4();*/

	}
	void test1() {

		cout << "test1:" << endl;
		int a[] = { 222,223,224 };
		SortMinNum(a, 3);
	}
	void test2() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test2:" << endl;
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
	void test3() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test3:" << endl;
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

using namespace T46;

//int main() {
//	test();
//}
