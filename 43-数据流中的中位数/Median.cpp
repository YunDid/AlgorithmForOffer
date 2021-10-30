#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

namespace T43 {

	//����ԭ������
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
		//���ѹ��ʱ��̬������Ԫ�ظ���Ϊż������ѹ�뵽min�ѣ�����ѹ�뵽max�ѣ���֤�������ľ��ȷ���
		if (((max.size() + min.size()) & 1) == 0) {
			//��ѹ���Ԫ�ر�max���е����Ԫ�ش�����Ҫ����Ԫ��ѹ��max�Ѳ���max�������Ԫ��ѹ��min��

			if (max.size() > 0 && num < max[0]) {

				//����ǰԪ��ѹ�뵽max����
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
			//���ѹ��ʱ��̬������Ԫ�ظ���Ϊ��������ѹ�뵽max��
			//��ѹ���Ԫ�ر�min���е���С������Ҫ����Ԫ��ѹ��min�Ѳ���min������СԪ��ѹ��max��
			if (min.size() > 0 && num > min[0]) {

				//����ǰԪ��ѹ�뵽max����
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

		//�ж��쳣
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
			cout << "�쳣!";
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
