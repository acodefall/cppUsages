#pragma once
#include <iostream>
using namespace std;
class test1
{
	int data;
	public:
		test1(int d)
		{
			data = d;
		}
		test1(const test1& d)
		{
			data = d.data;
			cout << "inside copy ctor";
		}

		void Method1(test1 ix) //CALLS CTOR
		{
			cout << "\r\n\r\n inside Method1";
		}

		test1 Method2() //CALLS CTOR
		{
			test1 x(3);
			cout << "\r\n\r\n inside Method2";

			return x;
		}

		test1& Method3()
		{
			test1 x(3);
			cout << "\r\n\r\n inside Method3";

			return x;
		}

		void Method4()
		{
			test1 x(*this); //CALLS CTOR
			cout << "\r\n\r\n inside Method4";
		}

		void Method5(const test1& x)
		{
			
			cout << "\r\n\r\n inside Method5";
		}
};

class TestCpCtor
{
	public:
		void callTestCpCtor()
		{
			test1 t(9);


			t.Method1(t);

			t.Method4();

			test1 t2 = t.Method2();

			test1& t3 = t.Method3();

			t.Method5(t3);
		}

};
