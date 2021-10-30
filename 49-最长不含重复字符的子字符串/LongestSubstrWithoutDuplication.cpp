
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T49 {
	#pragma warning(disable:4996);

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	int LongestSubstrWithoutDuplication(const string&);

	int LongestSubstrWithoutDuplication(const string& str) {
		//异常判断
		if (str.length() == 0) {
			isExcption = true;
			return 0;
		}

		//设置LastAppear数组记录'a'-'z'字符上一次在字符串中出现的位置，若当前未出现，则为-1
		int* LastAppear = new int[26];
		for (int i = 0; i < 26; i++) {
			LastAppear[i] = -1;
		}

		//设置currentSum存储f(i-1)的值
		int currentSubLen = 0;
		//设置maxSum打擂存储最长字符串
		int maxSum = 0;

		//自前向后求得目前第i个元素作满足要求的子字符串末尾时的最长长度
		for (int i = 0; i < str.length(); i++) {
			//判断当前元素是否位于f(i-1)对应的子字符串中

			//获取当前遍历元素在LastAppear数组中的映射关系,从而获取当前元素上次在str中出现的位置
			int index = str[i] - 'a';
			//获取当前元素与上一次出现位置的差值
			int distance;

			if(LastAppear[index] >= 0)
				distance = i - LastAppear[index];

			if (LastAppear[index] < 0 || distance > currentSubLen) {
				//若之前最长子字符串中不含当前位置字符，则子字符串长度增1
				currentSubLen += 1;
			}
			else {
				//若之前最长子字符串中含当前位置字符，则存在重复，需要截断上一次出现位置以及之前的元素
				//此时maxSum才需要更新
				if (currentSubLen >= maxSum) {
					maxSum = currentSubLen;
				}
				currentSubLen = distance;
			}

			//记录当前元素本次在str出现的位置
			LastAppear[index] = i;

		}

		//最后更新maxSum，记录最长不含重复字符的子字符串
		if (currentSubLen >= maxSum) {
			maxSum = currentSubLen;
		}

		//清理内存
		delete[] LastAppear;

		return maxSum;
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

		string str = "abcd";

		int nums = LongestSubstrWithoutDuplication(str);
		if (!isExcption) {
			if (nums == 4) {
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

		string str = "";

		int nums = LongestSubstrWithoutDuplication(str);
		if (!isExcption) {
			if (nums == 53) {
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

		string str = "a";

		int nums = LongestSubstrWithoutDuplication(str);
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

using namespace T49;

//int main() {
//	test();
//}
