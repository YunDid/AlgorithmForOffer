
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T59 {

	#pragma warning(disable:4996);

	//����ԭ������
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
	
	//��ת�ַ���
	void ReverseWords(char*, char*);
	char* ReverseSentence(char*);

	//�ַ���������
	char* LeftRotateString(char*, int);

	char* LeftRotateString(char* pStr, int n) {
		//�ж��쳣
		if (pStr == nullptr || *pStr == '\0') {
			isExcption = true;
			return nullptr;
		}

		char* pStart = pStr;
		char* pEnd = pStart;

		//���÷�Χָ��Եķ�Χ��ʹpEndָ���ַ���β��
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

		//��ת�����ַ���
		ReverseWords(pStart, pEnd);

		//��ָ����Χ���з�ת
		//����Ҫ�������ַ������з�ת
		ReverseWords(pEnd - n + 1, pEnd);
		//������Ҫ�������ַ������лָ�
		ReverseWords(pStart, pEnd - n);

		return pStr;

	}

	char* ReverseSentence(char* pSen) {
		//�ж��쳣
		if (pSen == nullptr || *pSen == '\0') {
			isExcption = true;
			return nullptr;
		}

		char* pStart = pSen;
		char* pEnd = pStart;

		//���÷�Χָ��Եķ�Χ��ʹpEndָ���ַ���β��
		while (*pEnd != '\0') {
			pEnd++;
		}

		pEnd--;

		//��ת�����ַ���
		ReverseWords(pStart, pEnd);

		//��תÿ������
		//���÷�Χָ���ָ��Χ
		pStart = pEnd = pSen;

		while (*pStart != '\0') {
			if (*pStart == ' ' && *pEnd == ' ') {
				pStart++;
				pEnd++;
			}
			else if (*pEnd == ' ' || *pEnd == '\0') {
				//��ת����
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
		//�ж��쳣
		if (pStart == nullptr || pEnd == nullptr) {
			isExcption = true;
			return;
		}

		while (pStart < pEnd) {
			char temp = *pStart;
			*pStart = *pEnd;
			*pEnd = temp;

			//��С��Χ
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
			cout << "�쳣!" << endl;
		}
	}

	void test2() {
		//����Ի������踴ԭ
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
			cout << "�쳣!" << endl;
		}
	}
	void test3() {
		//����Ի������踴ԭ
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
			cout << "�쳣!" << endl;
		}
	}
	void test4() {
		//����Ի������踴ԭ
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
			cout << "�쳣!" << endl;
		}
	}
	void test5() {
		//����Ի������踴ԭ
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
			cout << "�쳣!" << endl;
		}
	}

	void test6() {
		//����Ի������踴ԭ
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
			cout << "�쳣!" << endl;
		}
	}

	void test7() {
		//����Ի������踴ԭ
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
			cout << "�쳣!" << endl;
		}
	}

	void test8() {
		//����Ի������踴ԭ
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
			cout << "�쳣!" << endl;
		}
	}

	void test9() {
		//����Ի������踴ԭ
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
			cout << "�쳣!" << endl;
		}
	}


}

using namespace T59;

//int main() {
//	test();
//}
