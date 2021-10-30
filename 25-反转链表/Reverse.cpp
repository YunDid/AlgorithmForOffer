#include<iostream>
using namespace std;

namespace T25 {

	struct ListNode
	{
		int pValue;
		ListNode* pNext;
	};

	//函数原型声明
	void test();
	ListNode* createNode(int);
	void setRelation(ListNode*, ListNode*);

	ListNode* Reverse(ListNode*);
	ListNode* RReverse(ListNode*);
	ListNode* RReverseCore(ListNode*);

	ListNode* Reverse(ListNode* pHead) {

		
		//设置状态保存变量
		ListNode* pPre = nullptr;
		ListNode* pNode = pHead;

		//遍历链表并设置每一个结点的pNext为前一个结点
		while (pNode != nullptr) {
			//保存下一个结点，防止链表断裂后无法遍历
			ListNode* ppNext = pNode->pNext;

			//设置当前结点的pNext为前一个结点
			pNode->pNext = pPre;

			//更新状态保存变量值对应于下一个结点
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
		
		//记录分治后的尾元结点即当前结点的下一个结点
		ListNode* LastTail = pNowHead->pNext;
		//递归返回分治后新的首结点
		ListNode* NewHead = RReverseCore(pNowHead->pNext);
		//将当前结点与已"反转"的后半部分的尾元结点连接
		LastTail->pNext = pNowHead;
		//当前结点成为新的尾元结点
		pNowHead->pNext = nullptr;

		return NewHead;
	}

	ListNode* RReverse(ListNode* pHead) {
		//异常判断
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
			cout << "异常!";
		}
	}

}

using namespace T25;

//int main() {
//	test();
//}