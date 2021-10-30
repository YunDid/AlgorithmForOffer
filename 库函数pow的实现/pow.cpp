#include<iostream>
#include<cmath>
#include<exception>
using namespace std;

double getPow(double, int);
double getAbsPow(double, unsigned int);
double getAbsPow2(double, unsigned int);

void test6();

bool failed = false;

//int main() {
//	test6();
//}

double getPow(double n, int index) {
	//����nΪ0ʱindexΪ������������޷�����
	if (n == 0.0&index < 0) {
		failed = true;
		return 0;
	}
	//����ָ������������ָ�������ֵ��Ĵη����
	unsigned int absIndex;

	if (index < 0) {
		absIndex = -index;
	}
	else {
		absIndex = index;
	}

	double result = getAbsPow2(n, absIndex);
	//��ָ��Ϊ�������������
	if (index < 0) {
		result = 1.0 / result;
	}

	return result;
}

double getAbsPow(double n, unsigned int absIndex) {
	double sum = 1.0;
	for (int i = 1.0; i <= absIndex; i++) {
		sum *= n;
	}
	return sum;
}

double getAbsPow2(double n, unsigned int absIndex) {
	
	//basecase
	if (absIndex == 0) {
		return 1;
	}
	else if (absIndex == 1) {
		return n;
	}
	else {
		double pow = getAbsPow2(n, absIndex >> 1);
		pow *= pow;
		if (absIndex & 0x1 == 1) {
			pow *= n;
		}

		return pow;
	}
}

void test6() {
	if (getPow(2, 3) == 8) {
		if (failed == false)
			cout << "passed";
		else
			cout << "����ʧ��";
	}
	else {
		cout << getPow(2, 3) << endl;
		cout << "failed";
	}
}