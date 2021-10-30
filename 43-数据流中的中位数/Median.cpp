#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

namespace T43 {

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	template <class T>
	class DynamicArray {
	public:
		DynamicArray() = default;
		~DynamicArray() = default;

		void Insert(T num);
		double GetMedian();
	private:
		vector<T> max;
		vector<T> min;
	};

	template <class T>
	void DynamicArray<T>::Insert(T num) {
		//如果压入时动态数组中元素个数为偶数，则压入到min堆，否则压入到max堆，保证数据流的均匀分配
		if (((max.size() + min.size()) & 1) == 0) {
			//若压入的元素比max堆中的最大元素大，则需要将该元素压入max堆并将max堆中最大元素压入min堆

			if (max.size() > 0 && num < max[0]) {

				//将当前元素压入到max堆中
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<T>());
				num = max[0];

				pop_heap(max.begin(), max.end(), less<T>());
				max.pop_back();
			}

			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<T>());
		}
		else {
			//如果压入时动态数组中元素个数为奇数，则压入到max堆
			//若压入的元素比min堆中的最小大，则需要将该元素压入min堆并将min堆中最小元素压入max堆
			if (min.size() > 0 && num > min[0]) {

				//将当前元素压入到max堆中
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<T>());

				num = min[0];

				pop_heap(min.begin(), min.end(), greater<T>());
				min.pop_back();
			}

			max.push_back(num);
			push_heap(max.begin(), max.end(), less<T>());
		}
	}

	template <class T>
	double DynamicArray<T>::GetMedian() {

		//判断异常
		int size = max.size() + min.size();
		if (size == 0) {
			isExcption = true;
			return 0;
		}
		
		T median;

		if ((size & 1) == 0) {
			median = (max[0] + min[0]) / 2;
		}
		else {
			median = min[0];
		}

		return median;
	}

	void test() {

		test1();
		/*test2();
		test3();
		test4();*/

	}

	void display(vector<int>q)
	{
		for (int i = 0; i < q.size(); i++)
		{
			cout << q[i] << " ";
		}
		cout << endl;
	}

	void test1() {

		cout << "q" << endl;
		vector<int> q;
		for (int i = 0; i < 10; i++)
		{
			q.push_back(i);
			cout << q.back() << " ";
		}

		cout << endl << "p" << endl;
		vector<int> p;
		for (int i = 0; i < 10; i++)
		{
			p.push_back(i);

			cout << p.back() << " ";
		}

		cout << endl << "q" << endl;
		for (int i = 0; i < 10; i++)
		{
			q.pop_back();
		}

		cout << "p" << endl;
		for (int i = 0; i < 10; i++)
		{
			pop_heap(p.begin(), p.end(), less<int>());
			p.pop_back();
		}
	
	}
	void test2() {

	}
	void test3() {
		/*vector<int> vec = { 1,2,3,4,5 };
		SetType store;
		GetLeastNumbersByRB(vec, store, 5);
		if (!isExcption) {
			for (auto ite : store) {
				cout << ite << " ";
			}
			for (auto ite = store.begin(); ite < store.end(); ite++) {}
		}
		else {
			cout << "异常!";
		}*/
	}

	void test4() {
		DynamicArray<double>* Num = new DynamicArray<double>();
		cout << Num->GetMedian() << endl;
		Num->Insert(1);
		cout << Num->GetMedian() << endl;
		Num->Insert(3);
		cout << Num->GetMedian() << endl;
		Num->Insert(5);
		cout << Num->GetMedian() << endl;
		Num->Insert(7);
		cout << Num->GetMedian() << endl;
		Num->Insert(9);
		cout << Num->GetMedian() << endl;
	}

}

using namespace T43;

//int main() {
//	test();
//}
