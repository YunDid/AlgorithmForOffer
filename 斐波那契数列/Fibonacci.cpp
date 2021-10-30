#include<iostream>
using namespace std;

long Fibonaci(int);
long Fibonaci_RR(int n);

//int main() {
//	cout << Fibonaci(10);
//	cout << Fibonaci_RR(10);
//}

long Fibonaci(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (n <= 1) {
		return 1;
	}
	else {
		long one = 0;
		long two = 1;
		long FN = 0;

		for (int i = 2; i <= n; i++) {
			FN = one + two;
			one = two;
			two = FN;
		}

		return FN;
	}
}

long Fibonaci_RR(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (n <= 1) {
		return 1;
	}
	else {
		return Fibonaci_RR(n - 1) + Fibonaci_RR(n - 2);
	}
}