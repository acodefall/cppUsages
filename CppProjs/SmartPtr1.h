
#ifndef _SmartPtr1
#define _SmartPtr1
#include "stdafx.h"
#include <iostream>
#include <thread>
#include <memory>  
using namespace std;



class Test1
{
	int m1;
	public:
		~Test1()
		{
			cout << "dtor called \r\n";
		}
		Test1(int x)
		{
			m1 = x;
		}
		Test1(const Test1& x)
		{
			m1 = x.m1;
			cout << "ctor called \r\n";
		}

		int get()
		{
			return m1;
		}
};


class SmartPtrTest
{
public:
	void callSmartPtrTest()
	{
		std::shared_ptr<Test1> sh1 = std::make_shared<Test1>(12);
		{
			std::shared_ptr<Test1> sh2(sh1);
		}

		{
			std::shared_ptr<Test1> sh3(sh1);
		}
		
		cout << "ending dtor called \r\n";
	}



};


#endif
