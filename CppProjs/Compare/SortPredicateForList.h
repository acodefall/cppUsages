#pragma once
#pragma once
#include <list>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
namespace SortPredicateForListNM
{
	/*
	
	Illustrates the use of SORT-Predicate used by Sort() for List.

		Overloading SEARCH and Overload ORDER
			SEARCH-Predicate-function uses "==" operator for to checking whether the VALUE is SAME,
			ahere as SORT-Predicate-function compares using "<" or ">" operator

		
		SORT-Predicate details_20170714003
			a) Define a SORT-Predicate class 
			b) Overload the operator() and accepts two instances of Person object as input param.
			   Function should compare the 'VALUE/age of one instance against other instance' using < or > operator
			Return TRUE if AGE are same.

			Predicate parameter should match the type accepted by collection class
			If collection class takes PTR then predifate parameter should also be pointer


			//SORT-Predicate
			struct sortByAge
			{
				bool operator()(Person* p1, Person* p2)
				{
					if (p1->age < p2->age) //Uses < or > 
					{
						return true;
					}
					return false;
				}
			};
			sortByAge sortByAgeInst;
			lst.sort(sortByAgeInst);
			

			class sortByPopulation
			{
				public:
				bool operator()(const City* p1, const City* p2)
				{
					bool ret = false;
					if (p1->population < p2->population)
						ret = true;
					return ret;
				}
			};

			map<City*, string, sortByPopulation> mp;

	*/
	class Person
	{
	public:
		std::string name;
		int		age;


		Person(const char* n, int a) //Uses < or > 
		{
			name = n;
			age = a;
		}
	};

	//SORT-Predicate
	struct sortByAge
	{
		bool operator()(Person* p1, Person* p2)
		{
			if (p1->age < p2->age) //
			{
				return true;
			}
			return false;
		}
	};
	class SortPredicateForList
	{
	public:
		void callSortPredicateForList()
		{
			std::list<Person*> lst;
			lst.push_back(new Person("A1", 12));
			lst.push_back(new Person("A67", 89));
			lst.push_back(new Person("Z7", 87));
			lst.push_back(new Person("C01", 982));
			lst.push_back(new Person("U17", 489));
			lst.push_back(new Person("D80", 712));

			cout << endl << "List before sorting"  << endl;
			
			for (auto itr = lst.begin(); itr != lst.end(); itr++)
			{
				cout << "Name " << (*itr)->name << " Age " << (*itr)->age << endl;
			}

			//Instantiate the SORT-Predicate class and pass it to Sort()
			sortByAge sortByAgeInst;
			lst.sort(sortByAgeInst);


			cout << endl << "List after sorting" << endl;
			for (auto itr = lst.begin(); itr != lst.end(); itr++)
			{
				cout << "Name " << (*itr)->name <<" Age "<< (*itr)->age << endl;
			}
			cout << endl;

			/*
				List before sorting
					Name A1 Age 12
					Name A67 Age 89
					Name Z7 Age 87
					Name C01 Age 982
					Name U17 Age 489
					Name D80 Age 712

				List after sorting
					Name A1 Age 12
					Name Z7 Age 87
					Name A67 Age 89
					Name U17 Age 489
					Name D80 Age 712
					Name C01 Age 982
			*/
		}


	



		
	};
};