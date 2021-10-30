
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

namespace T51 {

#pragma warning(disable:4996);

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	//�ַ�1byte 8bit 256��״̬ 256�в�ͬ�ַ���ʾ
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
				//��ǰ�ַ���������һ�Σ���˼�ֵ��ֵ��������ַ����е�λ��
				hash[ch] = index;
			}
			else if (hash[ch] >= 0) {
				//��ǰ�ַ��Ѿ����ַ����г�����һ�Σ���˵�ǰԪ�ز�����ΪҪ��Ԫ��,��ֵ����Ϊ-2��ʶ
				hash[ch] = -2;
			}

			//����ǰ�ַ��Ѿ��ظ������˶�Σ���������index

			//index++���ڱ�ʶ��һ��Ԫ�����ַ����е�λ��
			index++;
		}

		char getFirst() {
			//Front��¼�ַ����ַ����г��ֵ�λ�ã���ʼ��Ϊint�е����ֵ
			int min = numeric_limits<int>::max();

			//minChar��¼��С�ַ�
			char minChar = '\0';

			for (int i = 0; i < Allchar; i++) {
				//��Ϊ��ϣ����ΪԪ��˳�򲻴������ַ����г���˳�������Ҫ����������ϣ������index�ǵ�λ���ж��Ƿ�ǰ
				if (hash[i] >= 0 && hash[i] <= min) {
					minChar = (char)i;
					min = hash[i];
				}
			}

			return minChar;
		}

	private:
		//��ϣ����¼�ַ������ַ����ֵĴ���
		int hash[Allchar];
		//��¼��ǰ�ַ������ַ����ַ����е�λ��
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
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test4:" << endl;

		CharStatics* a = new CharStatics();

		cout << "��ǰ�ַ����е�һ��ֻ����һ�ε��ַ�Ϊ: " << a->getFirst() << endl;

		cout << "ѹ���ַ�: a"<< endl;
		a->insert('a');
		cout << "��ǰ�ַ����е�һ��ֻ����һ�ε��ַ�Ϊ: " << a->getFirst() << endl;

		cout << "ѹ���ַ�: b" << endl;
		a->insert('b');
		cout << "��ǰ�ַ����е�һ��ֻ����һ�ε��ַ�Ϊ: " << a->getFirst() << endl;

		cout << "ѹ���ַ�: a" << endl;
		a->insert('a');
		cout << "��ǰ�ַ����е�һ��ֻ����һ�ε��ַ�Ϊ: " << a->getFirst() << endl;

		cout << "ѹ���ַ�: c" << endl;
		a->insert('c');
		cout << "��ǰ�ַ����е�һ��ֻ����һ�ε��ַ�Ϊ: " << a->getFirst() << endl;

		
	}

}

using namespace T51;

//int main() {
//	test();
//}
