#include<iostream>
#include<deque>
using namespace std;

namespace T37 {

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
	TreeNode* Convert(TreeNode*);
	void ConvertCore(TreeNode*, TreeNode**);
	void printTree(TreeNode*);

	void printTree(TreeNode* pHead) {
		if (pHead == nullptr) {
			return;
		}	

		if (pHead->pLeft != nullptr)
			printTree(pHead->pLeft);

		cout << pHead->pValue << " ";

		if (pHead->pRight != nullptr)
			printTree(pHead->pRight);
		
	}

	TreeNode* Convert(TreeNode* pHead) {
		
		//异常判断
		if (pHead == nullptr) {
			return nullptr;
		}

		//设置记录当前双向链表尾部的指针
		TreeNode* PointToListTail = nullptr;
		//将尾部的指针一并传入进行递归
		ConvertCore(pHead, &PointToListTail);

		while (PointToListTail != nullptr && PointToListTail->pLeft != nullptr) {
			PointToListTail = PointToListTail->pLeft;
		}

		return PointToListTail;
	}

	void ConvertCore(TreeNode* pHead, TreeNode** PointToListTail) {
		
		//设置遍历指针
		TreeNode* pCurrentNode = pHead;
		
		//basecase
		if (pHead == nullptr) {
			return;
		}

		//中序遍历
		if (pCurrentNode->pLeft != nullptr) {
			ConvertCore(pCurrentNode->pLeft, PointToListTail);
		}

		//设置当前根节点为双向链表的新尾部
		pCurrentNode->pLeft = *PointToListTail;

		if (*PointToListTail != nullptr) {
			(*PointToListTail)->pRight = pCurrentNode;
		}

		*PointToListTail = pCurrentNode;

		//将新双向链表与右子树连接
		if (pCurrentNode->pRight != nullptr) {
			ConvertCore(pCurrentNode->pRight, PointToListTail);
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

		
	}
	void test3() {

		//仅一个结点的二叉树
		TreeNode* OnlyHead = createNode(1);

		

	}

	void test4() {

		//普通二叉树
		TreeNode* NormalHead = createNode(4);
		TreeNode* Node1 = createNode(2);
		TreeNode* Node2 = createNode(6);
		TreeNode* Node3 = createNode(1);
		TreeNode* Node4 = createNode(3);
		TreeNode* Node5 = createNode(5);
		TreeNode* Node6 = createNode(7);
		/*TreeNode* Node7 = createNode(8);
		TreeNode* Node8 = createNode(9);
		TreeNode* Node9 = createNode(10);
		TreeNode* Node10 = createNode(11);*/

		setRelation(NormalHead, Node1, Node2);
		setRelation(Node1, Node3, Node4);
		setRelation(Node2, Node5, Node6);
		/*setRelation(Node3, Node7, Node8);
		setRelation(Node4, Node9, Node10);*/

		TreeNode* pHead = Convert(NormalHead);
		TreeNode* pNode = pHead;

		while (pNode != nullptr) {
			cout << pNode->pValue << endl;
			if (pNode->pLeft != nullptr)
				cout << "pLeft: " << pNode->pLeft->pValue << endl;
			else 
				cout << "pLeft: nullptr" << endl;
			if (pNode->pRight != nullptr)
				cout << "pRight: " << pNode->pRight->pValue << endl;
			else 
				cout << "pRight: nullptr"<< endl;
			pNode = pNode->pRight;
		}
	}
}

using namespace T37;

//int main() {
//	test();
//}