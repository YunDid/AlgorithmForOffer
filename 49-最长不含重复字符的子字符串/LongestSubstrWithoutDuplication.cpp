
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T49 {
	#pragma warning(disable:4996);

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	int LongestSubstrWithoutDuplication(const string&);

	int LongestSubstrWithoutDuplication(const string& str) {
		//�쳣�ж�
		if (str.length() == 0) {
			isExcption = true;
			return 0;
		}

		//����LastAppear�����¼'a'-'z'�ַ���һ�����ַ����г��ֵ�λ�ã�����ǰδ���֣���Ϊ-1
		int* LastAppear = new int[26];
		for (int i = 0; i < 26; i++) {
			LastAppear[i] = -1;
		}

		//����currentSum�洢f(i-1)��ֵ
		int currentSubLen = 0;
		//����maxSum���޴洢��ַ���
		int maxSum = 0;

		//��ǰ������Ŀǰ��i��Ԫ��������Ҫ������ַ���ĩβʱ�������
		for (int i = 0; i < str.length(); i++) {
			//�жϵ�ǰԪ���Ƿ�λ��f(i-1)��Ӧ�����ַ�����

			//��ȡ��ǰ����Ԫ����LastAppear�����е�ӳ���ϵ,�Ӷ���ȡ��ǰԪ���ϴ���str�г��ֵ�λ��
			int index = str[i] - 'a';
			//��ȡ��ǰԪ������һ�γ���λ�õĲ�ֵ
			int distance;

			if(LastAppear[index] >= 0)
				distance = i - LastAppear[index];

			if (LastAppear[index] < 0 || distance > currentSubLen) {
				//��֮ǰ����ַ����в�����ǰλ���ַ��������ַ���������1
				currentSubLen += 1;
			}
			else {
				//��֮ǰ����ַ����к���ǰλ���ַ���������ظ�����Ҫ�ض���һ�γ���λ���Լ�֮ǰ��Ԫ��
				//��ʱmaxSum����Ҫ����
				if (currentSubLen >= maxSum) {
					maxSum = currentSubLen;
				}
				currentSubLen = distance;
			}

			//��¼��ǰԪ�ر�����str���ֵ�λ��
			LastAppear[index] = i;

		}

		//������maxSum����¼������ظ��ַ������ַ���
		if (currentSubLen >= maxSum) {
			maxSum = currentSubLen;
		}

		//�����ڴ�
		delete[] LastAppear;

		return maxSum;
	}

	void test() {

		test1();
		test2();
		test3();
		//test4();

	}
	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		string str = "abcd";

		int nums = LongestSubstrWithoutDuplication(str);
		if (!isExcption) {
			if (nums == 4) {
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

		string str = "";

		int nums = LongestSubstrWithoutDuplication(str);
		if (!isExcption) {
			if (nums == 53) {
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
	void test3() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test3:" << endl;

		string str = "a";

		int nums = LongestSubstrWithoutDuplication(str);
		if (!isExcption) {
			if (nums == 1) {
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

using namespace T49;

//int main() {
//	test();
//}
