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
//		throw new exception("�����쳣");
//	}
//	//�����ȡ�ؼ�������
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
//	//��ȡ�ؼ���λ��
//	int index = Position(arr, len, start, end);
//	//�ݹ����index��ߵ�����
//	if (index > start)
//		QuickSort(arr, len, start, index - 1);
//	//�ݹ����index�ұߵ�����
//	if (index < end)
//		QuickSort(arr, len, index + 1, end);
//}
//
//int RandNum(int start, int end) {
//	if (end > start)
//	{
//		srand(time(NULL));//��srand������������������ĳ�ʼ������,ʹ�������������ʱ��ı仯���仯
//		return start + rand() % ((end - start));//����start~end֮��������
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