#include<iostream>
using namespace std;

namespace T24 {

	struct ListNode
	{
		int pValue;
		ListNode* pNext;
	};

	//函数原型声明
	void test24();
	ListNode* createNode(int);
	void setRelation(ListNode*, ListNode*);
	ListNode* getMeetNode(ListNode*);
	ListNode* getEntryPoint(ListNode*);
	
	ListNode* getMeetNode(ListNode* pHead) {
		
		//异常判断
		if (pHead == nullptr) {
			return nullptr;
		}

		//若仅有一个结点则无环，无相遇结点可言
		if (pHead->pNext == nullptr) {
			return nullptr;
		}

		//设置快慢指针
		ListNode* faster = pHead;
		ListNode* slower = pHead;

		while (faster != nullptr) {
			faster = faster->pNext;
			if (faster != nullptr) {
				faster = faster->pNext;
			}

			slower = slower->pNext;

			if (faster == slower) {
				return faster;
			}
		}

		//若无环，返回nullptr
		return nullptr;
	}

	ListNode* getEntryPoint(ListNode* pHead) {
		ListNode* pMeetNode = getMeetNode(pHead);
		if (pMeetNode == nullptr) {
			return nullptr;
		}

		//若存在环，则计算环中结点个数
		int num = 1;
		ListNode* p = pMeetNode;

		while (p->pNext != pMeetNode) {
			p = p->pNext;
			num++;
		}


		//设置范围指针对，并设置初始位置
		ListNode* pRight = pHead;
		ListNode* pLeft= pHead;
	
		for (int i = 0; i < num; i++) {
			pRight = pRight->pNext;
		}

		//移动范围指针对找寻入口点
		while (pRight != pLeft) {
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

	void test24() {
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

		ListNode* EntryPoint = getEntryPoint(Head);

		if (EntryPoint != nullptr) {
			if (EntryPoint == Node4) {
				cout << "passed!";
			}
			else {
				cout << "failed!";
			}
		}
		else {
			cout << "异常!";
		}
	}

}

using namespace T24;

//int main() {
//	test24();
//}

