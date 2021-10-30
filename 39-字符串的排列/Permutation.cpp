#include<iostream>
#include<vector>
using namespace std;

namespace T39 {

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	void Permutation(char*);
	void PermutationCore(char*, char*);

	void Permutation(vector<char>&);
	void PermutationCore(vector<char>&, vector<char>&);

	int Num = 0;
	bool SameCheck(int*, int);
	void EightQueen(int*, int);
	void EightQueenCore(int*, int*, int);
	
	bool SameCheck(int* str, int len) {

		//判断是否存在同行，同列，同对角线的元素
		//双重循环时i，j必然不会相同，因此在于判断两元素是否在同一个对角线上
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (i - j == str[i] - str[j] || j - i == str[i] - str[j]) {
					return false;
				}
			}
		}

		return true;
	}

	void EightQueen(int* arr,int QueenNum) {
		//异常判断
		if (arr == nullptr) {
			return;
		}
		EightQueenCore(arr, arr, QueenNum);
	}

	void EightQueenCore(int* pAllStart, int* pCurrntStart, int len) {
		//base case
		//len为进行全排列的整数数目，当len减至0时，代表已将len长度的所有整数进行了全排列
		if (len == 0) {
			 
			if (SameCheck(pAllStart, pCurrntStart - pAllStart))
			{
				Num++;
				int* pStart = pAllStart;
				cout << Num << endl;
				for (; pStart < pCurrntStart; pStart++) {
					cout << *pStart << " ";
				}
				cout << endl;
			}
		}

		//遍历字符串的每个元素 -- 保证作出所有可能的水平决策
		int i = 0;
		for (int* pCur = pCurrntStart; i < len; pCur++, i++) {

			//决策结果为 pCur元素位于pCurrntStart位置 --水平决策

			int pTemp = *pCur;
			*pCur = *pCurrntStart;
			*pCurrntStart = pTemp;

			//pCurrntStart位置之后位置递归进行决策 --垂直决策
			EightQueenCore(pAllStart, pCurrntStart + 1, len - 1);

			//还原字符串  --水平决策复原
			pTemp = *pCur;
			*pCur = *pCurrntStart;
			*pCurrntStart = pTemp;

		}

	}

	void PermutationCore(vector<char>& ori, vector<char>& pmt) {
		//base case
		if (ori.empty()) {
			//输出当前的全排列结果
			for (auto i : pmt) {
				cout << i << " ";
			}

			cout << endl;
		}

		//遍历字符串的每个元素 -- 保证作出所有可能的水平决策
		for (int i = 0; i < ori.size(); i++) {

			//将当前决策结果存放于pmt数组中去 --水平决策
			pmt.push_back(ori[i]);

			//为了确保在剩余元素中作出下次垂直决策，需要将当前元素暂时弹出，因为需要恢复，因此先暂存
			char temp = ori[i];
			ori.erase(ori.begin() + i);

			//对已决策的下一个位置作出元素决策 --垂直决策
			PermutationCore(ori, pmt);

			//还原  --水平决策复原
			ori.insert(ori.begin() + i, temp);
			pmt.pop_back();

		}
	}

	void Permutation(vector<char>& Ori) {
		//异常判断
		if (Ori.empty()) {
			return;
		}

		vector<char> pmt;
		PermutationCore(Ori, pmt);
	}

	void Permutation(char* arr) {
		//异常判断
		if (arr == nullptr) {
			return;
		}
		PermutationCore(arr, arr);
	}

	void PermutationCore(char* pAllStart, char* pCurrntStart) {
		//base case
		if (*pCurrntStart == '\0') {
			cout << pAllStart << endl;
		}

		//遍历字符串的每个元素 -- 保证作出所有可能的水平决策
		for (char* pCur = pCurrntStart; *pCur != '\0'; pCur++) {

			//决策结果为 pCur元素位于pCurrntStart位置 --水平决策

			char pTemp = *pCur;
			*pCur = *pCurrntStart;
			*pCurrntStart = pTemp;

			//pCurrntStart位置之后位置递归进行决策 --垂直决策
			PermutationCore(pAllStart, pCurrntStart + 1);

			//还原字符串  --水平决策复原
			pTemp = *pCur;
			*pCur = *pCurrntStart;
			*pCurrntStart = pTemp;

		}

	}

	void test() {

		test1();
		/*test2();
		test3();
		test4();*/

	}
	void test1() {

		int a[8] = { 0,1,2,3,4,5,6,7 };
		EightQueen(a, 8);

	}
	void test2() {




	}
	void test3() {

		vector<char> a;
		a.push_back('a');
		a.push_back('b');
		a.push_back('c');
		Permutation(a);

	}

	void test4() {
		char a[] = "aaa";
		Permutation(a);
	}
}

using namespace T39;

//int main() {
//	test();
//}