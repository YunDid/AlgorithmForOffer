#include<iostream>
using namespace std;

bool isOK(int, int, int);
int getNumCore(int*, int, int, int, int, int, bool*);
int getNum(int*, int, int, int);
void ttest();

//int main() {
//	ttest();
//}

bool isOK(int cols, int rows, int k) {
	int sum = 0;
	while (cols != 0) {
		sum += cols % 10;
		cols /= 10;
	}

	while (rows != 0) {
		sum += rows % 10;
		rows /= 10;
	}

	if (sum > k) {
		return false;
	}
	else {
		return true;
	}
}

void ttest() {
	int a[4][3] = { {11,22,33},{4,5,6},{0,1,2},{15,16,17} };
	int num = getNum(a[0], 4, 3, 10);
	cout << num;
}

int getNum(int* arr, int rows, int cols, int k) {
	//异常处理
	if (arr == nullptr || cols < 1 || rows < 1 || k < 0) {
		throw new exception("异常!");
	}

	//设置访问标识数组
	bool* visited = new bool[cols*rows];
	//初始化
	memset(visited, 0, cols*rows);
	//设置出发点
	int col = 0;
	int row = 0;

	int num = getNumCore(arr, row, rows, col, cols, k, visited);

	//回收内存
	delete[] visited;
	return num;

}

int getNumCore(int* arr,int row, int rows,int col, int cols, int k, bool*visited) {
	//base case
	if (!isOK(cols, rows, k)) {
		return 0;
	}
	else {

		int num = 0;
		if (!visited[row*cols + col]) {
			num++;
			visited[row*cols + col] = true;

			num += getNumCore(arr, row - 1, rows, col, cols, k, visited);
			num += getNumCore(arr, row + 1, rows, col, cols, k, visited);
			num += getNumCore(arr, row, rows, col - 1, cols, k, visited);
			num += getNumCore(arr, row, rows, col + 1, cols, k, visited);

		}

		return num;
	}
}