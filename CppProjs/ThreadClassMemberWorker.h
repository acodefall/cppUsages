#pragma once
#include "stdafx.h"
#include <iostream>
#include <thread>
using namespace std;

namespace ThreadClassMemberWorkerNM
{
	class ThreadWorker
	{
		public:
			void ThreadWorkerX(string s)
			{

			}
	};

	class ThreadMemberWorker
	{
		public:
			void createThreads()
			{
				ThreadWorker x;
				thread *th = 0;
				string s;
				try
				{
					th = new thread(&ThreadWorker::ThreadWorkerX,
						&x, s);

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