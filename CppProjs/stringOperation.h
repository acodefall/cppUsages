#pragma once
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
namespace stringOperationNM
{
	class stringOperation
	{
		public:
				void callstringOperation()
				{
					//SORT
					string sSort("sqwa");
					cout << "before SORT " << sSort << endl;
					std::sort(std::begin(sSort), std::end(sSort));
					cout << "after SORT " << sSort << endl;

					//SEARCH for letter to its INDEX
					//rfind() is another STL naming blunder. It does not search from REVERSE direction but returns LAST occurance,
					//So if a letter is repeated only once, the find() and rfind() returns same value.
					string sSearch("abcdefghi");
					int fIndex = sSearch.find('c'); //2 
					int rIndex = sSearch.rfind('c'); //2
					int missIndex = sSearch.rfind('v'); //-1


					//Substring printing using OFFSET
					string sSubStr("abcdefghi");
					string sSub = sSubStr.substr(4,3); //efg
					string sSub0 = sSubStr.substr(0, 3); //abc
					//string sMissing = sSubStr.substr(24, 3); //crash


					//search for string in string
					string stringSearch("abcdefghi");
					int fIndexS = stringSearch.find("cde"); //2 
					int rIndexS = stringSearch.rfind("gh"); //6
					int missingIndexS = stringSearch.rfind("aaaagh"); //6
					



					//How to copy char* to string object
					//iterate the char array and add one letter at a time using + operator.
					//You can write a helper function to this.
					/*
						char* s;
					
						int len = strlen(s);
						string s1;
						for (int i = 0; i < len; i++)
						{
							s1 += s[i];
						}
						return s1;
					*/


					
					//StringObject -> char[]
					//Use string::copy(); this does not allocate memory nor it puts EOL at the end.
					//copy(char* s, size_t len, size_t pos = 0) const;
					char buf[200];
					string str("ghsdfsdfh");
					int charsToCopy = 4;
					int srcIdx = 2; //from where to copy
					std::size_t copiedBytes = str.copy(buf, charsToCopy, srcIdx);
					buf[copiedBytes] = '\0';
					
					//char[] -> StringObject
					//Constructing String object out of existing char array
					char bufx[3]={'a', 'n', 'k'};
					string stx(bufx,sizeof(bufx)); 
					
					//Shrink StringObject.(like setting '\0' in C) 
					//We used to shrink the c-array by setting '\0' somewhere in the middle of the array.
                    //We want to do same for STRING. This is done using RESIZE
					string someX("jkgchjgsdhgf");
					int newLen = 3;
					someX.resize(3);
					

				}
	};
};