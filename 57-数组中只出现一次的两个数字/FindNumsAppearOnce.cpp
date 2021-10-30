
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T57 {

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

	//��Ѱ������ֻ����һ�ε��������֣��������־���������
	void FindNumsAppearOnce(int*, int, int&, int&);
	int GetIndexOfNum1(int);
	bool isOneInIndex(int, int);

	//��Ѱ������ֻ����һ����Ψһһ�����֣��������־���������
	int FindNumAppearOnce(int*, int);

	int FindNumAppearOnce(int* data, int len) {
		//�ж��쳣
		if (data == nullptr || len <= 0) {
			isExcption = true;
			return 0;
		}

		//��������ÿһ��Ԫ�أ��ۼӼ���ÿ��Ԫ��ÿһλ�ϵĺ�
		int indexSum[32] = { 0 };

		for (int i = 0; i < len; i++) {
			//�ۼӵ�ǰԪ�صĸ�λ�ϵĺͣ�����Ԫ�ع�32λ

			//��λ����ʱ��ϣ����������Ԫ�ظ������ݣ���ѡ���ƶ�������������һλ���ۼӺͼ���
			int indexMask = 1;

			for (int j = 31; j >= 0; j--) {
				//��λ���¼��ǰλ�ϵ�ֵ
				int result = data[i] & indexMask;

				if (result != 0) {
					//����ǰλֵΪ1�����ۼ�1�������ۼ�result���Ǹ�λ���ۼӺͲ��ٿ��ǵ�λ
					indexSum[j] += 1;
				}

				//������һλ���ж�
				indexMask <<= 1;
			}

		}

		//����ֻ����һ�����ֵ�ֵ����λΪ��λ�������յõ�Numֵ
		int Num = 0;

		for (int i = 0; i < 32; i++) {
			Num <<= 1;
			Num += indexSum[i] % 3;
		}

		return Num;

	}

	bool isOneInIndex(int Num, int index) {
		//����index�ε���indexλ
		Num >> index;
		//�жϸ�λ�Ƿ�Ϊ1
		return Num & 1;
	}

	int GetIndexOfNum1(int Num) {
		int index = 0;
		//�Ե�λ��ʼ�ж��Ƿ�Ϊ1�������������ƣ���ע���ֹ�����ע��߽��жϣ��� 8*sizeof(int) λ
		while (((Num & 1) == 0) && (index < 8 * sizeof(int))) {
			Num >>= 1;
			index++;
		}

		return index;
	}

	void FindNumsAppearOnce(int* data, int len, int& Num1, int& Num2) {
		//�ж��쳣
		if (data == nullptr || len <= 0) {
			isExcption = true;
			return;
		}

		//�״α������飬����������ֵ������
		int ExclusiveOr = 0;
		for (int i = 0; i < len; i++) {
			ExclusiveOr ^= data[i];
		}

		//���������ӵ�λ���� 1 ��һ�γ��ֵ�λ��
		int FirstIndex = GetIndexOfNum1(ExclusiveOr);

		//������ֳ����� һ��FirstIndexλΪ0 һ��FirstIndexλΪ1
		//�ֱ���������������������Ϊ�������ִ���Ϊ1������

		Num1 = 0;
		Num2 = 0;

		for (int i = 0; i < len; i++) {
			if (isOneInIndex(data[i], FirstIndex)) {
				Num1 ^= data[i];
			}
			else {
				Num2 ^= data[i];
			}
		}
	}


	void test() {

		test1();	
		test2();
		test3();
		test4();	
		test5();
		
	}
	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		int data[] = { 1,1,2,2,1,2,3 };

		int nums = FindNumAppearOnce(data, 7);

		if (!isExcption) {
			if (nums == 3) {
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

		int data[] = { 1,1,1 };

		int nums = FindNumAppearOnce(data, 3);

		if (!isExcption) {
			if (nums == 0) {
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

		int data[] = { 1 };
		int num1;
		int num2;
		int nums = FindNumAppearOnce(data, 1);

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

		int data[] = { 1 };
		int num1;
		int num2;
		int nums = FindNumAppearOnce(nullptr, 7);

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
	void test5() {
		//����Ի������踴ԭ
		isExcption = false;

		int data[] = { -1 };

		int nums = FindNumAppearOnce(data, 1);

		cout << "test5:" << endl;
		if (!isExcption) {
			if (nums == -1) {
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

using namespace T57;

//int main() {
//	test();
//}
