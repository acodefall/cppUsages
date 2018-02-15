#pragma once
#pragma once
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

namespace SortPredicateForSetNM
{
	//Illustrates storing a PAIR in Set and sorting based on VALUE, but Set does not allow you to access by KEY.
	//Basically STL does not have container that has KEY and also support sorting by VALUE.

	class City
	{
		public:
			int population;
			string name;
			City(string nm, int pop)
			{
				population = pop;
				name = nm;
			}
	};

	//SORT-Predicate
	class sortByPopulation
	{
		public:
			bool operator()(pair<string, City*> p1, pair<string, City*> p2)
			{
				bool ret = false;
				if (p1.second->population < p2.second->population)
					ret = true;
				return ret;
			}
	};


	class SortPredicateForSet
	{
		public:
	
			void callSortPredicateForSet()
			{
				set<pair<string, City*>, sortByPopulation> st;
				//map<string, City*, compFunctor> mp;
			
				st.insert({ "ny", new City("ny", 100) });
				st.insert({ "london", new City("london", 5) });
				st.insert({ "tokyo", new City("tokyo", 45) });
				st.insert({ "bangalore", new City("bangalore", 15) });

			

				//print values
				cout << "print Map \r\n";
				cout << "\r\n\r\n";
				//for (map<string, City*>::iterator itr = mp.begin(); itr != mp.end(); itr++)
				for (auto itr = st.begin(); itr != st.end(); itr++)
				{
					cout << " KEY in SET " << (*itr).first.c_str() << " (" << (*itr).second->population << ")" << "\r\n";
				}

				/*
				london(5)
				bangalore(15)
				tokyo(45)
				ny(100)
				*/
			}

		

	};
};
