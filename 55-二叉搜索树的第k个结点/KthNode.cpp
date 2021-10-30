#include<iostream>
#include<deque>
using namespace std;

namespace T55 {

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

	void GetKthNode(TreeNode*, int);
	void GetKthNodeCore(TreeNode*, int&, int);

	TreeNode* GetKthNodePtr(TreeNode*, int);
	TreeNode* GetKthNodePtrCore(TreeNode*, int&);

	TreeNode* GetKthNodePtr(TreeNode* pHead, int k) {
		//�ж��쳣
		if (pHead == nullptr || k <= 0) {
			isException = true;
			return nullptr;
		}

		TreeNode* pKthNode = GetKthNodePtrCore(pHead, k);

		//����kԽ����쳣�ж�
		if (pKthNode == nullptr) {
			isException = true;
		}

		return pKthNode;
	}

	TreeNode* GetKthNodePtrCore(TreeNode* pHead, int& k) {
		
		TreeNode* pKthNode = nullptr;

		//���������ҵ�k�����
		if (pHead->pLeft != nullptr) {
			pKthNode = GetKthNodePtrCore(pHead->pLeft, k);
		}

		//��������δ�ҵ���k����㣬�жϵ�ǰ����Ƿ�Ϊ��k�����
		if (pKthNode == nullptr) {
			if (k == 1) {
				pKthNode = pHead;
			}
			k--;
		}

		//����ǰ��㲻�ǵ�k����㣬���ڵ�ǰ�������������ҵ�k�����
		if (pKthNode == nullptr && pHead->pRight != nullptr) {
			GetKthNodePtrCore(pHead->pRight, k);
		}

		return pKthNode;
	}

	void GetKthNode(TreeNode* pHead, int k) {
		//�ж��쳣
		if (pHead == nullptr || k <= 0) {
			isException = true;
			return;
		}

		int num = 0;

		GetKthNodeCore(pHead, num, k);
	}

	void GetKthNodeCore(TreeNode* pHead, int& num, int k) {
		//base case
		if (pHead == nullptr) {
			return;
		}

		if (pHead->pLeft != nullptr) {
			GetKthNodeCore(pHead->pLeft, num, k);
		}

		num++;
		if (num == k) {
			cout << pHead->pValue << endl;
		}

		if (pHead->pRight != nullptr) {
			GetKthNodeCore(pHead->pRight, num, k);
		}
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

		cout << "Test1:" << endl;
		//�����������Ķ�����
		TreeNode* LeftHead = createNode(4);
		TreeNode* Node1 = createNode(3);
		TreeNode* Node2 = createNode(2);
		TreeNode* Node3 = createNode(1);

		setRelation(LeftHead, Node1, nullptr);
		setRelation(Node1, Node2, nullptr);
		setRelation(Node2, Node3, nullptr);

		TreeNode* pKthNode = GetKthNodePtr(LeftHead, 1);
	}
	void test2() {

		cout << "Test2:" << endl;
		//�����������Ķ�����
		TreeNode* RightHead = createNode(1);
		TreeNode* Node1 = createNode(3);
		TreeNode* Node2 = createNode(5);
		TreeNode* Node3 = createNode(7);

		setRelation(RightHead, nullptr, Node1);
		setRelation(Node1, nullptr, Node2);
		setRelation(Node2, nullptr, Node3);

		TreeNode* pKthNode = GetKthNodePtr(RightHead, 1);
		
		if (!isException) {
			if (pKthNode->pValue == 1) {
				cout << "Passed!" << endl;
			}
			else {
				cout << "Failed!" << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}
	}
	void test3() {

		cout << "Test3:" << endl;

		//��һ�����Ķ�����
		TreeNode* OnlyHead = createNode(1);

		TreeNode* pKthNode = GetKthNodePtr(OnlyHead, 2);

		if (!isException) {
			if (pKthNode->pValue == 1) {
				cout << "Passed!" << endl;
			}
			else {
				cout << "Failed!" << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}

	}

	void test4() {

		cout << "Test4:" << endl;

		//��ͨ������
		TreeNode* NormalHead = createNode(5);
		TreeNode* Node1 = createNode(3);
		TreeNode* Node2 = createNode(7);
		TreeNode* Node3 = createNode(2);
		TreeNode* Node4 = createNode(4);
		TreeNode* Node5 = createNode(6);
		TreeNode* Node6 = createNode(8);


		setRelation(NormalHead, Node1, Node2);
		setRelation(Node1, Node3, Node4);
		setRelation(Node2, Node5, Node6);

		TreeNode* pKthNode = GetKthNodePtr(NormalHead, 7);
		
		if (!isException) {
			if (pKthNode->pValue == 8) {
				cout << "Passed!" << endl;
			}
			else {
				cout << "Failed!" << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}

	}
}

using namespace T55;

//int main() {
//	test();
//}