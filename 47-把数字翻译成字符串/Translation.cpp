

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T47 {
	#pragma warning(disable:4996);

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	bool Concat(char*, char*);

	bool Concat(char cnum1, char cnum2) {

		bool result = false;

		int num1 = cnum1 - '0';
		int num2 = cnum2 - '0';

		int concat = num1 * 10 + num2;

		if (concat >= 10 && concat <= 25) {
			result = true;
		}

		return result;
	}

	int TranslationNums(int);
	int RecursiveTranslationNums(int);

	int TranslationNumsCore(const string& num);
	int RecursiveTranslationNumsCore(char* num);

	int RecursiveTranslationNums(int num) {
		//异常判断
		if (num < 0) {
			isExcption = true;
			return 0;
		}
		char arr[10];
		sprintf(arr, "%d", num);
		return RecursiveTranslationNumsCore(arr);
	}

	int RecursiveTranslationNumsCore(char* num) {
		//base case
		if ((*(num + 1)) == '\0') {
			return 1;
		}

		int count = 0;
		//当前元素不与后一个元素组合
		count += RecursiveTranslationNumsCore(num + 1);
		//当前元素与后一个元素组合
		if (Concat(*num, *(num + 1))) {
			if ((*(num + 2)) != '\0')
				count += RecursiveTranslationNumsCore(num + 2);
			else
				count += 1;
		}

		return count;
	}

	int TranslationNums(int num) {
		//异常判断
		if (num < 0) {
			isExcption = true;
			return 0;
		}
		string n = to_string(num);
		return TranslationNumsCore(n);
	}

	int TranslationNumsCore(const string& num) {
		//设置记录各个位置起可翻译的字符串数结果，避免重复计算
		int* counts = new int[num.length()];
		//设置记录从当前位置元素开始的可翻译字符串数
		int count = 0;

		//从后向前遍历字符串，直至计算出第一个位置起的可翻译字符串数
		for (int i = num.length() - 1; i >= 0; i--) {
			//清零，计算当前位置作起始位置的可翻译字符串数
			count = 0;
			//若当前元素为末尾元素，则只能翻译1种字符串
			if (i == num.length() - 1) {
				count += 1;
			}
			else {
				//否则当前元素作起始位置的可翻译字符串数等于下一个位置的结果
				count += counts[i + 1];
			}

			if (i != num.length() - 1) {
				//若不为末尾元素，判断当前元素能否与后一个元素拼接
				if (Concat(num[i], num[i + 1])) {
					//若可拼接但是当前元素为倒数第二个元素，则可翻译字符串数增1
					if (i == num.length() - 2) {
						count += 1;
					}
					else {
						count += counts[i + 2];
					}
				}
			}

			counts[i] = count;
		}

		//释放内存
		delete[] counts;

		return count;
	}

	void test() {

		test1();
		/*test2();
		test3();
		test4();*/

	}
	void test1() {

		cout << "test1:" << endl;
		int nums = TranslationNums(12258);
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

using namespace T47;

//int main() {
//	test();
//}
