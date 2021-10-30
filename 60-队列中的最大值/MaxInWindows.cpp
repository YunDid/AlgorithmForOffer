
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

	//函数原型声明
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
	//滑动窗口中的最大值
	vector<int> MaxInWindows(const vector<int>&, int);

	//队列中的最大值
	template<class T>
	class QueueWithMax {

	public:

		QueueWithMax() :currentIndex(0) {}

		void push_back(T val) {
			//将数据封装为内部数据
			InternalData internalData;
			internalData.number = val;
			internalData.index = currentIndex;

			//将内部数据压入到data队列中
			data.push_back(internalData);

			//更新目前data队列的最大值，目前data队列的最大值位于max队首
			//先将已不可能成为data队列剩余状态的最大值的元素弹出
			while (!max.empty() && val >= max.back().number) {
				max.pop_back();
			}
			
			//剔除掉不可能元素后，剩余元素即为可能成为队列某一状态下的最大值，当前最大值为max队首元素
			//当前元素可能作为data队列某一状态下的最大值，压入
			max.push_back(internalData);

			//将索引更新指向下一个元素
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
				throw new exception("异常");
			}
		}

		T getMax() const {
			if (!max.empty()) {
				return max.front().number;
			}
			else {
				throw new exception("异常");
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

		//设置返回各窗口最大值的数组
		vector<int> maxInWindows;
		//判断异常
		if (data.size() < WinSize || WinSize <= 0) {
			isExcption = true;
			return maxInWindows;
		}

		//设置窗口队列，仅存可能为窗口最大值的元素
		deque<int> Window;

		//遍历数组元素，并对窗口状态进行更新，弹出不可能为窗口最大值的元素

		//先对数组前WinSize进行遍历，因为此时并未填满窗口
		for (int i = 0; i < WinSize; i++) {
			//根据当前元素值判断，弹出不可能为当前窗口最大值的元素
			while (!Window.empty() && data[i] >= data[Window.back()]) {
				Window.pop_back();
			}

			//将当前元素数组下标压入窗口
			Window.push_back(i);
		}

		for (int i = WinSize; i < data.size(); i++) {
			//将窗口队列队首元素压入maxInWindows，记录窗口最大值
			maxInWindows.push_back(data[Window.front()]);

			//根据当前元素值判断，弹出不可能为当前窗口最大值的元素
			while (!Window.empty() && data[i] >= data[Window.back()]) {
				Window.pop_back();
			}

			//根据当前元素的下标判断，弹出当前窗口之外的的元素
			while (!Window.empty() && (i - Window.front() >= WinSize)) {
				Window.pop_front();
			}

			//将当前元素数组下标压入窗口
			Window.push_back(i);
		}

		//将窗口队列队首元素压入maxInWindows，记录窗口最大值
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
			cout << "异常!" << endl;
		}
	}

	void test2() {
		//多测试环境下需复原
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
			cout << "异常!" << endl;
		}
	}
	void test3() {
		//多测试环境下需复原
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
			cout << "异常!" << endl;
		}
	}
	void test4() {
		//多测试环境下需复原
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
			cout << "异常!" << endl;
		}
	}
	void test5() {
		//多测试环境下需复原
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
			cout << "异常!" << endl;
		}
	}

	void test6() {
		//多测试环境下需复原
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
			cout << "异常!" << endl;
		}
	}

	void test7() {
		//多测试环境下需复原
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
		//多测试环境下需复原
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
			cout << "异常!" << endl;
		}
	}


}

using namespace T60;

//int main() {
//	test();
//}
