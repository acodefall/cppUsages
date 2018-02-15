#pragma once
#pragma once
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

namespace SortPredicateForMapNM
{
	//Illustrates the use of SORT-Predicate used by Sort().
	//Map sorts by default based on KEY. There is no way to sort on VALUE.
	//If the KEY is complex TYpe like Person, and we want to Sort based on Age, then we have to write SORT-Predicate
	//If you want to Sort based 
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
			bool operator()(const City* p1, const City* p2)
			{
				bool ret = false;
				if (p1->population < p2->population)
					ret = true;
				return ret;
			}
	};

	
	class SortPredicateForMap
	{
	public:
		void callSortPredicateForMap()
		{
			map<City*, string, sortByPopulation> mp;
			//map<string, City*, compFunctor> mp;
			/* OLD way: this could give template comp errors
			mp.insert(pair<string, City*>("ny", new City("ny", 100)));
			mp.insert(pair<string, City*>("london", new City("london", 5)));
			mp.insert(pair<string, City*>("tokyo", new City("tokyo", 45)));
			mp.insert(pair<string, City*>("bangalore", new City("bangalore", 15)));
			*/
			mp.insert({ new City("ny", 100) , "ny" });
			mp.insert({ new City("london", 5) , "london" });
			mp.insert({ new City("tokyo", 45) , "tokyo" });
			mp.insert({ new City("bangalore", 15) , "bangalore" });
			

			//print values
			cout << "print Map \r\n";
			cout << "\r\n\r\n";
			//for (map<string, City*>::iterator itr = mp.begin(); itr != mp.end(); itr++)
			for (auto itr = mp.begin(); itr != mp.end(); itr++)
			{
				cout << (*itr).first->name << " (" << (*itr).first->population << ")" << "\r\n";
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