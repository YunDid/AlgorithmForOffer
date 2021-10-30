#include<iostream>
using namespace std;

bool search(int* arr, int rows, int cols, int n);

//int main() {
//	int aa[4][4] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
//	int n;
//	cin >> n;
//	if (search(aa[0], 4, 4, n)) {
//		cout << "��������: "<< n << endl;
//	}else{
//		cout << "����������: "<< n << endl;
//	}
//}

bool search(int* arr,int rows,int cols, int n) {
	
	//�������Ͻ�λ��
	int row = 0;
	int col = cols - 1;

	//ֱ��Խ���������
	while (row < rows && col >= 0) {
		if (n > arr[row*cols + col]) {
			//�޳�һ��
			row++;
		}
		else if (n == arr[row*cols + col]) {
			return true;
		}
		else {
			//�޳�һ��
			col--;
		}
	}

	return false;
}
