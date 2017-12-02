#pragma once
#include <list>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
namespace CollectionTypeStandardOverloadsNM
{

	//Copy-ctor, assignment, ==, < 
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

			//Copy-ctor (this is required when we are not storing POINTER in stl container)
			Person(const Person& prs)
			{
				cout << "\r\n" << " CopyCtor got called";
				name = prs.name;
				age = prs.age;
			}
			//Copy-Assignment
			Person& operator = (const Person& prs)
			{
				cout << "\r\n" << " = got called";
				name = prs.name;
				age = prs.age;

				return *this;
			}

			//Equality
			bool operator == (const Person& prs) const
			{
				cout << "\r\n" << " == got called";
				if (age == prs.age)
					return true;
				else
					return false;
			}

			

	};

	//Less than 
	bool operator < (const Person& lhs, const Person& rhs )
	{
		cout << "\r\n" << "<< got called";
		if (lhs.age < rhs.age)
			return true;
		else
			return false;
	}
	class TestCollectionTypeStandardOverloads
	{
	public:
		void callTestFindIf()
		{
			std::list<Person*> lst;
			lst.push_back(new Person("A1", 12));
			lst.push_back(new Person("A67", 89));
			lst.push_back(new Person("Z7", 87));
			lst.push_back(new Person("C01", 982));
			lst.push_back(new Person("U17", 489));
			lst.push_back(new Person("D80", 712));

		
			sort(lst.begin(), lst.end());
		}


		void PredicateIsFunctor(std::list<Person*> lst, int age)
		{
			std::list<Person*>::iterator x = find_if(lst.begin(), lst.end(), compareAge(age));

			if (x == lst.end())
				cout << "not found \r\n";
			else
				cout << (*x)->name << " " << (*x)->age;
		}



		//[ capture-list ] ( params ) -> ret { body }
		//[ capture-list ] = [age1] "means Lamba will capture R-VALUE of only 'age1'. Lambda can read age1 but not modify it"
		void PredicateIsLambda(std::list<Person*> lst, int age1)
		{

			std::list<Person*>::iterator x = find_if(
				lst.begin(),
				lst.end(),
				[age1](Person* prs) -> bool
			{
				if (prs->age == age1)
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
	};
};