#include<iostream>
using namespace std;

int _getMin(int *, int, int);
int getMin(int *, int);


//int main() {
//	int a[] = { 1,0,1,1,1 };
//	cout << getMin(nullptr, 0) << endl;
//}

int getMin(int *arr, int length) {
	//�쳣����
	if (arr == nullptr || length <= 0) {
		throw new exception("�����쳣��");
	}

	//ָ���ʼ��
	int left = 0;
	int right = length - 1;
	//���ǵ���ת������ת�߶�Ϊ0ʱ�������������������ʱ�������������Ԫ��
	int mid = left;
	/*int mid = left;*/
	
	while (arr[left] >= arr[right]) {
		if (right - left == 1) {
			mid = right;
			break;
		}

		//ȡ��Χ�ڵ�һ����
		mid = (left + right) / 2;
		if (arr[left] == arr[right] && arr[mid] == arr[left]) {
			//ָ����Χ��˳�����
			_getMin(arr, left, right);
		}

		if (arr[mid] >= arr[left]) {
			left = mid;
		}
		else if (arr[mid] <= arr[right]) {
			right = mid;
		}

	}
	mid = right;
	return arr[mid];
}

int _getMin(int *arr, int left, int right) {
	int min = arr[left];
	for (int i = left + 1; i <= right; i++) {
		if (arr[i] <= min) {
			min = arr[i];
		}
	}
	return min;
}