
#ifndef _Thread1
#define _Thread1
#include "stdafx.h"
#include <iostream>
#include <thread>
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

class ThreadTest1
{
	int m1;
public:
	ThreadTest1(int x)
	{
		m1 = x;
	}
	ThreadTest1(const ThreadTest1& x)
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
void worker(void* y)
{
	ThreadTest1* c = (ThreadTest1*)y;
	cout << c->get() << " worker() \r\n";
	std::this_thread::sleep_for(chrono::seconds(6));
}




class Thread1Test
{
public:
	void callThread1Test()
	{
		ThreadTest1 x(23);
		thread *th = 0;
		
		try
		{
			th = new thread(worker, &x);
			
		}
		catch (...)
		{
			if (th->joinable())
				th->join();
			throw;
		}
		
		if (th->joinable())
			th->join();
		
	}

	

};


#endif
/*
#include <iostream>
#include <thread>

void hello()
{
std::cout << "in the thread \r\n";
}
int main()
{
std::thread t(hello);
t.join();
}

*/