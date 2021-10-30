#include<iostream>
using namespace std;

bool increment(char*);
void printNum(int);
void printNumCore(char*);
void test7();

bool xfailed = false;

//int main() {
//	test7();
//}

void printNum(int n) {
	//�쳣����
	if (n <= 0) {
		xfailed = true;
		return;
	}
	
	//���Ǵ������⣬�����ַ��������������������(�˴�ѡ���ַ���)
	char* str = new char[n + 1];
	memset(str, '0', n);
	str[n] = '\0';

	while (!increment(str)) {
		printNumCore(str);
	}

	//��ֹ�ڴ�й©
	delete[] str;
}

bool increment(char* str){
	//��¼�ַ�������
	int len = strlen(str);
	//���ý�λֵ
	int carry = 0;
	//���÷���ֵ�ж��Ƿ����������λ
	bool arrive = false;
	

	for (int i = len - 1; i >= 0; i--) {
		//����ģ��ӷ�����ʱ���ֱ���
		int num = str[i] - '0' + carry;
		//��Ϊ��λ����ֱ�ӽ��м�1����
		if (i == len - 1) {
			num++;
		}

		if (num >= 10) {
			if (i == 0) {
				arrive = true;
			}
			else {
				//���ý�λ�󣬽���λ����Ϊ0��д��
				num -= 10;
				str[i] = num + '0';
				carry = 1;
			}
		}
		else {
			//ֱ��д��
			str[i] = num + '0';
			//break����Ϊ:���е�ֱ�Ӽ�һ����������ڸ�λ������λ�ļ�1���������carry�Ľ�λ
			break;
		}
	}

	return arrive;
}

void printNumCore(char* str) {
	//�����ж��Ƿ�Ϊ��һ���������ı���
	bool first = false;
	int len = strlen(str);
	for (int i = 0; i <= len; i++) {

		if (!first&&str[i] != '0') {
			first = true;
		}
		if (first)
			cout << str[i];
	}
	cout << " ";
}

void test7() {
	int n = -1;
	printNum(n);
}