#pragma once
#include <iostream>

using namespace std;
namespace PrivateCtorNM
{
	/*
		Private and Protected CTORS
			Private constructors makes the base-class unavailable for all the derived class memeber and also outsiders.
			Outsiders can not even instantiate the derived class
		
			Protected constructors makes the base-class unavailable for outsiders and available for derived classes.
			Outsiders can instantiate the derived class.
	*/
	class PrivateCtorC
	{
		private:
					PrivateCtorC()
					{
						cout << "PrivateCtorC() private ctor" << endl;
					}

		public:
					void M1()
					{
					}
	};

	class PrivateCtorD : public PrivateCtorC
	{
		public:
				/* Give error
				PrivateCtorD(int s)
				{

				}*/
				void M2()
				{
					M1();
				}
	};

	class callPrivateTest
	{
		public:
				void test()
				{
					//Private constructors makes the class unavailable for all the derived classes and also outsiders
					//PrivateCtorD o1;
					//o1.M1();
				}

	}
};
