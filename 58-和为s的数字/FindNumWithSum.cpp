
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T58 {

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
	//���������к�Ϊs������
	bool FindNumWithSum(int*, int, int, int&, int&);
	//��Ϊs��������������
	void FindContinuousSequene(int);

	void printSequene(int, int);

	void printSequene(int start, int end) {
		for (int i = start; i <= end; i++) {
			cout << i << " ";
		}
		cout << endl;
	}

	void FindContinuousSequene(int sum) {
		//�ж��쳣
		if (sum < 3) {
			isExcption = true;
			return;
		}
		//�������з�Χָ��
		int start = 1;
		int end = 2;

		//��¼���з�Χ���������ֵĺ�
		int curSum = start + end;

		//������Ѱ��������������
		while (start < (sum + 1) / 2) {
			//�򻯰�
			if (curSum == sum) {
				printSequene(start, end);
			}

			while (curSum > sum && start < (sum + 1) / 2) {
				//�޳���������С�����������ۼ���++
				curSum -= start;
				start++;

				if (curSum == sum) {
					printSequene(start, end);
				}
			}

			//�������еķ�Χ����++���ۼ�
			end++;
			curSum += end;		

			//�����
			//if (curSum == sum) {
			//	printSequene(start, end);

			//	end++;
			//	curSum += end;
			//}
			//else if (curSum > sum) {
			//	curSum -= start;
			//	start++;

			//	if (curSum == sum) {
			//		printSequene(start, end);

			//		end++;
			//		curSum += end;
			//	}
			//}
			//else {
			//	//�������еķ�Χ����++���ۼ�
			//	end++;
			//	curSum += end;
			//}
		}
	}

	bool FindNumWithSum(int* data, int length, int Sum, int& Num1, int& Num2) {
		//�ж��쳣
		if (data == nullptr || length <= 0) {
			isExcption = true;
			return false;
		}

		//���÷���ֵ
		bool find = false;

		//��������ָ��ֱ�����ָ��Num1��Num2����ʼ��Ϊ�����������ֵ����Сֵ
		int maxIndex = length - 1;
		int minIndex = 0;

		while (minIndex < maxIndex) {
			int sum = data[maxIndex] + data[minIndex];
			if (sum == Sum) {
				find = true;
				Num2 = data[maxIndex];
				Num1 = data[minIndex];
				break;
			}
			else if (sum < Sum) {
				//����ʱָ��ָ�������Ԫ�غ�С��Sum,��ָ���СԪ�ص�ָ�����(������С��������)
				minIndex++;
			}
			else {
				//����ʱָ��ָ�������Ԫ�غʹ���Sum,��ָ��ϴ�Ԫ�ص�ָ�����(������С��������)
				maxIndex--;
			}
		}

		return find;
	}


	void test() {

		/*test1();
		test2();
		test3();
		test4();
		test5();*/
		test6();
		test7();
		test8();

	}
	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		int data[] = { 1,1,2,2,1,2,3 };
		int num1;
		int num2;
		bool find = FindNumWithSum(data, 7, 3, num1, num2);

		if (!isExcption) {
			if (find == true) {
				if (num1 == 1 && num2 == 2) {
					cout << "passed!" << endl;
				}
			}
			else {
				cout << "failed!" << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}
	}

	void test2() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test2:" << endl;

		int data[] = { 1,1,2,2,1,2,3 };
		int num1;
		int num2;
		bool find = FindNumWithSum(data, 7, 10, num1, num2);

		if (!isExcption) {
			if (find == true) {
				if (num1 == 1 && num2 == 2) {
					cout << "passed!" << endl;
				}
			}
			else {
				cout << "failed!" << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}
	}
	void test3() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test3:" << endl;

		int data[] = { 1,1 };
		int num1;
		int num2;
		bool find = FindNumWithSum(data, 2, 2, num1, num2);

		if (!isExcption) {
			if (find == true) {
				if (num1 == 1 && num2 == 1) {
					cout << "passed!" << endl;
				}
			}
			else {
				cout << "failed!" << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}
	}
	void test4() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test4:" << endl;

		int data[] = { 1 };
		int num1;
		int num2;
		bool find = FindNumWithSum(nullptr, 7, 10, num1, num2);

		if (!isExcption) {
			if (find == true) {
				if (num1 == 1 && num2 == 2) {
					cout << "passed!" << endl;
				}
			}
			else {
				cout << "failed!" << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}
	}
	void test5() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test5:" << endl;

		int data[] = { 1,1,2,2,1,2,3 };
		int num1;
		int num2;
		bool find = FindNumWithSum(data, 7, 10, num1, num2);

		if (!isExcption) {
			if (find == true) {
				if (num1 == 1 && num2 == 2) {
					cout << "passed!" << endl;
				}
			}
			else {
				cout << "failed!" << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}
	}

	void test6() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test6:" << endl;

		FindContinuousSequene(3);

		if (!isExcption) {
		}
		else {
			cout << "�쳣!" << endl;
		}
	}

	void test7() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test7:" << endl;

		FindContinuousSequene(15);

		if (!isExcption) {
		}
		else {
			cout << "�쳣!" << endl;
		}
	}

	void test8() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test8:" << endl;

		FindContinuousSequene(4);

		if (!isExcption) {
		}
		else {
			cout << "�쳣!" << endl;
		}
	}


}

using namespace T58;

//int main() {
//	test();
//}
