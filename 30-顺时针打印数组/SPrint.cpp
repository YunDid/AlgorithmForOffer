#include<iostream>
#include<vector>
using namespace std;

namespace T30 {

	//异常判断变量
	bool hasException = false;
	
	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	void Sprint(int** arr, int, int);
	void SprintCore(int** arr, int, int, int);

	void Sprint(int** arr, int rows, int cols) {
		if (arr == nullptr || rows <= 0 || cols <= 0) {
			hasException = true;
			return;
		}

		int start = 0;

		//判断循环输出圈的次数
		while (rows > 2 * start && cols > 2 * start) {
			
			SprintCore(arr, rows, cols, start);
			start++;

		}

	}

	void SprintCore(int** arr, int rows, int cols, int start) {
		
		//当前坐上结点的坐标为 (start,start)
		
		//记录当前待输出圈的边界
		int endX = cols - 1 - start;
		int endY = rows - 1 - start;

		//输出圈的上半部分
		for (int i = start; i <= endX; i++) {
			cout << arr[start][i] << " ";
		}
		//判断圈是否需要继续向下输出右半部分
		if (endY > start) {
			for (int i = start + 1; i <= endY; i++) {
				cout << arr[i][endX] << " ";
			}
		}
		//判断圈是否需要继续向左输出下半部分
		if (endY > start && endX > start) {
			for (int i = endX - 1; i >= start; i--) {
				cout << arr[endY][i] << " ";
			}
		}
		//判断圈是否需要继续向上输出左半部分
		if (endY - 1 > start && endX > start) {
			for (int i = endY - 1; i > start; i--) {
				cout << arr[i][start] << " ";
			}
		}
		
	}

	void test() {

		test1();
		test2();
		test3();
		test4();

	}
	void test1() {

		int arr [][1] = { {1}};
		int** index = new int*[1];
		index[0] = arr[0];

		Sprint(index, 1, 1);
		
		delete []index;
	}
	void test2() {

		Sprint(nullptr, 0, 0);

		
	}
	void test3() {


	}

	void test4() {

		

		
	}
}

using namespace T30;

//int main() {
//	test();
//}