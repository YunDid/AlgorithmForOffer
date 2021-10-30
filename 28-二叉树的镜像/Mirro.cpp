#include<iostream>
#include<queue>
using namespace std;

namespace T28 {

	struct TreeNode
	{
		double pValue;
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

	void RecursiveTreeMirro(TreeNode*);
	void Non_RecursiveTreeMirro(TreeNode*);

	void Non_RecursiveTreeMirro(TreeNode* pHead) {
		//判断异常
		if (pHead == nullptr) {
			return;
		}

		//使用队列完成非递归遍历
		queue<TreeNode*> Tqueue;
		Tqueue.push(pHead);
		
		//层次遍历
		while (!Tqueue.empty()) {

			//弹出根结点
			TreeNode* pTempHead = Tqueue.front();
			Tqueue.pop();
			
			//交换根节点的左右子树
			TreeNode* pTemp = pTempHead->pLeft;
			pTempHead->pLeft = pTempHead->pRight;
			pTempHead->pRight = pTemp;

			cout << pTempHead->pValue << " ";

			//将交换后的左右子树压入队列遍历交换
			if (pTempHead->pLeft) {
				Tqueue.push(pTempHead->pLeft);
			}

			if (pTempHead->pRight) {
				Tqueue.push(pTempHead->pRight);
			}
		}
	}

	void RecursiveTreeMirro(TreeNode* pHead) {
		//base case
		if (pHead == nullptr) {
			return;
		}

		//先根遍历的同时交换左右子结点，由根开始
		TreeNode* pTemp = pHead->pLeft;
		pHead->pLeft = pHead->pRight;
		pHead->pRight = pTemp;

		cout << pHead->pValue << " ";

		//左子树
		if (pHead->pLeft) {
			RecursiveTreeMirro(pHead->pLeft);
		}

		if (pHead->pRight) {
			RecursiveTreeMirro(pHead->pRight);
		}

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

		test1();
		test2();
		test3();
		test4();

	}
	void test1() {

		//仅有左子树的二叉树
		TreeNode* LeftHead = createNode(1);
		TreeNode* Node1 = createNode(3);
		TreeNode* Node2 = createNode(5);
		TreeNode* Node3 = createNode(7);

		setRelation(LeftHead, Node1, nullptr);
		setRelation(Node1, Node2, nullptr);
		setRelation(Node2, Node3, nullptr);

		Non_RecursiveTreeMirro(LeftHead);
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

		Non_RecursiveTreeMirro(RightHead);
	}
	void test3() {

		//仅一个结点的二叉树
		TreeNode* OnlyHead = createNode(1);

		Non_RecursiveTreeMirro(OnlyHead);
	}

	void test4() {
		
		//普通二叉树
		TreeNode* NormalHead = createNode(1);
		TreeNode* Node1 = createNode(3);
		TreeNode* Node2 = createNode(5);
		TreeNode* Node3 = createNode(7);
		TreeNode* Node4 = createNode(9);
		TreeNode* Node5 = createNode(11);
		TreeNode* Node6 = createNode(13);

		setRelation(NormalHead, Node1, Node2);
		setRelation(Node1, Node3, Node4);
		setRelation(Node2, Node5, Node6);

		Non_RecursiveTreeMirro(NormalHead);
	}
}

using namespace T28;

//int main() {
//	test();
//}