#include<iostream>
#include<deque>
using namespace std;

namespace T56 {

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
	void test5();

	bool isDepthException = false;
	bool isBalancedException = false;

	TreeNode* createNode(int);
	void setRelation(TreeNode*, TreeNode*, TreeNode*);
	void printTree(TreeNode*);

	//ǰ���������������
	int TreeDepthByPre(TreeNode*);
	void TreeDepthByPreCore(TreeNode*, int, int&);

	//�����������������
	int TreeDepthByPost(TreeNode*);
	int TreeDepthByPostCore(TreeNode*);

	//ƽ������� ǰ�����
	bool isBalancedTreeByPre(TreeNode*);
	bool isBalancedTreeByPreCore(TreeNode*);

	//ƽ������� �������
	bool isBalancedTreeByPost(TreeNode*);
	bool isBalancedTreeByPostCore(TreeNode*, int&);

	bool isBalancedTreeByPost(TreeNode* pHead) {
		//�ж��쳣
		if (pHead == nullptr) {
			isBalancedException = true;
			return false;
		}

		int Depth;
		return isBalancedTreeByPostCore(pHead, Depth);

	}

	bool isBalancedTreeByPostCore(TreeNode* pHead, int& Depth) {
		//base case
		if (pHead == nullptr) {
			return true;
			Depth = 0;
		}

		//���ü�¼����������ȵ��������
		int Left;
		int Right;

		if (isBalancedTreeByPostCore(pHead->pLeft, Left) && isBalancedTreeByPostCore(pHead->pRight, Right)) {
			int diff = Left - Right;
			if (diff >= -1 && diff <= 1) {

				//��¼��ǰ��������������������
				Depth = 1 + (Left > Right ? Left : Right);
				return true;			
			}
		}

		//����ǰ���ƽ�����Ӳ�����Ҫ���������¼��ȣ�ֱ�ӷ���false����
		return false;

	}

	bool isBalancedTreeByPre(TreeNode* pHead) {
		//�ж��쳣
		if (pHead == nullptr) {
			isBalancedException = true;
			return false;
		}

		return isBalancedTreeByPreCore(pHead);
	}

	bool isBalancedTreeByPreCore(TreeNode* pHead) {
		//base case
		if (pHead == nullptr) {
			return true;
		}

		//��ȡ��ǰ���������������
		int left = TreeDepthByPost(pHead->pLeft);
		int Right = TreeDepthByPost(pHead->pRight);

		//�жϵ�ǰ����ƽ�������Ƿ�����Ҫ��
		int diff = left - Right;
		if (diff < -1 || diff > 1) {
			return false;
		}

		//����ǰ���ƽ����������Ҫ��������ж������������и�����Ƿ�����Ҫ��
		return isBalancedTreeByPreCore(pHead->pLeft) && isBalancedTreeByPreCore(pHead->pRight);
	}

	int TreeDepthByPost(TreeNode* pHead) {
		//�쳣�ж�
		if (pHead == nullptr) {
			isDepthException = true;
			return 0;
		}

		return TreeDepthByPostCore(pHead);
	}
	int TreeDepthByPostCore(TreeNode* pHead) {
		//base case
		if (pHead == nullptr) {
			return 1;
		}

		int Left = TreeDepthByPostCore(pHead->pLeft);
		int Right = TreeDepthByPostCore(pHead->pRight);

		return (Left > Right) ? Left + 1 : Right + 1;

		/*if (pHead->pLeft == nullptr && pHead->pRight == nullptr) {
			return 1;
		}
		
		int Left = 0;
		if (pHead->pLeft != nullptr) {
			Left = TreeDepthByPostCore(pHead->pLeft);
		}
		int Right = 0;
		if (pHead->pRight != nullptr) {
			Right = TreeDepthByPostCore(pHead->pRight);
		}

		return (Left > Right) ? Left + 1 : Right + 1;*/
	}


	int TreeDepthByPre(TreeNode* pHead) {
		//�쳣�ж�
		if (pHead == nullptr) {
			isDepthException = true;
			return 0;
		}

		//��¼��ȵı���
		int Depth = 0;
		//��¼�����ȵı���
		int MaxDepth = 0;

		TreeDepthByPreCore(pHead, Depth, MaxDepth);
		
		return MaxDepth;
	}

	void TreeDepthByPreCore(TreeNode* pHead, int Depth, int& MaxDepth) {
		//�������
		Depth++;
		
		//����Ҷ�ӽ��
		if (pHead->pLeft == nullptr && pHead->pRight == nullptr) {
			if (Depth >= MaxDepth) {
				MaxDepth = Depth;
			}
			return;
		}

		if (pHead->pLeft != nullptr) {
			TreeDepthByPreCore(pHead->pLeft, Depth, MaxDepth);
		}

		if (pHead->pRight != nullptr) {
			TreeDepthByPreCore(pHead->pRight, Depth, MaxDepth);
		}

	}


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

		test1();
		test2();
		test3();
		test4();
		test5();

	}
	void test1() {

		isDepthException = false;
		isBalancedException = false;

		cout << "Test1:" << endl;
		//�����������Ķ�����
		TreeNode* LeftHead = createNode(4);
		TreeNode* Node1 = createNode(3);
		TreeNode* Node2 = createNode(2);
		TreeNode* Node3 = createNode(1);

		setRelation(LeftHead, Node1, nullptr);
		setRelation(Node1, Node2, nullptr);
		setRelation(Node2, Node3, nullptr);

		//int Depth = TreeDepthByPost(LeftHead);
		bool isBalanced = isBalancedTreeByPost(LeftHead);

		if (!isBalancedException) {
			if (isBalanced == false) {
				cout << "Passed!" << endl;
			}
			else {
				cout << "Failed!" << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}
	}
	void test2() {

		isDepthException = false;
		isBalancedException = false;

		cout << "Test2:" << endl;
		//�����������Ķ�����
		TreeNode* RightHead = createNode(1);
		TreeNode* Node1 = createNode(3);
		TreeNode* Node2 = createNode(5);
		TreeNode* Node3 = createNode(7);

		setRelation(RightHead, nullptr, Node1);
		setRelation(Node1, nullptr, Node2);
		setRelation(Node2, nullptr, Node3);

		//int Depth = TreeDepthByPost(RightHead);
		bool isBalanced = isBalancedTreeByPost(RightHead);

		if (!isBalancedException) {
			if (isBalanced == false) {
				cout << "Passed!" << endl;
			}
			else {
				cout << "Failed!" << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}
	}
	void test3() {

		isDepthException = false;
		isBalancedException = false;

		cout << "Test3:" << endl;

		//��һ�����Ķ�����
		TreeNode* OnlyHead = createNode(1);

		//int Depth = TreeDepthByPost(OnlyHead);
		bool isBalanced = isBalancedTreeByPost(OnlyHead);

		if (!isBalancedException) {
			if (isBalanced == true) {
				cout << "Passed!" << endl;
			}
			else {
				cout << "Failed!" << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}

	}

	void test4() {

		isDepthException = false;
		isBalancedException = false;

		cout << "Test4:" << endl;

		//��ͨ������
		TreeNode* NormalHead = createNode(5);
		TreeNode* Node1 = createNode(3);
		TreeNode* Node2 = createNode(7);
		TreeNode* Node3 = createNode(2);
		TreeNode* Node4 = createNode(4);
		TreeNode* Node5 = createNode(6);
		TreeNode* Node6 = createNode(8);


		setRelation(NormalHead, Node1, Node2);
		setRelation(Node1, Node3, Node4);
		setRelation(Node2, Node5, Node6);

		//int Depth = TreeDepthByPost(NormalHead);
		bool isBalanced = isBalancedTreeByPost(NormalHead);

		if (!isBalancedException) {
			if (isBalanced == true) {
				cout << "Passed!" << endl;
			}
			else {
				cout << "Failed!" << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}

	}

	void test5() {

		isDepthException = false;
		isBalancedException = false;

		cout << "Test5:" << endl;

		//nullptr

		//int Depth = TreeDepthByPost(nullptr);
		bool isBalanced = isBalancedTreeByPost(nullptr);

		if (!isBalancedException) {
			if (true) {
				cout << "Passed!" << endl;
			}
			else {
				cout << "Failed!" << endl;
			}
		}
		else {
			cout << "�쳣!" << endl;
		}

	}

}

using namespace T56;

//int main() {
//	test();
//}