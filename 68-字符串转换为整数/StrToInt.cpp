
#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
#include<algorithm>
#include<functional>
#include<list>
#include<string>
using namespace std;

namespace T68 {

	#pragma warning(disable:4996);

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();
	void test5();

	bool isExcption = false;

	//�ַ���ת��Ϊ����
	int StrToInt(char*);
	bool isNumber(char*);
	
	bool isNumber(char* str) {

		bool isNum = true;

		int len = strlen(str);

		//�жϿմ�
		if (len == 0) {
			isNum = false;
		}

		//�ж��Ƿ�Ϊ�����ַ��������ո��жϣ��Լ��������ж�
		for (int i = 0; i < len; i++) {

			//�ж����ַ��Ƿ�Ϊ+,-�ţ��������ǣ�������ж��Ƿ�Ϊ�����ַ�
			if (i == 0 && str[i] == '+' || i == 0 && str[i] == '-') {
				continue;
			}
			//�ж�ʣ���ַ��Ƿ�Ϊ�����ַ�
			if (str[i]<'0' || str[i]>'9') {
				isNum = false;
				break;
			}
		}

		return isNum;
	}

	int StrToInt(char* str) {
		//�߽��쳣�ж�
		if (str == nullptr || !isNumber(str)) {
			isExcption = true;
			return 0;
		}

		//ת���ַ���
		char*p = str;

		long long num = 0;

		//�ж��Ƿ�Ϊ��λ
		bool isFirst = true;
		bool isNegative = false;

		while (*p != '\0') {
			//�ж�������
			if (isFirst && (*p) == '-') {
				isNegative = true;

				//���±���
				p++;
				//������λ�жϱ���״̬
				isFirst = false;

				continue;
			}
			else if (isFirst && (*p) == '+') {
				//���±���
				p++;
				//������λ�жϱ���״̬
				isFirst = false;

				continue;
			}

			//�ۼ�ת��Ϊ����
			num = num * 10 + (*p - '0');

			//�����´�ǰ���жϵ�ǰ�Ƿ����Խ�����,�����ж��������������������ж���С���������
			if ((!isNegative && num > 0x7fffffff) || (isNegative && num < (signed int)0x80000000)) {
				isExcption = true;
				return 0;
			}
		
			//���±���
			p++;
			//������λ�жϱ���״̬
			isFirst = false;
		}

		return isNegative ? -num : num;

	}

	void test() {

		//test1();
		//test2();
		//test3();
		//test4();
		test5();

	}

	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		char a[] = "2147483647";

		//cout << 0x7fffffff;
		//cout << (signed int)0x80000000;

		//cout << numeric_limits<int>::max() << endl;
		//cout << numeric_limits<int>::min() << endl;

		int sum = StrToInt(a);

		if (!isExcption) {
			if (sum == 2147483647) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << sum << endl;
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

		char a[] = "-2147483648";

		int sum = StrToInt(a);

		if (!isExcption) {
			if (sum == -214748364) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << sum << endl;
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

		char a[] = "123";

		int sum = StrToInt(a);

		if (!isExcption) {
			if (sum == 123) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << sum << endl;
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

		char a[] = "";

		int sum = StrToInt(a);

		if (!isExcption) {
			if (sum == 0) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << sum << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}
	}

	void test5() {

		cout << (int)2147483648 << endl;
	}


}

using namespace T68;

//int main() {
//	test();
//}
