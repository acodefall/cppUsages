#ifndef _CopyCtorTest
#define _CopyCtorTest
#include "stdafx.h"
#include <iostream>
using namespace std;


/*
	Ctor get called
		-In case of pass-by-value
		-In case of return-by-value. There are two cases here. 
		 Function can return the instance that is declared locally. This will trigger CTOR.
		 Function can do NEW inside RETURN statement; this will not trigger CTOR due to compiler's 
		 return code optimization.
	 
		 {
			return new TestClass(); //Ctor not triggered
		 }

		 {
			TestClass x;
			return x; //Ctor gets triggered
		 }
*/

class CopyCtor1
{
	int m1;
	public:
		CopyCtor1( int x)
		{
			m1 = x;
		}
		CopyCtor1(const CopyCtor1& x)
		{
			m1 = x.m1;
			cout << "ctor called \r\n";
		}

		int get()
		{
			return m1;
		}
};

//This will trigger CTOR
void triggerCopyCtrByValue(CopyCtor1 y)
{
	cout << y.get() << " triggerCopyCtrByValue() \r\n";
}


//This will NOT trigger CTOR
CopyCtor1 triggerCopyCtrByValueReturn()
{
	cout << "triggerCopyCtrByValueReturn() \r\n";
	return CopyCtor1(67);
}


//This will trigger CTOR
CopyCtor1 triggerCopyCtrByValueReturn2()
{
	CopyCtor1 d2(78);
	cout << "triggerCopyCtrByValueReturn2() \r\n";
	return d2;
}

class CopyCtorTest
{
	public:
		void callCopyCtorTest1()
		{
			CopyCtor1 d1(91);
			CopyCtor1 d2(d1);
		}

		void callCopyCtorTest2()
		{
			cout << "callCopyCtorTest2() \r\n";
			CopyCtor1 d2(78);
			triggerCopyCtrByValue(d2);
			triggerCopyCtrByValueReturn();
			triggerCopyCtrByValueReturn2();
		}

};


#endif