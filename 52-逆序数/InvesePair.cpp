
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T52 {

	#pragma warning(disable:4996);

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	//int copy[4];

	bool isExcption = false;

	int InversePair(int*, int);
	int InversePairCore(int*, int*, int, int);

	int InversePair(int* data, int len) {
		//�ж��쳣
		if (data == nullptr || len <= 0) {
			isExcption = true;
			return 0;
		}

		//���ø����ݴ�����,����ʼ��Ϊarr
		int* copy = new int[len];
		for (int i = 0; i < len; i++) {
			copy[i] = data[i];
		}

		int count = InversePairCore(data, copy, 0, len - 1);

		//�����ڴ�
		delete[] copy;

		return count;
	}

	int InversePairCore(int* data, int* copy, int start, int end) {
		//base case
		if (start == end) {
			//�ݹ���ֹ����Ϊ����������һ��Ԫ��,��ʱ�������������Ϊ0
			//��֤�������򣬽�ֵ�����ݴ�����
			copy[start] = data[start];
			return 0;
		}

		//���û��ֽ���,�԰뻮��
		int len = (end - start) / 2;

		//��ȡ���������е�������
		int left = InversePairCore(copy, data, start, start + len);
		//��ȡ���������е�������
		int right = InversePairCore(copy, data, start + len + 1, end);
		//��ȡ����������ϲ����������
		int inNum = 0;
		//��������ָ�룬�ֱ�ָ��������ϲ����������ĩλ
		int Lend = start + len;
		int Rend = end;
		int Mend = end;
		//�Ӻ���ǰ������������������Ԫ�ؽ��кϲ�
		while (Lend >= start && Rend >= start + len + 1) {
			if (data[Lend] > data[Rend]) {
				//�����������ĩλԪ�ش������������ĩλԪ�أ�������д���ݴ�����
				copy[Mend] = data[Lend];
				//������Ӧָ��ǰ��
				Mend--;
				Lend--;
				//������������ĩλԪ��λ�ü����ʱ������
				inNum += Rend - start - len;
			}else{
				//�����������ĩλԪ��С�ڵ������������ĩλԪ�أ�������д���ݴ�����
				//��ʱ������������
				//������Ӧָ��ǰ��			
				copy[Mend] = data[Rend];
				Mend--;
				Rend--;
			}
		}

		//����һ�����������ȴ����ݴ����飬��ʱ����һ����Ԫ�ذ�������ݴ�����
		while (Lend >= start) {
			copy[Mend] = data[Lend];
			Mend--;
			Lend--;
		}

		while (Rend >= start + len + 1) {
			copy[Mend] = data[Rend];
			Mend--;
			Rend--;
		}

		return left + right + inNum;
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

		int data[] = { 7,5,6,4 };
		int nums = InversePair(data, 4);

		for (int i : data) {
			cout << i << " ";
		}
		
		cout << endl;

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

	void test2() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test2:" << endl;

		int data[] = { 6,5 };
		int nums = InversePair(data, 2);

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
	void test3() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test3:" << endl;

		int data[] = { 6 };
		int nums = InversePair(data, 1);

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
	void test4() {
		//����Ի������踴ԭ
		isExcption = false;

		int nums = InversePair(nullptr, 0);

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

using namespace T52;

//int main() {
//	test();
//}
