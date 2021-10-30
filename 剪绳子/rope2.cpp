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

	//记录绳子可剪为长度为3的绳子段的个数与长度为2的绳子段的个数
	int threeTimes = length / 3;
	int twoTimes = 0;
	//记录是否存在裁剪为3*1的情况，需使用2*2替代
	if (length - 3 * threeTimes == 1) {
		threeTimes -= 1;
	}
	
	twoTimes = (length - 3 * threeTimes) / 2;
	return pow(2, twoTimes) * pow(3, threeTimes);
}