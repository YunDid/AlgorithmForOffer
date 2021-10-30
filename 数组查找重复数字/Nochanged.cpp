#include<iostream>
using namespace std;


void repeat(const int* arr, int n);

//int main() {
//
//	int arr2[] = { 1,2,3,4,5,4,6 };
//	repeat(arr2, 7);
//}


void repeat(const int* arr, int n) {

	if (arr == nullptr || n < 0) {
		return;
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] > n - 1 || arr[i] < 1)
		{
			return;
		}
	}
	//ȷ�����ظ����ֵķ�Χ
	int low = 1;
	int high = n - 1;
	
	//�ڸ÷�Χ�ڽ��ж��֣���С�ظ����ֵķ�Χ
	while (low < high) {

		int mid = (high + 1) / 2;
		int nums = 0;

		//���������ж�ָ����Χ�� (1 - mid) �����ֳ��ֵĴ���
		for (int i = 0; i <= n; i++) {

			if (arr[i] <= mid && arr[i] >= 1) {
				nums++;
			}

		}

		//�õ������ַ�Χ�ĳ���
		int count = mid - low + 1;

		//�����������ֳ��ִ������ڸ����ַ�Χ�ĳ��ȣ�˵�������ַ�Χ�ڴ����ظ�����
		if (nums > count) {
			high = mid;
		}
		else {
			low = mid + 1;
		}

	}

	cout << arr[high];
}