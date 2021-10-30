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

	//函数原型声明
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
		//异常判断
		if (pHead == nullptr) {
			return;
		}

		//设置两个辅助栈
		deque<TreeNode*> deque1;
		deque<TreeNode*> deque2;

		//首先将根节点压入栈1
		deque1.push_back(pHead);

		//遍历
		while (deque1.size() != 0 || deque1.size() != 0) {

			//取出并遍历栈1中的元素
			while (deque1.size() != 0) {
				TreeNode* pTemp = deque1.back();
				deque1.pop_back();

				//输出元素
				cout << pTemp->pValue << " ";

				//若取出的结点含左右子树，则自左向右压入栈2
				if (pTemp->pLeft) {
					deque2.push_back(pTemp->pLeft);
				}
				if (pTemp->pRight) {
					deque2.push_back(pTemp->pRight);
				}

			}

			cout << endl;

			//取出并遍历栈2中的元素
			while (deque2.size() != 0) {
				TreeNode* pTemp2 = deque2.back();
				deque2.pop_back();

				//输出元素
				cout << pTemp2->pValue << " ";

				//若取出的结点含左右子树，则自右向左压入栈1
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
		//异常判断
		if (pHead == nullptr) {
			return;
		}

		//设置辅助队列
		deque<TreeNode*> deque;

		//首先将根节点压入队列
		deque.push_back(pHead);

		//设置状态记录变量
		//记录下一层的节点个数
		int NextLayer = 0;
		//记录本层仍未输出的节点个数
		int toBePrinted = 1;

		//遍历
		while (deque.size() != 0) {

			//取出当前队列中的头元素
			TreeNode* pTemp = deque.front();
			deque.pop_front();

			//输出元素
			cout << pTemp->pValue << " ";
			toBePrinted--;

			//若取出的结点含左右子树，则重新压入队列
			if (pTemp->pLeft) {
				deque.push_back(pTemp->pLeft);
				NextLayer++;
			}
			if (pTemp->pRight) {
				deque.push_back(pTemp->pRight);
				NextLayer++;
			}

			if (toBePrinted == 0) {
				//本层的元素输出完毕，换行，进行下一行元素的输出
				cout << endl;
				//更新toBePrinted为下一层应输出的节点数
				toBePrinted = NextLayer;
				//重置NextLayer，记录下一层的下一层节点数
				NextLayer = 0;
			}

		}
	}

	void printTree(TreeNode* pHead) {
		//异常判断
		if (pHead == nullptr) {
			return;
		}

		//设置辅助队列
		deque<TreeNode*> deque;

		//首先将根节点压入队列
		deque.push_back(pHead);

		//遍历
		while (deque.size() != 0) {

			//取出当前队列中的头元素
			TreeNode* pTemp = deque.front();
			deque.pop_front();

			//输出元素
			cout << pTemp->pValue << " ";

			//若取出的结点含左右子树，则重新压入队列
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

		//仅有左子树的二叉树
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

		//仅有右子树的二叉树
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

		//仅一个结点的二叉树
		TreeNode* OnlyHead = createNode(1);

		lprintTree(OnlyHead);

	}

	void test4() {

		//普通二叉树
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