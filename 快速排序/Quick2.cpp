#include<iostream>
using namespace std;
#include<time.h>

int RandomInRange(int start, int end)
{
	if (end > start)
	{
		srand(time(NULL));//　srand函数是随机数发生器的初始化函数,使得随机数种子随时间的变化而变化
		return start + rand() % ((end - start));//产生start~end之间的随机数
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
	//在数组末尾暂存基数，对基数前面的数据进行移动
	swap_element(&data[index], &data[end]);
	
	//设置small指针，时刻指向当前最后一个比基数小的元素
	int small = start - 1;

	//遍历数组，移动small指针，最终使small指向当前最后一个比基数小的元素
	for (index = start; index < end; index++) {
		if (data[index] < data[end]) {
			small++;
			if (small != index) {
				swap_element(&data[index], &data[small]);
			}
		}
	}
	//移动small指针，使其指向基数应在的位置，但是当前存放着比基数大的元素
	small++;
	//将末尾暂存的基数归位
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
