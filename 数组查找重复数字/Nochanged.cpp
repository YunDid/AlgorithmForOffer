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
	//确定有重复数字的范围
	int low = 1;
	int high = n - 1;
	
	//在该范围内进行二分，缩小重复数字的范围
	while (low < high) {

		int mid = (high + 1) / 2;
		int nums = 0;

		//遍历数组判断指定范围内 (1 - mid) 的数字出现的次数
		for (int i = 0; i <= n; i++) {

			if (arr[i] <= mid && arr[i] >= 1) {
				nums++;
			}

		}

		//得到该数字范围的长度
		int count = mid - low + 1;

		//若数组中数字出现次数大于该数字范围的长度，说明该数字范围内存在重复数字
		if (nums > count) {
			high = mid;
		}
		else {
			low = mid + 1;
		}

	}

	cout << arr[high];
}