#include<iostream>
using namespace std;

namespace T27 {

	struct TreeNode
	{
		double pValue;
		TreeNode* pLeft;
		TreeNode* pRight;
	};

	//����ԭ������
	void test();
	TreeNode* createNode(int);
	void setRelation(TreeNode*, TreeNode*, TreeNode*);
	
	bool hasSubTree(TreeNode*, TreeNode*);
	bool hasSubTreeCore(TreeNode*, TreeNode*);
	bool Equal(double, double);

	bool hasSubTree(TreeNode* pHead, TreeNode* pSHead) {
		//�ж��쳣
		if (pHead == nullptr || pSHead == nullptr) {
			return false;
		}
		//���÷���ֵ
		bool result = false;

		//�ж��Ƿ��Ƿ�����sub�������ͬ�Ľ��
		if (Equal(pHead->pValue, pSHead->pValue)) {
			//���������ͬ������ж��Ƿ���sub����
			result = hasSubTreeCore(pHead, pSHead);
		}

		//���ø������sub��������㲻ͬ����ø�����µ�������sub�����ṹ��ͬ�������±���
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
		//�жϵ�ǰ����Ƿ���ͬ
		if (!Equal(pHead->pValue, pSHead->pValue)) {
			return false;
		}
		//�ݹ��ж����������Ƿ�ṹ��ͬ
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
		//����1
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

		//����2
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