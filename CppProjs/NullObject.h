#pragma once
#include <iostream>
#include <iomanip>
#include <thread>
#include <mutex>
using namespace std;
#include<iostream>
#include<algorithm>
#include<list>
#include <string>

namespace NullObjectNM
{
	class Email
	{
		public:
			virtual void creteMessage() = 0;
	};
	
	class Calender : Email
	{
		public:
			void createMessage()
			{
				//do something
			}
	};

	class null_Email : Email
	{
		public:
			void createMessage()
			{
				//do nothing
			}
	};


	class UseNullObject
	{
		public:
				void TestNullObject()
				{
					Calender cal = null_Email;
				}
	};
};