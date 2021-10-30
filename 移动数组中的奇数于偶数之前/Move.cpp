#include<iostream>
using namespace std;

void Move(int*, int);
void Move(int*, int, bool(*)(int));
void test22();

//int main() {
//	test22();
//}

void Move(int* base, int length) {
	//�쳣�ж�
	if (base == nullptr || length < 0) {
		return;
	}

	//����ָ��
	int* pOdd = base;
	int* pEven = base + length - 1;

	//ͨ�������ƶ�������ż��֮ǰ
	while (pOdd <= pEven) {
		while (pOdd <= pEven && (*pOdd & 0x1) != 0) {
			pOdd++;
		}

		while (pOdd <= pEven && (*pEven & 0x1) == 0) {
			pEven--;
		}

		if (pOdd <= pEven) {
			int temp;
			temp = *pOdd; *pOdd = *pEven; *pEven = temp;
		}

	}
}


bool standard(int n) {
	return (n & 0x1) == 0;
}

void Move(int* base, int length, bool(*func)(int)) {
	//�쳣�ж�
	if (base == nullptr || length < 0) {
		return;
	}

	//����ָ��
	int* pOdd = base;
	int* pEven = base + length - 1;

	//ͨ�������ƶ�������ż��֮ǰ
	while (pOdd <= pEven) {
		while (pOdd <= pEven && !func((*pOdd))) {
			pOdd++;
		}

		while (pOdd <= pEven && func((*pEven))) {
			pEven--;
		}

		if (pOdd <= pEven) {
			int temp;
			temp = *pOdd; *pOdd = *pEven; *pEven = temp;
		}

	}
}

void test22() {
	int a[] = { 2,4,6,1,3,5 };
	Move(a, 6, standard);
	for (int i = 0; i < 6; i++) {
		cout << a[i] << " ";
	}
}