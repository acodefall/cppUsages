#pragma once
#include <iostream>

using namespace std;
namespace AccessorTestNM
{
	/*
		protected data member:
					These variables can be called from inside derived class, can not be called from instance of class. 

		Types of inheritance
		Asset being exported are
				-public and protected data memebers of base class.
				-private data members are exported.
		Public inheritance will inherit 'public as public' and 'protected as protected'. Outsider(using the instance) 
		can call public-asset(M3), but not protected-asset(M2) 
		Derived class can call both public-asset(M3) and protected-asset(M2), but not private asset.


		Private inheritance will inherit 'public as private' and 'protected as private'. Outsider(using the instance)
		can not call public-asset(M3) and also protected-asset(M2)
		Derived class can call both public-asset(M3) and protected-asset(M2), but not private asset.


	*/
	class baseArc 
	{
		private:
			void M1()
			{
				cout << "private baseArc::M1()" << endl;
			}

		protected:
			void M2() //this can only be called from inside the derived class member function.
			{
				cout << "protected baseArc::M2()" << endl;
			}

		public:
			void M3()
			{
				cout << "public baseArc::M3()" << endl;
			}
	};

	//Public inheritance will inherit 'public as public' and 'protected as protected'
	class dArc1 : public baseArc
	{
		private:
				void L1()
				{
					//POINT_1
						//Public inheritance will inherit 'public as public' and 'protected as protected'
						//private members of base class are nor accessible FROM any part of derived class.
						//can not be called from inside, nor be called from outside
						//derived class can not call private members of base class.
						//M1();
					M2();
					M3();
				}

	};

	//Public inheritance will inherit 'public as private' and 'protected as private'
	class dArc2 : private baseArc
	{
		private:
			void P1()
			{
				//POINT_1
				//private members of base class are nor accessible FROM any part of derived class.
				//can not be called from inside, nor be called from outside
				//derived class can not call private members of base class.
				//M1();
				M2();
				M3();
			}

	};

	class callAccessorTest
	{
		private:
			void test()
			{
				//POINT_2
				//Public inheritance 'public as public' and 'protected as protected'
				//So outside caller can only use baseArc::M3()
				
				dArc1 v1;
				//v1.M2(); Error
				v1.M3();
			}

			void test2()
			{
				//POINT_2
				//Private inheritance 'public as private' and 'protected as private'
				//So outside can not call anything 

				dArc2 v1;
				//v1.M2(); Error
				//v1.M3(); Error
			}
	};
};