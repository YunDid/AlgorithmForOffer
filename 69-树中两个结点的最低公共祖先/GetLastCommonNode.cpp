#include<iostream>
#include<deque>
using namespace std;

namespace T69 {

	struct TreeNode
	{
		int pValue;
		TreeNode* pLeft;
		TreeNode* pRight;
	};

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isException = false;

	TreeNode* createNode(int);
	void setRelation(TreeNode*, TreeNode*, TreeNode*);
	void printTree(TreeNode*);

	//����������������������͹�������
	TreeNode* GetLastCommonNode(TreeNode*, TreeNode*, TreeNode*);
	TreeNode* GetLastCommonNodeCore(TreeNode*, TreeNode*, TreeNode*);

	TreeNode* GetLastCommonNodeCore(TreeNode* pHead, TreeNode* pNode1, TreeNode* pNode2) {

		//base case
		if (pHead == nullptr) {
			return nullptr;
		}

		//����ǰ�����������ֵ���󣬸��ݶ������������ʣ������������м�������
		if (pHead->pValue > pNode1->pValue && pHead->pValue > pNode2->pValue) {
			return GetLastCommonNodeCore(pHead->pLeft, pNode1, pNode2);
		}

		//����ǰ�����������ֵ��С�����ݶ������������ʣ������������м�������
		else if (pHead->pValue < pNode1->pValue && pHead->pValue < pNode2->pValue) {
			return GetLastCommonNodeCore(pHead->pRight, pNode1, pNode2);
		}

		//��ʱpHead���ֵҪô���������֮�䣬Ҫô��������һ�ߵ�ֵ
		else
			return pHead;
	}

	TreeNode* GetLastCommonNode(TreeNode* pHead, TreeNode* pNode1, TreeNode* pNode2) {
		//�ж��쳣
		if (pHead == nullptr || pNode1 == nullptr || pNode2 == nullptr) {
			isException = true;
			return nullptr;
		}

		return GetLastCommonNodeCore(pHead, pNode1, pNode2);

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

		//�����������Ķ�����
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
			cout << "�쳣!" << endl;
		}
	}
	void test2() {

		//�����������Ķ�����
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
			cout << "�쳣!" << endl;
		}

	}
	void test3() {

		//��һ�����Ķ�����
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
			cout << "�쳣!" << endl;
		}

	}

	void test4() {

		//��ͨ������
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
			cout << "�쳣!" << endl;
		}

	}
}

using namespace T69;

//int main() {
//	test();
//}