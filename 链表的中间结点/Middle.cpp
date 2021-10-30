#include<iostream>
using namespace std;

struct ListNode
{
	int pValue;
	ListNode* pNext;
};

ListNode* Middle(ListNode*);
void test100();
ListNode* createNode2(int);
void setRelation2(ListNode*, ListNode*);


//int main() {
//	test100();
//}

ListNode* Middle(ListNode* pHead) {
	//判断异常
	if (pHead == nullptr) {
		return nullptr;
	}

	//设置遍历指针与定位指针
	ListNode* faster = pHead;
	ListNode* slower = pHead;

	while (faster->pNext != nullptr) {
		faster = faster->pNext;
		if (faster->pNext != nullptr) {
			faster = faster->pNext;
		}
		slower = slower->pNext;
	}

	return slower;

}

ListNode* createNode2(int value) {
	ListNode* Node = new ListNode();
	Node->pValue = value;
	Node->pNext = nullptr;

	return Node;
}

void setRelation2(ListNode* pLeft, ListNode* pRight) {
	if (pLeft != nullptr)
		pLeft->pNext = pRight;
	if (pRight != nullptr)
		pRight->pNext = nullptr;
}

void test100() {
	ListNode* Head = createNode2(1);
	/*ListNode* Node1 = createNode2(2);
	ListNode* Node2 = createNode2(3);
	ListNode* Node3 = createNode2(4);
	ListNode* Node4 = createNode2(5);
	ListNode* Node5 = createNode2(6);*/


	/*setRelation2(Head, Node1);
	setRelation2(Node1, Node2);
	setRelation2(Node2, Node3);
	setRelation2(Node3, Node4);
	setRelation2(Node4, Node5);*/

	ListNode* middle = Middle(Head);

	if (middle != nullptr) {
		if (middle->pValue == 1) {
			cout << "passed!";
		}
		else {
			cout << middle->pValue << endl << "failed!";
		}
	}
	else {
		cout << "异常!";
	}
}