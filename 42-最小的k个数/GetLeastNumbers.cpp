#include<iostream>
#include<vector>
#include<set>
using namespace std;

namespace T42 {

	typedef multiset<int,greater<int>>  SetType;
	typedef multiset<int, greater<int>>::iterator  SetIteratorType;

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	int Partition(int*, int, int, int);
	void GetLeastNumbers(int*, int, int*, int);

	void GetLeastNumbersByRB(const vector<int>&, SetType&, int);

	void GetLeastNumbersByRB(const vector<int>& data, SetType& store, int k) {
		//�쳣�ж�
		if (data.size() == 0 || k < 0 || k > data.size()) {
			isExcption = true;
			return;
		}

		//�����������飬��ǰk���Ԫ�ش��뵽store������
		vector<int>::const_iterator ite = data.begin();
		for (; ite < data.end(); ite++) {
			//������Ԫ��δ��k������ֱ�Ӳ���
			if (store.size() < k) {
				store.insert(*ite);
			}
			else {
				//����k���ҵ�ǰ����Ԫ��С�ں��������㣬���滻���ø��ڵ�
				if (*ite < *store.begin()) {
					store.erase(*(store.begin()));
					store.insert(*ite);
				}
			}
		}
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

	void GetLeastNumbers(int* input, int len, int* output, int k) {
		//�쳣�ж�
		if (input == nullptr || len < 0 || k > len || k < 0) {
			isExcption = true;
			return;
		}

		//���ڿ��Ż����ҵ����ֻ�׼Ϊ k-1 �Ļ��ֽ��
		int start = 0;
		int end = len - 1;
		int index = Partition(input, len, start, end);

		while (index != k - 1) {
			if (index > k - 1) {
				end = index - 1;
				index = Partition(input, len, start, end);
			}
			else {
				start = index + 1;
				index = Partition(input, len, start, end);
			}
		}

		//�����ֺ��ǰk��Ԫ�ش����������
		for (int i = 0; i < k; i++) {
			output[i] = input[i];
		}

	}

	void test() {

		/*test1();
		test2();*/
		test3();
		//test4();

	}
	void test1() {

	}
	void test2() {

	}
	void test3() {
		vector<int> vec = { 1,2,3,4,5 };
		SetType store;
		GetLeastNumbersByRB(vec, store, 5);
		if (!isExcption) {
			for (auto ite : store) {
				cout << ite << " ";
			}
		}
		else {
			cout << "�쳣!";
		}
	}

	void test4() {
		int a[1] = { 5 };
		int b[1];
		GetLeastNumbers(a, 1, b, 1);
		if (!isExcption) {
			for (int i = 0; i < 1; i++) {
				cout << b[i] << " ";
			}
		}
		else {
			cout << "�쳣!";
		}
	}

}

using namespace T42;

//int main() {
//	test();
//}