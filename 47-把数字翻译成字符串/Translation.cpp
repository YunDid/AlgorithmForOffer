

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T47 {
	#pragma warning(disable:4996);

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	bool Concat(char*, char*);

	bool Concat(char cnum1, char cnum2) {

		bool result = false;

		int num1 = cnum1 - '0';
		int num2 = cnum2 - '0';

		int concat = num1 * 10 + num2;

		if (concat >= 10 && concat <= 25) {
			result = true;
		}

		return result;
	}

	int TranslationNums(int);
	int RecursiveTranslationNums(int);

	int TranslationNumsCore(const string& num);
	int RecursiveTranslationNumsCore(char* num);

	int RecursiveTranslationNums(int num) {
		//�쳣�ж�
		if (num < 0) {
			isExcption = true;
			return 0;
		}
		char arr[10];
		sprintf(arr, "%d", num);
		return RecursiveTranslationNumsCore(arr);
	}

	int RecursiveTranslationNumsCore(char* num) {
		//base case
		if ((*(num + 1)) == '\0') {
			return 1;
		}

		int count = 0;
		//��ǰԪ�ز����һ��Ԫ�����
		count += RecursiveTranslationNumsCore(num + 1);
		//��ǰԪ�����һ��Ԫ�����
		if (Concat(*num, *(num + 1))) {
			if ((*(num + 2)) != '\0')
				count += RecursiveTranslationNumsCore(num + 2);
			else
				count += 1;
		}

		return count;
	}

	int TranslationNums(int num) {
		//�쳣�ж�
		if (num < 0) {
			isExcption = true;
			return 0;
		}
		string n = to_string(num);
		return TranslationNumsCore(n);
	}

	int TranslationNumsCore(const string& num) {
		//���ü�¼����λ����ɷ�����ַ���������������ظ�����
		int* counts = new int[num.length()];
		//���ü�¼�ӵ�ǰλ��Ԫ�ؿ�ʼ�Ŀɷ����ַ�����
		int count = 0;

		//�Ӻ���ǰ�����ַ�����ֱ���������һ��λ����Ŀɷ����ַ�����
		for (int i = num.length() - 1; i >= 0; i--) {
			//���㣬���㵱ǰλ������ʼλ�õĿɷ����ַ�����
			count = 0;
			//����ǰԪ��ΪĩβԪ�أ���ֻ�ܷ���1���ַ���
			if (i == num.length() - 1) {
				count += 1;
			}
			else {
				//����ǰԪ������ʼλ�õĿɷ����ַ�����������һ��λ�õĽ��
				count += counts[i + 1];
			}

			if (i != num.length() - 1) {
				//����ΪĩβԪ�أ��жϵ�ǰԪ���ܷ����һ��Ԫ��ƴ��
				if (Concat(num[i], num[i + 1])) {
					//����ƴ�ӵ��ǵ�ǰԪ��Ϊ�����ڶ���Ԫ�أ���ɷ����ַ�������1
					if (i == num.length() - 2) {
						count += 1;
					}
					else {
						count += counts[i + 2];
					}
				}
			}

			counts[i] = count;
		}

		//�ͷ��ڴ�
		delete[] counts;

		return count;
	}

	void test() {

		test1();
		/*test2();
		test3();
		test4();*/

	}
	void test1() {

		cout << "test1:" << endl;
		int nums = TranslationNums(12258);
		if (!isExcption) {
			if (nums == 5) {
				cout << "passed!" << endl;
			}
			else {				
				cout << "failed!" << endl;
				cout << nums << endl;
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
		if (!isExcption) {
			if (0) {
				cout << "passed!" << endl;
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
		if (!isExcption) {
			if (0) {
				cout << "passed!" << endl;
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
		if (!isExcption) {
			if (0) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}
	}

}

using namespace T47;

//int main() {
//	test();
//}
