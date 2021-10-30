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

//创建结点子函数并返回该子节点
BinaryTreeNode* createNode(string value) {
	BinaryTreeNode* node = new BinaryTreeNode();

	node->m_pValue = value;
	node->m_pLeft = nullptr;
	node->m_pParent = nullptr;
	node->m_pRight = nullptr;

	return node;
}

//对指定的结点建立父子兄连接关系
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

//单元测试
//并非通过直接观察结果来测试
//而是通过设置测试条件来判断是否通过
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

	//树的创建
	//直接创建结点并赋予关系来构建树

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

	//内存泄漏问题
	DestoryNode(a);
}

//int main() {
//	Test1();
//}