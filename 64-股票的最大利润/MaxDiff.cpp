
#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
#include<algorithm>
#include<functional>
#include<list>
#include<string>
using namespace std;

namespace T64 {

#pragma warning(disable:4996);

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();
	void test5();
	//void test6();
	//void test7();
	//void test8();

	bool isExcption = false;

	//��Ʊ���������
	int MaxDiff(const int*, int);

	int MaxDiff(const int* data, int length) {
		//�ж��쳣
		if (data == nullptr || length < 2) {
			isExcption = true;
			return 0;
		}

		//���ü�¼��Ʊ��С������뵱ǰ�������ָ��
		int smallestBuy = 0;
		int curSell = 1;

		//���޼�¼bigָ���Ԫ������������������
		int maxDiff = data[curSell] - data[smallestBuy];

		//��¼��һ��������ļ۸����±���
		int preSell = curSell++;

		//����ʣ��Ԫ�أ���¼ʣ��Ԫ������������������
		while (curSell < length) {
			//����һ���������ֵС����С������ֵ����Ӧ����һ�����룬������С�����
			if (data[preSell] < data[smallestBuy]) {
				smallestBuy = preSell;
			}

			//���㵱ǰ�������
			int curDiff = data[curSell] - data[smallestBuy];
			//���޼�¼��ĿǰΪֹ���������
			if (curDiff >= maxDiff) {
				maxDiff = curDiff;
			}

			//������
			preSell = curSell;
			curSell++;
		}

		return maxDiff;

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

		int data[] = { 9,11,8,5,7,12,16,14 };
		int maxDiff = MaxDiff(data, 8);

		if (!isExcption) {
			if (maxDiff == 11) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
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

		int data[] = { 9,11 };
		int maxDiff = MaxDiff(data, 2);

		if (!isExcption) {
			if (maxDiff == 2) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
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

		int data[] = { 11,9 };
		int maxDiff = MaxDiff(data, 2);

		if (!isExcption) {
			if (maxDiff == -2) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
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

		int data[] = { 9,11,8,5,7,12,16,14 };
		int maxDiff = MaxDiff(data, 8);

		if (!isExcption) {
			if (maxDiff == 11) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
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

		int data[] = { 9,11,8,5,7,12,16,14 };
		int maxDiff = MaxDiff(data, 8);

		if (!isExcption) {
			if (maxDiff == 11) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
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

		int data[] = { 9,11,8,5,7,12,16,14 };
		int maxDiff = MaxDiff(data, 8);

		if (!isExcption) {
			if (maxDiff == 11) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
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

		int data[] = { 9,11,8,5,7,12,16,14 };
		int maxDiff = MaxDiff(data, 8);

		if (!isExcption) {
			if (maxDiff == 11) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
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

		int data[] = { 9,11,8,5,7,12,16,14 };
		int maxDiff = MaxDiff(data, 8);

		if (!isExcption) {
			if (maxDiff == 11) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << maxDiff << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}
	}


}

using namespace T64;

//int main() {
//	test();
//}
