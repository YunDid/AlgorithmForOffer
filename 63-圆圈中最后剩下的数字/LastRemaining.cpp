
#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
#include<algorithm>
#include<functional>
#include<list>
#include<string>
using namespace std;

namespace T63 {

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

	//ԲȦ�����ʣ�µ�����
	int LastRemaining(int, int);

	int LastRemaining(int n, int m) {
		//�ж��쳣
		if (n <= 0 || m <= 0) {
			isExcption = true;
			return -1;
		}

		//ʹ��˫������ģ�⻷״����
		list<int> RingList;

		//��0��n-1��Ԫ��ѹ�뵽������
		for (int i = 0; i < n; i++) {
			RingList.push_back(i);
		}

		//���ñ���������
		auto currentIte = RingList.begin();

		//�޳���0��ĵ�m��Ԫ��,ֱ����ʣһ��Ԫ��
		while (RingList.size() > 1) {
			//��λ���������Ե�ǰԪ����ĵ�m��Ԫ��
			for (int i = 1; i < m; i++) {
				currentIte++;
				if (currentIte == RingList.end()) {
					//ͨ���ֶ�������ģ�⻷������
					currentIte = RingList.begin();
				}
			}

			//��¼��״�����е�ǰԪ�ص���һ��Ԫ��
			auto nextIte = ++currentIte;
			if (nextIte == RingList.end()) {
				nextIte = RingList.begin();
			}

			//�ָ�currentIte������ָ��Ԫ��
			currentIte--;

			//�޳�Ԫ��
			RingList.erase(currentIte);

			//���±���
			currentIte = nextIte;
		}

		return *currentIte;

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

		int lastRemaining = LastRemaining(5, 3);

		if (!isExcption) {
			if (lastRemaining == 3) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << lastRemaining << endl;
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

		int lastRemaining = LastRemaining(0, 0);

		if (!isExcption) {
			if (true) {
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

		int lastRemaining = LastRemaining(1, 2);

		if (!isExcption) {
			if (lastRemaining == 0) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << lastRemaining << endl;
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

		int lastRemaining = LastRemaining(5, 3);

		if (!isExcption) {
			if (lastRemaining == 4) {
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

		int lastRemaining = LastRemaining(4000, 997);

		if (!isExcption) {
			if (lastRemaining == 1027) {
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

		int lastRemaining = LastRemaining(5, 3);

		if (!isExcption) {
			if (lastRemaining == 4) {
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

		int lastRemaining = LastRemaining(5, 3);

		if (!isExcption) {
			if (lastRemaining == 4) {
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

		int lastRemaining = LastRemaining(5, 3);

		if (!isExcption) {
			if (lastRemaining == 4) {
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

using namespace T63;

//int main() {
//	test();
//}
