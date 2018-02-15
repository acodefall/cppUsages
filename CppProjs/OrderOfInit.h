#pragma once
#include <list>
#include <iostream>
using namespace std;

namespace OrderOfInitNM
{
	/*
		Order of creation is as follows
			Data members of base-class are created based on their order of declaration.
			Then CTOR of the base-class gets executed.

			Data members of derived-class are created based on their order of declaration.
			Then CTOR of the derived-class gets executed.

			Dtor of derived class goes first, and then the Dtor of the Data members of derived class goes next.
			Dtor of base class goes next, and then the Dtor of the Data members of base class gets executed.
	*/
	class mem1
	{
		public:
				int r;
				mem1()
				{
					r = 10;
					cout << "mem1::mem1()" << endl;
				}

				~mem1()
				{
					cout << "~mem1::mem1()" << endl;
				}
	};

	class mem2
	{
		public:
			int r2;
			mem2()
			{
				r2 = 20;
				cout << "mem2::mem2()" << endl;
			}

			~mem2()
			{
				cout << "~mem2::mem2()" << endl;
			}
	};

	class B
	{
		mem1 x;
		public:
				int r3;
				B()
				{
					r3 = 30;
					cout << "B::B()" << endl;
					cout << "B::B() mem1::r1  " << x.r << endl;
				}

				~B()
				{
					cout << "~B::B()" << endl;
				}

	};

	class A : public B
	{
		mem2 x;
		public:
			int r4;
			A()
			{
				r4 = 40;
				cout << "A::A()" << endl;
				cout << "A::A() mem2::r2  " << x.r2 << endl;
			}

			~A()
			{
				cout << "~A::A()" << endl;
			}
	};

	class testOrderInit
	{
		public:
			void calltestOrderInit()
			{
				A o1;

				cout << "end" << endl;


				/*
					mem1::mem1()
					B::B()
					B::B() mem1::r1  10
					mem2::mem2()
					A::A()
					A::A() mem2::r2  20
					
					~A::A()
					~mem2::mem2()
					~B::B()
					~mem1::mem1()

					Order of creation is as follows
					Data members of base-class are created based on their order of declaration.
					Then CTOR of the base-class gets executed.

					Data members of derived-class are created based on their order of declaration.
					Then CTOR of the derived-class gets executed.

					Dtor of derived class goes first, and then the Dtor of the Data members of derived class goes next.
					Dtor of base class goes next, and then the Dtor of the Data members of base class gets executed.
				*/
			}
	};
};