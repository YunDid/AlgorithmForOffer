#include<iostream>
#include<string>
using namespace std;

void replace(char*);

//int main() {
//	char p[100] = "";
//	replace(nullptr);
//	cout << p;
//	return 0;
//}

void replace(char* arr) {
	if (arr == nullptr || strlen(arr) == 0) {
		return;
	}
	char* p = arr;

	//��λpָ��λ�ò������ո�����������λqָ��λ��
	int nums = 0;
	for (; *p != '\0'; p++) {
		if (*p == ' ') {
			nums++;
		}
	}

	char* q = p + nums * 2;

	while (p != q) {
		if (*p != ' ') {
			*q = *p;
			p--;
			q--;
		}
		else {
			
			p--;
			for (int i = 0; i < 3; i++){
				if (i == 0) {		
					*q = '0';
					q--;
				}
				else if (i == 1) {
					*q = '2';
					q--;
				}
				else {
					*q = '%';
					q--;
				}
			}
			
		}
	}
}