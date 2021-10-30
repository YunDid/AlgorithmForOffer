
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

	//函数原型声明
	void test();
	void test1();
	void test2();
	void test3();
	void test4();

	bool isExcption = false;

	//基于递归 - 非类型模板参数

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

	//基于递归 - 虚函数
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

	//基于递归 - 函数指针
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

	//基于循环 - 构造函数

	class GSum;
	int GetSumFrom1TonByClass(int);

	class GSum {

	public:

		GSum() {
			//记录当前数字
			N++;
			//记录累加和
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

	//成员初始化
	int GSum::N = 0;
	int GSum::Sum = 0;

	int GetSumFrom1TonByClass(int n) {

		//重置
		GSum::ResetSum();

		//创建n个GSum对象，进而累加1-n的和
		GSum* arr = new GSum[n];
		//清理内存
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
		//多测试环境下需复原
		isExcption = false;

		cout << "test2:" << endl;

		cout << GetSumByPointer(1) << endl;

	}
	void test3() {
		//多测试环境下需复原
		isExcption = false;

		cout << "test3:" << endl;

		cout << GetSumByVirtual(1) << endl;

		
	}
	void test4() {
		//多测试环境下需复原
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
