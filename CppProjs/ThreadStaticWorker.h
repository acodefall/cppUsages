#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <thread>
using namespace std;

/*
	Calling Thread object in C++ 11.
	-There is no start() method on thread class, this means thread will start running as soon as you 
	 create it thread instance.
	-Since there is no start() method, all the parameters (worker-func and params) should be passed passed to CTOR.
		Passed info could be
			-func-name qualified with class name. Add & only when work-func is regular class member
			-class instance . Pass this only when work-func is regular class member. Use &
			-parameters to work-func. Pass this all the time
	-Worker-func can be global, static memmber of a class or regular member of a class.
		In case of global-func, pass the name of global-function along with the param-list.
			th = new thread(worker, param);	
	
		In case of static memmber, pass func-name qualified with class name, but do not pass class instance. 
		Pass param-list.
				th = new thread(ThreadWorker::ThreadWorkerX, param);
		In case of regular memmber function, pass func-name qualified with class name(use &), 
		also pass class instance(use &), and pass param-list.
				th = new thread(&ThreadWorker::ThreadWorkerX, &classInst, param);

		When passing the parameter to wrorker function, use & only if the function param has pointer
*/
namespace ThreadStaticWorkerNM
{
	class ThreadWorker
	{
		public:
			static void ThreadWorkerX(string x)
			{

			}
	};

	class ThreadStaticWorker
	{
		public:
			void createThreads()
			{
				thread *th = 0;
				string x;
				try
				{
					//When worker is static-member, there is no need to instantiate 
					//the class hosting the static worker function. When passing methos name to thread-CTOR
					//do not use "&" 
					//when passing the parameter to wrorker function, use & only if the function 
					//param has pointer
					th = new thread(ThreadWorker::ThreadWorkerX, x);

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