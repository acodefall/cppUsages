#pragma once
#include <list>
#include <iostream>
using namespace std;
namespace UsingListNM
{
	/*
		List 

	*/
	class UsingListC
	{
		public:		
			UsingListC()
			{

			}

			void callUsingListC()
			{
				list<int> lst;

				lst.push_back(90);
				lst.push_back(91);
				lst.push_back(93);
				lst.push_back(95);
				print(lst); // 90 91 93 95
				cout << lst.front() << endl;  //90 
				cout << lst.front() << endl;  //91
				print(lst); //90 91 93 95
				lst.remove(91); //90 x 93 95
				cout << lst.size(); //3
				print(lst);//90 x 93 95

			}

			void print(list<int>& x)
			{
				cout << "print " << x.size() << endl;
				for (auto itr = x.begin(); itr != x.end(); itr++)
				{
					cout << (*itr) << endl;
				}

				
			}
	};
};