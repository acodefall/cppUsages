#pragma once
#include <string>
#include <iostream>
using namespace std;
namespace AppendToStringNM
{
	class AppendCharToString
	{
		public:	
			void callAppendCharToString()
			{
				string sss("retarted string object");
				sss += 'Y';
				sss += 'e';
				sss += 's';

				cout << sss << "\r\n";
			}
	};
};