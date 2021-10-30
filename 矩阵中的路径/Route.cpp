#include<iostream>
using namespace std;


bool hasPathCore(char*, int, int, int, int, int&, string, bool*&);
bool hasPath(char*, int, int, string);
void tttest();

//int main() {
//	tttest();
//}

void tttest() {
	char p[][4] = { { 'a','a','a','a'} };
	if (hasPath(p[0], 4, 1, "aaaa")) {
		cout << "passed" << endl;
	}
	else {
		cout << "failed" << endl;
	}
}

bool hasPath(char* arr, int cols, int rows, string str) {
	//�쳣����
	if (arr == nullptr || cols < 1 || rows < 1 || str.empty()) {
		throw new exception("�쳣!");
	}

	//���÷��ʱ�ʶ����
	bool* visited = new bool[cols*rows];
	//��ʼ��
	memset(visited, 0, cols*rows);
	//����·�����������ڱ�ʶ·������״̬
	int pathLength = 0;

	//��������ÿһ��Ԫ�ؽ���·������
	for (int col = 0; col < cols; col++) {
		for (int row = 0; row < rows; row++) {
			if (hasPathCore(arr, cols, col, rows, row, pathLength, str, visited)) {
				return true;
			}
		}
	}

	delete []visited;
	return false;
	
}

bool hasPathCore(char* arr, int cols, int col, int rows, int row, int& pathLength,string str, bool*&visited) {
	//base case
	if (str[pathLength] == '\0') {
		return true;
	}
	
	//���÷���ֵ
	bool hasPath = false;
	if (col >= 0 && col < cols&&row>=0 && row < rows&&arr[row*cols + col] == str[pathLength] && visited[row*cols + col] != true) {
		//�ҵ�ƥ��·��Ԫ�أ�������һ��ƥ���·��Ԫ��
		pathLength++;
		//���÷���״̬
		visited[row*cols + col] == true;
		
		//���Ҹ�Ԫ�ص�����Ԫ��
		if (hasPathCore(arr, cols, col + 1, rows, row, pathLength, str, visited)
			|| hasPathCore(arr, cols, col, rows, row + 1, pathLength, str, visited)
			|| hasPathCore(arr, cols, col - 1, rows, row, pathLength, str, visited)
			|| hasPathCore(arr, cols, col, rows, row - 1, pathLength, str, visited)) {
			hasPath = true;
		}

		//��δ�ҵ���һ��ƥ��Ԫ�أ���Ҫ���ݵ���һ��Ԫ��
		if (!hasPath) {
			pathLength--;
			visited[row*cols + col] == false;
		}
	}

	return hasPath;
}