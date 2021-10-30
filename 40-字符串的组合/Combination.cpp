#include<iostream>
#include<vector>
using namespace std;

namespace T40 {

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	void Combination(char*);
	void CombinationCore(char*, int, vector<char>&);

	void Combination(char* arr) {
		//异常判断
		if (arr == nullptr) {
			return;
		}

		//将n个元素的所有组合拆解为求n次 mlen个元素中长度为k的组合
		char *len = arr;
		int mlen = 0;
		vector<char> comb;

		for (; *len != '\0'; len++) {
			mlen++;
		}

		for (int k = 1; k <= mlen; k++) {
			CombinationCore(arr, k, comb);
		}
	}

	void CombinationCore(char* str, int k, vector<char>& comb) {
		//base case
		if (k == 0) {
			//输出组合结果
			for (auto i : comb) {
				cout << i << " ";
			}

			cout << endl;
			return;
		}

		if (*str == '\0') {
			return;
		}

		//对str中的每个元素进行决策 长度为k的组合是否含有当前元素
		//yes k个元素组合中含当前元素
		comb.push_back(*str);
		//在str剩余元素中取k-1个元素进行组合
		CombinationCore(str + 1, k - 1, comb);

		//在进行同层结果为no的决策前，需要恢复
		comb.pop_back();

		//no k个元素组合中不含当前元素
		//在str剩余元素中取k个元素进行组合
		CombinationCore(str + 1, k, comb);
	}

	void test() {

		/*test1();
		test2();
		test3();*/
		test4();

	}
	void test1() {



	}
	void test2() {




	}
	void test3() {

		vector<char> a;
		a.push_back('a');
		a.push_back('b');
		a.push_back('c');

	}

	void test4() {
		char a[] = "abc";
		Combination(a);
	}
}

using namespace T40;

//int main() {
//	test();
//}