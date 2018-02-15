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

namespace PrintBitsUsingBitSetNM
{
    class PrintBitsUsingBitSet
    {
        ////@BT02
		public:
			void callPrintBitsUsingBitSet()
			{
				int x1 = 0x17;
				int x2 = 0x97;
				cout << endl;
				cout << " 32-bit width :'" << bitset<32>(x1) << "'" << endl;
				cout << " 10-bit width :'" << bitset<10>(x2) << "'" << endl;
				
			}
	};
};
