
#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
#include<algorithm>
#include<functional>
#include<list>
#include<string>
using namespace std;

namespace T65 {

	#pragma warning(disable:4996);

	//����ԭ������
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	//���ڵݹ� - ������ģ�����

	struct Testt
	{
		enum value { N = 1 };
	};

	template<int n>
	struct GetSumByTem
	{
		enum value { N = GetSumByTem<n - 1>::N + n };
	};

	template<>
	struct GetSumByTem<1>
	{
		enum value { N = 1 };
	};

	//���ڵݹ� - �麯��
	class GSumByVirtualBase {

	public:
		virtual int GetSum(int n) {
			return 0;
		}
	};

	class GSumByVirtual : public GSumByVirtualBase {

	public:
		GSumByVirtual(GSumByVirtualBase* GBS) :GSumByVirtualBase() {
			arr[0] = GBS;
			arr[1] = this;
		}

		int GetSum(int n) override{
			return n + arr[!!n]->GetSum(n - 1);
		}
	private:
		GSumByVirtualBase* arr[2];
	};

	int GetSumByVirtual(int);

	int GetSumByVirtual(int n) {

		GSumByVirtualBase* GBS = new GSumByVirtualBase();
		GSumByVirtual* GS = new GSumByVirtual(GBS);

		return GS->GetSum(n);

	}

	//���ڵݹ� - ����ָ��
	typedef int(*func) (int);

	int GetSumByPointerBaseCase(int);
	int GetSumByPointer(int);

	int GetSumByPointer(int n) {
		static func arr[2] = { GetSumByPointerBaseCase,GetSumByPointer };
		return arr[!!n](n - 1) + n;
	}

	int GetSumByPointerBaseCase(int n) {
		return 0;
	}

	//����ѭ�� - ���캯��

	class GSum;
	int GetSumFrom1TonByClass(int);

	class GSum {

	public:

		GSum() {
			//��¼��ǰ����
			N++;
			//��¼�ۼӺ�
			Sum += N;
		}

		static void ResetSum() {
			N = Sum = 0;
		}

		static int GetSum() {
			return Sum;
		}

	private:
		static int N;
		static int Sum;
	};

	//��Ա��ʼ��
	int GSum::N = 0;
	int GSum::Sum = 0;

	int GetSumFrom1TonByClass(int n) {

		//����
		GSum::ResetSum();

		//����n��GSum���󣬽����ۼ�1-n�ĺ�
		GSum* arr = new GSum[n];
		//�����ڴ�
		delete[] arr;
		arr = nullptr;

		return GSum::GetSum();
	}

	void test() {

		test1();
		test2();
		test3();
		test4();

	}

	void test1() {

		isExcption = false;

		cout << "test1:" << endl;

		cout << GetSumFrom1TonByClass(1) << endl;

	}

	void test2() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test2:" << endl;

		cout << GetSumByPointer(1) << endl;

	}
	void test3() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test3:" << endl;

		cout << GetSumByVirtual(1) << endl;

		
	}
	void test4() {
		//����Ի������踴ԭ
		isExcption = false;

		cout << "test4:" << endl;

		cout << GetSumByTem<100>::value::N << endl;
		cout << Testt::value::N << endl;
	}
	


}

using namespace T65;

//int main() {
//	test();
//}
