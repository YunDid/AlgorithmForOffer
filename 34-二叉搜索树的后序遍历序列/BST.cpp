#include<iostream>
#include<deque>
using namespace std;

namespace T34 {

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool VerifySquenceOfBST(int*, int);

	bool VerifySquenceOfBST(int* Seq, int Slength) {
		
		//�쳣�ж�
		if (Seq == nullptr || Slength <= 0) {
			return false;
		}

		//�жϵ�ǰ���ڵ��������������Ƿ��������������
		//ȡ��ǰ���ڵ�
		int root = Seq[Slength - 1];

		//��Ѱ��һ���ȸ��ڵ��ڵ���Ϊ���������ֽ磬��ʱ���������ȸ��ڵ�С
		int i = 0;
		for (; i < Slength - 1; i++) {
			if (Seq[i] > root) {
				break;
			}
		}

		//�жϸø��ڵ��������Ƿ���ڱ���С�Ľڵ�
		int j = i;
		for (; j < Slength - 1; j++) {
			if (Seq[j] < root) {
				return false;
			}
		}

		//��ʱ���ڵ��������Ľڵ���ȸ��ڵ�С���������Ľڵ���ȸ��ڵ�������������������
		//--------------------------------------------------------------------
		//�����жϸø��ڵ�����������Ƿ������������������

		//���������������ж��������Ƿ������������������
		bool left = true;
		if (i > 0)
			left = VerifySquenceOfBST(Seq, i);

		//�������������ж��������Ƿ������������������
		bool Right = true;
		if (i < Slength - 1)
			Right = VerifySquenceOfBST(Seq + i, Slength - i - 1);

		return left && Right;
	}

	void test() {

		test1();
		test2();
		test3();
		test4();

	}
	void test1() {
		int a[] = { 5,7,6,9,11,10,8 };
		if (VerifySquenceOfBST(a, 7) == true) {
			cout << "test1 passed!" << endl;
		}
		else {
			cout << "test1 failed!" << endl;
		}
	}
	void test2() {
		int a[] = { 7,4,6,5 };
		if (VerifySquenceOfBST(nullptr, 4) != true) {
			cout << "test2 passed!" << endl;
		}
		else {
			cout << "test2 failed!" << endl;
		}
	}
	void test3() {

	}

	void test4() {
		
	}
}

using namespace T34;

//int main() {
//	test();
//}