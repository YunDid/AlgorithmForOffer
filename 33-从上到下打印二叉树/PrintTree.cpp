#include<iostream>
#include<deque>
using namespace std;

namespace T33 {

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
	void printTree(TreeNode*);
	void lprintTree(TreeNode*);
	void SprintTree(TreeNode*);


	void SprintTree(TreeNode* pHead) {
		//�쳣�ж�
		if (pHead == nullptr) {
			return;
		}

		//������������ջ
		deque<TreeNode*> deque1;
		deque<TreeNode*> deque2;

		//���Ƚ����ڵ�ѹ��ջ1
		deque1.push_back(pHead);

		//����
		while (deque1.size() != 0 || deque1.size() != 0) {

			//ȡ��������ջ1�е�Ԫ��
			while (deque1.size() != 0) {
				TreeNode* pTemp = deque1.back();
				deque1.pop_back();

				//���Ԫ��
				cout << pTemp->pValue << " ";

				//��ȡ���Ľ�㺬��������������������ѹ��ջ2
				if (pTemp->pLeft) {
					deque2.push_back(pTemp->pLeft);
				}
				if (pTemp->pRight) {
					deque2.push_back(pTemp->pRight);
				}

			}

			cout << endl;

			//ȡ��������ջ2�е�Ԫ��
			while (deque2.size() != 0) {
				TreeNode* pTemp2 = deque2.back();
				deque2.pop_back();

				//���Ԫ��
				cout << pTemp2->pValue << " ";

				//��ȡ���Ľ�㺬��������������������ѹ��ջ1
				if (pTemp2->pRight) {
					deque1.push_back(pTemp2->pRight);
				}

				if (pTemp2->pLeft) {
					deque1.push_back(pTemp2->pLeft);
				}
				
			}

			cout << endl;

		}
	}

	void lprintTree(TreeNode* pHead) {
		//�쳣�ж�
		if (pHead == nullptr) {
			return;
		}

		//���ø�������
		deque<TreeNode*> deque;

		//���Ƚ����ڵ�ѹ�����
		deque.push_back(pHead);

		//����״̬��¼����
		//��¼��һ��Ľڵ����
		int NextLayer = 0;
		//��¼������δ����Ľڵ����
		int toBePrinted = 1;

		//����
		while (deque.size() != 0) {

			//ȡ����ǰ�����е�ͷԪ��
			TreeNode* pTemp = deque.front();
			deque.pop_front();

			//���Ԫ��
			cout << pTemp->pValue << " ";
			toBePrinted--;

			//��ȡ���Ľ�㺬����������������ѹ�����
			if (pTemp->pLeft) {
				deque.push_back(pTemp->pLeft);
				NextLayer++;
			}
			if (pTemp->pRight) {
				deque.push_back(pTemp->pRight);
				NextLayer++;
			}

			if (toBePrinted == 0) {
				//�����Ԫ�������ϣ����У�������һ��Ԫ�ص����
				cout << endl;
				//����toBePrintedΪ��һ��Ӧ����Ľڵ���
				toBePrinted = NextLayer;
				//����NextLayer����¼��һ�����һ��ڵ���
				NextLayer = 0;
			}

		}
	}

	void printTree(TreeNode* pHead) {
		//�쳣�ж�
		if (pHead == nullptr) {
			return;
		}

		//���ø�������
		deque<TreeNode*> deque;

		//���Ƚ����ڵ�ѹ�����
		deque.push_back(pHead);

		//����
		while (deque.size() != 0) {

			//ȡ����ǰ�����е�ͷԪ��
			TreeNode* pTemp = deque.front();
			deque.pop_front();

			//���Ԫ��
			cout << pTemp->pValue << " ";

			//��ȡ���Ľ�㺬����������������ѹ�����
			if (pTemp->pLeft)
				deque.push_back(pTemp->pLeft);
			if (pTemp->pRight)
				deque.push_back(pTemp->pRight);

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

		lprintTree(LeftHead);
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

		lprintTree(RightHead);
	}
	void test3() {

		//��һ�����Ķ�����
		TreeNode* OnlyHead = createNode(1);

		lprintTree(OnlyHead);

	}

	void test4() {

		//��ͨ������
		TreeNode* NormalHead = createNode(1);
		TreeNode* Node1 = createNode(2);
		TreeNode* Node2 = createNode(3);
		TreeNode* Node3 = createNode(4);
		TreeNode* Node4 = createNode(5);
		TreeNode* Node5 = createNode(6);
		TreeNode* Node6 = createNode(7);
		TreeNode* Node7 = createNode(8);
		TreeNode* Node8 = createNode(9);
		TreeNode* Node9 = createNode(10);
		TreeNode* Node10 = createNode(11);

		setRelation(NormalHead, Node1, Node2);
		setRelation(Node1, Node3, Node4);
		setRelation(Node2, Node5, Node6);
		setRelation(Node3, Node7, Node8);
		setRelation(Node4, Node9, Node10);

		SprintTree(NormalHead);
	}
}

using namespace T33;

//int main() {
//	test();
//}