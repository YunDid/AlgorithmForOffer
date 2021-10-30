
#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
#include<algorithm>
#include<functional>
#include<list>
#include<string>
using namespace std;

namespace T66 {

	#pragma warning(disable:4996);

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	//�ӷ����� - ѭ��
	int PlusNotByRecursive(int, int);

	int PlusNotByRecursive(int num1, int num2) {


		do {

			//a ��¼������������λ�ĺ� ���������
			int NoCarrySum = num1 ^ num2;
			//b ��¼����������λ�ĺ� ��������������һλ
			int Carry = (num1 & num2) << 1;
			//�´�ѭ������a+b�������ڽ����´μ���֮ǰ��Ҫ��¼���μ���Ľ�����´εļ���
			num1 = NoCarrySum;
			num2 = Carry;

		} while (num2 != 0);
	
		return num1;
	}

	//�ӷ����� - �ݹ�
	int PlusByRecursive(int, int);

	int PlusByRecursive(int num1, int num2) {

		//base case 
		if (num2 == 0) {
			return num1;
		}

		//��¼������������λ�ĺ� ���������
		int NoCarrySum = num1 ^ num2;
		//��¼����������λ�ĺ� ��������������һλ
		int Carry = (num1 & num2) << 1;
		//����������������ĺ�
		return PlusByRecursive(NoCarrySum, Carry);
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

		int sum = PlusNotByRecursive(0, 0);

		if (!isExcption) {
			if (sum == 0) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << sum << endl;
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

		int sum = PlusNotByRecursive(5, 17);

		if (!isExcption) {
			if (sum == 22) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << sum << endl;
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

		int sum = PlusNotByRecursive(-100, 100);

		if (!isExcption) {
			if (sum == 0) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << sum << endl;
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

		int sum = PlusNotByRecursive(0, 10);

		if (!isExcption) {
			if (sum == 10) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << sum << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}
	}


}

using namespace T66;

//int main() {
//	test();
//}
