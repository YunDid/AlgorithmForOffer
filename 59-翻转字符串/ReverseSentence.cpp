
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T59 {

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
	void test9();

	bool isExcption = false;
	
	//翻转字符串
	void ReverseWords(char*, char*);
	char* ReverseSentence(char*);

	//字符串的左旋
	char* LeftRotateString(char*, int);

	char* LeftRotateString(char* pStr, int n) {
		//判断异常
		if (pStr == nullptr || *pStr == '\0') {
			isExcption = true;
			return nullptr;
		}

		char* pStart = pStr;
		char* pEnd = pStart;

		//设置范围指针对的范围，使pEnd指向字符串尾部
		int num = 0;

		while (*pEnd != '\0') {
			pEnd++;
			num++;
		}

		if (n > num) {
			isExcption = true;
			return nullptr;
		}

		pEnd--;

		//翻转整个字符串
		ReverseWords(pStart, pEnd);

		//对指定范围进行翻转
		//将需要左旋子字符串进行翻转
		ReverseWords(pEnd - n + 1, pEnd);
		//将不需要左旋的字符串进行恢复
		ReverseWords(pStart, pEnd - n);

		return pStr;

	}

	char* ReverseSentence(char* pSen) {
		//判断异常
		if (pSen == nullptr || *pSen == '\0') {
			isExcption = true;
			return nullptr;
		}

		char* pStart = pSen;
		char* pEnd = pStart;

		//设置范围指针对的范围，使pEnd指向字符串尾部
		while (*pEnd != '\0') {
			pEnd++;
		}

		pEnd--;

		//翻转整个字符串
		ReverseWords(pStart, pEnd);

		//翻转每个单词
		//重置范围指针对指向范围
		pStart = pEnd = pSen;

		while (*pStart != '\0') {
			if (*pStart == ' ' && *pEnd == ' ') {
				pStart++;
				pEnd++;
			}
			else if (*pEnd == ' ' || *pEnd == '\0') {
				//翻转单词
				ReverseWords(pStart, --pEnd);
				pStart = ++pEnd;
			}
			else {
				pEnd++;
			}
		}

		return pSen;
	}

	void ReverseWords(char* pStart, char* pEnd) {
		//判断异常
		if (pStart == nullptr || pEnd == nullptr) {
			isExcption = true;
			return;
		}

		while (pStart < pEnd) {
			char temp = *pStart;
			*pStart = *pEnd;
			*pEnd = temp;

			//缩小范围
			pStart++;
			pEnd--;
		}
	}


	void test() {

		//test1();
		//test2();
		//test3();
		//test4();
		//test5();
		test6();
		test7();
		test8();
		test9();

	}
	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		char a[] = "I am a student.";
		char *pReverse = ReverseSentence(a);
		char pExpected[] = "student. a am I";

		if (!isExcption) {
			if (strcmp(pReverse, pExpected) == 0) {
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

	void test2() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test2:" << endl;

		char a[] = "student.";
		char *pReverse = ReverseSentence(a);
		char pExpected[] = "student.";

		if (!isExcption) {
			if (strcmp(pReverse, pExpected) == 0) {
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

		char a[] = "";
		char *pReverse = ReverseSentence(a);
		char pExpected[] = "";

		if (!isExcption) {
			if (strcmp(pReverse, pExpected) == 0) {
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

		char a[] = "student.";
		char *pReverse = ReverseSentence(nullptr);
		char pExpected[] = "student.";

		if (!isExcption) {
			if (strcmp(pReverse, pExpected) == 0) {
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

		cout << "test5:" << endl;

		char a[] = "    ";
		char *pReverse = ReverseSentence(a);
		char pExpected[] = "    ";

		if (!isExcption) {
			if (strcmp(pReverse, pExpected) == 0) {
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

		cout << "test6:" << endl;

		char a[] = "student";
		char *pReverse = LeftRotateString(a, 2);
		char pExpected[] = "udentst";

		if (!isExcption) {
			if (strcmp(pReverse, pExpected) == 0) {
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

		cout << "test7:" << endl;

		char a[] = "student";
		char *pReverse = LeftRotateString(a, 6);
		char pExpected[] = "tstuden";

		if (!isExcption) {
			if (strcmp(pReverse, pExpected) == 0) {
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

	void test8() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test8:" << endl;

		char a[] = "student";
		char *pReverse = LeftRotateString(a, 0);
		char pExpected[] = "student";

		if (!isExcption) {
			if (strcmp(pReverse, pExpected) == 0) {
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

	void test9() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test9:" << endl;

		char a[] = "";
		char *pReverse = LeftRotateString(a, 0);
		char pExpected[] = "";

		if (!isExcption) {
			if (strcmp(pReverse, pExpected) == 0) {
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

using namespace T59;

//int main() {
//	test();
//}
