#pragma once
#include <unordered_map>
#include <iostream>
using namespace std;
namespace MapFunctionsNM
{
	class MapFunctions
	{
		public:
				void callMapFunctions()
				{

					unordered_map<char, int> charCount;

					const char* src = "hfghasfW2QWDSCad";
					const char* p = src;
					while (	*p != '\0')
					{
						
						if (charCount.find(*p) == charCount.end())
						{
							char c = (char)(*p);
							charCount.insert({c,1});
						}
						else
							charCount[*p]++;
						p++;
					}

					cout << "\r\n";
					
					for (auto itr = charCount.begin(); itr != charCount.end(); itr++)
					{
						cout << "\r\n";
						cout << (*itr).first << " " << (*itr).second << " \r\n";
					}
					cout << "\r\n";
				}
	};
};

