#pragma once
#include <list>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
namespace SearchPredicateForListNM
{
	/*
		Illustrates the use of SEARCH-Predicate used by Find_if().

		SEARCH-Predicate and SORT-Predicate_20170714001
			SEARCH-Predicate and SORT-Predicate are different. SEARCH-Predicate finds the specific Person object with specific age(say AGE 50), where as SORT-Predicate orders a bunch of Person objects according to their Age(ascending or descending). Parameter for SEARCH-Predicate are: VALUE/Age to search and Object/Person instance, and predicate uses "==" operator for checking whether the VALUE is SAME,
			Parameter for SORT-Predicate are two instances of Person object to be ORDREDED  using "<" or ">" operator

			Ex: SEARCH-Predicate is passed tp find_if()
			SORT-Predicate is passed to Sort() or template declaration of map.

		SEARCH-Predicate details_20170714002
			a) Define a SEARCH-Predicate class
			b) CTOR of the class should take the VALUE(say AGE) to be searched as parameter, and Store this VALUE/AGE in a class member.

			c) Overload the operator() and accept Person object as input param.
			   Function should compare the 'VALUE/age stored stored in class member' against the 'AGE store inside the Person Instrance passed to operator()',	   using == operator
			   Then Return TRUE if AGE are same.

			//SEARCH-Predicate
			struct compareAge
			{
				int age;  //Store the VALUE(say AGE) to be searched as class member.
				compareAge(int a) //pass the value to used when SEARCHING
				{
					age = a; //Store the VALUE(say AGE) to be searched in class member.
				}

				bool operator()(Person* p) //pass the object-instance to seatch
				{
					if (p->age == age) //compare teh 'VALUE stored as class member' against the 'AGE of Person Instrance'
					{
						return true;
					}
					return false;
				}
			};


			
		SEARCH-Predicate usage with Find_if()
			a) Instantiate the SEARCH-Predicate class, and pass the value to be passed as PARAM
			b) Pass the instance of SEARCH-Predicate to find_if(). Find_if() will call the SEARCH-Predicate for every object instance stored inside container.

				compareAge inst(age); //Load the VALUE to be searched in to SEARCH-Predicate instance
				std::list<Person*>::iterator x = find_if(lst.begin(), lst.end(), inst); //Pass the compare instance to finf_if()



	
	*/
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

	//SEARCH-Predicate
	struct searchAge
	{
		int age;  //Store the VALUE(say AGE) to be searched as class member.
		searchAge(int a) //pass the value to used when SEARCHING
		{
			age = a; //Store the VALUE(say AGE) to be searched in class member.
		}

		bool operator()(Person* p) //pass the object-instance to seatch
		{
			if (p->age == age) //compare teh 'VALUE stored as class member' against the 'AGE of Person Instrance'
			{
				return true;
			}
			return false;
		}
	};
	class SearchPredicateForList
	{
		public:
			void callSearchPredicateForList()
			{
				std::list<Person*> lst;
				lst.push_back(new Person("A1", 12));
				lst.push_back(new Person("A67", 89));
				lst.push_back(new Person("Z7", 87));
				lst.push_back(new Person("C01", 982));
				lst.push_back(new Person("U17", 489));
				lst.push_back(new Person("D80", 712));

				cout << endl;
				PredicateIsFunctor(lst, 87);

				PredicateIsLambda(lst, 90);
			}


			void PredicateIsFunctor(std::list<Person*> lst, int age)
			{
				searchAge inst(age); //Load the VALUE to be searched in to SEARCH-Predicate instance
				std::list<Person*>::iterator x = find_if(lst.begin(), lst.end(), inst); //Pass the compare instance to finf_if()

				if (x == lst.end())
					cout << endl << "Person of age " << age << " is not found \r\n";
				else
					cout << endl << "Person of age " << age << " is found. Person is " << (*x)->name << "\r\n";
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
					cout << endl << "Person of age " << age1 << " is not found \r\n";
				else
					cout << endl << "Person of age " << age1 << " is found. Person is " << (*x)->name << "\r\n";
				
			}
	};
};