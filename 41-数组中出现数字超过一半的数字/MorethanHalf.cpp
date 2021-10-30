#include<iostream>
#include<vector>
using namespace std;

namespace T41 {

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	int LikelyMoreThanHalf(int*,int);
	bool IsValidInput(int*, int);
	bool IsMoreThanHalf(int*, int, int);

	int Partition(int*, int, int, int);
	int MedianMoreThanHalf(int*, int);

	int MedianMoreThanHalf(int* arr, int len) {
		//�쳣�ж�
		if (IsValidInput(arr, len)) {
			isExcption = true;
			return 0;
		}

		//��¼�������λ��λ��
		int median = len >> 1;

		//��ȡ��ǰ���Ż��ֵõ��Ļ���λ��
		int start = 0;
		int end = len - 1;
		int pivot = Partition(arr, len, start, end);

		//���˻���λ�ò�Ϊ��λ�������ڻ��ֺ�����н��������λ��ֱ������λ�õ���median
		while (median != pivot) {
			if (pivot > median) {
				//�ڻ�����ߵ�������Ѱ��
				end = pivot - 1;
				pivot = Partition(arr, len, start, end);
			}
			else {
				//�ڻ����ұߵ�������Ѱ��
				start = pivot + 1;
				pivot = Partition(arr, len, start, end);
			}
		}

		//��ʱ����λ�ü�Ϊ��λ��λ�ã��û�������ΪҪ��������һ���ж�
		int result = arr[pivot];

		if (!IsMoreThanHalf(arr, len, result)) {
			isExcption = true;
			result = 0;
		}

		return result;
	}

	int Partition(int* arr, int len, int start, int end) {
		//�쳣�ж�
		if (arr == nullptr || len <= 0 || start < 0 || end >= len) {
			isExcption = true;
			return 0;
		}

		//����smallʱ��ָ��ǰ���һ����smallС��Ԫ��
		int small = start - 1;
		//����ĳλ�ݴ�pivot���� Ĭ��ȡstartԪ�أ��˴���δ���

		int pivot = arr[start];
			
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;	

		//�������飬�Ի���Ϊ��׼���л���
		for (int index = start; index < end; index++) {
			//������Ԫ�ر�pivot����С����small���ƣ�����������
			if (arr[index] < pivot) {

				small++;
				//��������pivot���Ԫ�غ���������pivotС��Ԫ�أ���small++�󽻻�������Ԫ��λ��
				if (index != small) {
					int temp = arr[index];
					arr[index] = arr[small];
					arr[small] = temp;
				}
			
			}
		}

		//��smallָ��ָ��pivot����Ӧ���λ��
		small++;

		//�����������һ��������Ԫ��
		temp = arr[small];
		arr[small] = arr[end];
		arr[end] = temp;

		return small;
	}

	bool IsMoreThanHalf(int* arr, int len, int result) {

		//����bool��������ֵ
		bool isMoreThanHalf = false;

		//��¼result�������еĳ��ִ���
		int num = 0;
		for (int i = 0; i < len; i++) {
			if (arr[i] == result) {
				num++;
			}
		}

		//����ȫ���쳣�жϱ�����ʼΪtrue
		isExcption = true;

		if (num > (len / 2)) {

			isExcption = false;
			isMoreThanHalf = true;
		}

		return isMoreThanHalf;
	}

	bool IsValidInput(int* arr, int len) {
		bool isExc = false;
		if (arr == nullptr || len <= 0) {
			isExc = true;
		}
		return isExc;
	}

	int LikelyMoreThanHalf(int* arr, int len) {
		//�쳣�ж�
		if (IsValidInput(arr, len)) {
			isExcption = true;
			return 0;
		}

		//���ñ�����¼��������
		int result = arr[0];
		//���������ϵ��
		int coefficient = 1;

		//��ѡ������������ܳ�Ϊresult������
		for (int i = 0; i < len; i++) {
			if (coefficient == 0) {

				//����ϵ��������0�����ʾ�����ֲ�����Ϊ��ֵ���л�����һ��ֵ				
				result = arr[i];
				//��������ϵ��Ϊ1
				coefficient = 1;

			}
			else if (result == arr[i]) {
				//ϵ����ǿ
				coefficient++;
			}
			else {
				//ϵ������
				coefficient--;
			}
		}

		//���result�Ƿ�Ϊ��ֵ
		if (!IsMoreThanHalf(arr, len, result)) {
			isExcption = true;
			result = 0;
		}

		return result;
	}

	void test() {

		/*test1();
		test2();
		test3();*/
		test4();

	}
	void test1() {

	}
	void test2() {

	}
	void test3() {

	}

	void test4() {
		int a[1] = { 1 };
		int result = MedianMoreThanHalf(a, 1);
		if (!isExcption) {
			cout << result << endl;
		}
		else {
			cout << "�쳣!";
		}
	}

}

using namespace T41;

//int main() {
//	test();
//}