
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T54 {

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

	//�����������в�������
	int GetNumOfK(int*, int, int);
	int GetFirstK(int*, int, int, int, int);
	int GetLastK(int*, int, int, int, int);

	//0 - n-1 ȱʧ������
	int GetMissingNum(int*, int);

	//��������ֵ���±���ȵ�Ԫ��
	int GetNumberSameAsIndex(int*, int);

	int GetNumberSameAsIndex(int* data, int len) {
		//�ж��쳣
		if (data == nullptr || len <= 0) {
			isExcption = true;
			return -1;
		}

		int start = 0;
		int end = len - 1;

		while (start <= end) {

			int mid = (start + end) >> 1;
			if (data[mid] == mid) {
				return mid;
			}
			else if (data[mid] < mid) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}		
		}

		return -1;
	}

	int GetMissingNum(int* data, int len) {
		//�ж��쳣
		if (data == nullptr || len <= 0) {
			isExcption = true;
			return -1;
		}

		//���ֲ��ҵ�һ��Ԫ��ֵ�������±��Ԫ��
		int start = 0;
		int end = len - 1;

		while(start <= end) {
			int mid = (start + end) >> 1;
			if (data[mid] != mid) {
				//�����жϸ�Ԫ���Ƿ�Ϊ�Ƿ�Ԫ��
				if (data[mid] >= len) {
					isExcption = true;
					return -1;
				}
				//��һ���жϸ�Ԫ���Ƿ�Ϊ��һ���±겻����Ԫ��ֵ��Ԫ�أ����ֿ���
				//- ����λԪ����ΪȱʧԪ��
				//- ������λԪ����ΪȱʧԪ��

				//�������������Ԫ�����Ӧ�Ǳ��ֵ������1 --Ԥ���Դ���
				bool isSort = data[mid] - mid == 1;
				//�жϷ���λ��Ԫ���Ƿ�Ϊ��һ��ֵ�������±��Ԫ��
				bool isMFirst = mid > 0 && data[mid - 1] == mid - 1;
				//�ж���λԪ���Ƿ�Ϊ��һ��һ��ֵ�������±��Ԫ�� --Ԥ���Դ���
				bool isFFirst = (mid == 0) && isSort;

				if (isFFirst || isMFirst) {
					return mid;
				}
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}

		//���ǽ�һ��Ԫ��0���������1
		if (start == len) {
			return len;
		}

		//�����ֱ����궼û���ҵ���������쳣
		//�Ƿ����֣����鲻�������
		isExcption = true;
		return -1;

	}

	int GetNumOfK(int* data, int length, int k) {
		//�ж��쳣
		if (data == nullptr || length <= 0) {
			isExcption = true;
			return -1;
		}

		int num = 0;

		//��ȡ���ڶ��ֲ��ҵ�k��һ�γ��ֵ�λ��
		int first = GetFirstK(data, length, k, 0, length - 1);
		int last = GetLastK(data, length, k, 0, length - 1);

		if (first != -1 && last != -1) {
			num = last - first + 1;
		}

		return num;

	}

	int GetFirstK(int* data, int len, int k, int start, int end) {
		//base case
		if (start > end) {
			return -1;
		}

		int mid = (start + end) / 2;
		if (data[mid] == k) {
			//����ǰ��ֵ����k���жϸ�ֵ�Ƿ�Ϊ��һ��ֵΪk��Ԫ��
			if (mid == 0 || (mid > 0 && data[mid - 1] != k)) {
				return mid;
			}
			//�����ǣ�������ڸ�Ԫ��֮ǰ���������в���
			end = mid - 1;

		}
		else if (data[mid] < k) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}

		//���ֵݹ�
		GetFirstK(data, len, k, start, end);
	}

	int GetLastK(int* data, int len, int k, int start, int end) {
		//base case
		if (start > end) {
			return -1;
		}

		int mid = (start + end) / 2;
		if (data[mid] == k) {
			//����ǰ��ֵ����k���жϸ�ֵ�Ƿ�Ϊ���һ��ֵΪk��Ԫ��
			if (mid == len - 1 || ((mid < (len - 1)) && data[mid + 1] != k)) {
				return mid;
			}
			//�����ǣ�������ڸ�Ԫ��֮����������в���
			start = mid + 1;

		}
		else if (data[mid] < k) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}

		//���ֵݹ�
		GetLastK(data, len, k, start, end);
	}

	void test() {

		/*test1();
		test2();
		test3();
		test4();*/
		test5();
		test6();
		test7();
		test8();

	}
	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		int data[] = { 1,2,3,4 };
		int nums = GetMissingNum(data, 4);

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

	void test2() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test2:" << endl;

		int data[] = { 0 };
		int nums = GetMissingNum(data, 1);

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

		//int data[] = { 5,4,8,9 };
		int data[] = { 3,2,0,1 };
		int nums = GetMissingNum(data, 4);

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

		int nums = GetNumOfK(nullptr, 0, 0);

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

		int nums = GetNumberSameAsIndex(nullptr, 0);

		cout << "test5:" << endl;
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

	void test6() {
		//����Ի������踴ԭ
		isExcption = false;

		int data[] = { 0,1,2,3 };
		int nums = GetNumberSameAsIndex(data, 4);

		cout << "test6:" << endl;
		if (!isExcption) {
			if (nums == 1) {
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

		int data[] = { -4,-3,-2,5 };
		int nums = GetNumberSameAsIndex(data, 4);

		cout << "test7:" << endl;
		if (!isExcption) {
			if (nums == -1) {
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

	void test8() {
		//����Ի������踴ԭ
		isExcption = false;

		int data[] = { 0 };
		int nums = GetNumberSameAsIndex(data, 1);

		cout << "test8:" << endl;
		if (!isExcption) {
			if (nums == 0) {
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

using namespace T54;

//int main() {
//	test();
//}
