#pragma once
#include <chrono>
#include <iostream>
using namespace std;
namespace UsingTimerNM
{
	class UsingTimer
	{
		public:
			void callUsingTimer()
			{
				
			}

			void randomFilenameUsingTickCount()
			{
				auto tickCount = std::chrono::system_clock::now().time_since_epoch();
				cout << tickCount.count() << ".log";
			}
	};
};