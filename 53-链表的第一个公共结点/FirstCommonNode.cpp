#include<iostream>
#include<stack>
using namespace std;

namespace T53 {

	struct ListNode
	{
		int pValue;
		ListNode* pNext;
	};

	//����ԭ������
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
		//�쳣�ж�
		if (pHead1 == nullptr || pHead2 == nullptr) {
			isExcption = true;
			return nullptr;
		}

		//��������ָ��ֱ�ָ��ϳ�������ͷ�ͽ϶̵�����ͷ
		ListNode* pLongerHead = pHead1;
		ListNode* pShorterHead = pHead2;

		//ȡ��������ĳ��ȣ�����ȡ��������֮��
		int pLen1 = GetListLength(pHead1);
		int pLen2 = GetListLength(pHead2);
		int pOffset = pLen1 - pLen2;

		//ʹ����ָ��ֱ�ָ��ϳ�������ͷ�ͽ϶̵�����ͷ
		if (pLen2 > pLen1) {
			pLongerHead = pHead2;
			pShorterHead = pHead1;
			//ʹ��ֵȡ��
			pOffset = -pOffset;
		}

		//�Ƚ�ָ�򳤶Ƚϳ������ָ�����pOffset��ʹ����ָ��ͬ���ƶ�
		for (int i = 0; i < pOffset; i++) {
			pLongerHead = pLongerHead->pNext;
		}

		//��������ֱ���ҵ���һ������������ĩβ
		while (pLongerHead != nullptr && pShorterHead != nullptr && pLongerHead->pValue != pShorterHead->pValue) {
			pLongerHead = pLongerHead->pNext;
			pShorterHead = pShorterHead->pNext;
		}

		ListNode* pCommonNode = pLongerHead;

		return pCommonNode;

	}

	ListNode* GetFirstCommonNodeByStack(ListNode* pHead1, ListNode* pHead2) {
		//�쳣�ж�
		if (pHead1 == nullptr || pHead2 == nullptr) {
			isExcption = true;
			return nullptr;
		}

		//������������ջ�ֱ�����������Ľ��
		stack<ListNode*> pStack1;
		stack<ListNode*> pStack2;

		//�������������ֱ𽫽��ѹջ
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

		//����ջ�н���β��㿪ʼ��ǰ�Ƚ��Ƿ���� Y or V �͹���������
		//����ָ���Ź������ĵ�ַ
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
			cout << "�쳣!" << endl;
		}
	}

	void test2() {
		//����Ի������踴ԭ
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
			cout << "�쳣!" << endl;
		}
	}
	void test3() {
		//����Ի������踴ԭ
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
			cout << "�쳣!" << endl;
		}
	}
	void test4() {
		//����Ի������踴ԭ
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
			cout << "�쳣!" << endl;
		}
	}

}


using namespace T53;

//int main() {
//	test();
//}