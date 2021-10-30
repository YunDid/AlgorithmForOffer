
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T51 {

#pragma warning(disable:4996);

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	//字符1byte 8bit 256中状态 256中不同字符表示
	const unsigned int Allchar = 256;

	class CharStatics {
	public:
		CharStatics():index(0){
			for (int i = 0; i < Allchar; i++) {
				hash[i] = -1;
			}
		}

		void insert(char ch) {
			if (hash[ch] == -1) {
				//当前字符仅出现了一次，因此键值对值存放其在字符流中的位置
				hash[ch] = index;
			}
			else if (hash[ch] >= 0) {
				//当前字符已经在字符流中出现了一次，因此当前元素不可能为要求元素,将值设置为-2标识
				hash[ch] = -2;
			}

			//若当前字符已经重复出现了多次，则仅需更新index

			//index++用于标识下一个元素在字符流中的位置
			index++;
		}

		char getFirst() {
			//Front记录字符在字符流中出现的位置，初始化为int中的最大值
			int min = numeric_limits<int>::max();

			//minChar记录最小字符
			char minChar = '\0';

			for (int i = 0; i < Allchar; i++) {
				//因为哈希表中为元素顺序不代表在字符流中出现顺序，因此需要遍历整个哈希表，根据index记得位置判断是否靠前
				if (hash[i] >= 0 && hash[i] <= min) {
					minChar = (char)i;
					min = hash[i];
				}
			}

			return minChar;
		}

	private:
		//哈希表，记录字符流中字符出现的次数
		int hash[Allchar];
		//记录当前字符流中字符在字符流中的位置
		int index;
	};

	bool isExcption = false;

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
		
	}
	void test4() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test4:" << endl;

		CharStatics* a = new CharStatics();

		cout << "当前字符流中第一次只出现一次的字符为: " << a->getFirst() << endl;

		cout << "压入字符: a"<< endl;
		a->insert('a');
		cout << "当前字符流中第一次只出现一次的字符为: " << a->getFirst() << endl;

		cout << "压入字符: b" << endl;
		a->insert('b');
		cout << "当前字符流中第一次只出现一次的字符为: " << a->getFirst() << endl;

		cout << "压入字符: a" << endl;
		a->insert('a');
		cout << "当前字符流中第一次只出现一次的字符为: " << a->getFirst() << endl;

		cout << "压入字符: c" << endl;
		a->insert('c');
		cout << "当前字符流中第一次只出现一次的字符为: " << a->getFirst() << endl;

		
	}

}

using namespace T51;

//int main() {
//	test();
//}
