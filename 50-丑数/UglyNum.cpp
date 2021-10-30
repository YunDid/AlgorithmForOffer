
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T50 {

	#pragma warning(disable:4996);

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	bool isUglyNum(int);
	int getUglyNum(int);

	int getUglyNum2(int);
	int getMin(int, int, int);

	int getMin(int n1, int n2, int n3) {
		int min;
		if (n1 < n2) {
			min = n1;
		}
		else {
			min = n2;
		}
		if (n3 < min) {
			min = n3;
		}

		return min;
	}

	int getUglyNum2(int num) {
		//�쳣�ж�
		if (num <= 0) {
			isExcption = true;
			return 0;
		}

		//������С��������ĳ�������
		int* Ugly = new int[num];
		Ugly[0] = 1;

		//������־ָ�룬�ֱ�ָ���һ�� ��2����3����5 ����Ŀǰ�������ĳ���Ԫ��
		int* Multiply2 = Ugly;
		int* Multiply3 = Ugly;
		int* Multiply5 = Ugly;

		//����ָ����һ�������ĽǱ��־,���ڱ�����¼ǰnum������
		int pNextUgly = 1;

		while (pNextUgly < num) {
			//��ȡ��ǰ������
			int min = getMin(*Multiply2 * 2, *Multiply3 * 3, *Multiply5 * 5);
			Ugly[pNextUgly] = min;

			//���¶�λ������־ָ��,ʹ�ֱ�ָ���һ�� ��2����3����5 ����Ŀǰ�������ĳ���Ԫ��
			//�ֱ��2����3����5 С�ڵ���Ŀǰ�������ĳ���Ԫ��һ���Ѿ�λ�ڳ���������
			while (*Multiply2 * 2 <= min) {
				Multiply2++;
			}
			while (*Multiply3 * 3 <= min) {
				Multiply3++;
			}
			while (*Multiply5 * 5 <= min) {
				Multiply5++;
			}

			//���±�����ֱ����������Ԫ����num�������ó���num������
			pNextUgly++;
		}

		int uglyNum = Ugly[pNextUgly - 1];

		//�����ڴ�
		delete[] Ugly;
		Ugly = nullptr;
		Multiply2 = nullptr;
		Multiply3 = nullptr;
		Multiply5 = nullptr;

		return uglyNum;
	}

	bool isUglyNum(int num) {
		//����ֻ����2,3,5���ӣ���ÿ�����ӳ�����Ϊ1��Ϊ����
		while (num % 2 == 0) {
			num /= 2;
		}
		while (num % 3 == 0) {
			num /= 3;
		}
		while (num % 5 == 0) {
			num /= 5;
		}

		if (num == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	int getUglyNum(int num) {
		//�쳣�ж�
		if (num <= 0) {
			isExcption = true;
			return 0;
		}

		//��¼��ǰ���������
		int number = 0;
		int uglyNum = 0;

		while (uglyNum < num) {
			//������1��ʼ������
			number++;

			if (isUglyNum(number)) {
				uglyNum++;
			}		
		}

		return number;
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

		int nums = getUglyNum2(1);
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
			cout << "�쳣!" << endl;
		}
	}
	void test2() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test2:" << endl;

		int nums = getUglyNum2(1500);
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
			cout << "�쳣!" << endl;
		}
	}
	void test3() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test3:" << endl;

		int nums = getUglyNum2(0);
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

using namespace T50;

//int main() {
//	test();
//}
