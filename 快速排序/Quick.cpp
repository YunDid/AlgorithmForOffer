//#include<iostream>
//#include<time.h>
//using namespace std;
//
//int RandNum(int n, int m);
//int Position(int *arr,int len, int start, int end);
//void QuickSort(int *arr, int len, int start, int end);
//void swap_element(int *a, int *b);
//void Test();
//void Test11();
//
//int main() {
//	Test();
//	Test11();
//}
//
//int Position(int *arr, int len, int start, int end) {
//	if (arr == nullptr || len <= 0 || start < 0 || end >= len) {
//		throw new exception("数组异常");
//	}
//	//随机获取关键字索引
//	int index = start;
//	int key = arr[index];
//
//	while (start < end) {
//		while (start < end &&arr[start] < key) {
//			start++;
//		}
//		
//		if (arr[start] >= key) {
//			arr[index] = arr[start];
//			index = start;
//		}
//
//		while (start < end &&arr[end] >= key) {
//			end--;
//		}
//
//		if (arr[end] < arr[index]) {
//			arr[index] = arr[end];
//			index = end;
//		}
//	}
//
//	arr[index] = key;
//	return index;
//
//}
//
//void QuickSort(int *arr, int len, int start, int end)
//{
//	if (start >= end) {
//		return;
//	}
//	//获取关键字位置
//	int index = Position(arr, len, start, end);
//	//递归快排index左边的数据
//	if (index > start)
//		QuickSort(arr, len, start, index - 1);
//	//递归快排index右边的数据
//	if (index < end)
//		QuickSort(arr, len, index + 1, end);
//}
//
//int RandNum(int start, int end) {
//	if (end > start)
//	{
//		srand(time(NULL));//　srand函数是随机数发生器的初始化函数,使得随机数种子随时间的变化而变化
//		return start + rand() % ((end - start));//产生start~end之间的随机数
//	}
//	return 0;
//}
//
//void Test() {
//	int a[] = { 4,5,3,7,9,8,1 };
//	QuickSort(a, 7, 0, 6);
//	for (int i = 0; i < 7; i++) {
//		cout << a[i] << " ";
//	}
//}
//
//void Test11() {
//	int a[] = {4};
//	QuickSort(nullptr, 1, 0, 0);
//	for (int i = 0; i < 1; i++) {
//		cout << a[i] << " ";
//	}
//}
//
//void swap_element(int *a, int *b) {
//	int t = *b; *b = *a; *a = t;
//}