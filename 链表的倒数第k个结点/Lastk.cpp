#include<iostream>
using namespace std;

struct ListNode
{
	int pValue;
	ListNode* pNext;
};

ListNode* LastK(ListNode*, unsigned int);
void test23();
ListNode* createNode(int);
void setRelation(ListNode*, ListNode*);


//int main() {
//	test23();
//}

ListNode* LastK(ListNode* pHead, unsigned int k) {
	//�쳣�ж�
	if (pHead == nullptr || k <= 0) {
		return nullptr;
	}

	//���÷�Χָ���
	ListNode* pRight = pHead;
	//���÷�Χָ��Ե�����ʼ�߽�
	ListNode* pLeft = pHead;

	//���÷�Χָ��Ե�����ʼ�߽�
	for (int i = 0; i < k - 1; i++) {
		if (pRight->pNext == nullptr) {
			return nullptr;
		}
		pRight = pRight->pNext;
	}

	//�ƶ���Χָ��ԣ�ֱ���ұ߽�ָ����β���
	while (pRight->pNext != nullptr) {
		pRight = pRight->pNext;
		pLeft = pLeft->pNext;
	}

	return pLeft;
}

ListNode* createNode(int value) {
	ListNode* Node = new ListNode();
	Node->pValue = value;
	Node->pNext = nullptr;

	return Node;
}

void setRelation(ListNode* pLeft, ListNode* pRight) {
	if (pLeft != nullptr)
		pLeft->pNext = pRight;
	if (pRight != nullptr)
		pRight->pNext = nullptr;
}

void test23() {
	ListNode* Head = createNode(1);
	ListNode* Node1 = createNode(2);
	ListNode* Node2 = createNode(3);
	ListNode* Node3 = createNode(4);
	ListNode* Node4 = createNode(5);
	ListNode* Node5 = createNode(6);

	setRelation(Head, Node1);
	setRelation(Node1, Node2);
	setRelation(Node2, Node3);
	setRelation(Node3, Node4);
	setRelation(Node4, Node5);

	ListNode* Last = LastK(Head, 7);
	
	if (Last != nullptr) {
		if (Last->pValue == 1) {
			cout << "passed!";
		}
		else {
			cout << Last->pValue << endl << "failed!";
		}
	}
	else {
		cout << "�쳣!";
	}
}