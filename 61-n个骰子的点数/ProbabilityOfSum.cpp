
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

	//����ԭ������
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

	//n�����ӵĵ������ֵĸ��� by ���¶��ϼ�¼
	void PrintProbabilityNR(int);


	//n�����ӵĵ������ֵĸ��� by�ݹ�
	void PrintProbability(int);

	void Probability(int,int*);
	void ProbabilityCore(int, int, int, int*);

	void PrintProbabilityNR(int n) {
		//�ж��쳣
		if (n < 1) {
			isExcption = true;
			return;
		}

		//��¼n�����Ӻ͵����ֵ����Сֵ�Լ��������ӵ����ֵ
		int maxNum = 6;
		int maxSum = maxNum * n;
		int minSum = n;

		//�����ݴ�n�����ӵ��������н�����ִ���������
		//ʹ���������齻����n-1�����ӵĵ��������н�����ִ��� �� ��ǰn�����ӵĵ��������н�����ִ���
		//�±��Ӧ�����ͣ�Ԫ��ֵΪ�õ����ͳ��ֵĴ���
		int** curSum = new int*[2];
		curSum[0] = new int[maxSum + 1];
		curSum[1] = new int[maxSum + 1];

		//��ʼ��
		for (int i = 0; i <= maxSum; i++) {
			curSum[0][i] = 0;
			curSum[1][i] = 0;
		}

		//���ý���ʱ�ı�־λ
		int flag = 0;

		//��¼һ�����ӵ����͵����н�����ֵĴ���
		for (int i = 1; i <= maxNum; i++) {
			curSum[flag][i] = 1;
		}

		//���¶��ϼ���������������...��n�����ӵĵ����ͽ���ĳ��ִ���
		for (int Dicenum = 2; Dicenum <= n; Dicenum++) {
			//�����ϴ�Dicenum - 1�����ӵĵ����ʹ���������㱾��Dicenum�����ӵĵ����ͳ��ֽ��

			//����ռ�¼����Dicenum�����ӵĵ����ͳ��ֽ��������
			for (int i = 0; i <= maxSum; i++) {
				curSum[1 - flag][i] = 0;
			}

			//��¼Dicenum�����ӵ�ÿ�ֵ����ͳ��ֵĴ�������СΪDicenum�����Ϊ maxNum * Dicenum
			for (int curDiceSum = Dicenum; curDiceSum <= maxNum * Dicenum; curDiceSum++) {
				//�ۼӼ�¼֮ǰ������
				curSum[1 - flag][curDiceSum] = 0;
				//n������ʱ�ĺ�curDiceSum���ִ�������n-1������ʱ f(curDiceSum-1) + f(curDiceSum-2) + ... + f(curDiceSum-6)
				for (int presum = 1; presum <= curDiceSum && presum <= maxNum; presum++) {
					curSum[1 - flag][curDiceSum] += curSum[flag][curDiceSum - presum];
				}
			}
			
			//�������飬ʹ�ñ��ν������++Dicenum�Ľ��
			flag = 1 - flag;
		}

		//���ø��ʷ�ĸ
		int countMax = pow(maxNum, n);
		//��������Ӻͳ��ֵĸ���
		for (int i = n; i <= maxSum; i++) {
			cout << i << endl;
			cout << "����: ";
			cout << curSum[flag][i] << "/" << countMax << " �� ";
			cout << ((double)(curSum[flag][i])) / countMax << endl;
		}

		//�����ڴ�
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
				//��¼��ǰ���ӵ���
				curSum += i;
				//���µݹ飬��ʣ�����ӵĵ���
				ProbabilityCore(minSum, remainingDice - 1, curSum, countSum);
				//�ڽ�����һ�־���ǰ����
				curSum -= i;
			}
		}
	}

	void Probability(int n, int* countSum) {
		ProbabilityCore(n, n, 0, countSum);
	}

	void PrintProbability(int n) {
		//�ж��쳣
		if (n < 1) {
			isExcption = true;
			return;
		}

		//��¼���Ӻ͵����ֵ����Сֵ
		int maxNum = 6;
		int maxSum = maxNum * n;
		int minSum = n;

		//���ü�¼���Ӻͳ��ִ��������飬��Ϊ 0 - (minSum-1) �������¼���������maxSum���ȣ�ֻ���¼ minSum - maxSum ֮�����
		int* countSum = new int[maxSum - minSum + 1];
		//��������ĳ�ʼ��
		for (int i = n; i <= maxSum; i++) {
			countSum[i - minSum] = 0;
		}

		//�ݹ����������Ӻͳ��ֵĴ���
		Probability(n, countSum);

		//���ø��ʷ�ĸ
		int countMax = pow(maxNum, n);
		//��������Ӻͳ��ֵĸ���
		for (int i = n; i <= maxSum; i++) {
			cout << i << endl;
			cout << "����: ";
			cout << countSum[i - minSum] << "/" << countMax << " �� ";
			cout << ((double)(countSum[i - minSum])) / countMax << endl;
		}

		//�����ڴ�
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
			cout << "�쳣!" << endl;
		}

	}

	void test2() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test2:" << endl;

		PrintProbabilityNR(2);

		if (!isExcption) {
			cout << endl;
		}
		else {
			cout << "�쳣!" << endl;
		}
	}
	void test3() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test3:" << endl;

		PrintProbabilityNR(0);

		if (!isExcption) {
			cout << endl;
		}
		else {
			cout << "�쳣!" << endl;
		}
	}
	void test4() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test4:" << endl;

		PrintProbabilityNR(11);

		if (!isExcption) {
			cout << endl;
		}
		else {
			cout << "�쳣!" << endl;
		}
	}
	void test5() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test5:" << endl;

		PrintProbability(1);

		if (!isExcption) {
			cout << endl;
		}
		else {
			cout << "�쳣!" << endl;
		}
	}

	void test6() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test6:" << endl;

		PrintProbability(1);

		if (!isExcption) {
			cout << endl;
		}
		else {
			cout << "�쳣!" << endl;
		}
	}

	void test7() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test7:" << endl;

		PrintProbability(1);

		if (!isExcption) {
			cout << endl;
		}
		else {
			cout << "�쳣!" << endl;
		}

	}

	void test8() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test8:" << endl;

		PrintProbability(1);

		if (!isExcption) {
			cout << endl;
		}
		else {
			cout << "�쳣!" << endl;
		}
	}


}

using namespace T61;

//int main() {
//	test();
//}
