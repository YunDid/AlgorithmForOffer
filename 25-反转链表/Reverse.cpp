#include<iostream>
using namespace std;

namespace T25 {

	struct ListNode
	{
		int pValue;
		ListNode* pNext;
	};

	//����ԭ������
	void test();
	ListNode* createNode(int);
	void setRelation(ListNode*, ListNode*);

	ListNode* Reverse(ListNode*);
	ListNode* RReverse(ListNode*);
	ListNode* RReverseCore(ListNode*);

	ListNode* Reverse(ListNode* pHead) {

		
		//����״̬�������
		ListNode* pPre = nullptr;
		ListNode* pNode = pHead;

		//������������ÿһ������pNextΪǰһ�����
		while (pNode != nullptr) {
			//������һ����㣬��ֹ������Ѻ��޷�����
			ListNode* ppNext = pNode->pNext;

			//���õ�ǰ����pNextΪǰһ�����
			pNode->pNext = pPre;

			//����״̬�������ֵ��Ӧ����һ�����
			pPre = pNode;
			pNode = ppNext;
		}

		return pPre;
	}

	ListNode* RReverseCore(ListNode* pNowHead) {
		//basecase
		if (pNowHead->pNext == nullptr) {
			return pNowHead;
		}
		
		//��¼���κ��βԪ��㼴��ǰ������һ�����
		ListNode* LastTail = pNowHead->pNext;
		//�ݹ鷵�ط��κ��µ��׽��
		ListNode* NewHead = RReverseCore(pNowHead->pNext);
		//����ǰ�������"��ת"�ĺ�벿�ֵ�βԪ�������
		LastTail->pNext = pNowHead;
		//��ǰ����Ϊ�µ�βԪ���
		pNowHead->pNext = nullptr;

		return NewHead;
	}

	ListNode* RReverse(ListNode* pHead) {
		//�쳣�ж�
		if (pHead == nullptr) {
			return nullptr;
		}
		return RReverseCore(pHead);		
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

	void test() {
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
		/*Node5->pNext = Node4;*/

		ListNode* RHead = RReverse(Head);

		if (RHead != nullptr) {
			if (RHead->pValue == 6) {
				cout << "passed!";
			}
			else {
				cout << RHead->pValue << endl;
				cout << "failed!";
			}
		}
		else {
			cout << "�쳣!";
		}
	}

}

using namespace T25;

//int main() {
//	test();
//}