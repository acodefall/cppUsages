#pragma once
#include <list>
#include <string>
#include <iostream>
#include <algorithms>

namespace CompareUsingGrtNM
{
	//Overload the comparison operator
	class Person
	{
		std::string name;
		int		age;

		public:
			Person(const char* n, int a)
			{
				name = n;
				age = a;
			}

			bool operator >(Person& p)
			{
				if (age < p.age)
					return true;
				return true;
			}
		
	};


	class CompareUsingGrt
	{
		public:
			void callCompareUsingGrt()
			{
				std::list<Person*> lst;
				lst.push_back(new Person("A1", 12));
				lst.push_back(new Person("A67", 89));
				lst.push_back(new Person("Z7", 87));
				lst.push_back(new Person("C01", 982));
				lst.push_back(new Person("U17", 489));
				lst.push_back(new Person("D80", 712));
			}


	};

};