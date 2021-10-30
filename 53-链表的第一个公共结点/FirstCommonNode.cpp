#include<iostream>
#include<stack>
using namespace std;

namespace T53 {

	struct ListNode
	{
		int pValue;
		ListNode* pNext;
	};

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	ListNode* createNode(int);
	void setRelation(ListNode*, ListNode*);

	ListNode* GetFirstCommonNodeByStack(ListNode*, ListNode*);
	ListNode* GetFirstCommonNode(ListNode*, ListNode*);

	int GetListLength(ListNode*);

	int GetListLength(ListNode* pHead) {

		ListNode* pNode = pHead;

		int len = 0;
		while (pNode != nullptr) {
			len++;
			pNode = pNode->pNext;
		}

		return len;
	}

	ListNode* GetFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		//异常判断
		if (pHead1 == nullptr || pHead2 == nullptr) {
			isExcption = true;
			return nullptr;
		}

		//设置两个指针分别指向较长的链表头和较短的链表头
		ListNode* pLongerHead = pHead1;
		ListNode* pShorterHead = pHead2;

		//取两个链表的长度，并获取两链表长度之差
		int pLen1 = GetListLength(pHead1);
		int pLen2 = GetListLength(pHead2);
		int pOffset = pLen1 - pLen2;

		//使两个指针分别指向较长的链表头和较短的链表头
		if (pLen2 > pLen1) {
			pLongerHead = pHead2;
			pShorterHead = pHead1;
			//使差值取正
			pOffset = -pOffset;
		}

		//先将指向长度较长链表的指针后移pOffset，使两个指针同步移动
		for (int i = 0; i < pOffset; i++) {
			pLongerHead = pLongerHead->pNext;
		}

		//向后遍历，直至找到第一个公共结点或至末尾
		while (pLongerHead != nullptr && pShorterHead != nullptr && pLongerHead->pValue != pShorterHead->pValue) {
			pLongerHead = pLongerHead->pNext;
			pShorterHead = pShorterHead->pNext;
		}

		ListNode* pCommonNode = pLongerHead;

		return pCommonNode;

	}

	ListNode* GetFirstCommonNodeByStack(ListNode* pHead1, ListNode* pHead2) {
		//异常判断
		if (pHead1 == nullptr || pHead2 == nullptr) {
			isExcption = true;
			return nullptr;
		}

		//设置两个辅助栈分别存放两个链表的结点
		stack<ListNode*> pStack1;
		stack<ListNode*> pStack2;

		//遍历两个链表并分别将结点压栈
		ListNode* pNode1 = pHead1;
		ListNode* pNode2 = pHead2;

		while (pNode1 != nullptr) {
			pStack1.push(pNode1);
			pNode1 = pNode1->pNext;
		}

		while (pNode2 != nullptr) {
			pStack2.push(pNode2);
			pNode2 = pNode2->pNext;
		}

		//根据栈中结点从尾结点开始向前比较是否存在 Y or V 型公共链表结点
		//设置指针存放公共结点的地址
		ListNode* pCommonNode = nullptr;

		while (pStack1.size() != 0 && pStack2.size() != 0) {

			if (pStack1.top()->pValue == pStack2.top()->pValue) {
				pCommonNode = pStack1.top();
			}
			else {
				break;
			}

			pStack1.pop();
			pStack2.pop();
		}

		return pCommonNode;

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

		test1();
		test2();
		test3();
		test4();

	}
	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		ListNode* pHead1 = createNode(1);
		ListNode* pHead2 = createNode(1);
		ListNode* pCommonNode = GetFirstCommonNode(pHead1, pHead2);

		if (!isExcption) {
			if (pCommonNode != nullptr) {
				if (pCommonNode->pValue == 1) {
					cout << "passed!" << endl;
				}
				else {
					cout << "failed!" << endl;
					cout << pCommonNode->pValue << endl;
				}
			}
			else {
				cout << "nullptr!" << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}
	}

	void test2() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test2:" << endl;

		ListNode* pHead1 = createNode(1);
		ListNode* pNode11 = createNode(2);
		ListNode* pNode12 = createNode(3);
		ListNode* pNode13 = createNode(4);
		ListNode* pNode14 = createNode(5);

		setRelation(pHead1, pNode11);
		setRelation(pNode11, pNode12);
		setRelation(pNode12, pNode13);
		setRelation(pNode13, pNode14);

		ListNode* pHead2 = createNode(3);
		ListNode* pNode21 = createNode(4);
		ListNode* pNode22 = createNode(3);
		ListNode* pNode23 = createNode(4);
		ListNode* pNode24 = createNode(5);

		setRelation(pHead2, pNode21);
		setRelation(pNode21, pNode22);
		setRelation(pNode22, pNode23);
		setRelation(pNode23, pNode24);

		ListNode* pCommonNode = GetFirstCommonNode(pHead1, pHead2);

		if (!isExcption) {
			if (pCommonNode != nullptr) {
				if (pCommonNode->pValue == 3) {
					cout << "passed!" << endl;
				}
				else {
					cout << "failed!" << endl;
					cout << pCommonNode->pValue << endl;
				}
			}
			else {
				cout << "nullptr!" << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}
	}
	void test3() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test3:" << endl;

		ListNode* pCommonNode = GetFirstCommonNode(nullptr, nullptr);

		if (!isExcption) {
			if (pCommonNode != nullptr) {
				if (pCommonNode->pValue == 1) {
					cout << "passed!" << endl;
				}
				else {
					cout << "failed!" << endl;
					cout << pCommonNode->pValue << endl;
				}
			}
			else {
				cout << "nullptr!" << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}
	}
	void test4() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test4:" << endl;

		ListNode* pHead1 = createNode(1);
		ListNode* pNode11 = createNode(2);
		ListNode* pNode12 = createNode(3);
		ListNode* pNode13 = createNode(4);
		ListNode* pNode14 = createNode(5);

		setRelation(pHead1, pNode11);
		setRelation(pNode11, pNode12);
		setRelation(pNode12, pNode13);
		setRelation(pNode13, pNode14);

		ListNode* pHead2 = createNode(6);
		ListNode* pNode21 = createNode(7);
		ListNode* pNode22 = createNode(8);
		ListNode* pNode23 = createNode(9);
		ListNode* pNode24 = createNode(10);

		setRelation(pHead2, pNode21);
		setRelation(pNode21, pNode22);
		setRelation(pNode22, pNode23);
		setRelation(pNode23, pNode24);

		ListNode* pCommonNode = GetFirstCommonNode(pHead1, pHead2);

		if (!isExcption) {
			if (pCommonNode == nullptr) {
				cout << "passed!" << endl;
			}
			else {
				cout << "failed!" << endl;
			}
		}
		else {
			cout << "异常!" << endl;
		}
	}

}


using namespace T53;

//int main() {
//	test();
//}