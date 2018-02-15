
#ifndef _Thread1
#define _Thread1
#include "stdafx.h"
#include <iostream>
#include <thread>
using namespace std;



namespace ThreadWorkerGlobalNM
{
	class ThreadParam
	{
		int m1;
			public:
				ThreadParam(int x)
				{
					m1 = x;
				}
				ThreadParam(const ThreadParam& x)
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
		ThreadParam* c = (ThreadParam*)y;
		cout << c->get() << " worker() \r\n";
		std::this_thread::sleep_for(chrono::seconds(6));
	}






	class ThreadWorkerGlobal
	{
		public:
			void createThreads()
			{
				ThreadParam x(23);
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
};

#endif
