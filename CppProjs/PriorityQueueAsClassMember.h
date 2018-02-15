#pragma once
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
namespace PriorityQueueAsClassMemberNM
{
	/*
	Initialization using Curly braces
	Using () we can pass parameter to CTOR, to be used during construction of object. Using {} we can pass parameter to Initialization, which happens before construction. In the past, initializor list was used for passing parameter to initialization; now we can use { }. Difference between these  two methods is that, {} can be made part of class-member declaration.

			String s(“one”); //passes to ctor for construction	
			String sx{“one”}; //passes to initializor


	Example: if you want to declare priority_queue as class member and also pass comparator as part of class declaration, then use {}.
			priority_queue<int, vector<int>, m1> pq{ cLess }; //works. Same as initializer list


	*/


	//if you want to declare priority_queue as class member and pass comparator as part of class declaration follow this example.

	class comprLess
	{
		public:
			bool operator() (int p1, int p2)
			{
				return true;
			}
	};


	class Something
	{
		public:
			comprLess cLess;
			//priority_queue<int, vector<int>, comprLess> pq(cLess); //Gives compilation error "syntax error: identifier 'cLess'"
			priority_queue<int, vector<int>, comprLess> pq{ cLess }; //works this is equivalent to using initializer list

			void Method()
			{
				priority_queue<int, vector<int>, comprLess> pq2(cLess); //works fine
			}
	};
};
