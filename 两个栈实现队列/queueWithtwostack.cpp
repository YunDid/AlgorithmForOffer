//#include<iostream>
//#include<stack>
//using namespace std;
//
//template<typename T>
//class CQueue {
//public:
//	CQueue(void) = default;
//	~CQueue() = default;
//
//	void appendTail(const T&node);
//	int size();
//	T deleteHead();
//private:
//	stack<T> stack1;
//	stack<T> stack2;
//};
//
//template<typename T>
//int CQueue<T>::size() {
//	return stack1.size() + stack2.size();
//}
//
//template<typename T>
//void CQueue<T>::appendTail(const T&node) {
//	stack1.push(node);
//}
//
//template<typename T>
//T CQueue<T>::deleteHead() {
//
//	if (stack2.size() == 0) {
//
//		while (stack1.size() != 0) {
//			stack2.push(stack1.top());
//			stack1.pop();
//		}
//
//	}
//
//	if (stack2.size() == 0) {
//		throw new exception("stack2 is empty!");
//	}
//
//	T head = stack2.top();
//	stack2.pop();
//
//	return head;
//}
//
//void test() {
//	CQueue<int> queue;
//	for (int i = 1; i < 10; i++) {
//		queue.appendTail(i);
//	}
//
//	for (int i = 11; i < 12; i++) {
//		queue.appendTail(i);
//	}
//
//	while (queue.size() != 0) {
//		cout << queue.deleteHead() << " ";
//	}
//}
//
////int main() {
////	test();
////}