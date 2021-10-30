#include<iostream>
#include<string>
using namespace std;

struct BinaryTreeNode {

	BinaryTreeNode* m_pParent;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pLeft;

	string m_pValue;

};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr) {
		return nullptr;
	}

	BinaryTreeNode* pNext = nullptr;

	if (pNode->m_pRight != nullptr) {
		
		BinaryTreeNode* pCurrent = pNode->m_pRight;
		while (pCurrent->m_pLeft != nullptr) {
			pCurrent = pCurrent->m_pLeft;
		}
		pNext = pCurrent;
	}
	else if (pNode->m_pParent != nullptr) {
		
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;

		while (pParent->m_pParent != nullptr && pCurrent == pParent->m_pRight) {
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}

		if (pCurrent == pParent->m_pLeft) {
			pNext = pParent;
		}
	}

	return pNext;

}

// ==================== Code for Binary Trees ====================

//��������Ӻ��������ظ��ӽڵ�
BinaryTreeNode* createNode(string value) {
	BinaryTreeNode* node = new BinaryTreeNode();

	node->m_pValue = value;
	node->m_pLeft = nullptr;
	node->m_pParent = nullptr;
	node->m_pRight = nullptr;

	return node;
}

//��ָ���Ľ�㽨�����������ӹ�ϵ
void connectNode(BinaryTreeNode* Parent, BinaryTreeNode* Left, BinaryTreeNode* Right) {
	if (Parent != nullptr) {
		Parent->m_pLeft = Left;
		Parent->m_pRight = Right;
	}

	if (Left != nullptr) {
		Left->m_pParent = Parent;
	}

	if (Right != nullptr) {
		Right->m_pParent = Parent;
	}
}

void DestoryNode(BinaryTreeNode* Root) {
	if (Root != nullptr) {
		
		BinaryTreeNode* left = Root->m_pLeft;
		BinaryTreeNode* right = Root->m_pRight;
		
		if (left != nullptr) {
			DestoryNode(left);
		}

		if (right != nullptr) {
			DestoryNode(right);
		}

		delete Root;
		Root = nullptr;

	}
}

//��Ԫ����
//����ͨ��ֱ�ӹ۲���������
//����ͨ�����ò����������ж��Ƿ�ͨ��
void Test(BinaryTreeNode* pNode, BinaryTreeNode* ispNext) {
	BinaryTreeNode* pNext = GetNext(pNode);
	if (pNext == ispNext) {
		cout << "passed" << endl;
	}
	else {
		cout << "failed" << endl;
	}
}

void Test1() {

	//���Ĵ���
	//ֱ�Ӵ�����㲢�����ϵ��������

	BinaryTreeNode* a = createNode("a");
	BinaryTreeNode* b = createNode("b");
	BinaryTreeNode* c = createNode("c");
	BinaryTreeNode* d = createNode("d");
	BinaryTreeNode* e = createNode("e");
	BinaryTreeNode* f = createNode("f");
	BinaryTreeNode* g = createNode("g");
	BinaryTreeNode* h = createNode("h");
	BinaryTreeNode* i = createNode("i");

	connectNode(a,b,c);
	connectNode(b,d,e);
	connectNode(e,h,i);
	connectNode(c,f,g);
	
	Test(i,a);
	Test(d,b);
	Test(g,nullptr);
	Test(a,f);

	//�ڴ�й©����
	DestoryNode(a);
}

//int main() {
//	Test1();
//}