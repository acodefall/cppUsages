#include<stdio.h>
#include<iostream>

using namespace std;

/*

//@GN812  Implement a SizeOf() function_GN812
This is implemented in C++ and C#	
This function is a Template Function. Function creates an instance of T and assigns 1 to it. Then start a while loop to run as long as (T > 0). Inside the while loop, right-shift the T by 1, and also increment the BitCount variable.  In the end BitCount variable will have the result of SizeOf().
	
	Steps: 
		a) Implement the template function as follows.
			template <typename T> int getSize()
			{
				T n = 1;
				int cnt = 0;
				while (n != 0)
				{
					n <<= 1;
					cnt++;
				}
				return cnt;
			}

		b) Calling is 
				getSize<int>()
				getSize<char>()

*/
template <typename T> int getSize()
{
	T n = 1;
	int cnt = 0;

	while (n != 0)
	{
		n <<= 1;
		cnt++;
	}

	return cnt;
}

class SizeofX
{
	public:
			SizeofX()
			{

			}

			void callSizeof()
			{
				cout << "size of Int is " << getSize<int>(); 
				cout << "size of char is " << getSize<char>();
			}
};
