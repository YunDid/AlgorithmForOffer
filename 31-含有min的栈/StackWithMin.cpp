#include<iostream>
#include<stack>
using namespace std;

template <class T> 
class StackWithMin {

public:
	StackWithMin() = default;
	~StackWithMin() = default;

	void push(const T& value) {
		//压入元素
		m_data.push(value);
		//更新min栈的栈顶元素
		if (m_min.size() == 0 || value <= m_min.top()) {
			//若min栈为空或者压入的元素为最小元素，即小于等于min栈栈顶元素
			m_min.push(value);
		}
		else {
			//保持两栈元素个数相等，保证min栈的每个栈顶元素均对应data栈不同状态下的最小值
			m_min.push(m_min.top());
		}
	}
	void pop() {
		if (m_data.size() != 0 && m_min.size() != 0) {
			m_data.pop();
			m_min.pop();
		}
	}

	const T& getMin() const {
		if (m_min.size() != 0) {
			return m_min.top();
		}
	}
private:
	stack<T> m_data;
	stack<T> m_min;
};

namespace T31 {

	void test();

	void test() {
		StackWithMin<int> stackwithmin;
		
		stackwithmin.push(4);	
		stackwithmin.push(3);		
		stackwithmin.push(2);
		stackwithmin.push(1);
		stackwithmin.pop();
		cout << stackwithmin.getMin() << endl;
	}
}

using namespace T31;

//int main() {
//	test();
//}