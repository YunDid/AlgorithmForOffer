#include<iostream>
#include<deque>
using namespace std;

namespace T37 {

	struct TreeNode
	{
		int pValue;
		TreeNode* pLeft;
		TreeNode* pRight;
	};

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	TreeNode* createNode(int);
	void setRelation(TreeNode*, TreeNode*, TreeNode*);
	TreeNode* Convert(TreeNode*);
	void ConvertCore(TreeNode*, TreeNode**);
	void printTree(TreeNode*);

	void printTree(TreeNode* pHead) {
		if (pHead == nullptr) {
			return;
		}	

		if (pHead->pLeft != nullptr)
			printTree(pHead->pLeft);

		cout << pHead->pValue << " ";

		if (pHead->pRight != nullptr)
			printTree(pHead->pRight);
		
	}

	TreeNode* Convert(TreeNode* pHead) {
		
		//�쳣�ж�
		if (pHead == nullptr) {
			return nullptr;
		}

		//���ü�¼��ǰ˫������β����ָ��
		TreeNode* PointToListTail = nullptr;
		//��β����ָ��һ��������еݹ�
		ConvertCore(pHead, &PointToListTail);

		while (PointToListTail != nullptr && PointToListTail->pLeft != nullptr) {
			PointToListTail = PointToListTail->pLeft;
		}

		return PointToListTail;
	}

	void ConvertCore(TreeNode* pHead, TreeNode** PointToListTail) {
		
		//���ñ���ָ��
		TreeNode* pCurrentNode = pHead;
		
		//basecase
		if (pHead == nullptr) {
			return;
		}

		//�������
		if (pCurrentNode->pLeft != nullptr) {
			ConvertCore(pCurrentNode->pLeft, PointToListTail);
		}

		//���õ�ǰ���ڵ�Ϊ˫���������β��
		pCurrentNode->pLeft = *PointToListTail;

		if (*PointToListTail != nullptr) {
			(*PointToListTail)->pRight = pCurrentNode;
		}

		*PointToListTail = pCurrentNode;

		//����˫������������������
		if (pCurrentNode->pRight != nullptr) {
			ConvertCore(pCurrentNode->pRight, PointToListTail);
		}

	}

	TreeNode* createNode(int value) {
		TreeNode* Node = new TreeNode();
		Node->pValue = value;
		Node->pLeft = nullptr;
		Node->pRight = nullptr;

		return Node;
	}

	void setRelation(TreeNode* pHead, TreeNode* ppLeft, TreeNode* ppRight) {
		if (pHead != nullptr) {
			pHead->pLeft = ppLeft;
			pHead->pRight = ppRight;
		}
		if (ppLeft != nullptr) {
			ppLeft->pLeft = nullptr;
			ppLeft->pRight = nullptr;
		}
		if (ppRight != nullptr) {
			ppRight->pLeft = nullptr;
			ppRight->pRight = nullptr;
		}
	}

	void test() {

		/*test1();
		test2();
		test3();*/
		test4();

	}
	void test1() {

		//�����������Ķ�����
		TreeNode* LeftHead = createNode(1);
		TreeNode* Node1 = createNode(2);
		TreeNode* Node2 = createNode(3);
		TreeNode* Node3 = createNode(4);

		setRelation(LeftHead, Node1, nullptr);
		setRelation(Node1, Node2, nullptr);
		setRelation(Node2, Node3, nullptr);

		
	}
	void test2() {

		//�����������Ķ�����
		TreeNode* RightHead = createNode(1);
		TreeNode* Node1 = createNode(3);
		TreeNode* Node2 = createNode(5);
		TreeNode* Node3 = createNode(7);

		setRelation(RightHead, nullptr, Node1);
		setRelation(Node1, nullptr, Node2);
		setRelation(Node2, nullptr, Node3);

		
	}
	void test3() {

		//��һ�����Ķ�����
		TreeNode* OnlyHead = createNode(1);

		

	}

	void test4() {

		//��ͨ������
		TreeNode* NormalHead = createNode(4);
		TreeNode* Node1 = createNode(2);
		TreeNode* Node2 = createNode(6);
		TreeNode* Node3 = createNode(1);
		TreeNode* Node4 = createNode(3);
		TreeNode* Node5 = createNode(5);
		TreeNode* Node6 = createNode(7);
		/*TreeNode* Node7 = createNode(8);
		TreeNode* Node8 = createNode(9);
		TreeNode* Node9 = createNode(10);
		TreeNode* Node10 = createNode(11);*/

		setRelation(NormalHead, Node1, Node2);
		setRelation(Node1, Node3, Node4);
		setRelation(Node2, Node5, Node6);
		/*setRelation(Node3, Node7, Node8);
		setRelation(Node4, Node9, Node10);*/

		TreeNode* pHead = Convert(NormalHead);
		TreeNode* pNode = pHead;

		while (pNode != nullptr) {
			cout << pNode->pValue << endl;
			if (pNode->pLeft != nullptr)
				cout << "pLeft: " << pNode->pLeft->pValue << endl;
			else 
				cout << "pLeft: nullptr" << endl;
			if (pNode->pRight != nullptr)
				cout << "pRight: " << pNode->pRight->pValue << endl;
			else 
				cout << "pRight: nullptr"<< endl;
			pNode = pNode->pRight;
		}
	}
}

using namespace T37;

//int main() {
//	test();
//}