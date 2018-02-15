#pragma once
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

namespace SetUsageNM
{
	class testSetUsage
	{
		public:
		void callsetSimpleUsage()
		{
			setSimpleUsage();
		}
		
		void setSimpleUsage()
		{
			set<string> setsimple;
			
			//add some values 
			setsimple.insert({"one"});
			setsimple.insert({"two"});
			
			for(auto it = setsimple.begin(); it != setsimple.end(); it++)
				cout << (*it).c_str() << endl;
		}
	};
};