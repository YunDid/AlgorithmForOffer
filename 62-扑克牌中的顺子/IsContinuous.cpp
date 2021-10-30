
#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T62 {

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

	bool isExcption = false;

	//�˿����е�˳��
	bool IsContinuous(int*, int);
	int Compare(const void*, const void*);

	int Compare(const void* data1, const void* data2) {
		int d1 = *((int*)data1);
		int d2 = *((int*)data2);
		return d1 - d2;
	}


	bool IsContinuous(int* data, int length) {
		//�ж��쳣
		if (data == nullptr || length <= 0) {
			isExcption = true;
			return false;
		}

		//���ü�¼�˿����м�¼ 0:��С�����������ּ�϶�ı���
		int NumOfZero = 0;
		int NumOfGap = 0;

		//�������������
		qsort(data, length, sizeof(int), Compare);

		//��¼������0���ֵĴ���
		for (int i = 0; i < length; i++) {
			if (data[i] == 0) {
				NumOfZero++;
				if (NumOfZero > 2) {
					isExcption = true;
					return false;
				}
			}
		}	

		//��¼�������������ֵ��������ֵļ�϶��С
		int small = NumOfZero;
		int big = small + 1;

		while (big != length) {
			//�ų�����
			if (data[small] == data[big]) {
				return false;
			}
			//�ۼӼ����϶��
			NumOfGap += data[big] - data[small] - 1;
			//���±������ƶ��α�
			small = big++;
		}

		//ͨ���ж�0:��С���Ƿ��ܹ����϶���ж��Ƿ�Ϊ˳��
		return NumOfZero >= NumOfGap ? true : false;

	}

	void test() {

		test1();
		test2();
		test3();
		test4();	
		test5();
		/*
		test6();
		test7();
		test8();
		*/

	}

	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		int data[5] = { 5,4,3,2,1 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == true) {
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

		int data[5] = { 5,3,2,1,0 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == true) {
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

		int data[5] = { 5,1,1,2,3 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == false) {
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

		int data[5] = { 6,1,2,3,4 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == false) {
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

		int data[5] = { 0,0,0,0,0 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == true) {
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

		int data[5] = { 0,0,0,0,0 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == true) {
				if (isContinuous == true) {
					cout << "passed!" << endl;
				}
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

		int data[5] = { 1,2,3,4,5 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == true) {
				if (isContinuous == true) {
					cout << "passed!" << endl;
				}
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

		int data[5] = { 1,2,3,4,5 };

		bool isContinuous = IsContinuous(data, 5);

		if (!isExcption) {
			if (isContinuous == true) {
				if (isContinuous == true) {
					cout << "passed!" << endl;
				}
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

using namespace T62;

//int main() {
//	test();
//}
