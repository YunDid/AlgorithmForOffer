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
	//对输入长度作初始判断
	if (length < 2) {
		//没办法砍
		return 0;
	}
	if (length == 2) {
		//只能砍一刀
		return 1;
	}
	if (length == 3) {
		return 3;
	}

	//使用数组暂存自下向上的各长度的最大乘积值
	int* temp = new int[length + 1];
	for (int i = 0; i < 4; i++) {
		temp[i] = i;
	}

	//设置记录长度为n时的乘积max变量
	int max = 0;

	//计算其余长度的最大乘积值
	for (int i = 4; i <= length; i++) {
		max = 0;
		//使用已记录的值迭代进行计算，防止重复计算乘积值，设置终止条件为i/2
		for (int j = 1; j <= i / 2; j++) {
			max = temp[j] * temp[i - j];
			if (max >= temp[i]) {
				temp[i] = max;
			}
		}
	}

	max = temp[length];

	//防止内存泄漏
	delete[] temp;
	return max;

}