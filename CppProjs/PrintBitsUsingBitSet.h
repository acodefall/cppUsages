#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

namespace PrintHexDecNM
{
    class PrintHexDec
    {
        ////@BT02
		public:
			void callPrintHexDec()
			{
				
				int x2 = 0x97;
				cout << endl;
				cout << " (hex) : " << hex << x2 << endl;
				cout << " (dec) : " << dec << x2 << endl;
			}
	};
};
