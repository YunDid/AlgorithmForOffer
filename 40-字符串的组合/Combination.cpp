#include<iostream>
#include<vector>
using namespace std;

namespace T40 {

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	void Combination(char*);
	void CombinationCore(char*, int, vector<char>&);

	void Combination(char* arr) {
		//�쳣�ж�
		if (arr == nullptr) {
			return;
		}

		//��n��Ԫ�ص�������ϲ��Ϊ��n�� mlen��Ԫ���г���Ϊk�����
		char *len = arr;
		int mlen = 0;
		vector<char> comb;

		for (; *len != '\0'; len++) {
			mlen++;
		}

		for (int k = 1; k <= mlen; k++) {
			CombinationCore(arr, k, comb);
		}
	}

	void CombinationCore(char* str, int k, vector<char>& comb) {
		//base case
		if (k == 0) {
			//�����Ͻ��
			for (auto i : comb) {
				cout << i << " ";
			}

			cout << endl;
			return;
		}

		if (*str == '\0') {
			return;
		}

		//��str�е�ÿ��Ԫ�ؽ��о��� ����Ϊk������Ƿ��е�ǰԪ��
		//yes k��Ԫ������к���ǰԪ��
		comb.push_back(*str);
		//��strʣ��Ԫ����ȡk-1��Ԫ�ؽ������
		CombinationCore(str + 1, k - 1, comb);

		//�ڽ���ͬ����Ϊno�ľ���ǰ����Ҫ�ָ�
		comb.pop_back();

		//no k��Ԫ������в�����ǰԪ��
		//��strʣ��Ԫ����ȡk��Ԫ�ؽ������
		CombinationCore(str + 1, k, comb);
	}

	void test() {

		/*test1();
		test2();
		test3();*/
		test4();

	}
	void test1() {



	}
	void test2() {




	}
	void test3() {

		vector<char> a;
		a.push_back('a');
		a.push_back('b');
		a.push_back('c');

	}

	void test4() {
		char a[] = "abc";
		Combination(a);
	}
}

using namespace T40;

//int main() {
//	test();
//}