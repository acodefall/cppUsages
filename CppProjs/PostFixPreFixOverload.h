#include <stdio.h>
#include <iostream>

class testFixes
{
	int x;

	public:
		testFixes(int y)
		{
			x = y;
		}

		testFixes& operator++()
		{
			x++;
			return *this;
		}

		testFixes& operator++(int)
		{
			testFixes t1(*this);
			x++;
			return t1;
		}
};

class callTestFixes
{
	public:
		void callTestFixesX()
		{
			testFixes f(78);

			f++;
			++f;
		}

};