#include<iostream>
using namespace std;
int getMax(int);
void test3();

//int main() {
//	test3();
//	return 0;
//}

void test3() {
	int len = 8;
	if (getMax(len) == 18) {
		cout << "passed";
	}
	else {
		cout << getMax(len) << endl;
		cout << "failed";
	}
}

int getMax(int length) {
	//�����볤������ʼ�ж�
	if (length < 2) {
		//û�취��
		return 0;
	}
	if (length == 2) {
		//ֻ�ܿ�һ��
		return 1;
	}
	if (length == 3) {
		return 3;
	}

	//ʹ�������ݴ��������ϵĸ����ȵ����˻�ֵ
	int* temp = new int[length + 1];
	for (int i = 0; i < 4; i++) {
		temp[i] = i;
	}

	//���ü�¼����Ϊnʱ�ĳ˻�max����
	int max = 0;

	//�������೤�ȵ����˻�ֵ
	for (int i = 4; i <= length; i++) {
		max = 0;
		//ʹ���Ѽ�¼��ֵ�������м��㣬��ֹ�ظ�����˻�ֵ��������ֹ����Ϊi/2
		for (int j = 1; j <= i / 2; j++) {
			max = temp[j] * temp[i - j];
			if (max >= temp[i]) {
				temp[i] = max;
			}
		}
	}

	max = temp[length];

	//��ֹ�ڴ�й©
	delete[] temp;
	return max;

}