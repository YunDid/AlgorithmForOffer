#include<iostream>
#include<stack>
#include<deque>
using namespace std;

namespace T70 {

	struct TreeNode
	{
		int pValue;
		TreeNode* pLeft;
		TreeNode* pRight;
		TreeNode* pParent;
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

	//����ָ����������������͹�������
	TreeNode* GetLastCommonNode(TreeNode*, TreeNode*);
	TreeNode* GetLastCommonNodeCoreByStack(TreeNode*, TreeNode*);

	TreeNode* GetLastCommonNodeCoreByStack(TreeNode* pNode1, TreeNode* pNode2) {

		//������������ջ
		stack<TreeNode*> List1;
		stack<TreeNode*> List2;

		//������������ֱ�ѹջ
		while (pNode1 != nullptr) {
			List1.push(pNode1);
			pNode1 = pNode1->pParent;
		}

		while (pNode2 != nullptr) {
			List2.push(pNode2);
			pNode2 = pNode2->pParent;
		}

		//���ü�¼�������ȵ�ָ��
		TreeNode* pCommon = nullptr;

		//������β����ʼ��Ѱ��һ�β����ֲ�Ľ��
		while (!List1.empty() && !List2.empty() && List1.top() == List2.top()) {
			
			pCommon = List1.top();
			List1.pop();
			List2.pop();
		}		

		return pCommon;
	}

	TreeNode* GetLastCommonNode(TreeNode* pNode1, TreeNode* pNode2) {
		//�ж��쳣
		if (pNode1 == nullptr || pNode2 == nullptr) {
			isException = true;
			return nullptr;
		}

		return GetLastCommonNodeCoreByStack(pNode1, pNode2);

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
		Node->pParent = nullptr;

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
			ppLeft->pParent = pHead;
		}
		if (ppRight != nullptr) {
			ppRight->pLeft = nullptr;
			ppRight->pRight = nullptr;
			ppRight->pParent = pHead;
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
		TreeNode* pCom = GetLastCommonNode(Node5, Node4);
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
		TreeNode* pCom = GetLastCommonNode(Node2, Node3);
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
		TreeNode* pCom = GetLastCommonNode(OnlyHead, OnlyHead);
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
		TreeNode* pCom = GetLastCommonNode(Node5, Node6);
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

using namespace T70;

//int main() {
//	test();
//}