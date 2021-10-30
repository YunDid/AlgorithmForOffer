#include<iostream>
using namespace std;
int getNOne1(int);
int getNOne2(int);
int getNOne3(int);

void test5();

//int main() {
//	test5();
//}

int getNOne1(int n){
	int nums = 0;
	while (n) {
		if (n & 1) {
			nums++;
		}
		n >>= 1;
	}
	return nums;
}
int getNOne2(int n){
	int nums = 0;
	unsigned int flag = 1;
	while (flag) {
		if (n & flag) {
			nums++;
		}
		flag <<= 1;
	}
	return nums;
}
int getNOne3(int n){
	int nums = 0;
	while (n) {
		nums++;
		n = (n - 1)&n;
	}
	return nums;
}

void test5() {
	if (getNOne1(9) == 2) {
		cout << "1passed" << endl;
	}
	else {
		cout << "1failed" << endl;
	}

	if (getNOne2(9) == 2) {
		cout << "2passed" << endl;
	}
	else {
		cout << "2failed" << endl;
	}

	if (getNOne3(9) == 2) {
		cout << "3passed" << endl;
	}
	else {
		cout << "3failed" << endl;
	}
}