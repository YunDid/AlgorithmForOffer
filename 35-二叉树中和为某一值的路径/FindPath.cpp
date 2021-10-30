#include<iostream>
#include<deque>
#include<vector>
using namespace std;

namespace T35 {

	struct TreeNode
	{
		int pValue;
		TreeNode* pLeft;
		TreeNode* pRight;
	};

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	TreeNode* createNode(int);
	void setRelation(TreeNode*, TreeNode*, TreeNode*);
	
	void FindPathInTree(TreeNode*, int);
	void FindPathInTree(TreeNode*, int, vector<int>&, int);

	void FindPathInTree(TreeNode* pHead, int ExpectedNum) {
		//判断异常
		if (pHead == nullptr) {
			return;
		}

		//设置存储路径的容器与记录和的变量
		vector<int> path;
		int currentSum = 0;

		//转调路径函数
		FindPathInTree(pHead, ExpectedNum, path, currentSum);
	}

	void FindPathInTree(TreeNode* pHead, int ExpectedNum, vector<int>& path, int currentSum) {
		
		//先序遍历
		
		//将当前结点的值压入路径数组，记录当前路径
		path.push_back(pHead->pValue);

		//累加和，记录当前路径和
		currentSum += pHead->pValue;

		//判断当前路径和是否为期望值且为一条树的路径(该结点为叶子结点)
		if (pHead->pLeft == nullptr && pHead->pRight == nullptr && ExpectedNum == currentSum) {
			//找到一条路径，输出该路径
			cout << "Path1 : ";
			for (auto i : path) {
				cout << i << " ";
			}
		}

		//先序遍历，判断左右子树中是否存在路径
		if (pHead->pLeft != nullptr)
			FindPathInTree(pHead->pLeft, ExpectedNum, path, currentSum);

		if (pHead->pRight != nullptr)
			FindPathInTree(pHead->pRight, ExpectedNum, path, currentSum);

		//直到找寻到叶子结点且不满足路径和才回退
		path.pop_back();
	}

	TreeNode* createNode(int value) {
		TreeNode* Node = new TreeNode();
		Node->pValue = value;
		Node->pLeft = nullptr;
		Node->pRight = nullptr;

		return Node;
	}

	void setRelation(TreeNode* pHead, TreeNode* ppLeft, TreeNode* ppRight) {
		if (pHead != nullptr) {
			pHead->pLeft = ppLeft;
			pHead->pRight = ppRight;
		}
		if (ppLeft != nullptr) {
			ppLeft->pLeft = nullptr;
			ppLeft->pRight = nullptr;
		}
		if (ppRight != nullptr) {
			ppRight->pLeft = nullptr;
			ppRight->pRight = nullptr;
		}
	}

	void test() {

		/*test1();
		test2();
		test3();*/
		test4();

	}
	void test1() {

		//仅有左子树的二叉树
		TreeNode* LeftHead = createNode(1);
		TreeNode* Node1 = createNode(2);
		TreeNode* Node2 = createNode(3);
		TreeNode* Node3 = createNode(4);

		setRelation(LeftHead, Node1, nullptr);
		setRelation(Node1, Node2, nullptr);
		setRelation(Node2, Node3, nullptr);

		/*lprintTree(LeftHead);*/
	}
	void test2() {

		//仅有右子树的二叉树
		TreeNode* RightHead = createNode(1);
		TreeNode* Node1 = createNode(3);
		TreeNode* Node2 = createNode(5);
		TreeNode* Node3 = createNode(7);

		setRelation(RightHead, nullptr, Node1);
		setRelation(Node1, nullptr, Node2);
		setRelation(Node2, nullptr, Node3);

		//lprintTree(RightHead);
	}
	void test3() {

		//仅一个结点的二叉树
		TreeNode* OnlyHead = createNode(1);

		//lprintTree(OnlyHead);

	}

	void test4() {

		//普通二叉树
		TreeNode* NormalHead = createNode(10);
		TreeNode* Node1 = createNode(5);
		TreeNode* Node2 = createNode(12);
		TreeNode* Node3 = createNode(4);
		TreeNode* Node4 = createNode(7);
		TreeNode* Node5 = createNode(9);
		//TreeNode* Node6 = createNode(7);
		//TreeNode* Node7 = createNode(8);
		//TreeNode* Node8 = createNode(9);
		//TreeNode* Node9 = createNode(10);
		//TreeNode* Node10 = createNode(11);

		setRelation(NormalHead, Node1, Node2);
		setRelation(Node1, Node3, Node4);
		setRelation(Node2, Node5, nullptr);
		//setRelation(Node3, Node7, Node8);
		//setRelation(Node4, Node9, Node10);

		FindPathInTree(NormalHead, 22);
	}
}

using namespace T35;

//int main() {
//	test();
//}