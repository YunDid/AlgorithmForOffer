#include<iostream>
#include<deque>
#include<vector>
using namespace std;

namespace T35 {

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
	
	void FindPathInTree(TreeNode*, int);
	void FindPathInTree(TreeNode*, int, vector<int>&, int);

	void FindPathInTree(TreeNode* pHead, int ExpectedNum) {
		//�ж��쳣
		if (pHead == nullptr) {
			return;
		}

		//���ô洢·�����������¼�͵ı���
		vector<int> path;
		int currentSum = 0;

		//ת��·������
		FindPathInTree(pHead, ExpectedNum, path, currentSum);
	}

	void FindPathInTree(TreeNode* pHead, int ExpectedNum, vector<int>& path, int currentSum) {
		
		//�������
		
		//����ǰ����ֵѹ��·�����飬��¼��ǰ·��
		path.push_back(pHead->pValue);

		//�ۼӺͣ���¼��ǰ·����
		currentSum += pHead->pValue;

		//�жϵ�ǰ·�����Ƿ�Ϊ����ֵ��Ϊһ������·��(�ý��ΪҶ�ӽ��)
		if (pHead->pLeft == nullptr && pHead->pRight == nullptr && ExpectedNum == currentSum) {
			//�ҵ�һ��·���������·��
			cout << "Path1 : ";
			for (auto i : path) {
				cout << i << " ";
			}
		}

		//����������ж������������Ƿ����·��
		if (pHead->pLeft != nullptr)
			FindPathInTree(pHead->pLeft, ExpectedNum, path, currentSum);

		if (pHead->pRight != nullptr)
			FindPathInTree(pHead->pRight, ExpectedNum, path, currentSum);

		//ֱ����Ѱ��Ҷ�ӽ���Ҳ�����·���ͲŻ���
		path.pop_back();
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

		/*lprintTree(LeftHead);*/
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

		//lprintTree(RightHead);
	}
	void test3() {

		//��һ�����Ķ�����
		TreeNode* OnlyHead = createNode(1);

		//lprintTree(OnlyHead);

	}

	void test4() {

		//��ͨ������
		TreeNode* NormalHead = createNode(10);
		TreeNode* Node1 = createNode(5);
		TreeNode* Node2 = createNode(12);
		TreeNode* Node3 = createNode(4);
		TreeNode* Node4 = createNode(7);
		TreeNode* Node5 = createNode(9);
		//TreeNode* Node6 = createNode(7);
		//TreeNode* Node7 = createNode(8);
		//TreeNode* Node8 = createNode(9);
		//TreeNode* Node9 = createNode(10);
		//TreeNode* Node10 = createNode(11);

		setRelation(NormalHead, Node1, Node2);
		setRelation(Node1, Node3, Node4);
		setRelation(Node2, Node5, nullptr);
		//setRelation(Node3, Node7, Node8);
		//setRelation(Node4, Node9, Node10);

		FindPathInTree(NormalHead, 22);
	}
}

using namespace T35;

//int main() {
//	test();
//}