#include<iostream>
#include<stack>
using namespace std;

template <class T> 
class StackWithMin {

public:
	StackWithMin() = default;
	~StackWithMin() = default;

	void push(const T& value) {
		//ѹ��Ԫ��
		m_data.push(value);
		//����minջ��ջ��Ԫ��
		if (m_min.size() == 0 || value <= m_min.top()) {
			//��minջΪ�ջ���ѹ���Ԫ��Ϊ��СԪ�أ���С�ڵ���minջջ��Ԫ��
			m_min.push(value);
		}
		else {
			//������ջԪ�ظ�����ȣ���֤minջ��ÿ��ջ��Ԫ�ؾ���Ӧdataջ��ͬ״̬�µ���Сֵ
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