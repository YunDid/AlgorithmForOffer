#include<iostream>
#include<deque>
using namespace std;

namespace T38 {

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

	void Serializaion(TreeNode*);
	void ReSerializaionCore(TreeNode**, char**);
	bool isNumber(char);

	//用于异常判断的全局变量
	bool hasException = false;

	bool isNumber(char c) {
		if (c == '$') {
			return false;
		}
		else if (c >= '0' && c <= '9') {
			return true;
		}
		else {
			hasException = true;
			return false;
		}
	}

	void ReSerializaionCore(TreeNode** pRoot, char** ser) {

		if (isNumber(**ser)) {
			*pRoot = new TreeNode();
			(*pRoot)->pValue = **ser - '0';
			(*pRoot)->pLeft = nullptr;
			(*pRoot)->pRight = nullptr;

			//序列指针后移
			(*ser)++;

			ReSerializaionCore(&((*pRoot)->pLeft), ser);
			ReSerializaionCore(&((*pRoot)->pRight), ser);

		}
		else {
			if (hasException)
				return;
			//序列指针后移
			(*ser)++;
		}
		
	}

	void Serializaion(TreeNode* pHead) {

		//异常判断
		if (pHead == nullptr) {
			cout << "$,";
			return;
		}

		//先序遍历
		cout << pHead->pValue << ",";
		Serializaion(pHead->pLeft);
		Serializaion(pHead->pRight);

	}

	void printTree(TreeNode* pHead) {
		if (pHead == nullptr) {
			return;
		}

		cout << pHead->pValue << " ";
		
		if (pHead->pLeft != nullptr)
			printTree(pHead->pLeft);	

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


	}
	void test3() {

		//仅一个结点的二叉树
		TreeNode* OnlyHead = createNode(1);

		cout << "二叉树序列化的结果:" << endl;
		Serializaion(OnlyHead);
		cout << endl;

		cout << "根据序列化结果构建的二叉树为:" << endl;
		if (hasException) {
			cout << "异常" << endl;
			return;
		}
		TreeNode* pHead = nullptr;
		char a[] = "1$$";
		char ** c = new char*;
		*c = a;

		ReSerializaionCore(&pHead, c);

		printTree(pHead);

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
		/*TreeNode* Node7 = createNode(8);
		TreeNode* Node8 = createNode(9);
		TreeNode* Node9 = createNode(10);
		TreeNode* Node10 = createNode(11);*/

		setRelation(NormalHead, Node1, Node2);
		setRelation(Node1, Node3, Node4);
		setRelation(Node2, Node5, Node6);
		/*setRelation(Node3, Node7, Node8);
		setRelation(Node4, Node9, Node10);*/

		cout << "二叉树序列化的结果:" << endl;
		Serializaion(NormalHead);
		cout << endl;

		cout << "根据序列化结果构建的二叉树为:" << endl;
		if (hasException) {
			cout << "异常" << endl;
			return;
		}
		TreeNode* pHead = nullptr;
		char a[] = "111$$1$$11$$1$$";
		char ** c = new char*;
		*c = a;

		ReSerializaionCore(&pHead, c);

		printTree(pHead);

		
	}
}

using namespace T38;

//int main() {
//	test();
//}