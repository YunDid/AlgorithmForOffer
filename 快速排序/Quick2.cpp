#include<iostream>
using namespace std;
#include<time.h>

int RandomInRange(int start, int end)
{
	if (end > start)
	{
		srand(time(NULL));//��srand������������������ĳ�ʼ������,ʹ�������������ʱ��ı仯���仯
		return start + rand() % ((end - start));//����start~end֮��������
	}
	return 0;
}

void swap_element(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int data[], int length, int start, int end)
{
	if (data == NULL || length <= 0 || start < 0 || end >= length)
	{
		cout << "error1!" << endl;
		exit(0);
	}

	int index = RandomInRange(start, end);
	//������ĩβ�ݴ�������Ի���ǰ������ݽ����ƶ�
	swap_element(&data[index], &data[end]);
	
	//����smallָ�룬ʱ��ָ��ǰ���һ���Ȼ���С��Ԫ��
	int small = start - 1;

	//�������飬�ƶ�smallָ�룬����ʹsmallָ��ǰ���һ���Ȼ���С��Ԫ��
	for (index = start; index < end; index++) {
		if (data[index] < data[end]) {
			small++;
			if (small != index) {
				swap_element(&data[index], &data[small]);
			}
		}
	}
	//�ƶ�smallָ�룬ʹ��ָ�����Ӧ�ڵ�λ�ã����ǵ�ǰ����űȻ������Ԫ��
	small++;
	//��ĩβ�ݴ�Ļ�����λ
	swap_element(&data[end], &data[small]);
	return small;
}
void Quicksort(int data[], int length, int start, int end)
{
	if (start == end)
	{
		return;
	}
	int index = Partition(data, length, start, end);
	if (index > start)
		Quicksort(data, length, start, index - 1);
	if (index < end)
		Quicksort(data, length, index + 1, end);
}

//int main(void)
//{
//	int data[10] = { 1,4,7,0,6,10,3,8,2,9 };
//	Quicksort(data, 10, 0, 9);
//	for (int i = 0; i < 10; i++)
//		cout << data[i] << " ";
//	cout << endl;
//	return 0;
//}
