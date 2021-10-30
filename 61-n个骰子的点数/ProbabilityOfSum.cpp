
#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T61 {

#pragma warning(disable:4996);

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();
	void test5();
	void test6();
	void test7();
	void test8();

	bool isExcption = false;

	//n个骰子的点数出现的概率 by 自下而上记录
	void PrintProbabilityNR(int);


	//n个骰子的点数出现的概率 by递归
	void PrintProbability(int);

	void Probability(int,int*);
	void ProbabilityCore(int, int, int, int*);

	void PrintProbabilityNR(int n) {
		//判断异常
		if (n < 1) {
			isExcption = true;
			return;
		}

		//记录n个骰子和的最大值与最小值以及单个骰子的最大值
		int maxNum = 6;
		int maxSum = maxNum * n;
		int minSum = n;

		//开辟暂存n个骰子点数和所有结果出现次数的数组
		//使用两个数组交替存放n-1个骰子的点数和所有结果出现次数 与 当前n个骰子的点数和所有结果出现次数
		//下标对应点数和，元素值为该点数和出现的次数
		int** curSum = new int*[2];
		curSum[0] = new int[maxSum + 1];
		curSum[1] = new int[maxSum + 1];

		//初始化
		for (int i = 0; i <= maxSum; i++) {
			curSum[0][i] = 0;
			curSum[1][i] = 0;
		}

		//设置交替时的标志位
		int flag = 0;

		//记录一个骰子点数和的所有结果出现的次数
		for (int i = 1; i <= maxNum; i++) {
			curSum[flag][i] = 1;
		}

		//自下而上计算两个，三个，...，n个骰子的点数和结果的出现次数
		for (int Dicenum = 2; Dicenum <= n; Dicenum++) {
			//借用上次Dicenum - 1个骰子的点数和次数结果计算本次Dicenum个骰子的点数和出现结果

			//先清空记录本次Dicenum个骰子的点数和出现结果的数组
			for (int i = 0; i <= maxSum; i++) {
				curSum[1 - flag][i] = 0;
			}

			//记录Dicenum个骰子的每种点数和出现的次数，最小为Dicenum，最大为 maxNum * Dicenum
			for (int curDiceSum = Dicenum; curDiceSum <= maxNum * Dicenum; curDiceSum++) {
				//累加记录之前先清零
				curSum[1 - flag][curDiceSum] = 0;
				//n个骰子时的和curDiceSum出现次数等于n-1个骰子时 f(curDiceSum-1) + f(curDiceSum-2) + ... + f(curDiceSum-6)
				for (int presum = 1; presum <= curDiceSum && presum <= maxNum; presum++) {
					curSum[1 - flag][curDiceSum] += curSum[flag][curDiceSum - presum];
				}
			}
			
			//交替数组，使用本次结果计算++Dicenum的结果
			flag = 1 - flag;
		}

		//设置概率分母
		int countMax = pow(maxNum, n);
		//计算各骰子和出现的概率
		for (int i = n; i <= maxSum; i++) {
			cout << i << endl;
			cout << "概率: ";
			cout << curSum[flag][i] << "/" << countMax << " ≈ ";
			cout << ((double)(curSum[flag][i])) / countMax << endl;
		}

		//清理内存
		delete[] curSum[0];
		delete[] curSum[1];
		delete[] curSum;

	}

	void ProbabilityCore(int minSum, int remainingDice, int curSum, int* countSum) {
		//base case 
		if (remainingDice == 0) {
			countSum[curSum - minSum]++;
		}
		else {
			for (int i = 1; i <= 6; i++) {
				//记录当前骰子点数
				curSum += i;
				//向下递归，求剩余骰子的点数
				ProbabilityCore(minSum, remainingDice - 1, curSum, countSum);
				//在进行下一种决策前回退
				curSum -= i;
			}
		}
	}

	void Probability(int n, int* countSum) {
		ProbabilityCore(n, n, 0, countSum);
	}

	void PrintProbability(int n) {
		//判断异常
		if (n < 1) {
			isExcption = true;
			return;
		}

		//记录骰子和的最大值与最小值
		int maxNum = 6;
		int maxSum = maxNum * n;
		int minSum = n;

		//设置记录骰子和出现次数的数组，和为 0 - (minSum-1) 的无需记录，因此无需maxSum长度，只需记录 minSum - maxSum 之间的数
		int* countSum = new int[maxSum - minSum + 1];
		//计数数组的初始化
		for (int i = n; i <= maxSum; i++) {
			countSum[i - minSum] = 0;
		}

		//递归计算各种骰子和出现的次数
		Probability(n, countSum);

		//设置概率分母
		int countMax = pow(maxNum, n);
		//计算各骰子和出现的概率
		for (int i = n; i <= maxSum; i++) {
			cout << i << endl;
			cout << "概率: ";
			cout << countSum[i - minSum] << "/" << countMax << " ≈ ";
			cout << ((double)(countSum[i - minSum])) / countMax << endl;
		}

		//清理内存
		delete[] countSum;

	}

	void test() {

		test1();
		test2();
		test3();
		test4();
		/*
		test5();
		test6();
		test7();
		test8();
		*/

	}

	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		PrintProbabilityNR(1);

		if (!isExcption) {
			cout << endl;
		}
		else {
			cout << "异常!" << endl;
		}

	}

	void test2() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test2:" << endl;

		PrintProbabilityNR(2);

		if (!isExcption) {
			cout << endl;
		}
		else {
			cout << "异常!" << endl;
		}
	}
	void test3() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test3:" << endl;

		PrintProbabilityNR(0);

		if (!isExcption) {
			cout << endl;
		}
		else {
			cout << "异常!" << endl;
		}
	}
	void test4() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test4:" << endl;

		PrintProbabilityNR(11);

		if (!isExcption) {
			cout << endl;
		}
		else {
			cout << "异常!" << endl;
		}
	}
	void test5() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test5:" << endl;

		PrintProbability(1);

		if (!isExcption) {
			cout << endl;
		}
		else {
			cout << "异常!" << endl;
		}
	}

	void test6() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test6:" << endl;

		PrintProbability(1);

		if (!isExcption) {
			cout << endl;
		}
		else {
			cout << "异常!" << endl;
		}
	}

	void test7() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test7:" << endl;

		PrintProbability(1);

		if (!isExcption) {
			cout << endl;
		}
		else {
			cout << "异常!" << endl;
		}

	}

	void test8() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test8:" << endl;

		PrintProbability(1);

		if (!isExcption) {
			cout << endl;
		}
		else {
			cout << "异常!" << endl;
		}
	}


}

using namespace T61;

//int main() {
//	test();
//}
