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

	//����ԭ������
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
		//�쳣�ж�
		if (pHead == nullptr) {
			return nullptr;
		}

		//���ƽ�㲢������Ӧ��ϵ����Map
		map<LinkNode*, LinkNode*> NodeMap;

		//������ʱ����ָ��,���������ͷ�ĸ���
		LinkNode* pNode = pHead;
		LinkNode* pCopyHead = new LinkNode();

		pCopyHead->pValue = pNode->pValue;
		pCopyHead->pNext = nullptr;
		pCopyHead->pSibling = nullptr;

		//map���ԭ����븴�ƽ���ӳ��
		NodeMap[pNode] = pCopyHead;

		//���±���
		LinkNode* pCNode = pCopyHead;
		pNode = pNode->pNext;
		
		//����ԭ������ɽ��ĸ�����ӳ��Ĵ��
		while (pNode != nullptr) {

			//��㸴��
			LinkNode* pCTemp = new LinkNode();
			pCTemp->pValue = pNode->pValue;
			pCTemp->pNext = nullptr;
			pCTemp->pSibling = nullptr;

			//map���ԭ����븴�ƽ���ӳ��
			NodeMap[pNode] = pCTemp;

			//�������������
			pCNode->pNext = pCTemp;

			//���±���
			pCNode = pCNode->pNext;
			pNode = pNode->pNext;

		}

		//���ñ���ָ���������ͷ
		pNode = pHead;
		pCNode = pCopyHead;

		//����ԭ������ɸ��������pSibilingָ��
		while (pNode != nullptr) {
			if (pNode->pSibling != nullptr) {
				pCNode->pSibling = NodeMap[pNode->pSibling];
			}

			//���±���
			pNode = pNode->pNext;
			pCNode = pCNode->pNext;
		}

		return pCopyHead;
	}

	void CopyNode(LinkNode* pHead) {
		
		//������ʱָ��
		LinkNode* pNode = pHead;
		//����������ɽ�㴴��������
		while (pNode != nullptr) {
			LinkNode* pCopyNode = new LinkNode();
			pCopyNode->pSibling = nullptr;
			//���ƽ��
			pCopyNode->pValue = pNode->pValue;
			//���ӽ��
			pCopyNode->pNext = pNode->pNext;
			pNode->pNext = pCopyNode;

			//���±���
			pNode = pCopyNode->pNext;
		}
	}

	void ConnectSibiling(LinkNode* pHead) {

		//������ʱָ��
		LinkNode* pNode = pHead;
		//�����������sibilingָ��ĸ���
		while (pNode != nullptr) {
			//����ָ��ǰ����Ӧ�ĸ��ƽ���ָ��
			LinkNode* pCopyNode = pNode->pNext;

			//���ø��ƽ���sibilingָ��
			if (pNode->pSibling)
				pCopyNode->pSibling = pNode->pSibling->pNext;

			//���±���
			pNode = pCopyNode->pNext;
		}
	}

	LinkNode* ConnectNext(LinkNode* pHead) {
		
		//������ʱ����ָ��
		LinkNode* pNode = pHead;
		LinkNode* pCNode = nullptr;
		//�������մ�Ÿ�������ͷ��ָ��
		LinkNode* pCopyHead = nullptr;
		

		//����ȷ������ͷ
		pCopyHead = pNode->pNext;
		//��ԭԭ����
		pNode->pNext = pCopyHead->pNext;
		//��ʼ�������������ָ��
		pCNode = pCopyHead;
		//���±���
		pNode = pNode->pNext;

		//��ʱpNodeλ��pCNode֮��һ�����

		while (pNode != nullptr) {
			//�����ƺ�Ľ���ָ����£�ʹ��ָ����һ�����ƺ�Ľ��
			pCNode->pNext = pNode->pNext;
			//���±���
			pCNode = pCNode->pNext;
			//������ǰ�Ľ���ָ����£�ʹ��ָ����һ������ǰ�Ľ��
			pNode->pNext = pCNode->pNext;
			//���±���
			pNode = pNode->pNext;
		}

		return pCopyHead;
	}

	LinkNode* CopyFromComplexList(LinkNode* pHead) {

		//�쳣�ж�
		if (pHead == nullptr) {
			return nullptr;
		}
		
		//��������ɸ�������ĸ���

		//��һ�� ����ÿ����㲢��ԭ��������
		CopyNode(pHead);
		//�ڶ��� ��ԭ�����sibilingָ���Ƶ�������
		ConnectSibiling(pHead);
		//������ �������������������pNextָ��
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

		//��һ����������
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

		//��ͨ����
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