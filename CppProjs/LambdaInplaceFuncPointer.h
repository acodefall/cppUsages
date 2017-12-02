#pragma once
#include <list>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
namespace LambdaInplaceFuncPointerNM
{
	class Person
	{
		public:
			std::string name;
			int		age;


			Person(const char* n, int a)
			{
				name = n;
				age = a;
			}
	};


	class TestLambdaInplaceFuncPointer
	{
		public:
			void callLambdaInplaceFuncPointer()
			{
				std::list<Person*> lst;
				lst.push_back(new Person("A1", 12));
				lst.push_back(new Person("A67", 89));
				lst.push_back(new Person("Z7", 87));
				lst.push_back(new Person("C01", 982));
				lst.push_back(new Person("U17", 489));
				lst.push_back(new Person("D80", 712));

				LambdaFunctionPointer(lst, 87);
				LambdaInplace(lst, 87);
			}



			void LambdaInplace(std::list<Person*> lst, int age1)
			{
				std::list<Person*>::iterator x = find_if(
					lst.begin(),
					lst.end(),
					[](Person* prs) -> bool
						{
							if (prs->age == 982)
							{
								return true;
							}
							return false;
						}
				);

				if (x == lst.end())
					cout << "not found \r\n";
				else
					cout << (*x)->name << " " << (*x)->age << endl;
			}


			void LambdaFunctionPointer(std::list<Person*> lst, int age1)
			{
				auto fptr = [age1](Person* prs) -> bool
				{
					if (prs->age == age1)
					{
						return true;
					}
					return false;
				};

				std::list<Person*>::iterator x = find_if(
					lst.begin(),
					lst.end(),
					fptr
				);

				if (x == lst.end())
					cout << "not found \r\n";
				else
					cout << (*x)->name << " " << (*x)->age << endl;
			}
	};
};