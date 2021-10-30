#include<iostream>
#include<deque>
using namespace std;

namespace T34 {

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool VerifySquenceOfBST(int*, int);

	bool VerifySquenceOfBST(int* Seq, int Slength) {
		
		//异常判断
		if (Seq == nullptr || Slength <= 0) {
			return false;
		}

		//判断当前根节点与其左右子树是否满足二叉搜索树
		//取当前根节点
		int root = Seq[Slength - 1];

		//找寻第一个比根节点大节点作为左右子树分界，此时左子树均比根节点小
		int i = 0;
		for (; i < Slength - 1; i++) {
			if (Seq[i] > root) {
				break;
			}
		}

		//判断该根节点右子树是否存在比其小的节点
		int j = i;
		for (; j < Slength - 1; j++) {
			if (Seq[j] < root) {
				return false;
			}
		}

		//此时根节点左子树的节点均比根节点小，右子树的节点均比根节点大，满足二叉搜索树性质
		//--------------------------------------------------------------------
		//进而判断该根节点的左右子树是否满足二叉搜索树性质

		//若含左子树，则判断左子树是否满足二叉搜索树性质
		bool left = true;
		if (i > 0)
			left = VerifySquenceOfBST(Seq, i);

		//若含右子树，判断右子树是否满足二叉搜索树性质
		bool Right = true;
		if (i < Slength - 1)
			Right = VerifySquenceOfBST(Seq + i, Slength - i - 1);

		return left && Right;
	}

	void test() {

		test1();
		test2();
		test3();
		test4();

	}
	void test1() {
		int a[] = { 5,7,6,9,11,10,8 };
		if (VerifySquenceOfBST(a, 7) == true) {
			cout << "test1 passed!" << endl;
		}
		else {
			cout << "test1 failed!" << endl;
		}
	}
	void test2() {
		int a[] = { 7,4,6,5 };
		if (VerifySquenceOfBST(nullptr, 4) != true) {
			cout << "test2 passed!" << endl;
		}
		else {
			cout << "test2 failed!" << endl;
		}
	}
	void test3() {

	}

	void test4() {
		
	}
}

using namespace T34;

//int main() {
//	test();
//}