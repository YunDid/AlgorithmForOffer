

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T48 {
	#pragma warning(disable:4996);

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;
	int MaxGift = 0;

	//决策树 + 递归
	int MaxValueOfGiftByTree(int**, int, int);
	void MaxValueOfGiftByTreeCoreByTree(int**, int, int, int, int, vector<int>&);

	//公式 + 递归
	int MaxValueOfGiftByFunc(int**, int, int);
	int MaxValueOfGiftCoreByFunc(int**, int, int);

	//动态规划 + 迭代计算
	int MaxValueOfGift(int**, int, int);

	int MaxValueOfGift(int** gift, int rows, int cols) {
		//异常判断
		if (gift == nullptr || rows <= 0 || cols <= 0) {
			isExcption = true;
			return 0;
		}

		//辅助二维数组记录各个位置处的礼物最大价值
		int** MaxValue = new int*[rows];
		for (int i = 0; i < rows; i++) {
			MaxValue[i] = new int[cols];
		}

		//自左上角开始遍历，计算各个位置处的礼物最大价值
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				
				//设置记录当前位置左边与上边礼物最大价值的变量
				int up = 0;
				int left = 0;

				if (i > 0)
					up = MaxValue[i - 1][j];
				if (j > 0)
					left = MaxValue[i][j - 1];

				//设置当前位置的礼物最大价值
				MaxValue[i][j] = max(up, left) + gift[i][j];

			}
		}

		int max = MaxValue[rows - 1][cols - 1];

		//释放内存
		for(int i = 0; i < rows; i++) {
			delete[] MaxValue[i];
		}

		delete[] MaxValue;

		return max;
	}

	int MaxValueOfGiftByFunc(int** arr, int rows, int cols) {
		//异常判断
		if (arr == nullptr || rows <= 0 || cols <= 0) {
			isExcption = true;
			return 0;
		}

		int max = MaxValueOfGiftCoreByFunc(arr, rows - 1, cols - 1);

		return max;
	}

	int MaxValueOfGiftCoreByFunc(int** gift, int row, int col) {
		//base case
		if (row == 0 && col == 0) {
			return gift[row][col];
		}
		else if (row == 0) {
			return MaxValueOfGiftCoreByFunc(gift, row, col - 1) + gift[row][col];
		}
		else if (col == 0) {
			return MaxValueOfGiftCoreByFunc(gift, row - 1, col) + gift[row][col];
		}
		else {
			return max(MaxValueOfGiftCoreByFunc(gift, row - 1, col), MaxValueOfGiftCoreByFunc(gift, row, col - 1)) + gift[row][col];
		}
	}

	int MaxValueOfGiftByTree(int** arr, int rows, int cols) {
		//异常判断
		if (arr == nullptr || rows <= 0 || cols <= 0) {
			isExcption = true;
			return 0;
		}

		vector<int> Gift;

		MaxValueOfGiftByTreeCoreByTree(arr, 0, 0, rows, cols, Gift);

		return MaxGift;
	}

	void MaxValueOfGiftByTreeCoreByTree(int** gift, int row, int col, int rows, int cols, vector<int>& Gift) {
		//base case
		if (row == rows - 1 && col == cols - 1) {

			Gift.push_back(gift[row][col]);

			int sum = 0;
			for (auto i : Gift) {
				cout << i << " ";
				sum += i;
			}
			if (sum >= MaxGift) {
				MaxGift = sum;
			}
			cout << "max = " << MaxGift;
			cout << endl;

			if (Gift.size() != 0)
				Gift.pop_back();

			return;
		}

		//将从左上角至右下角的一条路径经过的所有礼物进行记录
		//防止边界元素的重复压入

		Gift.push_back(gift[row][col]);
		
		//向下移动
		if (row < rows - 1) {
			//down = false;
			MaxValueOfGiftByTreeCoreByTree(gift, row + 1, col, rows, cols, Gift);
		}

		//向右移动
		if (col < cols - 1) {
			//right = false;
			MaxValueOfGiftByTreeCoreByTree(gift, row, col + 1, rows, cols, Gift);
		}

		//恢复
		if (Gift.size() != 0)
			Gift.pop_back();

	}

	void test() {

		test1();
		test2();
		test3();
		//test4();

	}
	void test1() {

		cout << "test1: MaxValueOfGiftByFunc" << endl;

		int a[4][4] = { {1,10,3,8},{12,2,9,6},{5,7,4,11}, {3,7,16,5} };

		int** arr= new int*[4];

		for (int i = 0; i < 4; i++) {
			arr[i] = a[i];
		}
		
		int nums = MaxValueOfGiftByFunc(arr, 4, 4);
		if (!isExcption) {
			if (nums == 53) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << nums << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}
	}
	void test2() {
		//多测试环境下需复原
		cout << "test2: MaxValueOfGift" << endl;

		int a[4][4] = { {1,10,3,8},{12,2,9,6},{5,7,4,11}, {3,7,16,5} };

		int** arr = new int*[4];

		for (int i = 0; i < 4; i++) {
			arr[i] = a[i];
		}

		int nums = MaxValueOfGift(arr, 4, 4);
		if (!isExcption) {
			if (nums == 53) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << nums << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}
	}
	void test3() {
		//多测试环境下需复原
		cout << "test3: MaxValueOfGiftByTree" << endl;

		int a[4][4] = { {1,10,3,8},{12,2,9,6},{5,7,4,11}, {3,7,16,5} };

		int** arr = new int*[4];

		for (int i = 0; i < 4; i++) {
			arr[i] = a[i];
		}

		int nums = MaxValueOfGiftByTree(arr, 4, 4);
		if (!isExcption) {
			if (nums == 53) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
				cout << nums << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}
	}
	void test4() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test4:" << endl;
		if (!isExcption) {
			if (0) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}
	}

}

using namespace T48;

//int main() {
//	test();
//}
