#include<iostream>
using namespace std;


bool repeat(int arr[], int n);

//int main() {
//	int arr1[] = { 0,1,2,3,4,5,6 };
//	int arr2[] = { 0,1,1,3,3,4,6 };
//	if (repeat(arr2, 7)) {
//		cout << endl;
//	}
//}

//¹éÎ»·¨
bool repeat(int arr[], int n) {

	bool re = false;
	
	if (arr == nullptr || n < 0) {
		return false;
	}
	
	for (int i = 0; i < n; i++) {
		if (arr[i] > n - 1 || arr[i] < 0)
		{
			return false;
		}
	}

	for (int i = 0; i < n; i++) {

		if (i != arr[i]) {
			if (arr[i] == arr[arr[i]]) {
				cout << arr[i] << " ";
				re = true;
			}
			else {
				int t = arr[i];
				arr[i] = arr[arr[i]];
				arr[arr[i]] = t;
			}
		}

	}

	return re;
}