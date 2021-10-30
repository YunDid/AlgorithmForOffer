
#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T60 {

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
	//���������е����ֵ
	vector<int> MaxInWindows(const vector<int>&, int);

	//�����е����ֵ
	template<class T>
	class QueueWithMax {

	public:

		QueueWithMax() :currentIndex(0) {}

		void push_back(T val) {
			//�����ݷ�װΪ�ڲ�����
			InternalData internalData;
			internalData.number = val;
			internalData.index = currentIndex;

			//���ڲ�����ѹ�뵽data������
			data.push_back(internalData);

			//����Ŀǰdata���е����ֵ��Ŀǰdata���е����ֵλ��max����
			//�Ƚ��Ѳ����ܳ�Ϊdata����ʣ��״̬�����ֵ��Ԫ�ص���
			while (!max.empty() && val >= max.back().number) {
				max.pop_back();
			}
			
			//�޳���������Ԫ�غ�ʣ��Ԫ�ؼ�Ϊ���ܳ�Ϊ����ĳһ״̬�µ����ֵ����ǰ���ֵΪmax����Ԫ��
			//��ǰԪ�ؿ�����Ϊdata����ĳһ״̬�µ����ֵ��ѹ��
			max.push_back(internalData);

			//����������ָ����һ��Ԫ��
			currentIndex++;
		}

		void pop_front() {
			if (!data.empty() && !max.empty()) {

				if (data.front().index == max.front().index) {
					max.pop_front();
				}
				data.pop_front();
			}
			else {
				throw new exception("�쳣");
			}
		}

		T getMax() const {
			if (!max.empty()) {
				return max.front().number;
			}
			else {
				throw new exception("�쳣");
			}
		}

	private:

		struct InternalData {
			T number;
			int index;
		};

		deque<InternalData> data;
		deque<InternalData> max;

		int currentIndex;
	};


	vector<int> MaxInWindows(const vector<int>& data, int WinSize) {

		//���÷��ظ��������ֵ������
		vector<int> maxInWindows;
		//�ж��쳣
		if (data.size() < WinSize || WinSize <= 0) {
			isExcption = true;
			return maxInWindows;
		}

		//���ô��ڶ��У��������Ϊ�������ֵ��Ԫ��
		deque<int> Window;

		//��������Ԫ�أ����Դ���״̬���и��£�����������Ϊ�������ֵ��Ԫ��

		//�ȶ�����ǰWinSize���б�������Ϊ��ʱ��δ��������
		for (int i = 0; i < WinSize; i++) {
			//���ݵ�ǰԪ��ֵ�жϣ�����������Ϊ��ǰ�������ֵ��Ԫ��
			while (!Window.empty() && data[i] >= data[Window.back()]) {
				Window.pop_back();
			}

			//����ǰԪ�������±�ѹ�봰��
			Window.push_back(i);
		}

		for (int i = WinSize; i < data.size(); i++) {
			//�����ڶ��ж���Ԫ��ѹ��maxInWindows����¼�������ֵ
			maxInWindows.push_back(data[Window.front()]);

			//���ݵ�ǰԪ��ֵ�жϣ�����������Ϊ��ǰ�������ֵ��Ԫ��
			while (!Window.empty() && data[i] >= data[Window.back()]) {
				Window.pop_back();
			}

			//���ݵ�ǰԪ�ص��±��жϣ�������ǰ����֮��ĵ�Ԫ��
			while (!Window.empty() && (i - Window.front() >= WinSize)) {
				Window.pop_front();
			}

			//����ǰԪ�������±�ѹ�봰��
			Window.push_back(i);
		}

		//�����ڶ��ж���Ԫ��ѹ��maxInWindows����¼�������ֵ
		maxInWindows.push_back(data[Window.front()]);

		return maxInWindows;
	}

	void test() {

		/*test1();
		test2();
		test3();
		test4();
		test5();
		test6();*/
		test7();
		/*test8();*/

	}

	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		vector<int> data = { 2,3,4,2,6,2,5,1 };
		vector<int> rdata = MaxInWindows(data, 3);

		if (!isExcption) {
			for (int i : rdata) {
				cout << i << " ";
			}
			cout << endl;
		}
		else {
			cout << "�쳣!" << endl;
		}
	}

	void test2() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test2:" << endl;

		vector<int> data = { 1,2,3,4,5,6,7,8 };
		vector<int> rdata = MaxInWindows(data, 3);

		if (!isExcption) {
			for (int i : rdata) {
				cout << i << " ";
			}
			cout << endl;
		}
		else {
			cout << "�쳣!" << endl;
		}
	}
	void test3() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test3:" << endl;

		vector<int> data = { 8,7,6,5,4,3,2,1 };
		vector<int> rdata = MaxInWindows(data, 3);

		if (!isExcption) {
			for (int i : rdata) {
				cout << i << " ";
			}
			cout << endl;
		}
		else {
			cout << "�쳣!" << endl;
		}
	}
	void test4() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test4:" << endl;

		vector<int> data = {};
		vector<int> rdata = MaxInWindows(data, 0);

		if (!isExcption) {
			for (int i : rdata) {
				cout << i << " ";
			}
			cout << endl;
		}
		else {
			cout << "�쳣!" << endl;
		}
	}
	void test5() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test5:" << endl;

		vector<int> data = { 2,3,4,2,6,2,5,1 };
		vector<int> rdata = MaxInWindows(data, 1);

		if (!isExcption) {
			for (int i : rdata) {
				cout << i << " ";
			}
			cout << endl;
		}
		else {
			cout << "�쳣!" << endl;
		}
	}

	void test6() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test6:" << endl;

		vector<int> data = { 2,3,4,2,6,2,5,1 };
		vector<int> rdata = MaxInWindows(data, 10);

		if (!isExcption) {
			for (int i : rdata) {
				cout << i << " ";
			}
			cout << endl;
		}
		else {
			cout << "�쳣!" << endl;
		}
	}

	void test7() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test7:" << endl;

		QueueWithMax<int> queue;

		//cout << "max:" << queue.getMax() << endl;

		queue.push_back(2);
		cout << "max:" << queue.getMax() << endl;

		queue.push_back(3);
		cout << "max:" << queue.getMax() << endl;

		queue.push_back(4);
		cout << "max:" << queue.getMax() << endl;

		queue.push_back(6);
		cout << "max:" << queue.getMax() << endl;

		queue.pop_front();
		cout << "max:" << queue.getMax() << endl;

		queue.pop_front();
		cout << "max:" << queue.getMax() << endl;

		queue.pop_front();
		cout << "max:" << queue.getMax() << endl;

		//queue.pop_front();
		//cout << "max:" << queue.getMax() << endl;
		
	}

	void test8() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test8:" << endl;

		vector<int> data = { 2,3,4,2,6,2,5,1 };
		vector<int> rdata = MaxInWindows(data, 3);

		if (!isExcption) {
			for (int i : rdata) {
				cout << i << " ";
			}
			cout << endl;
		}
		else {
			cout << "�쳣!" << endl;
		}
	}


}

using namespace T60;

//int main() {
//	test();
//}
