

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
using namespace std;

namespace T46 {

	#pragma warning(disable:4996);

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	//����ȫ��ƴ�����ݴ��ַ���
	int MaxLen = 10;
	char* PlusOne = new char[MaxLen * 2 + 1];
	char* PlusTwo = new char[MaxLen * 2 + 1];

	int Compare(const void*, const void*);
	void SortMinNum(int*, int);
	
	//�ȽϹ���
	int Compare(const void* strNum1, const void* strNum2) {
		//ƴ�Ӻ��ַ���PlusOne strNum1��ǰ��strNum2�ں�
		strcpy(PlusOne, *(char**)strNum1);
		strcat(PlusOne, *(char**)strNum2);

		//ƴ�Ӻ��ַ���PlusTwo strNum2��ǰ��strNum1�ں�
		strcpy(PlusTwo, *(char**)strNum2);
		strcat(PlusTwo, *(char**)strNum1);

		//������ֵС��0 strNum1��ǰ������0 strNum1�ں󣬵���0 �޷�ȷ��
		return strcmp(PlusOne, PlusTwo);
	}

	void SortMinNum(int* intNum, int len) {
		//�쳣�ж�
		if (intNum == nullptr || len <= 0) {
			isExcption = true;
			return;
		}

		//����������Ԫ�ش��ڶ�ά�ַ�������
		char** strNum = new char* [len];

		for (int i = 0; i < len; i++) {
			strNum[i] = new char[MaxLen + 1];
			//���������뵽�ַ�����
			sprintf(strNum[i], "%d", intNum[i]);
		}

		//�Ըö�ά�ַ������������
		qsort(strNum, len, sizeof(char*), Compare);

		//���ƴ�Ӻ����С����
		cout << "��С����:" << endl;

		for (int i = 0; i < len; i++) {
			cout << strNum[i];
		}

		//�ڴ����
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
		//����Ի������踴ԭ
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
			cout << "�쳣!" << endl;
		}
	}
	void test3() {
		//����Ի������踴ԭ
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
			cout << "�쳣!" << endl;
		}
	}
	void test4() {
		//����Ի������踴ԭ
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
			cout << "�쳣!" << endl;
		}
	}

}

using namespace T46;

//int main() {
//	test();
//}
