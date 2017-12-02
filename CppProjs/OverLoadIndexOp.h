
#include "stdafx.h"
#include <iostream>
using namespace std;

/*
	No. Object overloads the Index operator to make the object appear like collection. Index operator can only read the value, 	it can not update the current object. So we can not have something like
		array[5] = 100;
		So instead of overloading index operator, expose set/get methods.
*/
class OIndex
{
	int* a;
	public:
		OIndex(int x)
		{
			a = new int[x];
		}

		int& operator[] (int index)
		{
			return a[index];
		}

};

class OIndexX
{
	public:
		void callOIndex()
		{
			OIndex x(10);

			x[0] = 2;
			x[1] = 4;
		}
};