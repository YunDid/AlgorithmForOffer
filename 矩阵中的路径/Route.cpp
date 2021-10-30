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
	//异常处理
	if (arr == nullptr || cols < 1 || rows < 1 || str.empty()) {
		throw new exception("异常!");
	}

	//设置访问标识数组
	bool* visited = new bool[cols*rows];
	//初始化
	memset(visited, 0, cols*rows);
	//设置路径变量，用于标识路径搜索状态
	int pathLength = 0;

	//遍历矩阵每一个元素进行路径搜索
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
	
	//设置返回值
	bool hasPath = false;
	if (col >= 0 && col < cols&&row>=0 && row < rows&&arr[row*cols + col] == str[pathLength] && visited[row*cols + col] != true) {
		//找到匹配路径元素，查找下一个匹配的路径元素
		pathLength++;
		//设置访问状态
		visited[row*cols + col] == true;
		
		//查找该元素的相邻元素
		if (hasPathCore(arr, cols, col + 1, rows, row, pathLength, str, visited)
			|| hasPathCore(arr, cols, col, rows, row + 1, pathLength, str, visited)
			|| hasPathCore(arr, cols, col - 1, rows, row, pathLength, str, visited)
			|| hasPathCore(arr, cols, col, rows, row - 1, pathLength, str, visited)) {
			hasPath = true;
		}

		//若未找到下一个匹配元素，需要回溯到上一个元素
		if (!hasPath) {
			pathLength--;
			visited[row*cols + col] == false;
		}
	}

	return hasPath;
}