#include<iostream>
#include<queue>
using namespace std;

namespace T29 {

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

	TreeNode* createNode(int);
	void setRelation(TreeNode*, TreeNode*, TreeNode*);
	bool isSymmetry(TreeNode*);
	bool isSymmetryCore(TreeNode*, TreeNode*);
	
	bool isSymmetry(TreeNode* pHead) {
		//�ж��쳣
		if (pHead == nullptr) {
			return false;
		}

		return isSymmetryCore(pHead, pHead);
	}

	bool isSymmetryCore(TreeNode* pHead, TreeNode* pSHead) {
		//base case
		//��ǰ�������Գ�ǰ�������ͷ���ͬʱΪ�գ�����Գ�����
		if (pHead == nullptr && pSHead == nullptr) {
			return true;
		}
		//��ǰ�������Գ�ǰ�������ͷ��㲻ͬʱΪ�գ�������Գ�����
		if (pHead == nullptr || pSHead == nullptr) {
			return false;
		}

		if (!(pHead->pValue == pSHead->pValue)) {
			return false;
		}

		//�ݹ��ж�ǰ�������Գ�ǰ������Ľ��
		return isSymmetryCore(pHead->pLeft, pSHead->pRight) && isSymmetryCore(pHead->pRight, pSHead->pLeft);

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
		TreeNode* LeftHead = createNode(1);
		TreeNode* Node1 = createNode(1);
		TreeNode* Node2 = createNode(1);
		TreeNode* Node3 = createNode(1);

		setRelation(LeftHead, Node1, nullptr);
		setRelation(Node1, Node2, nullptr);
		setRelation(Node2, Node3, nullptr);

		if (!isSymmetry(LeftHead)) {
			cout << "test1 passed" << endl;
		}
		else {
			cout << "test1 failed" << endl;
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

		if (!isSymmetry(RightHead)) {
			cout << "test2 passed" << endl;
		}
		else {
			cout << "test2 failed" << endl;
		}
	}
	void test3() {

		//��һ�����Ķ�����
		TreeNode* OnlyHead = createNode(1);

		if (isSymmetry(OnlyHead)) {
			cout << "test3 passed" << endl;
		}
		else {
			cout << "test3 failed" << endl;
		}

	}

	void test4() {

		//��ͨ������
		TreeNode* NormalHead = createNode(5);
		TreeNode* Node1 = createNode(1);
		TreeNode* Node2 = createNode(1);
		TreeNode* Node3 = createNode(1);
		TreeNode* Node4 = createNode(1);
		TreeNode* Node5 = createNode(1);
		TreeNode* Node6 = createNode(1);

		setRelation(NormalHead, Node1, Node2);
		setRelation(Node1, Node3, Node4);
		setRelation(Node2, Node5, Node6);

		if (isSymmetry(NormalHead)) {
			cout << "test4 passed" << endl;
		}
		else {
			cout << "test4 failed" << endl;
		}
	}
}

using namespace T29;

//int main() {
//	test();
//}