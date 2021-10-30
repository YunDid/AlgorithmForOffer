#include<iostream>
using namespace std;

long Fibonaci_F_R(int n);
long Fibonaci_F(int);

//int main() {
//	cout << Fibonaci_F(5);
//	cout << Fibonaci_F_R(5);
//}

long Fibonaci_F(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (n <= 1) {
		return 1;
	}
	else if (n <= 2) {
		return 2;
	}
	else {
		long one = 1;
		long two = 2;
		long FN = 0;

		for (int i = 2; i < n; i++) {
			FN = one + two;
			one = two;
			two = FN;
		}

		return FN;
	}
}

long Fibonaci_F_R(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (n <= 1) {
		return 1;
	}
	else if (n <= 2) {
		return 2;
	}
	else {
		return Fibonaci_F_R(n - 1) + Fibonaci_F_R(n - 2);
	}
}