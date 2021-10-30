#include<iostream>
#include<vector>
using namespace std;

namespace T30 {

	//�쳣�жϱ���
	bool hasException = false;
	
	//����ԭ������
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

		//�ж�ѭ�����Ȧ�Ĵ���
		while (rows > 2 * start && cols > 2 * start) {
			
			SprintCore(arr, rows, cols, start);
			start++;

		}

	}

	void SprintCore(int** arr, int rows, int cols, int start) {
		
		//��ǰ���Ͻ�������Ϊ (start,start)
		
		//��¼��ǰ�����Ȧ�ı߽�
		int endX = cols - 1 - start;
		int endY = rows - 1 - start;

		//���Ȧ���ϰ벿��
		for (int i = start; i <= endX; i++) {
			cout << arr[start][i] << " ";
		}
		//�ж�Ȧ�Ƿ���Ҫ������������Ұ벿��
		if (endY > start) {
			for (int i = start + 1; i <= endY; i++) {
				cout << arr[i][endX] << " ";
			}
		}
		//�ж�Ȧ�Ƿ���Ҫ������������°벿��
		if (endY > start && endX > start) {
			for (int i = endX - 1; i >= start; i--) {
				cout << arr[endY][i] << " ";
			}
		}
		//�ж�Ȧ�Ƿ���Ҫ�������������벿��
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