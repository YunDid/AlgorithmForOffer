#include<iostream>
using namespace std;
int getMaxx(int);
void test4();

//int main() {
//	test4();
//	return 0;
//}

void test4() {
	int len = 8;
	if (getMaxx(len) == 18) {
		cout << "passed";
	}
	else {
		cout << getMaxx(len) << endl;
		cout << "failed";
	}
}

int getMaxx(int length) {
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

	//��¼���ӿɼ�Ϊ����Ϊ3�����Ӷεĸ����볤��Ϊ2�����Ӷεĸ���
	int threeTimes = length / 3;
	int twoTimes = 0;
	//��¼�Ƿ���ڲü�Ϊ3*1���������ʹ��2*2���
	if (length - 3 * threeTimes == 1) {
		threeTimes -= 1;
	}
	
	twoTimes = (length - 3 * threeTimes) / 2;
	return pow(2, twoTimes) * pow(3, threeTimes);
}