#pragma once
#include <queue>
#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <mutex>
using namespace std;
namespace BlockingQNM
{

	class Person
	{
		string name;
		int age;
		
		
		public:
			Person()
			{
				age = 0;
			}
	};
	template<T>
	class blockingQ
	{
		private:
			queue<T*> bq;
			unique_lock<mutex> lck;

		public:
			blockingQ()
			{
				lck.
			}

			void Eq(T* val)
			{
				
			}
	};

};