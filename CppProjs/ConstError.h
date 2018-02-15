#ifndef _ConstError
#define _ConstError
#include "stdafx.h"
#include <iostream>
using namespace std;


class ConstError;
class ConstError2;

class ConstError2
{
	public:
		void Method()
		{

		}
};

class ConstError
{
	int m1;
	public:
		ConstError(int x)
		{
			m1 = x;
		}
	
		ConstError(const ConstError& x)
		{
			m1 = x.m1;
			cout << "ctor called \r\n";
		}

		int testConst(const ConstError& d1)
		{
			ConstError2* tmp = new ConstError2();
			tmp->Method();
			return m1;
		}

		int get()
		{
			return m1;
		}
};





class ConstErrorTest
{
	public:
		void callConstErrorTest()
		{
			ConstError x(12);
			ConstError x1(13);
			x.testConst(x1);
		}
};


#endif