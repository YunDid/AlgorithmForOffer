#include<iostream>
#include<stack>
using namespace std;

namespace T32 {

	bool isIOMatch(const int*, const int*, int);
	void test();

	bool isException = false;

	bool isIOMatch(const int* pInput, const int* pOutput, int length) {
		
		//���÷���ֵ
		bool imatch = false;
		//�쳣�ж�
		if (pInput == nullptr || pOutput == nullptr || length <= 0) {
			isException = true;
			return imatch;
		}

		//��������ջ
		stack<int> helperStack;

		//������ʱָ��
		const int* tInput = pInput;
		const int* tOutput = pOutput;

		//����ж���������еĸ�Ԫ���Ƿ�ƥ��
		while (tOutput - pOutput != length) {

			//��ջ����Ԫ�ػ��ߵ�ǰջ��Ԫ�������ָ��ָ���Ԫ�ز�ƥ�䣬��������е�Ԫ��ѹ��ջ
			if (helperStack.size() == 0 || helperStack.top() != *tOutput) {
				
				if (tInput - pInput == length) {
					break;
				}

				helperStack.push(*tInput);
				tInput++;
			}

			//����ǰջ��Ԫ���뵱ǰ���ָ��ָ���Ԫ�أ���ջ��Ԫ�ص������жϵ�ǰջ�������ָ�����һ��ָ���Ƿ�ƥ��
			if (helperStack.top() == *tOutput) {
				helperStack.pop();
				tOutput++;
			}

		}

		//��������б�������Ҹ���ջΪ�գ����ʾƥ��
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