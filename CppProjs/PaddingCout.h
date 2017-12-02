#pragma once
#include <iomanip>
#include <iostream>
using namespace std;
namespace PaddingCoutNM
{
	/*
		Pad the text printed using COUT
		For padding with 4 spaces call setw(4) and follow it up with actual text.
			cout << setw(4) << 25; //"    25"
			//setw() can be read as setwidth();
		For padding with 4 zero or anything call setfill(), and then setw() and provide actual text to be printed.
		Character to be used for filling is passed to setfill().
		Width of padding is passed to setw().
			cout << setfill('c') << setw(4) << "ok";

		declared ins <iomanip>
					void CallPaddingCout()
					{
						cout << "\r\n";
						cout << setfill('x') << setw(4) << "oK";
						cout << "\r\n";
						cout << setw(4) << "oK";
					}
	};
	*/
	class PaddingCout
	{
		public:
			void CallPaddingCout()
			{
				cout << "\r\n";
				cout << setfill('x') << setw(4) << "oK";
				cout << "\r\n";
				cout << setw(4) << "oK";
			}
	};
};