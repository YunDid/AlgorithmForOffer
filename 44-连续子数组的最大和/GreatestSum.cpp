#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

namespace T44 {

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	int GetGreatestNum(int*, int);

	int GetGreatestNum(int* arr, int len) {
		
		//�쳣�ж�
		if (arr == nullptr || len <= 0) {
			isExcption = true;
			return 0;
		}

		//��¼�� i-1 Ԫ��Ϊβ�����������ĺ�
		int currentSum = 0;
		//��¼���������ĺ�
		int MaxNum = arr[0];
		//������� ��iԪ��Ϊβ������������
		for (int i = 0; i < len; i++) {
			if (currentSum <= 0) {
				//����� i-1 Ԫ��Ϊβ������������С�ڵ���0��������֮ǰԪ�أ���ǰԪ�ع��ɵ�������ͼ�Ϊ��ǰλ�õ�����
				currentSum = arr[i];
			}
			else {
				//����� i-1 Ԫ��Ϊβ�����������ʹ���0�����ۼ�
				currentSum += arr[i];
			}

			//���޼�¼����������
			if (currentSum >= MaxNum) {
				MaxNum = currentSum;
			}
	
		}

		return MaxNum;
	}

	void test() {

		test1();
		test2();
		test3();
		test4();

	}
	void test1() {
		int a[] = { -7,-2,-3,-10,-4,-7,-2,-5 };
		int num = GetGreatestNum(a, 8);

		if (!isExcption) {
			cout << num << endl;
		}
		else {
			cout << "�쳣��" << endl;
		}
		
	}
	void test2() {

	}
	void test3() {

	}
	void test4() {
				
	}

}

using namespace T44;

//int main() {
//	test();
//}
