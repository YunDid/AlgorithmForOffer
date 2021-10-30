#include<iostream>
#include<deque>
#include<list>
using namespace std;

namespace T71 {

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

	bool isException = false;

	TreeNode* createNode(int);
	void setRelation(TreeNode*, TreeNode*, TreeNode*);
	void printTree(TreeNode*);

	//普通树中两个结点的最低公共祖先
	TreeNode* GetLastCommonNode(TreeNode*, TreeNode*, TreeNode*);
	bool GetLastCommonNodePath(TreeNode*, TreeNode*, list<int>&);
	TreeNode* GetLastCommonNodeCore(list<TreeNode*>&, list<TreeNode*>&);

	TreeNode* GetLastCommonNodeCore(list<TreeNode*>& PathList1, list<TreeNode*>& PathList2) {

		//设置记录公共结点的指针
		TreeNode* pCommon = nullptr;

		//正向遍历两个链表(根节点为头结点)，找寻第一个产生分叉的结点
		auto ite1 = PathList1.begin();
		auto ite2 = PathList2.begin();

		while (ite1 != PathList1.end() && ite2 != PathList2.end()) {
			
			if ((*ite1)->pValue == (*ite2)->pValue) {

				//记录当前公共结点
				pCommon = *ite1;
				//向后遍历
				ite1++;
				ite2++;
			}
			else {
				break;
			}

		}
		return pCommon;
	}


	bool GetLastCommonNodePath(TreeNode* pHead, TreeNode* pNode, list<TreeNode*>& PathList) {

		if (pHead == nullptr) {
			return false;
		}

		//设置返回值记录变量
		bool hasPath = false;
		
		//路径链表中记录当前遍历结点
		PathList.push_back(pHead);	

		//判断当前压入结点构成的路径是否为要求的路径
		if (pHead->pValue == pNode->pValue) {
			hasPath = true;
		}

		//若当前压入结点构成的路径不满足要求，则在当前结点的左子树中继续找寻路径
		if (!hasPath && pHead->pLeft != nullptr)
			hasPath = GetLastCommonNodePath(pHead->pLeft, pNode, PathList);
		//若左子树中未找寻到路径，则在当前结点的右子树中继续找寻路径
		if (!hasPath && pHead->pRight != nullptr)
			hasPath = GetLastCommonNodePath(pHead->pRight, pNode, PathList);

		//回溯
		if(!hasPath)
			PathList.pop_back();

		return hasPath;

	}

	TreeNode* GetLastCommonNode(TreeNode* pHead, TreeNode* pNode1, TreeNode* pNode2) {
		//判断异常
		if (pHead == nullptr || pNode1 == nullptr || pNode2 == nullptr) {
			isException = true;
			return nullptr;
		}

		//创建存储路径的辅助空间
		list<TreeNode*> PathList1;
		list<TreeNode*> PathList2;

		//设置返回值
		TreeNode* pCommonNode = nullptr;

		//获取根结点到两个结点的路径，若有一条路径不存在，则无公共结点
		if (GetLastCommonNodePath(pHead, pNode1, PathList1) && GetLastCommonNodePath(pHead, pNode2, PathList2)) {
			pCommonNode = GetLastCommonNodeCore(PathList1, PathList2);
		}

		return pCommonNode;
	}


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
		TreeNode* LeftHead = createNode(8);
		TreeNode* Node1 = createNode(6);
		TreeNode* Node2 = createNode(4);
		TreeNode* Node3 = createNode(1);
		TreeNode* Node4 = createNode(7);
		TreeNode* Node5 = createNode(5);

		setRelation(LeftHead, Node1, nullptr);
		setRelation(Node1, Node2, nullptr);
		setRelation(Node2, Node3, nullptr);

		cout << "Test1:" << endl;
		TreeNode* pCom = GetLastCommonNode(LeftHead, Node5, Node4);
		if (!isException) {
			if (pCom != nullptr) {
				if (pCom->pValue == 2) {
					cout << "passed!" << endl;
				}
				else {
					cout << "failed!" << endl;
					cout << pCom->pValue << endl;
				}
			}
			else {
				cout << "nullptr!" << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}
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

		cout << "Test2:" << endl;
		TreeNode* pCom = GetLastCommonNode(RightHead, Node2, Node3);
		if (!isException) {
			if (pCom != nullptr) {
				if (pCom->pValue == 5) {
					cout << "passed!" << endl;
				}
				else {
					cout << "failed!" << endl;
					cout << pCom->pValue << endl;
				}
			}
			else {
				cout << "nullptr!" << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}

	}
	void test3() {

		//仅一个结点的二叉树
		TreeNode* OnlyHead = createNode(1);

		cout << "Test3:" << endl;
		TreeNode* pCom = GetLastCommonNode(OnlyHead, OnlyHead, OnlyHead);
		if (!isException) {
			if (pCom != nullptr) {
				if (pCom->pValue == 1) {
					cout << "passed!" << endl;
				}
				else {
					cout << "failed!" << endl;
					cout << pCom->pValue << endl;
				}
			}
			else {
				cout << "nullptr!" << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}

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


		setRelation(NormalHead, Node1, Node2);
		setRelation(Node1, Node3, Node4);
		setRelation(Node2, Node5, Node6);

		cout << "Test4:" << endl;
		TreeNode* pCom = GetLastCommonNode(NormalHead, Node5, Node6);
		if (!isException) {
			if (pCom != nullptr) {
				if (pCom->pValue == 6) {
					cout << "passed!" << endl;
				}
				else {
					cout << "failed!" << endl;
					cout << pCom->pValue << endl;
				}
			}
			else {
				cout << "nullptr!" << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}

	}
}

using namespace T71;

int main() {
	test();
}