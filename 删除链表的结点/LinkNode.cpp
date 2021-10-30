#include<iostream>
using namespace std;

struct LinkNode {
	LinkNode* pNext;
	int pValue;
};

void deleteNode(LinkNode**,LinkNode*);
void test11();
void SetNextNode(LinkNode*, LinkNode*);
LinkNode* CreateNode(int);
void PrintNode(LinkNode*);

//int main() {
//	test11();
//}

bool doFalse = false;

void deleteNode(LinkNode** pHead, LinkNode* dNode) {
	//�ж��쳣
	if (pHead == nullptr || dNode == nullptr) {
		doFalse = true;
		return;
	}

	if (dNode == *pHead) {
		//ɾ���Ľ��Ϊͷ���
		delete dNode;
		dNode = nullptr;
		*pHead = nullptr;
	}
	else if (dNode->pNext != nullptr) {
		//ɾ���Ľ��Ϊ��β���֮��Ľ��
		LinkNode* ppNext = dNode->pNext;
		dNode->pValue = ppNext->pValue;
		dNode->pNext = ppNext->pNext;

		delete ppNext;
		ppNext = nullptr;
	}else {
		//ɾ���Ľ��ΪβԪ���
		LinkNode* pPre = (*pHead)->pNext;
		//��������ɾ������ǰһ�����
		while (pPre->pNext != dNode) {
			pPre = pPre->pNext;
		}

		pPre->pNext = nullptr;
		delete dNode;
		dNode = nullptr;
	}
}

void test11() {
	LinkNode* Head = CreateNode(0);
	LinkNode* Node1 = CreateNode(1);
	LinkNode* Node2 = CreateNode(2);
	LinkNode* Node3 = CreateNode(3);
	LinkNode* Node4 = CreateNode(4);
	LinkNode* Node5 = CreateNode(5);

	SetNextNode(Head, Node1);
	SetNextNode(Node1, Node2);
	SetNextNode(Node2, Node3);
	SetNextNode(Node3, Node4);
	SetNextNode(Node4, Node5);

	deleteNode(&Head, Head);

	PrintNode(Head);
}

void SetNextNode(LinkNode* Pre, LinkNode* Next) {
	Pre->pNext = Next;
	Next->pNext = nullptr;
}

LinkNode* CreateNode(int value) {
	
	LinkNode* node = new LinkNode();
	node->pValue = value;
	node->pNext = nullptr;
	return node;
}

void PrintNode(LinkNode* pHead) {
	while (pHead != nullptr) {
		cout << pHead->pValue << " ";
		pHead = pHead->pNext;
	}
}