#include <stdio.h>
#include <iostream>
using namespace std;


/*
	Why Protected is used?
		Protected is used for exposing the method only to the derived-class-instance. Protected member can not be called on the instance created using NEW; this applies to derived class also.
		Though Derived class can access the protected content, it can not access the protected content though the brand new instance of base class, created locally.

		Derived class can access the protected content of base class irrespective of Type of inheritance.

*/
class P0
{
	int x;
	
	void P0PrivateM2()
	{
		cout << "In P0PrivateM2()" << x;
	}

	public:
		P0()
		{
			x = 90;
			p0ProtData = 78;
		}

		void P0PublicM1()
		{
			cout << "In P0PublicM1()" << x;
		}

	protected:
		int p0ProtData;
		void P0ProtectedM3()
		{
			cout << "In P0ProtectedM3()" << x;
		}
};

class P1 : private P0
{	
	public:
		P1()
		{

		}
		void P1PublicMethod()
		{
			p0ProtData = 90; //Accessing the private data of base class.
			P0ProtectedM3();
			P0PublicM1();
			//P0PrivateM2(); Derived class can never access the PRIVATE members of base class irrespective of type of INHERITANCE
		}
};


class P2 : protected P0
{
	public:
		P2()
		{

		}
		void P2PublicMethod()
		{
			P0ProtectedM3();
			P0PublicM1();
			//P0PrivateM2(); Derived class can never access the PRIVATE members of base class irrespective of type of INHERITANCE


			/*
			Derived class can access the protected content of base class irrespective of Type of inheritance.
			Derived class will not be able to access the protected content if it creates brand new instance of
			base class and uses that to call the protected methods.*/
			P0 s1;
			//s1.P0ProtectedM3(); can not call the protected member of base class using brand new instance.
		}
};


class P3 : public P0
{
	public:
		P3()
		{

		}
		void P3PublicMethod()
		{
			P0ProtectedM3();
			P0PublicM1();
			//P0PrivateM2(); //Derived class can never access the PRIVATE members of base class irrespective of type of INHERITANCE
		}
};



class TryEncap
{
	public:
		void callTryEncap()
		{
			P1	p1;
			p1.P1PublicMethod();
			//p.P0PublicM1(); Since the inheritance is PRIVATE, client of derived class can not access the PRIVATE methods of BASE class

			P2 p2;
			p2.P2PublicMethod();
			
			P3 p3;
			p3.P3PublicMethod();
			p3.P0PublicM1(); //Since inheritance is PUBLIC, client of drevied class can call the PUBLIC methods of BASE class.
			
		}
};