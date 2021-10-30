#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int m_nKey;
	ListNode* m_pNext;
};

void reprint(ListNode*);
void rreprint(ListNode* head);

//int main() {
//
//	ListNode* head;
//	head = new ListNode();
//	head->m_pNext = nullptr;
//
//	ListNode* p = head;
//	//Õ∑≤ø≤Â»Î
//	for (int i = 0; i < 3; i++) {
//		ListNode* pNode = new ListNode();
//		pNode->m_nKey = i;
//		pNode->m_pNext = nullptr;
//		
//		p->m_pNext = pNode;
//		p = pNode;
//	}
//
//	/*ListNode* q = head->m_pNext;
//	while (q != nullptr) {
//		cout << q->m_nKey << " ";
//		q = q->m_pNext;
//	}*/
//
//	/*reprint(head);
//	reprint(nullptr);*/
//
//	rreprint(head);
//	rreprint(nullptr);
//}

//’ª
void reprint(ListNode* head) {

	if (head == nullptr) {
		return;
	}

	ListNode* q = head->m_pNext;
	stack<int> st;
	while (q != nullptr) {	
		st.push(q->m_nKey);
		q = q->m_pNext;
	}

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}

//µ›πÈ
void rreprint(ListNode* head) {

	if (head == nullptr) {
		return;
	}

	if (head->m_pNext != nullptr) {
		reprint(head->m_pNext);
	}
	cout << head->m_nKey << " ";
}
