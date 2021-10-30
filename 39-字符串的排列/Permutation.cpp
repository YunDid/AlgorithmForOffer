#include<iostream>
#include<vector>
using namespace std;

namespace T39 {

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	void Permutation(char*);
	void PermutationCore(char*, char*);

	void Permutation(vector<char>&);
	void PermutationCore(vector<char>&, vector<char>&);

	int Num = 0;
	bool SameCheck(int*, int);
	void EightQueen(int*, int);
	void EightQueenCore(int*, int*, int);
	
	bool SameCheck(int* str, int len) {

		//�ж��Ƿ����ͬ�У�ͬ�У�ͬ�Խ��ߵ�Ԫ��
		//˫��ѭ��ʱi��j��Ȼ������ͬ����������ж���Ԫ���Ƿ���ͬһ���Խ�����
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (i - j == str[i] - str[j] || j - i == str[i] - str[j]) {
					return false;
				}
			}
		}

		return true;
	}

	void EightQueen(int* arr,int QueenNum) {
		//�쳣�ж�
		if (arr == nullptr) {
			return;
		}
		EightQueenCore(arr, arr, QueenNum);
	}

	void EightQueenCore(int* pAllStart, int* pCurrntStart, int len) {
		//base case
		//lenΪ����ȫ���е�������Ŀ����len����0ʱ�������ѽ�len���ȵ���������������ȫ����
		if (len == 0) {
			 
			if (SameCheck(pAllStart, pCurrntStart - pAllStart))
			{
				Num++;
				int* pStart = pAllStart;
				cout << Num << endl;
				for (; pStart < pCurrntStart; pStart++) {
					cout << *pStart << " ";
				}
				cout << endl;
			}
		}

		//�����ַ�����ÿ��Ԫ�� -- ��֤�������п��ܵ�ˮƽ����
		int i = 0;
		for (int* pCur = pCurrntStart; i < len; pCur++, i++) {

			//���߽��Ϊ pCurԪ��λ��pCurrntStartλ�� --ˮƽ����

			int pTemp = *pCur;
			*pCur = *pCurrntStart;
			*pCurrntStart = pTemp;

			//pCurrntStartλ��֮��λ�õݹ���о��� --��ֱ����
			EightQueenCore(pAllStart, pCurrntStart + 1, len - 1);

			//��ԭ�ַ���  --ˮƽ���߸�ԭ
			pTemp = *pCur;
			*pCur = *pCurrntStart;
			*pCurrntStart = pTemp;

		}

	}

	void PermutationCore(vector<char>& ori, vector<char>& pmt) {
		//base case
		if (ori.empty()) {
			//�����ǰ��ȫ���н��
			for (auto i : pmt) {
				cout << i << " ";
			}

			cout << endl;
		}

		//�����ַ�����ÿ��Ԫ�� -- ��֤�������п��ܵ�ˮƽ����
		for (int i = 0; i < ori.size(); i++) {

			//����ǰ���߽�������pmt������ȥ --ˮƽ����
			pmt.push_back(ori[i]);

			//Ϊ��ȷ����ʣ��Ԫ���������´δ�ֱ���ߣ���Ҫ����ǰԪ����ʱ��������Ϊ��Ҫ�ָ���������ݴ�
			char temp = ori[i];
			ori.erase(ori.begin() + i);

			//���Ѿ��ߵ���һ��λ������Ԫ�ؾ��� --��ֱ����
			PermutationCore(ori, pmt);

			//��ԭ  --ˮƽ���߸�ԭ
			ori.insert(ori.begin() + i, temp);
			pmt.pop_back();

		}
	}

	void Permutation(vector<char>& Ori) {
		//�쳣�ж�
		if (Ori.empty()) {
			return;
		}

		vector<char> pmt;
		PermutationCore(Ori, pmt);
	}

	void Permutation(char* arr) {
		//�쳣�ж�
		if (arr == nullptr) {
			return;
		}
		PermutationCore(arr, arr);
	}

	void PermutationCore(char* pAllStart, char* pCurrntStart) {
		//base case
		if (*pCurrntStart == '\0') {
			cout << pAllStart << endl;
		}

		//�����ַ�����ÿ��Ԫ�� -- ��֤�������п��ܵ�ˮƽ����
		for (char* pCur = pCurrntStart; *pCur != '\0'; pCur++) {

			//���߽��Ϊ pCurԪ��λ��pCurrntStartλ�� --ˮƽ����

			char pTemp = *pCur;
			*pCur = *pCurrntStart;
			*pCurrntStart = pTemp;

			//pCurrntStartλ��֮��λ�õݹ���о��� --��ֱ����
			PermutationCore(pAllStart, pCurrntStart + 1);

			//��ԭ�ַ���  --ˮƽ���߸�ԭ
			pTemp = *pCur;
			*pCur = *pCurrntStart;
			*pCurrntStart = pTemp;

		}

	}

	void test() {

		test1();
		/*test2();
		test3();
		test4();*/

	}
	void test1() {

		int a[8] = { 0,1,2,3,4,5,6,7 };
		EightQueen(a, 8);

	}
	void test2() {




	}
	void test3() {

		vector<char> a;
		a.push_back('a');
		a.push_back('b');
		a.push_back('c');
		Permutation(a);

	}

	void test4() {
		char a[] = "aaa";
		Permutation(a);
	}
}

using namespace T39;

//int main() {
//	test();
//}