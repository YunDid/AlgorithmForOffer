#include<iostream>
using namespace std;

namespace T26 {

	struct ListNode
	{
		int pValue;
		ListNode* pNext;
	};

	//函数原型声明
	void test();
	ListNode* createNode(int);
	void setRelation(ListNode*, ListNode*);
	ListNode* Merge(ListNode*, ListNode*);

	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		//basecase
		if (pHead1 == nullptr) {
			return pHead2;
		}
		else if (pHead2 == nullptr) {
			return pHead1;
		}

		//设置合并后的首结点
		ListNode* MergedHead = nullptr;

		if (pHead1->pValue <= pHead2->pValue) {
			MergedHead = pHead1;
			MergedHead->pNext = Merge(pHead1->pNext, pHead2);
		}
		else {
			MergedHead = pHead2;
			MergedHead->pNext = Merge(pHead1, pHead2->pNext);
		}

		return MergedHead;
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
		//链表1
		ListNode* Head1 = createNode(1);
		ListNode* Node1 = createNode(3);
		ListNode* Node2 = createNode(5);
		ListNode* Node3 = createNode(7);
		ListNode* Node4 = createNode(9);
		ListNode* Node5 = createNode(11);

		setRelation(Head1, Node1);
		setRelation(Node1, Node2);
		setRelation(Node2, Node3);
		setRelation(Node3, Node4);
		setRelation(Node4, Node5);
		/*Node5->pNext = Node4;*/

		//链表2
		ListNode* Head2 = createNode(2);
		ListNode* Node6 = createNode(4);
		ListNode* Node7 = createNode(6);
		ListNode* Node8 = createNode(8);
		ListNode* Node9 = createNode(10);
		ListNode* Node10 = createNode(12);

		setRelation(Head2, Node6);
		setRelation(Node6, Node7);
		setRelation(Node7, Node8);
		setRelation(Node8, Node9);
		setRelation(Node9, Node10);

		ListNode* MergedHead = Merge(Head1, Head2);

		if (MergedHead != nullptr) {
			while (MergedHead != nullptr) {
				cout << MergedHead->pValue << " ";
				MergedHead = MergedHead->pNext;
			}
		}
		else {
			cout << "异常!";
		}
	}

}

using namespace T26;

//int main() {
//	test();
//}