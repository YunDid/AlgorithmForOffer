#include<iostream>
#include<stack>
using namespace std;

namespace T32 {

	bool isIOMatch(const int*, const int*, int);
	void test();

	bool isException = false;

	bool isIOMatch(const int* pInput, const int* pOutput, int length) {
		
		//设置返回值
		bool imatch = false;
		//异常判断
		if (pInput == nullptr || pOutput == nullptr || length <= 0) {
			isException = true;
			return imatch;
		}

		//创建辅助栈
		stack<int> helperStack;

		//设置临时指针
		const int* tInput = pInput;
		const int* tOutput = pOutput;

		//逐个判断输出队列中的各元素是否匹配
		while (tOutput - pOutput != length) {

			//若栈中无元素或者当前栈顶元素与输出指针指向的元素不匹配，则将输入队列的元素压入栈
			if (helperStack.size() == 0 || helperStack.top() != *tOutput) {
				
				if (tInput - pInput == length) {
					break;
				}

				helperStack.push(*tInput);
				tInput++;
			}

			//若当前栈顶元素与当前输出指针指向的元素，则将栈顶元素弹出，判断当前栈顶与输出指针的下一个指向是否匹配
			if (helperStack.top() == *tOutput) {
				helperStack.pop();
				tOutput++;
			}

		}

		//若输出队列遍历完毕且辅助栈为空，则表示匹配
		if (helperStack.size() == 0 && tOutput - pOutput == length) {
			imatch = true;
		}

		return imatch;
	}

	void test() {
		int a[] = { 1,2 };
		int b[] = { 1,1 };

		if (isIOMatch(a, b, 2) != true) {
			cout << "passed";
		}else {
			cout << "failed";
		}
	}
}

using namespace T32;

//int main() {
//	test();
//}