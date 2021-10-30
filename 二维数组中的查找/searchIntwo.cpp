#include<iostream>
using namespace std;

bool search(int* arr, int rows, int cols, int n);

//int main() {
//	int aa[4][4] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
//	int n;
//	cin >> n;
//	if (search(aa[0], 4, 4, n)) {
//		cout << "存在数字: "<< n << endl;
//	}else{
//		cout << "不存在数字: "<< n << endl;
//	}
//}

bool search(int* arr,int rows,int cols, int n) {
	
	//锁定右上角位置
	int row = 0;
	int col = cols - 1;

	//直到越界结束查找
	while (row < rows && col >= 0) {
		if (n > arr[row*cols + col]) {
			//剔除一行
			row++;
		}
		else if (n == arr[row*cols + col]) {
			return true;
		}
		else {
			//剔除一列
			col--;
		}
	}

	return false;
}
