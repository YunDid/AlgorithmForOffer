#include<iostream>
#include<string>
using namespace std;

void Plus(int, int);
void PlusCore(string, string);
void test9();

//int main() {
//	test9();
//}

void Plus(int n1, int n2) {


	string str1 = "";
	string str2 = "";

	while (n1 != 0) {
		int r = n1 % 10;
		str1 += r + '0';
		n1 /= 10;
	}

	while (n2 != 0) {
		int r = n2 % 10;
		str2 += r + '0';
		n2 /= 10;
	}
	
	PlusCore(str1, str2);

}

void PlusCore(string, string) {
	
}

void test9() {
	Plus(5, 6);
}