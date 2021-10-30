#include<iostream>
#include<stack>
#include<queue>
using namespace std;

template<typename T>
class CStack {
public:
	CStack(void) = default;
	~CStack() = default;

	void appendTail(const T&node);
	int size();
	T deleteHead();
private:
	queue<T> queue1;
	queue<T> queue2;
};

template<typename T>
int CStack<T>::size() {
	return queue1.size() + queue2.size();
}

template<typename T>
void CStack<T>::appendTail(const T&node) {
	if (queue1.size() == 0 && queue2.size() == 0) {
		queue1.push(node);
	}
	else if (queue1.size() != 0) {
		queue1.push(node);
	}
	else {
		queue2.push(node);
	}
}

template<typename T>
T CStack<T>::deleteHead() {

	if (queue2.size() == 0 && queue1.size() == 0) {
		throw new exception("queue is empty!");
	}
	else if (queue2.size() != 0) {
		while (queue2.size() != 1) {
			
			queue1.push(queue2.front());
			queue2.pop();
		}

		T head = queue2.front();
		queue2.pop();

		return head;
	}
	else {
		while (queue1.size() != 1) {

			queue2.push(queue1.front());
			queue1.pop();
		}

		T head = queue1.front();
		queue1.pop();

		return head;
	}
}

void test() {
	CStack<int> stack;
	for (int i = 1; i < 10; i++) {
		stack.appendTail(i);
	}

	for (int i = 11; i < 12; i++) {
		stack.appendTail(i);
	}

	while (stack.size() != 0) {
		cout << stack.deleteHead() << " ";
	}
}

//int main() {
//	test();
//}