#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
using namespace std;

namespace T45 {

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	int GetNum(int);
	int GetDiditNums(int);
	int GetNumCore(int, int);
	int GetHead(int);

	int GetHead(int digit) {
		if (digit == 1) {
			return 0;
		}
		else {
			return (int)(pow(10, digit - 1));
		}
	}

	int GetNumCore(int index, int digit) {
		//��ȡdigitλ������λ����
		int NumHead = GetHead(digit);
		//�ж�indexλ��λ���ĸ�������������
		int indexInNum = NumHead + index / digit;
		//�ж�indexλ����indexInNum��������������Ҳ��ƫ����
		int offSetRight = digit - index % digit - 1;
		//ȡ��ֵindex��
		for (int i = 0; i < offSetRight; i++) {
			indexInNum /= 10;
		}

		return indexInNum % 10;
	}

	int GetDiditNums(int digit) {
		if (digit == 1) {
			return 10;
		}
		else {
			return 9 * (int)(pow(10, digit - 1));
		}

	}

	int GetNum(int index) {
		//�쳣�ж�
		//����Ի������踴ԭ
		isExcption = false;

		if (index < 0) {
			isExcption = true;
			return 0;
		}

		//��Χɸѡλ��ĳλ����Χ��
		int digit = 1;
		while (true) {
			//��1λ����ʼ����nλ�������ڵ�λ����Χ
			int digitNums = GetDiditNums(digit);
			if (index < digitNums * digit) {
				//����nλ������digitλ����Χ��
				return GetNumCore(index, digit);
			}
			//nλ��������digitλ���ķ�Χ�ڣ����±���
			index -= digitNums * digit;
			digit++;
		}
	}

	void test() {

		test1();
		test2();
		test3();
		test4();

	}
	void test1() {
		
		cout << "test1:" << endl;
		if (!isExcption) {
			if (GetNum(0) == 0) {
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
		if (!isExcption) {
			if (GetNum(-1) == 0) {
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
			if (GetNum(21) == 5) {
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
			if (GetNum(10) == 1) {
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

using namespace T45;

//int main() {
//	test();
//}
