#pragma once
#include <iostream>
#include <thread>
#include <string>
#include <sstream>
#include <list>
using namespace std;
namespace StaticClassNM
{
	class MakeMeStatic
	{
		public:
			MakeMeStatic()
			{
				cout << "inside MakeMeStatic()  " << endl;
			}
			int something;
			
			void printTID(string s)
			{
				cout << "inside printTID()  " << s.c_str() << endl;
			}
	};

	class StaticWrapper
	{
		public:
			static MakeMeStatic& getInstance()
			{
				static MakeMeStatic ist;
				cout << "StaticWrapper::getInstance() " << std::this_thread::get_id() << endl;
				return ist;
			}
	};

	class ThreadWorker
	{
		public:
			static void ThreadWorkerX(string s)
			{
				MakeMeStatic& st = StaticWrapper::getInstance();
				st.printTID(s);
				cout << "inside thread " << s << endl;
				std::this_thread::sleep_for(chrono::minutes(2));

				cout << "inside thread ending" << s << endl;
			}
	};

	class useStaticClass
	{
		public:
			useStaticClass()
			{
			}

			void createThreads()
			{
				list<thread*> lst;
				for (int i = 0; i < 10; i++)
				{
					stringstream ss;
					ss << i;
					string d;
					//calling 
					//unique_ptr<thread> t(new thread(ThreadWorker::ThreadWorkerX, d));
					//thread* t = new thread(ThreadWorker::ThreadWorkerX, d);
					lst.push_front(new thread(ThreadWorker::ThreadWorkerX, d));
				}

				for (auto itr = lst.begin(); itr != lst.end(); itr++)
				{
					((thread*)(*itr))->join();
				}


				for (auto itr = lst.begin(); itr != lst.end(); itr++)
				{
					delete ((thread*)(*itr));
				}

			}
		

	};

};
