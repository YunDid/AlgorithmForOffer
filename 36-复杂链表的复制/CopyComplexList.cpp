#include<iostream>
#include<deque>
#include<vector>
#include<map>
using namespace std;

namespace T36 {

	struct LinkNode
	{
		int pValue;
		LinkNode* pSibling;
		LinkNode* pNext;
	};

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	LinkNode* createNode(int);
	void setRelation(LinkNode*, LinkNode*, LinkNode*);

	LinkNode* CopyFromComplexList(LinkNode*);
	void CopyNode(LinkNode*);
	void ConnectSibiling(LinkNode*);
	LinkNode* ConnectNext(LinkNode*);
	LinkNode* CopyFromComplexListByMap(LinkNode*);

	LinkNode* CopyFromComplexListByMap(LinkNode* pHead) {
		//异常判断
		if (pHead == nullptr) {
			return nullptr;
		}

		//复制结点并将结点对应关系存入Map
		map<LinkNode*, LinkNode*> NodeMap;

		//设置临时遍历指针,并完成链表头的复制
		LinkNode* pNode = pHead;
		LinkNode* pCopyHead = new LinkNode();

		pCopyHead->pValue = pNode->pValue;
		pCopyHead->pNext = nullptr;
		pCopyHead->pSibling = nullptr;

		//map存放原结点与复制结点的映射
		NodeMap[pNode] = pCopyHead;

		//向下遍历
		LinkNode* pCNode = pCopyHead;
		pNode = pNode->pNext;
		
		//遍历原链表完成结点的复制与映射的存放
		while (pNode != nullptr) {

			//结点复制
			LinkNode* pCTemp = new LinkNode();
			pCTemp->pValue = pNode->pValue;
			pCTemp->pNext = nullptr;
			pCTemp->pSibling = nullptr;

			//map存放原结点与复制结点的映射
			NodeMap[pNode] = pCTemp;

			//复制链表的链接
			pCNode->pNext = pCTemp;

			//向下遍历
			pCNode = pCNode->pNext;
			pNode = pNode->pNext;

		}

		//重置遍历指针于链表表头
		pNode = pHead;
		pCNode = pCopyHead;

		//遍历原链表完成复制链表的pSibiling指向
		while (pNode != nullptr) {
			if (pNode->pSibling != nullptr) {
				pCNode->pSibling = NodeMap[pNode->pSibling];
			}

			//向下遍历
			pNode = pNode->pNext;
			pCNode = pCNode->pNext;
		}

		return pCopyHead;
	}

	void CopyNode(LinkNode* pHead) {
		
		//创建临时指针
		LinkNode* pNode = pHead;
		//遍历链表并完成结点创建与链接
		while (pNode != nullptr) {
			LinkNode* pCopyNode = new LinkNode();
			pCopyNode->pSibling = nullptr;
			//复制结点
			pCopyNode->pValue = pNode->pValue;
			//链接结点
			pCopyNode->pNext = pNode->pNext;
			pNode->pNext = pCopyNode;

			//向下遍历
			pNode = pCopyNode->pNext;
		}
	}

	void ConnectSibiling(LinkNode* pHead) {

		//创建临时指针
		LinkNode* pNode = pHead;
		//遍历链表并完成sibiling指向的复制
		while (pNode != nullptr) {
			//创建指向当前结点对应的复制结点的指针
			LinkNode* pCopyNode = pNode->pNext;

			//设置复制结点的sibiling指向
			if (pNode->pSibling)
				pCopyNode->pSibling = pNode->pSibling->pNext;

			//向下遍历
			pNode = pCopyNode->pNext;
		}
	}

	LinkNode* ConnectNext(LinkNode* pHead) {
		
		//创建临时遍历指针
		LinkNode* pNode = pHead;
		LinkNode* pCNode = nullptr;
		//创建最终存放复制链表头的指针
		LinkNode* pCopyHead = nullptr;
		

		//首先确定链表头
		pCopyHead = pNode->pNext;
		//还原原链表
		pNode->pNext = pCopyHead->pNext;
		//初始化复制链表遍历指针
		pCNode = pCopyHead;
		//向下遍历
		pNode = pNode->pNext;

		//此时pNode位于pCNode之后一个结点

		while (pNode != nullptr) {
			//将复制后的结点的指向更新，使其指向下一个复制后的结点
			pCNode->pNext = pNode->pNext;
			//向下遍历
			pCNode = pCNode->pNext;
			//将复制前的结点的指向更新，使其指向下一个复制前的结点
			pNode->pNext = pCNode->pNext;
			//向下遍历
			pNode = pNode->pNext;
		}

		return pCopyHead;
	}

	LinkNode* CopyFromComplexList(LinkNode* pHead) {

		//异常判断
		if (pHead == nullptr) {
			return nullptr;
		}
		
		//分三步完成复杂链表的复制

		//第一步 复制每个结点并与原链表链接
		CopyNode(pHead);
		//第二步 将原链表的sibiling指向复制到新链表
		ConnectSibiling(pHead);
		//第三步 拆解链表，并完成新链表的pNext指向
		return ConnectNext(pHead);
	}

	LinkNode* createNode(int value) {
		LinkNode* Node = new LinkNode();
		Node->pValue = value;
		Node->pSibling = nullptr;
		Node->pNext = nullptr;

		return Node;
	}

	void setRelation(LinkNode* pHead, LinkNode* ppSibling, LinkNode* ppNext) {
		if (pHead != nullptr) {
			pHead->pSibling = ppSibling;
			pHead->pNext = ppNext;
		}
		/*if (ppSibling != nullptr) {
			ppSibling->pSibling = nullptr;
			ppSibling->pNext = nullptr;
		}
		if (ppNext != nullptr) {
			ppNext->pSibling = nullptr;
			ppNext->pNext = nullptr;
		}*/
	}

	void test() {

		/*test1();
		test2();*/
		test3();
		test4();

	}
	void test1() {

		
	}
	void test2() {

		
	}
	void test3() {

		//仅一个结点的链表
		LinkNode* OnlyHead = createNode(1);

		LinkNode* CopyHead = CopyFromComplexListByMap(OnlyHead);

		LinkNode* temp = CopyHead;
		while (temp != nullptr) {
			cout << temp->pValue << endl;

			if (temp->pSibling != nullptr)
				cout << "sibling : " << temp->pSibling->pValue << endl;
			else
				cout << "sibling : nullptr" << endl;

			temp = temp->pNext;
		}
	}

	void test4() {

		//普通链表
		LinkNode* NormalHead = createNode(1);
		LinkNode* Node1 = createNode(2);
		LinkNode* Node2 = createNode(3);
		LinkNode* Node3 = createNode(4);
		LinkNode* Node4 = createNode(5);
		LinkNode* Node5 = createNode(6);

		setRelation(NormalHead, Node1, Node1);
		setRelation(Node1, NormalHead, Node2);
		setRelation(Node2, Node5, Node3);
		setRelation(Node3, nullptr, Node4);
		setRelation(Node4, nullptr, Node5);

		LinkNode* CopyHead = CopyFromComplexListByMap(NormalHead);
		
		LinkNode* temp = CopyHead;
		while (temp != nullptr) {
			cout << temp->pValue << endl;

			if (temp->pSibling != nullptr)
				cout << "sibling : " << temp->pSibling->pValue << endl;
			else
				cout << "sibling : nullptr" << endl;

			temp = temp->pNext;
		}

	}
}

using namespace T36;

//int main() {
//	test();
//}