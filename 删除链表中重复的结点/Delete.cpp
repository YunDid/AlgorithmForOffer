#include<iostream>
using namespace std;

struct LinkNode {
	LinkNode* pNext;
	int pValue;
};

void deleteNode2(LinkNode**);
void test12();
void SetNextNode2(LinkNode*, LinkNode*);
LinkNode* CreateNode2(int);
void PrintNode2(LinkNode*);

//int main() {
//	test12();
//}

//bool doFalse = false;

void deleteNode2(LinkNode** PHead) {
	//判断异常
	if (PHead == nullptr || *PHead== nullptr) {
		/*doFalse = true;*/
		return;
	}

	//为保证连续性需要每次记录当前未被删除结点的上一个结点
	LinkNode* preNode = nullptr;
	LinkNode* pNode = *PHead;
	//遍历链表找寻重复结点
	while (pNode != nullptr) {
		//设置结点是否需要删除的标志
		bool deleteY = false;
		//设置指向当前结点下一结点的指针
		LinkNode* ppNext = pNode->pNext;

		//判断当前结点是否需要删除
		if (ppNext != nullptr && ppNext->pValue == pNode->pValue) {
			deleteY = true;
		}

		//若不要删除则继续向下遍历
		if (!deleteY) {
			preNode = pNode;
			pNode = pNode->pNext;
		}
		else {
			
			//记录当前需要删除的结点
			LinkNode* DeleteNeed = pNode;
			//记录重复的元素值
			int value = DeleteNeed->pValue;
			//若当前结点需要删除，继续循环判断当前结点的下一个是否需要删除，判断结束后再进行删除
			ppNext = DeleteNeed->pNext;
			//删除当前结点
			delete DeleteNeed;
			DeleteNeed = nullptr;

			while (ppNext != nullptr&&ppNext->pValue == value) {
				
				//设置当前结点为需要删除的结点
				DeleteNeed = ppNext;
				//继续判断下一结点是否需要删除
				ppNext = ppNext->pNext;		
				//删除上一个结点
				delete DeleteNeed;
				DeleteNeed = nullptr;
				
			}

			if (preNode == nullptr) {
				*PHead = ppNext;
			}
			else {
				preNode->pNext = ppNext;
			}

			pNode = ppNext;

		}
	}
}

void test12() {
	LinkNode* Head = CreateNode2(2);	
	LinkNode* Node1 = CreateNode2(2);
	LinkNode* Node2 = CreateNode2(3);
	LinkNode* Node3 = CreateNode2(4);
	LinkNode* Node4 = CreateNode2(6);
	LinkNode* Node5 = CreateNode2(6);

	SetNextNode2(Head, Node1);
	SetNextNode2(Node1, Node2);
	SetNextNode2(Node2, Node3);
	SetNextNode2(Node3, Node4);
	SetNextNode2(Node4, Node5);

	deleteNode2(&Head);

	PrintNode2(Head);
}

void SetNextNode2(LinkNode* Pre, LinkNode* Next) {
	Pre->pNext = Next;
	Next->pNext = nullptr;
}

LinkNode* CreateNode2(int value) {

	LinkNode* node = new LinkNode();
	node->pValue = value;
	node->pNext = nullptr;
	return node;
}

void PrintNode2(LinkNode* PHead) {
	while (PHead != nullptr) {
		cout << PHead->pValue << " ";
		PHead = PHead->pNext;
	}
}