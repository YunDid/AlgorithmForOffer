#include<iostream>
#include<vector>
using namespace std;

void combine(vector<int>&,const vector<int>&);

//int main() {
//	vector<int> v1 = { 1,3,5,7,9 };
//	vector<int> v2 = { 2,4,6,8,10};
//	combine(v1, v2);
//	for (auto e : v1) {
//		cout << e << " ";
//	}
//	return 0;
//}

void combine(vector<int>& v1,const vector<int>&v2) {
	if (v1.size() == 0 && v2.size() == 0) {
		return;
	}
	
	//vector���ݺ�Ϊ����������һ��������С�ڴ棬ע���ȡ��������ʱ��
	v1.resize(v1.size() + v2.size());

	//��λ������ָ��
	auto p1 = v1.end() - 1 - v2.size();
	auto p2 = v2.end() - 1;
	auto q = p1 + v2.size();

	//�ϲ�����
	while (q != v1.begin() && p1 >= v1.begin() && p2 >= v2.begin()) {
		if (*p1 >= *p2) {			
			*q = *p1;
			q--;
			if (p1 == v1.begin()) {
				break;
			}
			p1--;
		}
		else {	
			*q = *p2;
			q--;
			if (p2 == v2.begin()) {
				break;
			}
			p2--;
		}
	}

	//��ʣ��δ�ϲ�Ԫ������ϲ�
	if (p1 == v1.begin() && p2 != v2.begin()) {

		auto re = v2.begin();
		while (re <= p2) {
			*p1 = *re;
			re++;
			p1++;
		}

	}

}