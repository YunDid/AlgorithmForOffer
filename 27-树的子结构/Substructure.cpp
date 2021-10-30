#include<iostream>
using namespace std;

namespace T27 {

	struct TreeNode
	{
		double pValue;
		TreeNode* pLeft;
		TreeNode* pRight;
	};

	//函数原型声明
	void test();
	TreeNode* createNode(int);
	void setRelation(TreeNode*, TreeNode*, TreeNode*);
	
	bool hasSubTree(TreeNode*, TreeNode*);
	bool hasSubTreeCore(TreeNode*, TreeNode*);
	bool Equal(double, double);

	bool hasSubTree(TreeNode* pHead, TreeNode* pSHead) {
		//判断异常
		if (pHead == nullptr || pSHead == nullptr) {
			return false;
		}
		//设置返回值
		bool result = false;

		//判断是否是否含有与sub根结点相同的结点
		if (Equal(pHead->pValue, pSHead->pValue)) {
			//若根结点相同则继续判断是否含有sub子树
			result = hasSubTreeCore(pHead, pSHead);
		}

		//若该根结点与sub子树根结点不同，或该根结点下的子树与sub子树结构不同，则向下遍历
		if (!result) {
			result = hasSubTreeCore(pHead->pLeft, pSHead);
		}
		if (!result) {
			result = hasSubTreeCore(pHead->pRight, pSHead);
		}

		return result;

	}

	bool hasSubTreeCore(TreeNode* pHead, TreeNode* pSHead) {
		//base case
		if (pSHead == nullptr) {
			return true;
		}
		if (pHead == nullptr) {
			return false;
		}
		//判断当前结点是否相同
		if (!Equal(pHead->pValue, pSHead->pValue)) {
			return false;
		}
		//递归判断左右子树是否结构相同
		bool hasLeftSub = hasSubTreeCore(pHead->pLeft, pSHead->pLeft);
		bool hasRightSub = hasSubTreeCore(pHead->pRight, pSHead->pRight);
		
		return hasLeftSub && hasRightSub;
	}

	bool Equal(double x, double y) {
		return (x - y >= -0.001) && (x - y <= 0.001);
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
		//链表1
		TreeNode* Head1 = createNode(1);
		TreeNode* Node1 = createNode(3);
		TreeNode* Node2 = createNode(5);
		TreeNode* Node3 = createNode(7);
		TreeNode* Node4 = createNode(9);
		TreeNode* Node5 = createNode(11);

		setRelation(Head1, Node1, Node2);
		setRelation(Node1, Node2, Node3);
		setRelation(Node2, Node3, Node4);
		setRelation(Node3, Node4, Node5);
		/*Node5->pNext = Node4;*/

		//链表2
		TreeNode* Head2 = createNode(1);
		TreeNode* Node6 = createNode(3);
		TreeNode* Node7 = createNode(5);
		TreeNode* Node8 = createNode(7);
		/*TreeNode* Node9 = createNode(10);
		TreeNode* Node10 = createNode(12);*/

		setRelation(Head2, Node6, Node7);
		setRelation(Node6, Node7, Node8);
		/*setRelation(Node7, Node8, Node9);
		setRelation(Node8, Node9, Node10);*/

		bool has = hasSubTree(Head1, Head2);

		if (has == true) {
			cout << "passed" << endl;
		}
		else {
			cout << "failed" << endl;
		}
	}

}

using namespace T27;

//int main() {
//	test();
//}