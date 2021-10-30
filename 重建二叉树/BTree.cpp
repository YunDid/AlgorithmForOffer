#include<exception>
#include<iostream>
using namespace std;

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* constructBTreeCore(int*, int*, int*, int*);
BinaryTreeNode* constructBTree(int*,int*, int);
void print(BinaryTreeNode*);

//int main() {
//	int forword[] = { 1,2,4,7,3,5,6,8 };
//	int mid[] = { 4,7,2,1,5,3,8,6 };
//	BinaryTreeNode* head = constructBTree(forword, mid, 8);
//	print(head);
//}

BinaryTreeNode* constructBTree(int* forword,int* mid, int len) {
	return constructBTreeCore(forword, forword + len - 1, mid, mid + len - 1);
}

BinaryTreeNode* constructBTreeCore(int* stp, int*sep, int*itp, int*iep) {
	//����������������ҵ����ڵ�
	int rootValue = stp[0];
	//�������ڵ�
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	//���õݹ���ֹ�������ж��쳣
	if (stp == sep) {
		if (itp == iep && *stp == *itp) {
			return root;
		}
		else {
			throw std::exception();
		}
	}

	//������������
	int *Iroot = itp;
	while (Iroot != iep && *Iroot != rootValue) {
		Iroot++;
	}
	
	//�쳣����
	if (Iroot == iep && *Iroot != rootValue) {
		throw std::exception();
	}

	//ȷ������������Χ
	int leftlen = Iroot - itp;

	//����������
	if (leftlen > 0) {
		root->m_pLeft = constructBTreeCore(stp + 1, stp + leftlen, itp, Iroot - 1);
	}
	//���������� - �����������������蹹��
	if (leftlen < iep - itp) {
		root->m_pRight = constructBTreeCore(stp + leftlen + 1, sep, Iroot + 1, iep);
	}

	return root;

}

void print(BinaryTreeNode* head) {
	if (head != nullptr) {
		cout << head->m_nValue << " ";
		print(head->m_pLeft);
		print(head->m_pRight);
	}
}