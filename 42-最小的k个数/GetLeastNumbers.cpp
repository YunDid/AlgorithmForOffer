#include<iostream>
#include<vector>
#include<set>
using namespace std;

namespace T42 {

	typedef multiset<int,greater<int>>  SetType;
	typedef multiset<int, greater<int>>::iterator  SetIteratorType;

	//函数原型声明
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
		//异常判断
		if (data.size() == 0 || k < 0 || k > data.size()) {
			isExcption = true;
			return;
		}

		//遍历输入数组，将前k大的元素存入到store容器中
		vector<int>::const_iterator ite = data.begin();
		for (; ite < data.end(); ite++) {
			//若容器元素未满k个，则直接插入
			if (store.size() < k) {
				store.insert(*ite);
			}
			else {
				//若满k个且当前输入元素小于红黑树根结点，则替换掉该根节点
				if (*ite < *store.begin()) {
					store.erase(*(store.begin()));
					store.insert(*ite);
				}
			}
		}
	}

	int Partition(int* arr, int len, int start, int end) {
		//异常判断
		if (arr == nullptr || len <= 0 || start < 0 || end >= len) {
			isExcption = true;
			return 0;
		}

		//设置small时刻指向当前最后一个比small小的元素
		int small = start - 1;
		//数组某位暂存pivot基数 默认取start元素，此处并未随机

		int pivot = arr[start];

		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		//遍历数组，以基数为基准进行划分
		for (int index = start; index < end; index++) {
			//若遍历元素比pivot基数小，则small后移，否则不作处理
			if (arr[index] < pivot) {

				small++;
				//若遇到比pivot大的元素后又遇到比pivot小的元素，则small++后交换这两个元素位置
				if (index != small) {
					int temp = arr[index];
					arr[index] = arr[small];
					arr[small] = temp;
				}

			}
		}

		//将small指针指向pivot基数应存放位置
		small++;

		//交换基数与第一个比其大的元素
		temp = arr[small];
		arr[small] = arr[end];
		arr[end] = temp;

		return small;
	}

	void GetLeastNumbers(int* input, int len, int* output, int k) {
		//异常判断
		if (input == nullptr || len < 0 || k > len || k < 0) {
			isExcption = true;
			return;
		}

		//基于快排划分找到划分基准为 k-1 的划分结果
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

		//将划分后的前k个元素存入输出数组
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
			cout << "异常!";
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
			cout << "异常!";
		}
	}

}

using namespace T42;

//int main() {
//	test();
//}