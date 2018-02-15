
#ifndef _MutexTest1
#define _MutexTest1
#include "stdafx.h"
#include <iostream>
#include <thread>
#include <memory>  
#include <mutex>  
using namespace std;


/*
unique_lock,unique_ptr, shared_ptr
	unique_ptr: An object can be owned by only one instance of unique_ptr. When the object moves between the unique_ptr, ownership 
	will also gets transferred. Destructor will be called by the owning instance of unique_ptr.

	shared_ptr: Multiple instances of shared_ptr can share the same object; each instance shared_ptr will increment reference count.
	Destruction of shared_ptr instance will decrement the ref-count; when the ref-count becomes 0, actual object will be deleted.


	unique_lock: unique_lock encapsulates sync objects like Mutex. We have to intialize unique_lock with native sync-object.
	unique_lock.release() will detache the under lying MUTEX from unique_lock() instance, but does not call RELEASE on underying MUTEX.
	unique_lock.unlock() will call RELEASE on underying MUTEX also.

*/
class TestWork1
{
	int m1;
	public:
		~TestWork1()
		{
			cout << "dtor called \r\n";
		}
		TestWork1(int x)
		{
			m1 = x;
		}
		TestWork1(const TestWork1& x)
		{
			m1 = x.m1;
			cout << "ctor called \r\n";
		}

		int get()
		{
			return m1;
		}

		void worker()
		{
			std::mutex mut;
			std::unique_lock<std::mutex> lk(mut); //
			if (lk.owns_lock() == false)
			{
				lk.lock();
				//Test1* c = (Test1*)y;
				cout << get() << " worker() \r\n";
				std::this_thread::sleep_for(chrono::seconds(6));
				lk.release(); //This will detaches the under lying MUTEX from unique_lock() instance, but does call RELEASE on underying MUTEX
			}

			////unique_lock.unlock() will call RELEASE on underying MUTEX also.
			//lk.unlock();

			////unique_lock.release() will detache the under lying MUTEX from unique_lock() instance, but does not call RELEASE on underying MUTEX.
			lk.release();
			mut.unlock();

		}
};
 





class MutexTest
{
	public:
		void callMutexTest()
		{
			std::thread* tt = 0;
			TestWork1 wrk(55);
			try
			{
				tt = new std::thread(&TestWork1::worker, wrk);
				if (tt->joinable())
					tt->join();
				cout << "ending dtor called \r\n";
			}
			catch (...)
			{
				if (tt->joinable())
					tt->join();
			}
		}
};


#endif
