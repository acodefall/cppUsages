#pragma once
#pragma once
#pragma once
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

namespace SortMapByValueNM
{
	/*
		Map does not sort by value. Work around is store name/value in PAIR instances.
		Then store these PAIR instances in set<>, and also provide a Orderdelegate for 
		ordering the set using VALUE. 

		This does not give the ability for accessing by value.
	*/
	
};
