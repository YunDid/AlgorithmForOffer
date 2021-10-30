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
	//�ж��쳣
	if (PHead == nullptr || *PHead== nullptr) {
		/*doFalse = true;*/
		return;
	}

	//Ϊ��֤��������Ҫÿ�μ�¼��ǰδ��ɾ��������һ�����
	LinkNode* preNode = nullptr;
	LinkNode* pNode = *PHead;
	//����������Ѱ�ظ����
	while (pNode != nullptr) {
		//���ý���Ƿ���Ҫɾ���ı�־
		bool deleteY = false;
		//����ָ��ǰ�����һ����ָ��
		LinkNode* ppNext = pNode->pNext;

		//�жϵ�ǰ����Ƿ���Ҫɾ��
		if (ppNext != nullptr && ppNext->pValue == pNode->pValue) {
			deleteY = true;
		}

		//����Ҫɾ����������±���
		if (!deleteY) {
			preNode = pNode;
			pNode = pNode->pNext;
		}
		else {
			
			//��¼��ǰ��Ҫɾ���Ľ��
			LinkNode* DeleteNeed = pNode;
			//��¼�ظ���Ԫ��ֵ
			int value = DeleteNeed->pValue;
			//����ǰ�����Ҫɾ��������ѭ���жϵ�ǰ������һ���Ƿ���Ҫɾ�����жϽ������ٽ���ɾ��
			ppNext = DeleteNeed->pNext;
			//ɾ����ǰ���
			delete DeleteNeed;
			DeleteNeed = nullptr;

			while (ppNext != nullptr&&ppNext->pValue == value) {
				
				//���õ�ǰ���Ϊ��Ҫɾ���Ľ��
				DeleteNeed = ppNext;
				//�����ж���һ����Ƿ���Ҫɾ��
				ppNext = ppNext->pNext;		
				//ɾ����һ�����
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